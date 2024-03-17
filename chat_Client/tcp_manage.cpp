#include "tcp_manage.h"
#include "qtcpsocket.h"
#include "qtmetamacros.h"
#include "sql_manage.h"
#include "type.h"
#include <QDataStream>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include<QMessageBox>
#include"myapp.h"

//发送消息套接字

clientSock::clientSock(QObject *parent)
    : QObject{parent}
{

    tcpSocket = new QTcpSocket(this);

    ID=-1;
    connect(tcpSocket,&QTcpSocket::connected,this,&clientSock::sltConnected);
    connect(tcpSocket,&QTcpSocket::disconnected,this,&clientSock::sltDisconnected);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&clientSock::recvMsg);

}

void clientSock::connectServer(const QString &host, const int &port)
{
    if (tcpSocket->isOpen())
        tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress(host), quint16(port));

}

void  clientSock::sendMsg(const quint8 &type, const QJsonValue &dataVal)
{
//        QString sendmsg=QString("[%1]:%2").arg(name).arg(msg);
//        int len=tcpSocket->write(sendmsg.toUtf8());
//        if(len<0)
//        {
//            qDebug()<<"发送失败！";
//        }
    // 连接服务器
    if (!tcpSocket->isOpen()) {
        tcpSocket->connectToHost(MyApp::m_strHostAddr, quint16(MyApp::m_nMsgPort));
        tcpSocket->waitForConnected(1000);
    }

    // 超时1s后还是连接不上，直接返回
    if (!tcpSocket->isOpen())
        return;

    //创建json对象
    QJsonObject json;
    json.insert("from",ID);
    json.insert("type",type);
    json.insert("data",dataVal);

    //创建json文档
    QJsonDocument document;
    document.setObject(json);
    tcpSocket->write(document.toJson(QJsonDocument::Indented));

    qDebug() << "-> 向服务器发送一条消息，消息内容为：" << json;


}

void clientSock::recvMsg()
{

    QByteArray data=tcpSocket->readAll();
    qDebug()<<"recv msg from server "<<data;
    QJsonParseError jsonError;
    // 转化为 JSON 文档
    QJsonDocument doucment = QJsonDocument::fromJson(data, &jsonError);
    // 解析未发生错误
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
        // JSON 文档为对象
        if (doucment.isObject()) {
            // 转化为对象
            QJsonObject jsonObj = doucment.object();
            qDebug() << "<- 收到服务器发来的消息，消息内容为："  << jsonObj;

            QJsonValue dataVal = jsonObj.value("data");

            int msgType = jsonObj.value("type").toInt();

            // 根据消息类型解析服务器消息
            switch (msgType) {
            case SendMsg://私聊消息
            {
//                emit recvFormServre(dataVal.toString());
                Q_EMIT signalMessage(SendMsg, dataVal);
                qDebug()<<"私聊";
                break;
            }
            case SendFile:
            {
                Q_EMIT signalMessage(SendFile, dataVal);
                qDebug()<<"sendfile";
            }
            break;
            case SendGroupMsg:
            {
                Q_EMIT signalMessage(SendGroupMsg, dataVal);
            }
            case SendPicture:
            {
                Q_EMIT signalMessage(SendPicture, dataVal);
            }
            break;
            case CreateGroup:
            {
                Q_EMIT signalMessage(CreateGroup, dataVal);
            }
            break;
            case MsgReceived:
            {
                Q_EMIT signalMessage(MsgReceived, dataVal);
                qDebug()<<"msgrecived";
            }
            break;
            case Login:
            {
                parseLogin(dataVal);
                break;
            }
            case Register:
            {
                QJsonObject obj;
                obj=dataVal.toObject();
                int id=obj.value("id").toInt();
                QString infor=QString("连接成功！\n 你的ID是：%1").arg(id);
                qDebug()<<infor;
                QMessageBox::information(NULL,"sucess",infor,QMessageBox::Ok);
                emit registerOk(dataVal);
                break;
            }
            case UserOnLine:
            {
                qDebug() << "user is oline" << dataVal;
                Q_EMIT signalMessage(UserOnLine, dataVal);
            }
            break;
            case UserOffLine:
            {
                qDebug() << "user is offline" << dataVal;
                Q_EMIT signalMessage(UserOffLine, dataVal);
            }
            break;
            case Logout:
            {
                tcpSocket->abort();
            }
            break;
            case FindFriend:
                emit signalFindFriendReply(dataVal);
                break;
            case AddFriend:
                emit signalMessage(AddFriend,dataVal);
                break;
            case AddFriendRequist:
                emit signalMessage(AddFriendRequist,dataVal);
                break;
            case AddGroup:
            {
                emit signalMessage(AddGroup, dataVal);
            }
            break;
            case AddGroupRequist:
            {
                emit signalMessage(AddGroupRequist, dataVal);
            }
            break;
            case GetOfflineMsg:
            {
                emit signalGetOfflineMsg(dataVal);
                break;
            }
            default:
                break;
            }
        }
    }
}

