#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

//封装用于和客户端通信的套接字

#include <QFile>
#include <QObject>
#include<QTcpSocket>
#include <QTimer>


//消息套接字
class tcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit tcpSocket(QObject *parent = nullptr,QTcpSocket* tcpsock=nullptr);
    void readMsg();
    void sendMessage(QString data);
    int getID();
signals:
    void sendMessagetoClient(QString data,int ID);
private:
    QTcpSocket *tcpsock;
    int ID;
};

//文件套接字

class tcpFileSocket : public QObject
{
    Q_OBJECT
public:
    explicit  tcpFileSocket(QObject *parent = nullptr,QTcpSocket* sock=nullptr);

    int getID() const;
    void readFileMsg();
   void handleHeadmsg(QString data);
   void handleFileMsg(QByteArray dataD);
   void sendFile();
signals:
void headmsg(QString data);
void sendFileToUSer(int recvID);
private:
    QTcpSocket* fileSock;
    int ID;
    QFile file;
    QString fileName;
    int fileSize;
    bool isFile;
    int recvSize;
    int sendSize;
    QTimer timer;
    int recvID;

};

#endif // CLIENTSOCKET_H
