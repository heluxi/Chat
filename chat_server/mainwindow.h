#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
#include<QTimer>
#include<tcpServer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readMsg();
    void newConnect();
    void removeSocket();
    void sendfile(QTcpSocket* &sock);
    void sendhead(QTcpSocket* &sock);
    void sendGroupMesg(QJsonValue dataVal);
signals:
    void sendSock(QTcpSocket* &sock);
private:
    Ui::MainWindow *ui;
    QTcpServer *sockSer;//用于监听
    QList<QTcpSocket*> sockLists;//用于通信
    QFile file;
    QString fileName;
    int fileSize;
    bool isFile;
    int recvSize;
    int sendSize;
    QTimer timer;
    QTcpSocket* curScok;
    int fileport;//对方发送文件的端口
    TcpMsgSever* msgServer;
    TcpFileSever *fileServer;

};
#endif // MAINWINDOW_H