QString clientSock::getName()
{
return name;
}

void clientSock::parseLogin(const QJsonValue &dataVal)
{

// data 的 value 是对象
if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        int code = dataObj.value("code").toInt();

        if (0 == code) { //登陆成功
            qDebug()<<"登陆成功";
            MyApp::m_nId = dataObj.value("id").toInt();
            ID=dataObj.value("id").toInt();
            MyApp::m_strUserName = dataObj.value("name").toString();
            MyApp::m_strHeadFile = dataObj.value("head").toString();//服务器发来的头像名
           //            ID = MyApp::m_nId;
//            ID=dataObj.value("id").toInt();
//            MyApp::m_nId=ID;
           emit signalStatus(LoginSuccess);
        } else if (-1 == code) {
            emit signalStatus(LoginPasswdError);
        } else if (-2 == code) {
           emit signalStatus(UserNotExist);
        } else if (-3 == code) {
            emit signalStatus(LoginRepeat);
        }
}
}

void clientSock::setID(int newID)
{
    ID = newID;
}

int clientSock::GetID() const
{
    return  ID;
}

void clientSock::sltDisconnected()
{
    qDebug() << "disconnecetd to server";
    tcpSocket->abort();
    Q_EMIT signalStatus(DisConnectedHost);
}

void clientSock::sltConnected()
{
//        emit connectSucess();
        qDebug() << "connecetd to server";
    Q_EMIT signalStatus(ConnectedHost);

    QMessageBox::information(NULL,"sucess","连接成功！",QMessageBox::Ok);
}

void clientSock::sltSendOnline()
{
    // 上线的时候给当前好友上报下状态
    QJsonArray friendArr = sql_manage::Instance()->getMyFriends();

    // 组织Jsonarror
    sendMsg(UserOnLine, friendArr);
}

void clientSock::sltSendOffline()
{
    QJsonObject json;
    json.insert("id", ID);
    QJsonArray friendArr = sql_manage::Instance()->getMyFriends();
    json.insert("friends", friendArr);

    // 通知我的好友，我下线了
    this->sendMsg(Logout, json);
}



//发送接受文件的套接字
//---------------------------------------------------



clientFileSock::clientFileSock(QObject *parent)
    : QObject{parent}
{

    m_type = Login;

    strFilePath = MyApp::m_strRecvPath;

    initSocket();


}

void clientFileSock::connectToServer(const QString &ip, const int &port, const int &userId)
{
    if (fileSocket->isOpen())
        return;
    ID = userId;
    fileSocket->connectToHost(QHostAddress(ip), quint16(port));
}

void clientFileSock::closeConnection()
{
    // 还原变量
    finishSendFile();
    // 主动断开
    fileSocket->abort();
}


//void clientFileSock::connectServer(const QString &host, const int &port)
//{
//   fileSocket->connectToHost(QHostAddress(host), quint16(port));
//}


