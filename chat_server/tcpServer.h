#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include "clientsocket.h"
#include "qtmetamacros.h"


// 服务器管理类
class TcpServer : public QObject {
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    ~TcpServer();

    bool StartListen(int port = 6666);
    void CloseListen();
signals:
    void signalUserStatus(const QString &text);
protected:
    QTcpServer *m_tcpServer;

public slots:

protected slots:
    // 继承虚函数
    virtual void SltNewConnection() = 0;
    virtual void SltConnected() = 0;
    virtual void SltDisConnected() = 0;
};

//处理消息的服务器端
class TcpMsgServer : public TcpServer
{
    Q_OBJECT
public:
    explicit TcpMsgServer(QObject *parent = nullptr);
    ~TcpMsgServer();

    void newConnect();
//    void sendToAll(QJsonValue);
signals:
    void signalDownloadFile(const QJsonValue &json);

private:
//    QTcpServer* sockServ;
//    QList<tcpSocket*> clnMsgList;//与客户端通信的套接字
    // 客户端管理
    QVector < ClientSocket * > m_clients;

public slots:
    void SltTransFileToClient(const int &userId, const QJsonValue &json);

    void SltMsgToClient(const quint8 &type, const int &receiverID, const QJsonValue &jsonVal);

private slots:
    void SltNewConnection();
    void SltConnected();
    void SltDisConnected();

};


//处理文件的服务器端
class TcpFileServer : public TcpServer
{
    Q_OBJECT
public:
    explicit TcpFileServer(QObject *parent = nullptr);
    ~TcpFileServer();
    void newConnect();

signals:
    void signalMsgToClient(const quint8 &, const int &, const QJsonValue &);
    void signalRecvFinished(int id, const QJsonValue &json);
private:
//    QTcpServer* sockServ;
//    QList<tcpFileSocket*> clnFileList;//与客户端通信的套接字
    // 客户端管理
    QVector < ClientFileSocket * > m_clients;



private slots:
    void SltNewConnection();
    void SltConnected();
    void SltDisConnected();
public slots:
    void SltClientDownloadFile(const QJsonValue &json);

};


#endif // TCPSERVER_H
