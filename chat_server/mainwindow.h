#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>      //系统托盘
#include <QTreeWidgetItem>
//#include<QTcpServer>
//#include<QTcpSocket>
#include<QFile>
#include<QTimer>
#include<tcpServer.h>
#include <QStandardItemModel>   //保存数据
#include "qtmetamacros.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class TcpMsgServer;
class TcpFileServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    void readMsg();
    void InitNetwork();
//    void newConnect();

    void SetUserIdentity(const int &identity);
    void removeSocket();


//    void sendfile(QTcpSocket* &sock);
//    void sendhead(QTcpSocket* &sock);
//    void sendGroupMesg(QJsonValue dataVal);
signals:
//    void sendSock(QTcpSocket* &sock);
private slots:
    void on_btn_Exit_clicked();

    void on_btn_Login_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void SltTableClicked(const QModelIndex &index);

    void ShowUserStatus(const QString &text);

    // 系统菜单
    void SltTrayIcoClicked(QSystemTrayIcon::ActivationReason reason);
    void SltTrayIconMenuClicked(QAction *action);

    void on_btn_quit_clicked();

    void on_btn_backUp_clicked();

    void on_btn_backUndo_clicked();

    void on_btn_Refresh_clicked();

    void on_btn_Insert_clicked();

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


    TcpMsgServer* msgServer;
    TcpFileServer *fileServer;

    QStandardItemModel *m_model;    //保存数据

    // 系统菜单
    QSystemTrayIcon *systemTrayIcon;

protected:
    int m_nTimerId;

};
#endif // MAINWINDOW_H
