#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include<QFileDialog>
#include<QMessageBox>
//#include <QListWidgetItem>

#include "leftbar.h"
#include "midw/midw.h"
//#include "qabstractbutton.h"
#include "rightw/rightw.h"

#include"tcp_manage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setMainSocket(clientSock *socket,clientFileSock *filesocket);
    void initUI();
    //    void dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QNChatMessage::User_Type type);
    //    void dealMessageTime(QString curMsgTime);
protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void signalFind(QJsonObject);
    void updateUserHead(const int &userId, const QString &strHead);
    void updateFriendStatus(const quint8 &nStatus, const QJsonValue &dataVal);
    void update(const QJsonValue &dataVal);

private slots:

    void sltTcpReply(quint8 type, QJsonValue dataVal);
    void sltTcpStatus(quint8);
    void sltAddChat(Cell*);
    void sltCreateGroup();

    void onleftBtnClicked(int page);

    void stayOnTop(bool top);
    void sltMaxMin(bool top);


private:
    // 以下便是每个消息类型的解析
    void ParseUpFriendHead(const QJsonValue &dataVal);

    // 头像图片的获取
    QString GetHeadPixmap(const QString &name) const;
    void DownloadFriendHead(const int &userId, const QString &strHead);

    void parseAddFriendReply(QJsonValue dataVal);
    void parseAddGroupReply(const QJsonValue &dataVal);
    void parseAddGroupRequestConfirmed(const QJsonValue &dataVal);
    void parseAddFriendRequestConfirmed(const QJsonValue &dataVal);

    void parseFriendMessageReply(const QJsonValue &dataVal);
    void parseGroupMessageReply(const QJsonValue &dataVal);
    void parseCreateGroupReply(const QJsonValue &dataVal);
    void parseGetGroupMembersReply(const QJsonValue &dataVal);
    void parseDeleteFriendReply(const QJsonValue &dataVal);

    void parseSendFileReply(const QJsonValue &dataVal);

    void SltUpdateUserHead(const int &userId, const QString &strHead);
    void parseDeleteGroupReply(const QJsonValue &dataVal);

    void sltFileRecvFinished(quint8,QString,int);
    void SltConnectedToServer();
    void SltBeginToSend();
    void UpdateFriendStatus(const quint8 &nStatus, const QJsonValue &dataVal);
    void ParseRefreshFriendsReply(const QJsonValue &dataVal);


    //    void on_btn_min_clicked();

    //    void on_btn_max_clicked();

private:
    //将程序主窗口分为三个部分
    leftBar *leftbar;
    midw *midBar;
    rightw *rightBar;

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    Ui::MainWindow *ui;

    clientSock *m_tcp;
    clientFileSock *m_fileTcp;
    clientFileSock *headupLoadSOcket;
    QFileInfo *fileInfo;
    QString fileName;

};
#endif // MAINWINDOW_H
