#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include<clientsocket.h>

//处理消息的服务器端

class TcpMsgSever : public QObject
{
    Q_OBJECT
public:
    explicit TcpMsgSever(QObject *parent = nullptr);

    void newConnect();

signals:
private:
    QTcpServer* sockServ;
    QList<tcpSocket*> clnMsgList;//与客户端通信的套接字
};


//处理文件的服务器端
class TcpFileSever : public QObject
{
    Q_OBJECT
public:
    explicit TcpFileSever(QObject *parent = nullptr);

    void newConnect();

signals:
private:
    QTcpServer* sockServ;
    QList<tcpFileSocket*> clnFileList;//与客户端通信的套接字
};


#endif // TCPSERVER_H
