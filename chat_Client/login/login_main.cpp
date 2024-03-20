#include "login_main.h"
#include "ui_login_main.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include "myapp.h"
#include<QPainter>
#include<QCheckBox>

login_main::login_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_main)
{
    ui->setupUi(this);
    //点击网络设置按钮 向loginw发送旋转窗口信号
    connect(ui->setNetBtn,&QPushButton::clicked,this,&login_main::rotateWindow);



    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    //qDebug() << headPath;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty()){
        //        headPath = ":/loginwnd/defalut_head";
        //headPath=":/login.jpg";
    }
    //登陆背景设置图片
    //QPixmap *pix=new QPixmap(headPath);
    //QSize sz=ui->lb_image->size();
    //ui->lb_image->setPixmap(pix->scaled(sz));

    //记住密码
    connect(ui->cb_remember,&QCheckBox::stateChanged,this,&login_main::savecfg);



    connect(ui->setNetBtn,&QPushButton::clicked,this,&login_main::rotateWindow);
    //换头像
    //connect(ui->le_username,&QLineEdit::textChanged,this,&login_main::changeHead);

    //return -->login
    connect(ui->pwdEdit, &QLineEdit::returnPressed, this, &login_main::on_bin_login_clicked);
    ui->btn_forget->setStyleSheet("text-decoration: underline;");

    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3,0);
    shadow->setColor(QColor("#888888"));
    shadow->setBlurRadius(30);
    ui->lb_image->setGraphicsEffect(shadow);
    ui->lb_image->setText("\n\nHi!\nWelcome!\n\n\n\n");
    ui->lb_image->setStyleSheet("border-image: url(:/sea.jpg);color: rgb(255, 255, 255);font: 67pt 方正魏碑_GBK");
    ui->lb_image->setAlignment(Qt::AlignCenter);

    ui->bin_login->setStyleSheet("  background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994   rgb(91, 156, 200),stop:1 rgba(255,255,255,255));color:white;border:0px groove gray;border-radius:7px;padding:2px 4px;font: 87 16pt Arial Black;");
    ui->btn_register->setStyleSheet("  background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994  rgb(91, 156, 200),stop:1 rgba(255,255,255,255));color:white;border:0px groove gray;border-radius:7px;padding:2px 4px;font: 87 16pt Arial Black;");
    ui->exitBtn->setStyleSheet("  background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994  rgb(91, 156, 200),stop:1 rgba(255,255,255,255));color:white;border:0px groove gray;border-radius:7px;padding:2px 4px;font: 87 16pt Arial Black;border-image: url(:/res/pic/删除2.png);");
    ui->setNetBtn->setStyleSheet("  background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994  rgb(91, 156, 200),stop:1 rgba(255,255,255,255));color:white;border:0px groove gray;border-radius:7px;padding:2px 4px;font: 87 16pt Arial Black;border-image: url(:/网络设置.svg);");
    //读取ini文件
    readcfg();


}

login_main::~login_main()
{
    if(ui->cb_remember->isChecked()){
        savecfg(true);
    }
    delete ui;
}

void login_main::savecfg(bool ischecked)
{
    MyApp::checked=ischecked;
    MyApp::saveConfig();
}

void login_main::readcfg()
{
    if(MyApp::checked){
        ui->accountEdit->setText(QString::number(MyApp::m_nId));
        ui->pwdEdit->setText(MyApp::m_strPassword);
        ui->cb_remember->setCheckState(Qt::CheckState::Checked);

    }

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

