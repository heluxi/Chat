#include "page_login.h"
#include "ui_page_login.h"
#include "dlg_regiseter.h"
#include "dlg_forget.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include"type.h"
#include"mainwindow.h"

Page_login::Page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_login)
{
    ui->setupUi(this);
    netdlg=new setnetDialog(this);
    sock=new clientSock();
    filesock=new clientFileSock();

    connect(netdlg,&setnetDialog::sendPortandAdd,this,[=](unsigned int port,QString ip,unsigned int fileport){
        sock->connectServer(ip,port);
        filesock->connectToServer(ip,fileport);
    });

    connect(sock,&clientSock::connectSucess,this,[=](){netdlg->close();});
    connect(sock,&clientSock::signalStatus,this,[=](const quint8 status){
        if(status==LoginSuccess)
        {
            this->hide();
            emit sendLoginSuccess();
            emit sendSokets(sock,filesock);
//            MainWindow *MainW=new MainWindow(this);
//            MainW->setMainSocket(sock,filesock);
//            MainW->show();
        }
        else if(status==LoginPasswdError)
        {
             QMessageBox::warning(NULL,"Error","用户名或密码错误！！！");
        }
        else if(status==LoginRepeat)
        {
              QMessageBox::warning(NULL,"Error","重复登陆！！！");
        }
    });




    QFile file;
    file.setFileName(":/dlg.css");
    file.open(QIODevice::ReadOnly);    //只读,true
    QString strQss=file.readAll();
    setStyleSheet(strQss);

    //设置图片
    QPixmap *pix=new QPixmap(":/login.jpg");
    QSize sz=ui->lb_image->size();
    ui->lb_image->setPixmap(pix->scaled(sz));

    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3,0);
    shadow->setColor(QColor("#888888"));
    shadow->setBlurRadius(30);
    ui->lb_image->setGraphicsEffect(shadow);

    //读取ini文件
    readcfg();

//    setAttribute(Qt::WA_DeleteOnClose);

}

void Page_login::savecfg()
{
    QSettings setting("./config.ini",QSettings::IniFormat);

    setting.setValue("password",ui->le_password->text());
    setting.setValue("username",ui->le_username->text());
//    setting.setValue("rememberPAssword",ui->cb_remember->isChecked());
    setting.sync();     //同步设置，将信息存储到ini里面
}

void Page_login::readcfg()
{
    //记住密码
    QSettings setting("./config.ini",QSettings::IniFormat); //设置一个用于存储ini文件
    QString username=setting.value("username").toString();
    QString password=setting.value("password").toString();
//    rememberPassword=setting.value("rememberPassword").toBool();

    ui->le_username->setText(username); //如果保存用户名
    ui->le_password->setText(password); //保存密码
//    ui->cb_remember->setChecked(rememberPassword);
}

//void Page_login::closeEvent(QCloseEvent *event)
//{
//    if(rememberPassword){
//        savecfg();
//        event->accept();
//    }
//    else{
//        event->ignore();
//    }
//}

Page_login::~Page_login()
{
    if(ui->cb_remember->isChecked()){
        savecfg();
    }
    delete ui;
}

void Page_login::on_bin_login_clicked()
{/*
    auto ptr=stusql::getinstance();
//    获取登录界面的数据
    QString username=ui->le_username->text();
    QString password=ui->le_password->text();
    if(""==username){
        QMessageBox::information(this,"登录","用户名不能为空");
    }else if(""==password){
        QMessageBox::information(this,"登录","密码不能为空");
    }
    else{
        //数据库查找用户名和密码
        bool is_Exit=ptr->user_isExit(username,password);
        if(is_Exit){
             //成功进入主界面
            emit sendLoginSuccess();
            this->hide();
//              this->close();
        }
        else{
            //失败就提示
            QMessageBox::warning(NULL,"Error","用户名或密码错误！！！");
        }
    }*/
    QString username=ui->le_username->text();
    QString password=ui->le_password->text();
    qDebug()<<password;
    if(""==username){
        QMessageBox::information(this,"登录","用户名不能为空");
    }else if(""==password){
        QMessageBox::information(this,"登录","密码不能为空");
    }
    else{
        //发送登陆消息给服务器 由服务器数据库查找用户密码
        //封装消息
        sock->setID(username.toInt());
        QJsonObject JsonObj;
//        JsonObj.insert("name", username);
//        JsonObj.insert("passwd", password);
        JsonObj.insert("id",username.toInt());
        qDebug()<<"id"<<username.toInt();
        JsonObj.insert("password",password);
        sock->sendMsg(Login,JsonObj);

    }



}



void Page_login::on_btn_register_clicked()
{
//    this->hide();
    Dlg_regiseter *reg=new Dlg_regiseter;

    connect(reg,&Dlg_regiseter::userRegister,[=](QString name,QString pwd){

        QJsonObject json;
        json.insert("name",name);
        json.insert("pwd",pwd);
        sock->sendMsg(Register,json);
    });
    connect(sock,&clientSock::registerOk,reg,&Dlg_regiseter::registerok);
    reg->exec();

//    auto ptr=MainWindow::getinstance();
//    ptr->updateUserTable();
}


void Page_login::on_btn_forget_clicked()
{
    Dlg_forget *forget=new Dlg_forget;

    forget->exec();
    emit sendRemeberSuccess();
}


void Page_login::on_setNetBut_clicked()
{

    netdlg->exec();

}

