#ifndef LOGINW_H
#define LOGINW_H

#include "login_main.h"
#include "page_login_logining.h"
#include "tcp_manage.h"

#include <QLabel>
#include <QStackedWidget>


class loginw : public QStackedWidget
{
    Q_OBJECT

public:
    explicit loginw(QWidget *parent = nullptr);
    void showMainUI();

signals:
    void rotateWindow();
    void closeWindow();
    void hideWindow();
    void loginSuccess();
    void openRegisterWnd();
    void openForgetPasswordWnd();

    void signalRegisterOK(const QJsonValue&);
    void signalForgetPwdReply(const QJsonValue &dataVal);

public slots:
    void changePage();
    void showNotifyMsg(QString);
    void hideNotifyMsg();
    void sltTcpStatus(const quint8 &state);
    void slotTimeout();

    void sltFileRecvFinished(quint8,QString,int);
    void checkAutoLogin();

    void sltRegister(const QJsonValue &);
    void sltChangePwd(const QJsonValue &);

    void writeOffLineMsgToDatabase(const QJsonValue &);
    void sltGetOffLineMsg();

private:
    login_main *loginMainPage;
    Page_Login_Logining *loginingPage;
    clientSock *tcpSocket;
    bool connected;
    QTimer *timer;

    clientFileSock *globalFileSocket;

    QLabel *m_notifyMsg;// 提醒信息 显示服务器连接情况

protected:
    void paintEvent(QPaintEvent*);
};

#endif // LOGINW_H
