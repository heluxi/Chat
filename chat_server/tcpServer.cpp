#include "tcpServer.h"

#include<QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QSqlQuery>

#include "clientsocket.h"
#include "database.h"
#include "myapp.h"
#include"type.h"

TcpServer::TcpServer(QObject *parent) :
    QObject(parent)
{
    m_tcpServer = new QTcpServer(this);

    //newconnect
    connect(m_tcpServer,&QTcpServer::newConnection, this, &TcpServer::SltNewConnection);
}

TcpServer::~TcpServer()
{
    if (m_tcpServer->isListening()) m_tcpServer->close();
}



//void TcpMsgServer::newConnect()
//{
//    QTcpSocket * sock=sockServ->nextPendingConnection();
//    tcpSocket* clnSock=new tcpSocket(this,sock);

    //当用户登陆成功
//    connect(clnSock,&tcpSocket::successLogin,this,[=](){
//          clnMsgList.append(clnSock);
//        qDebug()<<"login sucess";
//          //私发消息
//          connect(clnSock,&tcpSocket::sendMessagetoClient,this,[=](QJsonValue dataval,int ID){

//              foreach (tcpSocket* sock, clnMsgList) {
//                  if(sock->getID()==ID)
//                  {
//                      clnSock->sendMessage(SendMsg,dataval);
//                  }
//              }
//          });
//          //发送全部
//          connect(clnSock,&tcpSocket::sendAllMsg,this,&TcpMsgSever::sendToAll);
//    });

//}

//启动监听
bool TcpServer::StartListen(int port)
{
    if (m_tcpServer->isListening()) m_tcpServer->close();
    bool bOk = m_tcpServer->listen(QHostAddress::Any, port);
    return bOk;
}

void TcpServer::CloseListen()
{
    m_tcpServer->close();
}

TcpMsgServer::TcpMsgServer(QObject *parent)
    : TcpServer{parent}
{
    //    sockServ=new QTcpServer(this);
    //    sockServ->listen(QHostAddress::Any,8888);//消息端口
    //    connect(sockServ,&QTcpServer::newConnection,this,&TcpMsgSever::newConnect);


}

TcpMsgServer::~TcpMsgServer()
{
    qDebug() << "tcp server close";
    foreach (ClientSocket *client, m_clients) {
        m_clients.removeOne(client);
        client->closeSocket();
    }
}
//void TcpMsgServer::sendToAll(QJsonValue dataVal)
//{
////    foreach (tcpSocket *sock, clnMsgList) {
////        sock->sendMessage(SendMsg,dataVal);
////    }
//}

// 有新的客户端连接进来
void TcpMsgServer::SltNewConnection()
{
    ClientSocket *client = new ClientSocket(this, m_tcpServer->nextPendingConnection());
    //check
    connect(client, &ClientSocket::signalConnected, this, &TcpMsgServer::SltConnected);
    connect(client, &ClientSocket::signalDisConnected, this, &TcpMsgServer::SltDisConnected);
}

/**
 * @brief TcpMsgServer::SltConnected
 * 通过验证后，才可以加入容器进行管理(online
 */
void TcpMsgServer::SltConnected()
{
    //sender 如果在由信号激活的插槽中调用该函数 返回指向发送信号的对象的指针 否则返回0
    ClientSocket *client = (ClientSocket *)this->sender();
    if (NULL == client) return;

    //send message 发送全部
    connect(client,&ClientSocket::sendMessagetoClient,this,&TcpMsgServer::SltMsgToClient);
    //signal to signal
    connect(client, &ClientSocket::signalDownloadFile, this, &TcpMsgServer::signalDownloadFile);

    //get name from id
    Q_EMIT signalUserStatus(QString("用户 [%1] 上线").arg(Database::Instance()->getUserName(client->getUserID())));
    m_clients.push_back(client);
}

/**
 * @brief TcpMsgServer::SltDisConnected
 * 有客户端下线
 */
