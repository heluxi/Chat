#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

    //启动监听
    bool listen(int port=8888);
    //关闭监听
    void closeListen();
signals:

public slots:
    virtual void sltNewConnection() = 0;    //有新客户端连接
    virtual void sltConnected() = 0;
    virtual void sltDisConnected() = 0;

protected:
    QTcpServer *m_tcpServer;

};

//接收信息的服务器
class TcpMsgServer : public TcpServer
{
    Q_OBJECT
public:
    explicit TcpMsgServer(QObject *parent = nullptr);

private slots:
    void sltNewConnection();
    void sltConnected();
    void sltDisConnected();

private:
    // 客户端管理
//    QVector <ClientSocket*> clients;
    QList<QTcpSocket*> sockLists;//用于通信
};

//接收文件的服务器
class TcpFileServer : public TcpServer {
    Q_OBJECT

public :
    explicit TcpFileServer(QObject *parent = nullptr);

private slots:
    void sltNewConnection();
    void sltConnected();
    void sltDisConnected();
};

#endif // TCPSERVER_H
