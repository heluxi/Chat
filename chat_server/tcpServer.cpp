#include "tcpServer.h"
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonParseError>
TcpMsgSever::TcpMsgSever(QObject *parent)
    : QObject{parent}
{
    sockServ=new QTcpServer(this);
    sockServ->listen(QHostAddress::Any,8888);
    connect(sockServ,&QTcpServer::newConnection,this,&TcpMsgSever::newConnect);


}

void TcpMsgSever::newConnect()
{
    QTcpSocket * sock=sockServ->nextPendingConnection();
    tcpSocket* clnSock=new tcpSocket(this,sock);
    clnMsgList.append(clnSock);
    connect(clnSock,&tcpSocket::sendMessagetoClient,this,[=](QString data,int ID){

        foreach (tcpSocket* sock, clnMsgList) {
            if(sock->getID()==ID)
            {
                clnSock->sendMessage(data);
            }
        }
    });

}


TcpFileSever::TcpFileSever(QObject *parent):QObject{parent}
{
    sockServ=new QTcpServer(this);
    sockServ->listen(QHostAddress::Any,9999);
    connect(sockServ,&QTcpServer::newConnection,this,&TcpFileSever::newConnect);


}

void TcpFileSever::newConnect()
{
    QTcpSocket* sock=sockServ->nextPendingConnection();
    tcpFileSocket* filesock=new tcpFileSocket(this,sock);
    clnFileList.append(filesock);
    connect(filesock,&tcpFileSocket::sendFileToUSer,this,[=](int recvID){
        foreach (tcpFileSocket* fsock, clnFileList) {
            if(fsock->getID()==recvID)
            {
                filesock->sendFile();
            }
        }
    });
}
