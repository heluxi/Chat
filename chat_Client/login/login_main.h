#ifndef LOGIN_MAIN_H
#define LOGIN_MAIN_H

#include <QWidget>
#include <QSettings>
#include <QCloseEvent>
#include<tcp_manage.h>
#include"setnetdialog.h"


namespace Ui {
class login_main;
}

class login_main : public QWidget
{
    Q_OBJECT

public:
    explicit login_main(QWidget *parent = nullptr);
    ~login_main();
    void savecfg(bool ischecked);     //将信息存入配置文件
    void readcfg();     //读取上一次保存的登录信息
    //    void closeEvent(QCloseEvent *event); //重写关闭事件函数
    QString getID();
    QString getPassword();


private slots:
    void on_bin_login_clicked();

    void on_btn_register_clicked();

    void on_btn_forget_clicked();





    void on_exitBtn_clicked();

signals:
    void loginSignal();
    void closeWindow();
    void hideWindow();
    void rotateWindow();

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

    void checkAutoLogin();
    void changeHead();
private:
    Ui::login_main *ui;
    setnetDialog* netdlg;

};

#endif // LOGIN_MAIN_H
