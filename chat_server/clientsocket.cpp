#include "clientsocket.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "qtcpsocket.h"
#include "qtmetamacros.h"
#include "type.h"
#include "myapp.h"

#include "database.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include<QJsonValue>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>


ClientSocket::ClientSocket(QObject *parent,QTcpSocket* tcpSocket)
    : QObject{parent}
{
    m_id = -1;

    if (tcpSocket == NULL) m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket = tcpSocket;
    connect(tcpSocket,&QTcpSocket::readyRead,this,&ClientSocket::readMsg);
//    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(SltReadyRead()));
    connect(m_tcpSocket, &QTcpSocket::connected, this, &ClientSocket::sltConnected);
    connect(m_tcpSocket,&QTcpSocket::disconnected,this,&ClientSocket::sltDisconnected);
}

void ClientSocket::closeSocket()
{
    //终止当前连接并重置套接字 丢弃写缓冲区中的任何挂起数据
    m_tcpSocket->abort();

}

int ClientSocket::getUserID()
{
    return m_id;
}

void ClientSocket::readMsg()
{
    // 读取socket数据
    QByteArray reply=m_tcpSocket->readAll();
    //解析数据
    QJsonParseError jsonError;
    // 转化为 JSON 文档
    QJsonDocument document=QJsonDocument::fromJson(reply,&jsonError);

      // 解析未发生错误
    if((!document.isNull())&&(QJsonParseError::NoError==jsonError.error))
    {
        // JSON 文档为对象
        if(document.isObject())
        {
            // 转化为对象
            QJsonObject jsonObj=document.object();

            int sendID=jsonObj.value("from").toInt();
            int type=jsonObj.value("type").toInt();
            QJsonValue data=jsonObj.value("data");
            qDebug()<<"recv from client"<<sendID<<jsonObj;
            switch (type) {
            case SendGroupMsg:
//                emit sendAllMsg(data);
                ParseGroupMessages(reply);
            break;
            case SendFileOk:
            {

            }
            break;
            case SendMsg://私发消息
            case SendFile:
            case SendPicture:
            {
                parseFriendMessages(reply);
            }
            break;
            case GetFile:
            case GetPicture:
            {
                Q_EMIT signalDownloadFile(data);
            }
            break;
//            case GetFile:
//            {
//                emit signalDownloadFile(data);
//            }
//            break;
//            case GetPicture:
//            {
//                emit signalDownloadFile(data);
//            }
//            break;
//            case SendFace:
//            {
//                ParseGroupMessages(reply);
//            }
//            break;
            case FindFriend:
                parseFindFriend(data);
                break;
            case AddFriend:
            {
                ParseAddFriend(data);
            }
            break;
            case AddFriendRequist:
            {
                parseAddFriendReply(data);
            }
            break;
            case AddGroup:
            {
                parseAddGroup(data);
            }
            break;
            case AddGroupRequist:
            {
                parseAddGroupReply(data);
            }
            break;
            case CreateGroup:
            {
                parseCreateGroup(data);
            }
            break;
            case GetMyFriends:
            {
                ParseGetMyFriend(data);
            }
            break;
//            case GetMyGroups:
//            {
//                ParseGetMyGroups(dataVal);
//            }
//            break;

//            case RefreshFriends:
//            {
//                ParseRefreshFriend(dataVal);
//            }
//            break;
//            case RefreshGroups:
//            {
//                ParseRefreshGroups(dataVal);
//            }
//            break;
            case Login:
                UserLogin(data);
                break;
            case Register:
                parseReister(data);
                break;
            case UserOnLine:
                ParseUserOnline(data);
            break;
            case Logout:
            {
                ParseLogout(data);
                Q_EMIT signalDisConnected();
                m_tcpSocket->abort();
            }
            break;
            case UpdateHeadPic:
            {
                ParseUpdateUserHead(data);
            }
            break;
            case GetOfflineMsg:
            {
                parseGetOfflineMsg(data);
            }
            break;
            default:
                break;
            }

        }

    }        
}

void ClientSocket::parseFriendMessages(const QByteArray &reply)
{
    // 重新组装数据
    QJsonParseError jsonError;
    // 转化为 JSON 文档
    QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);
    // 解析未发生错误
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        // JSON 文档为对象
        if (doucment.isObject()) {
            // 转化为对象
            QJsonObject jsonObj = doucment.object();
            int nType = jsonObj.value("type").toInt();
            QJsonValue dataVal = jsonObj.value("data");

            //服务器收到了用户发来的消息，向用户回复已收到
            sendMessage(MsgReceived,dataVal);

            QJsonObject dataObj = dataVal.toObject();
            int reveicerID = dataObj.value("to").toInt();//获取消息接受者的ID

            Q_EMIT sendMessagetoClient(quint8(nType), reveicerID, dataObj);//(type,reveicerID,data)
        }
    }
}