void TcpMsgServer::SltDisConnected()
{
    ClientSocket *client = (ClientSocket *)this->sender();
    if (NULL == client) return;

    for (int i = 0; i < m_clients.size(); i++) {
        if (client == m_clients.at(i))
        {
            m_clients.remove(i);
            Q_EMIT signalUserStatus(QString("用户 [%1] 下线").arg(Database::Instance()->getUserName(client->getUserID())));
            return;
        }
    }

    disconnect(client, &ClientSocket::signalConnected, this, &TcpMsgServer::SltConnected);
    disconnect(client, &ClientSocket::signalDisConnected, this, &TcpMsgServer::SltDisConnected);
    disconnect(client, &ClientSocket::sendMessagetoClient,
               this, &TcpMsgServer::SltMsgToClient);
    disconnect(client, &ClientSocket::signalDownloadFile, this, &TcpMsgServer::signalDownloadFile);
}

/**
 * 消息转发控制
 */
void TcpMsgServer::SltMsgToClient(const quint8 &type, const int &receiverID, const QJsonValue &jsonVal)
{
    // 查找要发送过去的id
    for (int i = 0; i < m_clients.size(); i++) {
        if (receiverID == m_clients.at(i)->getUserID())
        {
            m_clients.at(i)->sendMessage(type, jsonVal);
            return;
        }
    }

    //服务器端没有查询到该消息对应的接受者，说明该用户当前不在线，需要先把数据记录在服务器，等到用户上线后再发送
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        int senderID = json.value("id").toInt();
        qint64 time = json.value("time").toInt();
        QString msg = json.value("msg").toString();
        int tag = json.value("tag").toInt();
        int groupID = 0;
        if(tag == 1)
            groupID = json.value("group").toInt();
        qint64 fileSize = json.value("fileSize").toInt();

        QSqlQuery query;
        query.prepare("INSERT INTO UnreadMsg (senderID, receiverID, groupID, type, time, msg, tag, fileSize) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, senderID);
        query.bindValue(1, receiverID);
        query.bindValue(2, tag == 0 ? 0 : groupID);//如果为私聊消息，该字段无效，设为0即可
        query.bindValue(3, type);
        query.bindValue(4, time);
        query.bindValue(5, msg);
        query.bindValue(6, tag);
        query.bindValue(7, fileSize);

        query.exec();
//        qDebug() << "lastError:" << query.lastError().text();
    }
}

void TcpMsgServer::SltTransFileToClient(const int &userId, const QJsonValue &json)
{
    // 查找要发送过去的id
    for (int i = 0; i < m_clients.size(); i++) {
        if (userId == m_clients.at(i)->getUserID())
        {
            m_clients.at(i)->sendMessage(SendFile, json);
            return;
        }
    }
}



//---------------------------------------------

/// 文件中转服务器，客户端先把待转发的文件发送到服务器，服务器接受完成后，通知
/// 其他客户端来下载
TcpFileServer::TcpFileServer(QObject *parent) :
    TcpServer(parent)
{
}

TcpFileServer::~TcpFileServer()
{
    qDebug() << "tcp server close";
    foreach (ClientFileSocket *client, m_clients) {
        m_clients.removeOne(client);
        client->closeSocket();
    }
}

void TcpFileServer::SltNewConnection()
{
    ClientFileSocket *client = new ClientFileSocket(this, m_tcpServer->nextPendingConnection());

    connect(client, &ClientFileSocket::signalConnected, this, &TcpFileServer::SltConnected);
    connect(client, &ClientFileSocket::signalDisConnected, this, &TcpFileServer::SltDisConnected);

    connect(client, &ClientFileSocket::sendMessagetoClient,
            this, &TcpFileServer::signalMsgToClient);

    connect(client, &ClientFileSocket::signalDownloadFile,
            this, &TcpFileServer::SltClientDownloadFile);
}