void clientFileSock::sendFile(QString fileName,qint64 time, quint8 type)
{
    if (busy)
        return;
    m_type = type;

    // 当有数据发送成功时，我们更新进度条
    connect(fileSocket, &QTcpSocket::bytesWritten,this, &clientFileSock::sltUpdateClientProgress);

    // 如果没有连接服务器，重新连接下
    if (!fileSocket->isOpen()) {
        connectToServer(MyApp::m_strHostAddr, MyApp::m_nFilePort, ID);
    }

    // 要发送的文件
   fileToSend=new QFile(fileName);

   if(!fileToSend->open(QFile::ReadOnly))
   {
        qDebug()<<"open file error!";
        return;
   }
   // 文件总大小
   ullSendTotalBytes=qint64(fileToSend->size());//获取要发送的文件大小

   //文件数据流
   QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
   sendOut.setVersion(QDataStream::Qt_6_4);

   fileSendName=fileName;

   // 当前文件名，不包含路径
   QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);

   // 依次写入总大小信息空间，文件名大小信息空间，文件发送时间戳，文件名
   sendOut << qint64(0) << qint64(0) << qint64(0) << currentFileName;

   // 这里的总大小是文件名大小等信息和实际文件大小的总和
   ullSendTotalBytes += outBlock.size();

   // 返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
   sendOut.device()->seek(0);
   //头部依次写入 发送数据总大小,文件名大小
   sendOut << ullSendTotalBytes << qint64(unsigned(outBlock.size()) - sizeof(qint64)*3)<<time ;

   // 发送完头数据后剩余数据的大小
   bytesToWrite = quint64(ullSendTotalBytes - fileSocket->write(outBlock));

   outBlock.resize(0);
   busy = true;

}

void clientFileSock::recvFile()
{
   QDataStream in(fileSocket);
   in.setVersion(QDataStream::Qt_6_4);

   // 如果接收到的数据小于等于32个字节，那么是刚开始接收数据，我们保存为头文件信息
   if (bytesReceived <= (sizeof(qint64)*5))
   {
        int nlen = sizeof(qint64) * 5;
        // 接收数据总大小信息和文件名大小信息
        if ((fileSocket->bytesAvailable() >= nlen) && (fileNameSize == 0))
        {
            in >> ullRecvTotalBytes >> fileNameSize >> senderID >> RecvFileSendTime >> flag;
            if (0 != ullRecvTotalBytes) bytesReceived += nlen;
        }

        // 接收文件名，并建立文件
        if((fileSocket->bytesAvailable() >= qint64(fileNameSize))&&
            (qint64(fileNameSize) != 0) && (0 != ullRecvTotalBytes)) {

            in >> fileReadName;
            qDebug() << "fileReadName:" << fileReadName;

            if(ID == -2){
                if(flag == -1){
                    fileReadName = MyApp::m_strRecvPath + fileReadName;
                }else{
                    fileReadName = MyApp::m_strHeadPath + fileReadName;
                }
            }else{
                fileReadName = MyApp::m_strRecvPath + fileReadName;
            }

            bytesReceived += fileNameSize;

            fileToRecv->setFileName(fileReadName);

            if (!fileToRecv->open(QFile::WriteOnly | QIODevice::Truncate)){
                qDebug() << "recv file open failed" << fileReadName;
                return;
            }

            qDebug() << "Begin to recv file" << fileReadName << "sent by:"
                     << (senderID == 0 ? QString::number(ID)
                                       : QString::number(senderID) + " in group " + QString::number(ID));
//            myHelper::printLogFile("Begin to recv file" + fileReadName + "sent by:" +
//                                   (senderID == 0 ? QString::number(ID)
//                                                  : QString::number(senderID) + " in group " + QString::number(ID)));

            QFileInfo fileinfo(fileReadName);
            if(fileinfo.suffix().toLower() == "png" || fileinfo.suffix().toLower() == "jpg"){//证明收到的是图片
                //emit signalFileArrived(Picture,winID);//通知聊天窗口在聊天界面插入一个气泡
            }else{

                QJsonObject json;
                json.insert("tag",tag);
                json.insert("type",Files);
                json.insert("from",senderID);
                json.insert("winID",ID);//senderID != 0表示是群聊,需要再把群id写入
                json.insert("time",RecvFileSendTime);

                if(ID != -2)
                    emit signalFileArrived(json);//更新聊天窗口相应气泡框的进度条
            }
        }
   }

   // 如果接收的数据小于总数据，那么写入文件
   if (bytesReceived < ullRecvTotalBytes)
   {
        bytesReceived += fileSocket->bytesAvailable();
        inBlock = fileSocket->readAll();

        if (fileToRecv->isOpen())
            fileToRecv->write(inBlock);

        inBlock.resize(0);
   }

   // 更新进度条
   QFileInfo fileinfo(fileReadName);
   if(fileinfo.suffix().toLower() != "png" && fileinfo.suffix().toLower() != "jpg" && tag != -2){
        //注意收到图片是不需要更新进度条的
        if(ID != -2)
            Q_EMIT signalUpdateProgress(bytesReceived, ullRecvTotalBytes);
   }

   // 接收数据完成时
   if ((bytesReceived >= ullRecvTotalBytes) && (0 != ullRecvTotalBytes))
   {
        fileToRecv->close();
        bytesReceived = 0; // clear for next receive
        ullRecvTotalBytes = 0;
        fileNameSize = 0;

        QFileInfo fileinfo(fileReadName);
        if(fileinfo.suffix().toLower() == "png" || fileinfo.suffix().toLower() == "jpg"){//证明收到的是图片
            if(ID != -2)
                Q_EMIT signalFileRecvOk(Picture, fileToRecv->fileName(), tag == 0?0:int(senderID));
        }else{
            if(ID != -2)
                Q_EMIT signalFileRecvOk(Files, fileToRecv->fileName(), tag == 0?0:int(senderID));
        }
        qDebug() << "File recv success!" << fileToRecv->fileName();

        // 数据接受完成
        finishSendFile();
   }

}