/**
 * 处理群组消息转发
*/
void ClientSocket::ParseGroupMessages(const QByteArray &reply)
{
    // 重新组装数据
    QJsonParseError jsonError;
    // 转化为 JSON 文档
    QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);
    // 解析未发生错误
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
    // JSON 文档为对象
        if (doucment.isObject()) {
            // 转化为对象
            QJsonObject jsonObj = doucment.object();
            int nType = jsonObj.value("type").toInt();
            QJsonValue dataVal = jsonObj.value("data");

            //通知客户端，该消息已经被服务器收到，客户端可以消除动画
            Q_EMIT sendMessage(MsgReceived,dataVal);

            QJsonObject dataObj = dataVal.toObject();
            // 转发的群组id
            int nGroupId = dataObj.value("to").toInt();
            QString strMsg = dataObj.value("msg").toString();
            QString groupHead = Database::Instance()->getGroupInfo(nGroupId).value("head").toString();

            // 查询该群组下面的用户，一一转发消息
            QString name = Database::Instance()->getUserName(m_id);
            qint64 time = dataObj.value("time").toInt();

            // 查询该群组里面的在线好友
            QJsonArray jsonArr = Database::Instance()->getGroupUsers(nGroupId);
            if (jsonArr.size() < 2) return;
            for (int i = 1; i < jsonArr.size(); i++) {
                QJsonObject json = jsonArr.at(i).toObject();
                int nStatus = json.value("status").toInt();
                int nUserId = json.value("id").toInt();

                // 只给在线的好友转发消息
                if (OnLine == nStatus && m_id != nUserId) {
                    // 重组消息
                    QJsonObject jsonMsg;
                    jsonMsg.insert("group", nGroupId);
                    jsonMsg.insert("groupHead",groupHead);
                    jsonMsg.insert("id", m_id);
                    jsonMsg.insert("time",time);
                    jsonMsg.insert("name", name);//发送该条群聊消息的人的名字
                    jsonMsg.insert("to", nUserId);
                    jsonMsg.insert("msg", strMsg);
                    jsonMsg.insert("head", Database::Instance()->getUserHead(m_id));

                    emit sendMessagetoClient(quint8(nType), nUserId, jsonMsg);
                }
            }
        }
    }
}
void ClientSocket::sendMessage(const quint8 &type, const QJsonValue &jsonVal)
{
    if (!m_tcpSocket->isOpen())
        return;

    // 构建 Json 对象
    QJsonObject jsonObj;
    jsonObj.insert("type", type);
    jsonObj.insert("from", m_id);
    jsonObj.insert("data", jsonVal);

    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(jsonObj);
    m_tcpSocket->write(document.toJson(QJsonDocument::Indented));
    qDebug() << "-> " << "服务器向用户" << m_id << "发送一条消息，"
             << "消息内容为:" << jsonObj ;
}

void ClientSocket::sltConnected()
{
    qDebug() << "new socket connected";
}

void ClientSocket::sltDisconnected()
{
    Database::Instance()->updateUserStatus(m_id, OffLine);
    Q_EMIT signalDisConnected();
}


void ClientSocket::UserLogin(QJsonValue dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        int id = dataObj.value("id").toInt();
//        QString name = dataObj.value("name").toString();
        QString strPwd = dataObj.value("password").toString();
        qDebug()<<strPwd;
        //查询数据库验证用户和密码是否匹配
        QJsonObject json = Database::Instance()->checkUserLogin(id, strPwd);
        qDebug()<<"验证完毕"<<json.value("code").toInt();
        int code = json.value("code").toInt();

        //登陆成功
        if(code == 0){
            m_id = id;
//            m_id = json.value("id").toInt();
            emit successLogin();
        }

//        m_id = json.value("id").toInt();
        qDebug() << "login " << json<<m_id;

        if (m_id > 0) emit signalConnected();
        //把登陆消息返回给客户端
        sendMessage(Login,json);
    }
}

void ClientSocket::parseReister(const QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataObj=dataVal.toObject();
        QString name=dataObj.value("name").toString();
        QString password=dataObj.value("pwd").toString();

        int id=Database::Instance()->registerUser(name,password);
        //封装数据 将数据结果发送至客户端
        QJsonObject json;
        json.insert("id",id);
        json.insert("pwd",password);
        json.insert("name",name);
        sendMessage(Register,json);
    }

}