/**
 * @brief TcpFileServer::SltConnected
 * socket管理
 */
void TcpFileServer::SltConnected()
{
    ClientFileSocket *client = (ClientFileSocket *)this->sender();
    if (NULL == client) return;

    m_clients.push_back(client);
}

/**
 * @brief TcpFileServer::SltDisConnected
 */
void TcpFileServer::SltDisConnected()
{
    ClientFileSocket *client = (ClientFileSocket *)this->sender();
    if (NULL == client) return;

    for (int i = 0; i < m_clients.size(); i++) {
        if (client == m_clients.at(i))
        {
            m_clients.remove(i);
            return;
        }
    }

    disconnect(client, &ClientFileSocket::signalConnected, this, &TcpFileServer::SltConnected);
    disconnect(client, &ClientFileSocket::signalDisConnected, this, &TcpFileServer::SltDisConnected);
}

/**
 * 客户端请求下载文件
 */
void TcpFileServer::SltClientDownloadFile(const QJsonValue &json)
{
//    // 根据ID寻找连接的socket
//    if (json.isObject()) {
//        QJsonObject jsonObj = json.toObject();
//        qint32 nId = jsonObj.value("from").toInt(); //from(me
//        qint32 nWid = jsonObj.value("id").toInt(); //to (friend
//        QString fileName = jsonObj.value("msg").toString();
//        qDebug() << "get file" << jsonObj << m_clients.size();
//        for (int i = 0; i < m_clients.size(); i++) {
//            if (m_clients.at(i)->CheckUserId(nId, nWid))
//            {
//                m_clients.at(i)->startTransferFile(fileName);
//                return;
//            }
//        }
//    }

    // 根据ID寻找连接的socket
    if (json.isObject()) {
        QJsonObject jsonObj = json.toObject();
        int tag = jsonObj.value("tag").toInt();

        qint32 sendID = jsonObj.value("from").toInt();
        qint32 recvID = jsonObj.value("to").toInt();
        qint32 groupID = jsonObj.value("group").toInt();
        qint64 time = jsonObj.value("time").toInt();
        int flag = jsonObj.value("flag").toInt();

        QString filename = Database::Instance()->getSentFile(sendID,recvID,time);

        if(tag != -2){
            qDebug() << recvID << "is getting file: " << filename
                     << (tag == 1 ? "[sent from group" + QString::number(groupID) +
                                        " by user" + QString::number(sendID) + "]"
                                  : "[sent from user" + QString::number(sendID)) + "]";
        }

        int nId = 0;
        int nWid = 0;
        if(tag == 0){
            nId = recvID;
            nWid = sendID;
            if(flag == -1){//用户接收离线消息文件
                nWid = -2;
            }
        }else if(tag == 1){
            nId = recvID;
            nWid = groupID;
            if(flag == -1){//用户接收离线消息文件
                nWid = -2;
            }
        }else if(tag == -2){
            //用户在获取头像
            int requestID = jsonObj.value("from").toInt();
            int targetID = jsonObj.value("who").toInt();

            nId = requestID;
            nWid = -2;
            filename = MyApp::m_strHeadPath + QString::number(targetID) + "/" + QString::number(targetID) + ".png";
            qDebug() << requestID << "is requesting head:" << targetID;
        }

        for (int i = 0; i < m_clients.size(); i++) {
            if (m_clients.at(i)->CheckUserId(nId, nWid)){
                if(tag == 0){
                    m_clients.at(i)->startTransferFile(filename,0,time,flag);//私发时第二个参数无效
                }else if(tag == 1){
                    m_clients.at(i)->startTransferFile(filename,sendID,time,flag);//群发时第二个参数表示发送者
                }else if(tag == -2){
                    m_clients.at(i)->startTransferFile(filename,0,0,0);//群发时第二个参数表示发送者
                }

                return;
            }
        }
    }
}


