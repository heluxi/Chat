#include "login_main.h"
#include "ui_login_main.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include "myapp.h"

login_main::login_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_main)
{
    ui->setupUi(this);
    connect(ui->setNetBtn,&QPushButton::clicked,this,&login_main::rotateWindow);



    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    //qDebug() << headPath;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty()){
        //        headPath = ":/loginwnd/defalut_head";
        //headPath=":/login.jpg";
    }
    //设置图片
    QPixmap *pix=new QPixmap(headPath);
    QSize sz=ui->lb_image->size();
    ui->lb_image->setPixmap(pix->scaled(sz));



    connect(ui->setNetBtn,&QPushButton::clicked,this,&login_main::rotateWindow);
    //换头像
    //connect(ui->le_username,&QLineEdit::textChanged,this,&login_main::changeHead);

    //return -->login
    connect(ui->pwdEdit, &QLineEdit::returnPressed, this, &login_main::on_bin_login_clicked);


    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3,0);
    shadow->setColor(QColor("#888888"));
    shadow->setBlurRadius(30);
    ui->lb_image->setGraphicsEffect(shadow);

    //读取ini文件
    readcfg();


}

login_main::~login_main()
{
    if(ui->cb_remember->isChecked()){
        savecfg();
    }
    delete ui;
}

void login_main::savecfg()
{
    QSettings setting("./config.ini",QSettings::IniFormat);

    setting.setValue("password",ui->pwdEdit->text());
    setting.setValue("username",ui->accountEdit->text());
    //    setting.setValue("rememberPAssword",ui->cb_remember->isChecked());
    setting.sync();     //同步设置，将信息存储到ini里面
}

void login_main::readcfg()
{
    //记住密码
    QSettings setting("./config.ini",QSettings::IniFormat); //设置一个用于存储ini文件
    if(MyApp::checked){
        QString username=setting.value("username").toString();
        QString password=setting.value("password").toString();
        //    rememberPassword=setting.value("rememberPassword").toBool();

        ui->accountEdit->setText(username); //如果保存用户名
        ui->pwdEdit->setText(password); //保存密码
    }
    //    if(MyApp::autoLogin){
    ////        ui->cb_remember->changeStatus(true);
    //        ui->bin_login->setEnabled(false);
    //    }
    //    ui->cb_remember->setChecked(rememberPassword);
}

QString login_main::getID()
{
    return ui->accountEdit->text();
}

QString login_main::getPassword()
{
     return  ui->pwdEdit->text();
}

void login_main::on_bin_login_clicked()
{
     QString username=ui->accountEdit->text();
     QString password=ui->pwdEdit->text();
     //    qDebug()<<password;
     if(""==username){
        QMessageBox::information(this,"登录","用户名不能为空");
     }else if(""==password){
        QMessageBox::information(this,"登录","密码不能为空");
     }
     else{
        //发送登陆消息给服务器 由服务器数据库查找用户密码
        //封装消息
        emit loginSignal();
     }
}

void login_main::on_btn_register_clicked()
{
    emit openRegisterWnd();
}

void login_main::on_btn_forget_clicked()
{
     emit openForgetPasswordWnd();
}


void login_main::checkAutoLogin()
{
    if(MyApp::autoLogin){
        qDebug() << "begin to autoLogin...";
        //        myHelper::printLogFile("begin to autoLogin...");

        on_bin_login_clicked();
    }
}

void login_main::changeHead()
{
    hideNotifyMsg();
    QString text = ui->accountEdit->text();
    int cnt = text.size();
    for(int i = 0;i < cnt;i++){
        if(text[i] >= QChar(48) && text[i] <= QChar(57))
            continue;
        else
            return;
    }

    QString headPath = MyApp::m_strHeadPath + QString::number(text.toInt()) + ".png";
    QFileInfo fileInfo(headPath);
    if(fileInfo.exists()){
        MyApp::m_strHeadFile = QString::number(text.toInt()) + ".png";
        //        ui->lb_image->changeHead(headPath);
        //        ui->lb_image->setText(headPath);
        //qDebug() << "update head:" << headPath;
    }else{
        MyApp::m_strHeadFile = "";
        //        headPath = ":/loginwnd/defalut_head";
        headPath=":/login.jpg";

        //        ui->lb_image->changeHead(headPath);
        //        ui->lb_image->setText(headPath);
        //qDebug() << "update head:" << headPath;
    }
    //设置图片
    QPixmap *pix=new QPixmap(headPath);
    QSize sz=ui->lb_image->size();
    ui->lb_image->setPixmap(pix->scaled(sz));

    emit changeLoginingHead();
}

void login_main::on_exitBtn_clicked()
{
    exit(0);
}