void ClientSocket::ParseUserOnline(const QJsonValue &dataVal)
{
    // data 的 value 是数组
    if (dataVal.isArray()) {
        QJsonArray jsonArray = dataVal.toArray();
        int nSize = jsonArray.size();
        for (int i = 0; i < nSize; ++i) {
            int nId = jsonArray.at(i).toInt();
            int nStatus = Database::Instance()->getUserOnLineStatus(nId);
            // 给在线的好友通报一下状态
            if (OnLine == nStatus) {
                QJsonObject jsonObj;
                jsonObj.insert("id", m_id);
                jsonObj.insert("text", "online");

                emit sendMessagetoClient(UserOnLine, nId, jsonObj);
            }
        }
    }
}

void ClientSocket::ParseLogout(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();

        QJsonArray array = dataObj.value("friends").toArray();
        int nId = dataObj.value("id").toInt();
        int nSize = array.size();

        Database::Instance()->updateUserStatus(nId, OffLine);

        for (int i = 0; i < nSize; ++i) {
            nId = array.at(i).toInt();
            int nStatus = Database::Instance()->getUserOnLineStatus(nId);
            // 给在线的好友通报一下状态
            if (OnLine == nStatus) {
                QJsonObject jsonObj;
                jsonObj.insert("id", m_id);
                jsonObj.insert("text", "offline");

                emit sendMessagetoClient(UserOffLine, nId, jsonObj);
            }
        }
    }
}

void ClientSocket::ParseUpdateUserHead(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        int nId = dataObj.value("id").toInt();
        QString strHead = dataObj.value("head").toString();

        // 更新数据库
        Database::Instance()->updateUserHead(nId, strHead);

        // 通知其他在线好友，说我已经修改了头像
        QJsonArray jsonFriends =  dataObj.value("friends").toArray();
        QJsonObject jsonObj;
        // 是我在更新，我要去下载我的头像
        jsonObj.insert("id", nId);
        jsonObj.insert("head", strHead);

        for (int i = 0; i < jsonFriends.size(); i++) {
            nId = jsonFriends.at(i).toInt();
            emit sendMessagetoClient(UpdateHeadPic, nId, jsonObj);
        }
    }
}

void ClientSocket::ParseGetMyFriend(const QJsonValue &dataVal)
{
    QJsonArray jsonArray;
    // data 的 value 是数组
    if (dataVal.isArray()) {
        QJsonArray array = dataVal.toArray();
        int nSize = array.size();
        // 先添加在线好友，在添加离线好友
        for (int i = 0; i < nSize; ++i) {
            int nId = array.at(i).toInt();
            jsonArray.append(Database::Instance()->getUserStatus(nId));
        }
    }

    sendMessage(GetMyFriends, jsonArray);
}

void ClientSocket::parseFindFriend(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();

        int tag = json.value("tag").toInt();
        int id = json.value("id").toInt();
        QJsonObject jsonObj;
        if(tag == 0){
            jsonObj = Database::Instance()->getUserInfo(id);
        }else if(tag == 1){
            jsonObj = Database::Instance()->getGroupInfo(id);
        }

        sendMessage(FindFriend,jsonObj);
    }
}

void ClientSocket::ParseAddFriend(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject json = dataVal.toObject();

        int id = json.value("id").toInt();
        int senderid = json.value("sender").toInt();

        QJsonObject jsonObj = Database::Instance()->getUserInfo(senderid);
        jsonObj.insert("msg","add friend request");
        jsonObj.insert("time",QDateTime::currentSecsSinceEpoch());
        jsonObj.insert("tag",0);

        emit sendMessagetoClient(AddFriend, id, jsonObj);

//        QJsonObject dataObj = dataVal.toObject();
//        QString strName = dataObj.value("name").toString();
//        QJsonObject jsonFriend = Database::Instance()->addFriend(strName);
//        int nId = jsonFriend.value("id").toInt();
//        QString strMsg = jsonFriend.value("msg").toString();

//        // 发送查询结果至客户端
//        sendMessage(AddFriend, jsonFriend);

//        if (nId < 0) return;

//        // 给对方ID发送add请求
//        QJsonObject jsonQuery = Database::Instance()->getUserInfo(nId);
//        QJsonObject jsonRequest;
//        jsonRequest.insert("id", nId);
//        jsonRequest.insert("name", jsonQuery.value("name").toString());
//        jsonRequest.insert("head", jsonQuery.value("head").toString());
//        jsonRequest.insert("msg", strMsg.isEmpty() ? "附加消息： 你好！" : strMsg);

//        emit sendMessagetoClient(AddFriendRequist, nId, jsonRequest);
    }
}

