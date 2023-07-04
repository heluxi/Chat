#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

//封装用于和客户端通信的套接字

#include <QFile>
#include <QObject>
#include<QTcpSocket>
#include <QTimer>
#include<QJsonValue>

//消息套接字
class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = nullptr,QTcpSocket* tcpSocket=nullptr);

    void closeSocket();

    int getUserID();


signals:
    void signalConnected();
    void signalDisConnected();
//    void sendMessagetoClient(QJsonValue data,int ID);
    void sendMessagetoClient(const quint8 &type, const int &reveicerID, const QJsonValue &dataVal);
    void signalDownloadFile(const QJsonValue &json);
    void successLogin();
    void sendAllMsg(QJsonValue);

public slots:
    // 消息回发
//    void SltSendMessage(const quint8 &type, const QJsonValue &json);
    // 消息回发
    void sendMessage(const quint8 &type, const QJsonValue &jsonVal);

private slots:
    void sltConnected();
    void sltDisconnected();

    // 消息解析和抓转发处理
    void readMsg();

private:

    // 消息回发
//    void sendMessage(const quint8 &type, const QJsonValue &jsonVal);

    void parseFriendMessages(const QByteArray &reply);
    void ParseGroupMessages(const QByteArray &reply);

    void UserLogin(QJsonValue data);
    void parseReister(const QJsonValue &dataVal);
    void ParseUserOnline(const QJsonValue &dataVal);
    void ParseLogout(const QJsonValue &dataVal);
    void ParseUpdateUserHead(const QJsonValue &dataVal);

    void ParseGetMyFriend(const QJsonValue &dataVal);
    void ParseGetMyGroups(const QJsonValue &dataVal);

    void parseFindFriend(const QJsonValue &dataVal);
    void ParseAddFriend(const QJsonValue &dataVal);
    void parseAddFriendReply(const QJsonValue &dataVal);

    void parseAddGroup(const QJsonValue &dataVal);
    void parseAddGroupReply(const QJsonValue &dataVal);
    void parseCreateGroup(const QJsonValue &dataVal);
    void parseGetOfflineMsg(const QJsonValue &dataVal);

private:
    QTcpSocket *m_tcpSocket;
    int m_id;
};

//文件套接字

class ClientFileSocket : public QObject
{
    Q_OBJECT
public:
    explicit  ClientFileSocket(QObject *parent = nullptr,QTcpSocket* sock=nullptr);

    void closeSocket();
    bool CheckUserId(const qint32 fromId,const qint32 toId);

    int getID() const;

    // 文件传输完成
    void fileTransFinished();

    void startTransferFile(QString fileName,int senderID, qint64 time,int flag = 0);
    void insertDataBase(QString filepath,QString filename);

//    void StartTransferFile(QString fileName);
//    void readFileMsg();

//   void handleHeadmsg(QString data);
//   void handleFileMsg(QByteArray dataD);

//   void sendFile();
signals:
   void signalConnected();
   void signalDisConnected();

   void signalRecvFinished(int id, const QJsonValue &json);
//void headmsg(QString data);
//void sendFileToUSer(int recvID);

   void sendMessagetoClient(const quint8 &type, const int &reveicerID, const QJsonValue &dataVal);

   void signalDownloadFile(const QJsonValue &json);

private slots:
   // 文件接收
   void sltReadyRead();
   // 发送
   void sltUpdateClientProgress(qint64 numBytes);

private:
//    QTcpSocket* m_fileSocket;

    /************* Receive file *******************/
    quint64 loadSize;
    quint64 bytesReceived;  //已收到数据的大小
    quint64 fileNameSize;  //文件名的大小信息
    QString fileReadName;   //存放文件名
    QString filesavepath;       //存放文件的保存路径
    QByteArray inBlock;   //数据缓冲区
    quint64 ullRecvTotalBytes;  //数据总大小
    QFile *fileToRecv;  //要接收的文件

    QTcpSocket *m_tcpSocket;

   /************* send file *******************/
    quint16 blockSize;  //存放接收到的信息大小
    QFile *fileToSend;  //要发送的文件
    quint64 ullSendTotalBytes;  //数据总大小
    quint64 bytesWritten;  //已经发送数据大小
    quint64 bytesToWrite;   //剩余数据大小
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据



    bool m_bBusy;

    // 需要转发的用户id(from 即发送文件的用户ID
    qint32 m_UserId;
    // 当前用户的窗口好友的id(to 即需要接收文件的用户ID
    qint32 m_WindowId;
    qint32 tag;//标记聊天双方是私聊还是群聊，tag=0表示私聊，tag=1表示群聊
    qint64 msgSendTime;

//    QFile file;
//    QString fileName;
//    int fileSize;
//    bool isFile;
//    int recvSize;
//    int sendSize;
//    QTimer timer;
//    int recvID;

};

#endif // CLIENTSOCKET_H
