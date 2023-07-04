#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include <QSettings>
#include <QCloseEvent>
#include<tcp_manage.h>
#include"setnetdialog.h"


namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
    void savecfg();     //将信息存入配置文件
    void readcfg();     //读取上一次保存的登录信息
//    void closeEvent(QCloseEvent *event); //重写关闭事件函数
    QString getID();
    QString getPassword();
    ~Page_login();

private slots:
    void on_bin_login_clicked();

    void on_btn_register_clicked();

    void on_btn_forget_clicked();

//    void on_setNetBut_clicked();

    void on_exitButton_clicked();

signals:
    void loginSignal();
    void closeWindow();
    void hideWindow();
    void rotateWindow();    //xuanzhuan

    void hideNotifyMsg();
    void showNotifyMsg(QString);

    void openRegisterWnd();
    void openForgetPasswordWnd();
    void changeLoginingHead();

    void sendLoginSuccess();
    void sendRegisterSUccess();
    void sendRemeberSuccess();
    void sendSokets(clientSock* sock,clientFileSock *filesock);

public slots:
//    void openRegisterAccountUrl(ClickableLabel*);
//    void openFindPasswordUrl(ClickableLabel*);
//    void autoLoginChecked(bool isChecked);

//    void remeberPassword(bool isChecked);
    void checkAutoLogin();
    void changeHead();
private:
    Ui::Page_login *ui;
    setnetDialog* netdlg;
    clientSock *sock;
    clientFileSock *filesock;
//    stusql *m_ptrstuSql;
//    bool rememberPassword;
};

#endif // PAGE_LOGIN_H