void ClientSocket::parseAddFriendReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int userID1 = json.value("userID1").toInt();//发送请求者
        int userID2 = json.value("userID2").toInt();
        QString time = json.value("time").toString();
        //先更新数据库，再通知发送请求的用户

        QSqlQuery query;

        query.prepare("INSERT INTO Friendship (userID1, userID2, createTime) "
                      "VALUES (?, ?, ?);");
        query.bindValue(0, userID1);
        query.bindValue(1, userID2);
        query.bindValue(2, time);

        query.exec();

        //通知用户
        QJsonObject jsonObj = Database::Instance()->getUserInfo(userID2);
        Q_EMIT sendMessagetoClient(AddFriendRequist, userID1, jsonObj);
    }
}

void ClientSocket::parseAddGroup(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject json = dataVal.toObject();
        int id = json.value("id").toInt();      //groupid
        int senderid = json.value("sender").toInt();

        QJsonObject jsonObj = Database::Instance()->getUserInfo(senderid);
        QJsonObject groupInfo = Database::Instance()->getGroupInfo(id);
        int adminID = groupInfo.value("adminID").toInt();
        QString groupName = groupInfo.value("name").toString();
        QString groupHead = groupInfo.value("head").toString();

        if(adminID != -1){
            jsonObj.insert("msg","add group request");
            jsonObj.insert("time",QDateTime::currentSecsSinceEpoch());
            jsonObj.insert("group",id);
            jsonObj.insert("groupName",groupName);
            jsonObj.insert("groupHead",groupHead);
            jsonObj.insert("tag",1);

            // 发送查询结果至客户端
            // 通知该群的群主处理该条请求消息
            Q_EMIT sendMessagetoClient(AddGroup, adminID, jsonObj);
        }
    }
}

void ClientSocket::parseAddGroupReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int userID = json.value("userID").toInt();//发送请求者
        int groupID = json.value("groupID").toInt();
        QString time = json.value("time").toString();
        //先更新数据库，再通知发送请求的用户

        QSqlQuery query;

        query.prepare("INSERT INTO GroupUser (groupID, userID, joinTime) "
                      "VALUES (?, ?, ?);");
        query.bindValue(0, groupID);
        query.bindValue(1, userID);
        query.bindValue(2, time);

        query.exec();

        //通知发送请求的用户
        QJsonObject jsonObj = Database::Instance()->getGroupInfo(groupID);
        Q_EMIT sendMessagetoClient(AddGroupRequist, userID, jsonObj);

        //----------------------------------------------

        //通知该群的用户，更新聊天窗口中的群列表信息，并且显示该用户已经加入群
        QJsonObject newUserInfo = Database::Instance()->getUserInfo(userID);
        QString name = newUserInfo.value("name").toString();
        QString head = newUserInfo.value("head").toString();

        QJsonObject groupInfo = Database::Instance()->getGroupInfo(groupID);
        QString groupName = groupInfo.value("name").toString();
        int adminID = groupInfo.value("adminID").toInt();

        QJsonArray jsonArr = Database::Instance()->getGroupUsers(groupID);
        for (int i = 0; i < jsonArr.size(); i++) {
            QJsonObject json = jsonArr.at(i).toObject();
            int id = json.value("id").toInt();

            if(id == userID || id == adminID)//不通知请求发送者和群主，因为他们已经处理了该条消息
                continue;

            // 重组消息
            QJsonObject jsonMsg;
            jsonMsg.insert("group", groupID);
            jsonMsg.insert("groupName",groupName);
            jsonMsg.insert("id", userID);//新入群用户的id
            jsonMsg.insert("name", name);//新入群用户的名字
            jsonMsg.insert("head",head);
            jsonMsg.insert("time",time);
            jsonMsg.insert("to", id);
            jsonMsg.insert("msg", QString::number(userID) + "已加入该群");
            jsonMsg.insert("tag",1);
            jsonMsg.insert("type",Notice);
            jsonMsg.insert("noticeType",NewMember);

            Q_EMIT sendMessagetoClient(SendGroupMsg, id, jsonMsg);
        }
    }
}

