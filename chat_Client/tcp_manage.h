#ifndef tcp_manage_H
#define tcp_manage_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QFile>
#include<QFileInfo>
#include<QTimer>
#include "qtmetamacros.h"


//发送消息套接字
class clientSock : public QObject
{
    Q_OBJECT
public:
    explicit clientSock(QObject *parent = nullptr);

    void connectServer(const QString &host, const int &port);


    QString getName();
    void parseLogin(const QJsonValue &dataVal);//解析登陆返回信息

    void setID(int newID);
    // 获取当前用户的ID
    int GetID() const;

signals:
    void recvFormServre(QString);
    void signalMessage(const quint8 &type, const QJsonValue &dataVal);
    //    void connectSucess();
    void signalStatus(const quint8 status);
    void registerOk(const QJsonValue &dataVal);
    void findFrindReply(const QJsonValue&);
    void ForgetPwdReply(const QJsonValue &dataVal);
    //    void GetOfflineMsg(const QJsonValue &dataVal);
    void signalFindFriendReply(const QJsonValue &dataVal);
    void signalGetOfflineMsg(const QJsonValue &dataVal);

public slots:
    void sendMsg(const quint8 &type, const QJsonValue &dataVal);
    // 发送上线通知
    void sltSendOnline();
    // 发送下线通知
    void sltSendOffline();
private slots:
    // 与服务器断开链接
    void sltDisconnected();
    // 链接上服务器
    void sltConnected();
    // tcp消息处理
    void  recvMsg();

private:
    QTcpSocket *tcpSocket;
    QString name="default";
    int ID;

};



//发送接受文件的套接字


class clientFileSock : public QObject
{
    Q_OBJECT
public:
    explicit clientFileSock(QObject *parent = nullptr);

    void setTag(int tag){this->tag = tag;}
    bool isBusy(){return this->busy;}

    //   void connectServer(const QString &host, const int &port);
    // 连接到服务器
    void connectToServer(const QString &ip, const int &port, const int &userId);

    // 断开服务器
    void closeConnection();

    // 发送文件大小等信息
    void sendFile(QString filePath,qint64 time,quint8 type);

    // 文件传输完成
    void finishSendFile();

    // 设置当前socket的id
    void setUserId(const int &id);

signals:
    //   void sucessRecvfile(QString recvFileName);
    //   void sendFileSucess(QString fileName);

    void signalSendFinished(quint8,QString);
    void signalFileRecvOk(const quint8 &type, const QString &filePath,int senderID);
    void signalUpdateProgress(qint64 currSize, qint64 total);
    void signalConnectd();

    void signalFileArrived(const QJsonValue&);

private slots:
    // 发送文件数据，更新进度条
    void sltUpdateClientProgress(qint64);

    // 文件接收
    void recvFile();
    // 链接上服务器
    void sltConnected();
    // 与服务器断开链接
    void sltDisConnected();

private:
    // socket 初始化
    void initSocket();

private:
    // 通信类
    QTcpSocket *fileSocket;
    int ID;

    quint64         loadSize;   //每次发送数据的大小

    /************* Receive file *******************/
    qint64          bytesReceived;      //已收到数据的大小
    quint64         fileNameSize;       //文件名的大小信息
    QString         fileReadName;       //存放文件名
    QByteArray      inBlock;            //数据缓冲区
    qint64          ullRecvTotalBytes;  //数据总大小
    QFile           *fileToRecv;        //要发送的文件
    qint64          senderID;           //发送文件者id
    qint64          RecvFileSendTime;   //文件发送时间

    /************* Send file **********************/
    quint16         blockSize;          //存放接收到的信息大小
    QFile           *fileToSend;        //要发送的文件
    qint64          ullSendTotalBytes;  //数据总大小
    qint64          bytesWritten;       //已经发送数据大小
    quint64         bytesToWrite;       //剩余数据大小
    QByteArray      outBlock;           //数据缓冲区，即存放每次要发送的数据
    QString         fileSendName;       //存放发送文件的名字(包括路径)

    // 用户目录
    QString         strFilePath;


    qint64          flag;
    int tag = 0;//tag = 0表示这是私聊窗口的一个filesocket,tag = 1表示这是群聊窗口的一个filesocket
    bool            busy;
    quint8          m_type;

};
#endif // tcp_manage_H