void clientFileSock::sltConnected()
{
   m_type = Login;

   QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
   sendOut.setVersion(QDataStream::Qt_6_4);

   // 给服务器socket上报自己的id和聊天窗口中对方的ID，方便下次查询
   sendOut << qint32(MyApp::m_nId) << qint32(ID) << qint32(tag);

   // 发送完头数据后剩余数据的大小
   fileSocket->write(outBlock);

   // 发送连接上的信号
   Q_EMIT signalConnectd();
}

void clientFileSock::sltDisConnected()
{
   if (fileSocket->isOpen())
        fileSocket->close();
}

void clientFileSock::finishSendFile()
{

   busy=false;

   ullSendTotalBytes   = 0;
   ullRecvTotalBytes   = 0;
   bytesWritten        = 0;
   bytesToWrite        = 0;
   bytesReceived       = 0;

   fileNameSize        = 0;
   qDebug() << "file transfer finished!";
}

void clientFileSock::setUserId(const int &id)
{
   ID=id;
}

void clientFileSock::sltUpdateClientProgress(qint64 numBytes)
{
   // 开始的时候，不记录流程
   if (Login == m_type) {
        m_type = Unknow;
        return;
   }

   // 已经发送数据的大小
   bytesWritten += numBytes;
   if (bytesToWrite > 0) {//如果已经发送了数据
        // 每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
        outBlock = fileToSend->read(qint64((qMin(bytesToWrite, loadSize))));

        // 发送完一次数据后还剩余数据的大小
        bytesToWrite -= quint64(fileSocket->write(outBlock));

        // 清空发送缓冲区
        outBlock.resize(0);
   }else{
        // 如果没有发送任何数据，则关闭文件
        if (fileToSend->isOpen())
        fileToSend->close();
   }

   // 发送进度信息
   if(ID != -2)
        Q_EMIT signalUpdateProgress(bytesWritten, ullSendTotalBytes);

   // 发送完毕
   if (bytesWritten >= ullSendTotalBytes)
   {
        if (fileToSend->isOpen())
        fileToSend->close();

        bytesWritten = 0;
        ullSendTotalBytes = 0;
        bytesToWrite = 0;
        // 文件发送完成，复位相关信息
        if(ID != -2)
        Q_EMIT signalSendFinished(m_type,fileSendName);

        finishSendFile();
   }
}

void clientFileSock::initSocket()
{
   // 将整个大的文件分成很多小的部分进行发送，每部分为50字节
   loadSize            = 50 * 1024;
   ullSendTotalBytes   = 0;
   ullRecvTotalBytes   = 0;
   bytesWritten        = 0;
   bytesToWrite        = 0;
   bytesReceived       = 0;

   ID            = -1;

   fileNameSize        = 0;
   busy = false;

   fileToSend = new QFile(this);
   fileToRecv = new QFile(this);

   fileSocket = new QTcpSocket(this);

   // 当有数据接收成功时，我们更新进度条
   connect(fileSocket, &QTcpSocket::readyRead, this, &clientFileSock::recvFile);
   connect(fileSocket, &QTcpSocket::connected, this,&clientFileSock::sltConnected);
   connect(fileSocket, &QTcpSocket::disconnected, this, &clientFileSock::sltDisConnected);
}