void ClientSocket::parseCreateGroup(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        QString name = dataObj.value("name").toString();
        int adminID = dataObj.value("adminID").toInt();
        qint64 time = dataObj.value("time").toInt();

        QJsonObject json = Database::Instance()->createGroup(adminID,name,time);
        // 发送查询结果至客户端
        sendMessage(CreateGroup, json);
    }
}

void ClientSocket::parseGetOfflineMsg(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int id = json.value("id").toInt();
        qDebug() << "user:" << id << "request for loading offline msg";

        QJsonArray jsonArr = Database::Instance()->getOfflineMsg(id);
        sendMessage(GetOfflineMsg,jsonArr);
    }
}



//--------------------filesocket--------------------------//

ClientFileSocket::ClientFileSocket(QObject *parent, QTcpSocket *tcpSocket):QObject{parent}
{

    // 将整个大的文件分成很多小的部分进行发送，每部分为4字节
    loadSize            = 50 * 1024;
    ullSendTotalBytes   = 0;
    ullRecvTotalBytes   = 0;
    bytesWritten        = 0;
    bytesToWrite        = 0;
    bytesReceived       = 0;

    fileNameSize        = 0;
    m_bBusy             = false;

    m_UserId           = -1;
    m_WindowId         = -1;

    // 本地文件存储
    fileToSend = new QFile(this);
    fileToRecv = new QFile(this);

    // 客户端
    if (tcpSocket == NULL) m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket = tcpSocket;

    // 我们更新进度条
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &ClientFileSocket::sltReadyRead);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &ClientFileSocket::signalDisConnected);

    // 当有数据发送成功时，我们更新进度条
    connect(m_tcpSocket, &QTcpSocket::bytesWritten, this, &ClientFileSocket::sltUpdateClientProgress);
}

void ClientFileSocket::closeSocket()
{
    m_tcpSocket->abort();
}

//用户socket检测，通过此函数进行判断连接的socket
bool ClientFileSocket::CheckUserId(const qint32 fromId,const qint32 toId)
{
    return ((m_UserId == fromId) && (m_WindowId == toId));
}

int ClientFileSocket::getID() const
{
    return m_UserId;
}

void ClientFileSocket::fileTransFinished()
{
    ullSendTotalBytes   = 0;
    ullRecvTotalBytes   = 0;
    bytesWritten        = 0;
    bytesToWrite        = 0;
    bytesReceived       = 0;

    fileNameSize        = 0;
    m_bBusy = false;
}

/**
 * 下发文件
 */
void ClientFileSocket::startTransferFile(QString fileName, int senderID, qint64 time, int flag)
{
    if (m_bBusy || !m_tcpSocket->isOpen())
        return;

    // 要发送的文件
    qDebug() << "服务器准备发送的文件为：" << fileName;
    fileToSend = new QFile(fileName);

    if (!fileToSend->open(QFile::ReadOnly)){
        qDebug() << "open file error!";
        return;
    }

    // 文件总大小
    ullSendTotalBytes = quint64(fileToSend->size());

    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_6_4);

    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);

    // 依次写入[总大小信息空间,文件名大小信息空间,文件发送者ID,文件时间,flag,文件名]
    sendOut << qint64(0) << qint64(0) << qint64(0) << qint64(0) << qint64(0) << currentFileName;

    // 这里的总大小是文件名大小等信息和实际文件大小的总和
    ullSendTotalBytes += quint64(outBlock.size());

    // 返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
    sendOut.device()->seek(0);
    sendOut << ullSendTotalBytes << qint64((unsigned(outBlock.size()) - sizeof(qint64)*5))
            << qint64(senderID) << time << qint64(flag);

    // 发送完头数据后剩余数据的大小
    bytesToWrite = ullSendTotalBytes - quint64(m_tcpSocket->write(outBlock));

    outBlock.resize(0);
    m_bBusy = true;

    if(senderID == 0){
        qDebug() << "Begin to send file" << fileName
                 << " [ sent by:" << m_WindowId << " recv by:"<< m_UserId << "]";
    }else{
        qDebug() << "Begin to send file" << fileName
                 << " [ sent by:" << senderID << "in group"
                 << m_WindowId << " recv by:"<< m_UserId << "]";
    }
}

