#ifndef tcp_manage_H
#define tcp_manage_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QFile>
#include<QFileInfo>
#include<QTimer>

class clientSock : public QObject
{
    Q_OBJECT
public:
    explicit clientSock(QObject *parent = nullptr);

   void connectServer(const QString &host, const int &port);
   void sendMsg(QString msg);
   QString recvMsg();
   QString getName();

signals:
void recvFormServre(QString);
void connectSucess();
private:
    static QTcpSocket *tcpSocket;
    QString name="default";


};



//发送接受文件的套接字


class clientFileSock : public QObject
{
    Q_OBJECT
public:
    explicit clientFileSock(QObject *parent = nullptr);

   void connectServer(const QString &host, const int &port);
   void sendFile(QString filePath);
   void recvFile();

signals:
   void sucessRecvfile(QString recvFileName);
void sendFileSucess(QString fileName);
private:
    static QTcpSocket *fileSocket;
    QString fileName;
    int fileSize;
    QFile file;
    int sendSize;
    QTimer  timer;

    QString recvFileName;
    int recvFileSize;
    QFile recvfile;
    bool isfile;
    int recvSize;

};
#endif // tcp_manage_H