void ClientFileSocket::insertDataBase(QString filepath, QString filename)
{
    QFileInfo fileinfo(filepath + filename);
    qint64 filesize = 0;
    if(fileinfo.exists()){
        filesize = fileinfo.size();
        qDebug()<<filesize;
    }

    QString sendtime = QDateTime::fromSecsSinceEpoch(msgSendTime).toString("yyyy-MM-dd  hh:mm:ss");
    qDebug() << "file sent time:" << msgSendTime << sendtime;
    QSqlQuery query;

    query.prepare("INSERT INTO FileSent (senderID, receiverID, groupID, "
                  "filename, filesize, filepath, time, tag, type) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
    query.bindValue(0, m_UserId);
    query.bindValue(3, filename);
    query.bindValue(4, filesize);
    query.bindValue(5, filepath);
    query.bindValue(6, sendtime);
    query.bindValue(7, 0);
    query.bindValue(8, tag);

    if(tag == 0){//私发文件
        query.bindValue(1, m_WindowId);
        query.bindValue(2, 0);
        query.exec();
        //qDebug() << query.lastError().text();

        if(fileinfo.suffix().toLower() == "png" || fileinfo.suffix().toLower() == "jpg"){
            //通知发送该图片的客户端已经收到该图片,客户端消除动画
            {
                QJsonObject json;
                json.insert("from",m_UserId);
                json.insert("to",m_WindowId);
                json.insert("time",msgSendTime);
                emit sendMessagetoClient(MsgReceived,m_UserId,json);
            }

            //此处需要先判断用户是否在线，若不在线，则不发送，等到下次用户启动客户端再发送
            int status = Database::Instance()->getUserOnLineStatus(m_WindowId);
            if(status == OnLine){//用户在线
                //通知接收该图片的客户端打开tcp连接来接受该图片，因为若对方的这个聊天窗口没有打开是没法接收该文件的
                {   QJsonObject json;
                    json.insert("id",m_UserId);
                    json.insert("to",m_WindowId);
                    json.insert("time",msgSendTime);
                    json.insert("tag",0);
                    json.insert("type",Picture);
                    QJsonObject jsonObj = Database::Instance()->getUserInfo(m_WindowId);
                    QString name = jsonObj.value("name").toString();
                    json.insert("name",name);
                    emit sendMessagetoClient(SendPicture,m_WindowId,json);
                }

//                myHelper::Sleep(500);//等待500毫秒

                //如果客户端在线，500毫秒后可以确定客户端打开了连接，可以进行文件传输
                //若用户不在线，则需要把未传输的文件记录到数据库中，等到用户上线后重新传送

                //这个时候可以直接把图片文件发往目标用户
                {
                    QJsonObject json2;
                    json2.insert("tag",0);//群聊私聊标记
                    json2.insert("from",m_UserId);//文件来自谁
                    json2.insert("to",m_WindowId);//文件发往谁
                    json2.insert("group",0);//群id，没有就设为0
                    json2.insert("filename",filename);
                    json2.insert("time",msgSendTime);
                    emit signalDownloadFile(json2);
                }
            }else{//用户不在线，记录离线消息到数据库
                QJsonObject json;
                json.insert("id",m_UserId);
                json.insert("to",m_WindowId);
                json.insert("time",msgSendTime);
                json.insert("tag",0);
                json.insert("type",Picture);
                QJsonObject jsonObj = Database::Instance()->getUserInfo(m_WindowId);
                QString name = jsonObj.value("name").toString();
                json.insert("name",name);
                json.insert("msg",filename);
                json.insert("fileSize",filesize);
                emit sendMessagetoClient(SendPicture,m_WindowId,json);
            }
        }else{//普通文件，通知用户下载
            QJsonObject json;
            json.insert("id",m_UserId);
            json.insert("time",msgSendTime);
            json.insert("fileName",filename);
            json.insert("fileSize",filesize);
            json.insert("tag",tag);//私发文件还是群发文件
            json.insert("msg","");
            json.insert("group",0);
            json.insert("type",Files);

            QJsonObject jsonObj = Database::Instance()->getUserInfo(m_WindowId);
            QString name = jsonObj.value("name").toString();
            json.insert("name",name);
            json.insert("msg",filename);
            json.insert("fileSize",filesize);

            //通知用户下载文件
            emit sendMessagetoClient(SendFile, m_WindowId, json);//(type,reveicerID,data)
        }
    }else if(tag == 1){//群发文件
        query.bindValue(2, m_WindowId);

        QJsonArray array = Database::Instance()->getGroupUsers(m_WindowId);
        for (int i = 0; i < array.size(); i++) {
            QJsonObject json = array.at(i).toObject();
            int id = json.value("id").toInt();//要发送的目标用户id

            if(id == m_UserId){//通知发送该图片的客户端已经收到该文件,客户端消除动画
                if(fileinfo.suffix().toLower() == "png" || fileinfo.suffix().toLower() == "jpg"){
                    QJsonObject json;
                    json.insert("from",m_UserId);
                    json.insert("to",m_WindowId);
                    json.insert("time",msgSendTime);

                    emit sendMessagetoClient(MsgReceived,m_UserId,json);
                }
            }else{
                //不要给自己发
                query.bindValue(1, id);
                query.exec();
                //qDebug() << query.lastError().text();

                if(fileinfo.suffix().toLower() == "png" || fileinfo.suffix().toLower() == "jpg"){
                    //此处需要先判断用户是否在线，若不在线，则不发送，等到下次用户启动客户端再发送
                    int status = Database::Instance()->getUserOnLineStatus(id);
                    if(status == OnLine){
                        //通知接收该图片的客户端打开tcp连接来接受该图片，因为若对方的这个聊天窗口没有打开是没法接收该文件的
                        {
                            QJsonObject json;
                            json.insert("id",m_UserId);
                            json.insert("group",m_WindowId);
                            json.insert("time",msgSendTime);
                            json.insert("tag",1);
                            json.insert("type",Picture);
                            QJsonObject jsonObj = Database::Instance()->getUserInfo(id);
                            QString name = jsonObj.value("name").toString();
                            json.insert("name",name);
                            emit sendMessagetoClient(SendPicture,id,json);
                        }

//                        myHelper::Sleep(500);//等待500毫秒

                        //如果客户端在线，500毫秒后可以确定客户端打开了连接，可以进行文件传输
                        //若用户不在线，则需要把未传输的文件记录到数据库中，等到用户上线后重新传送

                        //这个时候可以直接把图片文件发往目标用户
                        {
                            QJsonObject json2;
                            json2.insert("tag",1);//群聊私聊标记
                            json2.insert("from",m_UserId);//文件来自谁
                            json2.insert("to",id);//文件发往谁
                            json2.insert("group",m_WindowId);//群id，没有就设为0
                            json2.insert("filename",filename);
                            json2.insert("time",msgSendTime);
                            emit signalDownloadFile(json2);
                        }
                    }else{//用户离线
                        QJsonObject json;
                        json.insert("id",m_UserId);
                        json.insert("group",m_WindowId);
                        json.insert("time",msgSendTime);
                        json.insert("tag",1);
                        json.insert("type",Picture);
                        QJsonObject jsonObj = Database::Instance()->getUserInfo(id);
                        QString name = jsonObj.value("name").toString();
                        json.insert("name",name);
                        json.insert("msg",filename);
                        json.insert("fileSize",filesize);
                        emit sendMessagetoClient(SendPicture,id,json);
                    }
                }else{//普通文件，通知用户下载
                    QJsonObject json;
                    json.insert("id",m_UserId);
                    json.insert("time",msgSendTime);
                    json.insert("fileName",filename);
                    json.insert("fileSize",filesize);
                    json.insert("tag",tag);//私发文件还是群发文件
                    json.insert("msg","");
                    json.insert("group",m_WindowId);
                    json.insert("type",Files);

                    QJsonObject jsonObj = Database::Instance()->getUserInfo(id);
                    QString name = jsonObj.value("name").toString();
                    json.insert("name",name);
                    json.insert("msg",filename);
                    json.insert("fileSize",filesize);

                    //通知用户下载文件
                    emit sendMessagetoClient(SendFile, id, json);//(type,reveicerID,data)
                }
            }
        }
    }
}




void ClientFileSocket::sltReadyRead()
{
//    通过in对象读取m_tcpSocket对象接收到的二进制数据
    QDataStream in(m_tcpSocket);
    in.setVersion(QDataStream::Qt_6_4);

    // 连接时的消息
    if (0 == bytesReceived && (-1 == m_UserId) && (-1 == m_WindowId) &&
        (m_tcpSocket->bytesAvailable() == (sizeof(qint32) * 3))){
        //客户端的TcpFileSocket在连上服务器后会首先发来三个字节的数据，分别是下面三个字段
        in >> m_UserId >> m_WindowId >> tag;
        if(m_WindowId == -2){
           qDebug() << "用户" << m_UserId << "全局收发文件的FileSocket已连接上服务器" ;
        }else{
           qDebug() << "聊天双方ID分别为:[" << "sender:" << m_UserId
                    << "  ->  receiver:" << m_WindowId << "]"
                    << "聊天类型为:" << (tag == 0 ? "私聊" : "群聊") ;
        }

        Q_EMIT signalConnected();
        return;
    }

    // 如果接收到的数据小于等于24( sizeof(qint64) * 3 )个字节，那么是刚开始接收数据，我们保存为头文件信息
    if (bytesReceived <= (sizeof(qint64)*3)){
        unsigned nlen = sizeof(qint64) * 3;

        // 接收数据总大小信息和文件名大小信息,以及最后的时间戳
        if ((m_tcpSocket->bytesAvailable() >= nlen) && (fileNameSize == 0)){
           in >> ullRecvTotalBytes >> fileNameSize >> msgSendTime;

           qDebug() << "new file arrived!";
           qDebug() << "msg total size is:" << ullRecvTotalBytes << "bytes"
                    << " filename size is:" << fileNameSize << "bytes"
                    << " send time is:"
                    << QDateTime::fromSecsSinceEpoch(msgSendTime).toString("yyyy-MM-dd  hh:mm:ss");

           if (0 != ullRecvTotalBytes)
               bytesReceived += nlen;
        }

        // 接收文件名，并建立文件
        if((m_tcpSocket->bytesAvailable() >= qint64(fileNameSize)) &&
            (qint64(fileNameSize) != 0) && (0 != ullRecvTotalBytes)){

           in >> fileReadName;
           bytesReceived += fileNameSize;

           //如果用户是私发文件，则文件保存在服务器该用户个人目录下，
           //如果用户为群发文件，则保存在 GroupDir/UserDir/ 下
           QString strFilePath;
           if(tag == 0){
               strFilePath = MyApp::m_strRecvPath + "User/" + QString::number(m_UserId) + "/";
               MyApp::createDir(strFilePath);
               qDebug()<<"creat success";
           }else if(tag == 1){
               strFilePath = MyApp::m_strRecvPath + "Group/" + QString::number(m_WindowId) + "/";
               MyApp::createDir(strFilePath);
               strFilePath += QString::number(m_UserId) + "/";
               MyApp::createDir(strFilePath);
           }

           filesavepath = strFilePath;
           fileToRecv->setFileName(strFilePath+fileReadName);

//           bool bOk = fileToRecv->copy(fileReadName, strFilePath+fileReadName);
//           qDebug()<<bOk;
//           QMessageBox::information(this,"copy", bOk ? tr("数据copy成功") : tr("数据copy失败"));

           qDebug() << "file save path is" << strFilePath;


           if (!fileToRecv->open(QFile::WriteOnly | QIODevice::Truncate)){
               qDebug() << "open file error" << fileReadName;
               return;
           }
           qDebug() << "begin to receive file" << fileReadName << "...";
        }
    }

    //如果接收的数据小于总数据，那么写入文件
    if (bytesReceived < ullRecvTotalBytes){
        bytesReceived += quint64(m_tcpSocket->bytesAvailable());
        inBlock = m_tcpSocket->readAll();

        if (fileToRecv->isOpen()){
           fileToRecv->write(inBlock);
           qDebug()<<"write";
        }
        inBlock.resize(0);
    }

    // 接收数据完成时
    if ((bytesReceived >= ullRecvTotalBytes) && (0 != ullRecvTotalBytes)){
        fileToRecv->close();
        bytesReceived = 0; // clear for next receive
        ullRecvTotalBytes = 0;
        fileNameSize = 0;
        qDebug() << "file received success!" ;

        qDebug() << "recv ok" << fileToRecv->fileName();
        //向数据库插入一条记录
        insertDataBase(filesavepath,fileReadName);

        // 数据接受完成
        fileTransFinished();
    }
}

void ClientFileSocket::sltUpdateClientProgress(qint64 numBytes)
{
    // 已经发送数据的大小
    bytesWritten += quint64(numBytes);

    // 如果已经发送了数据
    if (bytesToWrite > 0){
        // 每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
        outBlock = fileToSend->read(qint64(qMin(bytesToWrite, loadSize)));

        // 发送完一次数据后还剩余数据的大小
        bytesToWrite -= quint64(m_tcpSocket->write(outBlock));

        // 清空发送缓冲区
        outBlock.resize(0);
    } else {
        // 如果没有发送任何数据，则关闭文件
        if (fileToSend->isOpen())
           fileToSend->close();
    }

    // 发送完毕
    if (bytesWritten >= ullSendTotalBytes) {
        if (fileToSend->isOpen())
           fileToSend->close();

        bytesWritten = 0;  // clear fot next send
        ullSendTotalBytes = 0;
        bytesToWrite = 0;
        qDebug() << "send ok" << fileToSend->fileName();
        fileTransFinished();
    }
}


