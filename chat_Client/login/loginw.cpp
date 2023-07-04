#include "loginw.h"
#include "mainwindow.h"
#include "myapp.h"
#include "page_login.h"
#include "qcolor.h"
#include "qmessagebox.h"
#include "tcp_manage.h"
#include "type.h"
#include "rightw/bubble/bubbleinfo.h"
#include "sql_manage.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QPainter>
#include <QTimer>
#include <qdebug.h>

loginw::loginw(QWidget *parent): QStackedWidget(parent)
{
    this->setFixedSize(870,520);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setContentsMargins(0,0,0,0);
//    this->setBackgroundRole(QColor(255,255,255));
    this->setStyleSheet("background-color:rgb(255,255,255);");

    m_notifyMsg= new QLabel(this);
    m_notifyMsg->setFixedSize(430, 20);
    m_notifyMsg->setStyleSheet("background-color:#09a3dc;font-size: 12px;font-family:Microsoft YaHei;border-radius:10px");
    m_notifyMsg->hide();


    //初始化TcpSocket
    tcpSocket = new clientSock();
    tcpSocket->connectServer(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
    connected = false;

    connect(tcpSocket, &clientSock::signalStatus, this, &loginw::sltTcpStatus);
    connect(tcpSocket, &clientSock::registerOk,
            this, &loginw::signalRegisterOK);
    connect(tcpSocket, &clientSock::ForgetPwdReply,
            this, &loginw::signalForgetPwdReply);
    //main
    connect(tcpSocket, &clientSock::signalGetOfflineMsg,
            this,&loginw::writeOffLineMsgToDatabase);

    timer = new QTimer();
    timer->setInterval(1000);//每隔1秒尝试重新连接服务器
    connect(timer,&QTimer::timeout,this,&loginw::slotTimeout);


    loginMainPage = new Page_login;
    connect(loginMainPage,&Page_login::loginSignal,this,&loginw::changePage);
    connect(loginMainPage,&Page_login::showNotifyMsg,this,&loginw::showNotifyMsg);
    connect(loginMainPage,&Page_login::hideNotifyMsg,this,&loginw::hideNotifyMsg);
    connect(loginMainPage,&Page_login::closeWindow,this,&loginw::closeWindow);
    connect(loginMainPage,&Page_login::hideWindow,this,&loginw::hideWindow);
    connect(loginMainPage,&Page_login::rotateWindow,this,&loginw::rotateWindow);
    connect(loginMainPage,&Page_login::openRegisterWnd,this,&loginw::openRegisterWnd);
    connect(loginMainPage,&Page_login::openForgetPasswordWnd,
            this,&loginw::openForgetPasswordWnd);


    loginingPage = new Page_Login_Logining;
    connect(loginingPage,&Page_Login_Logining::cancelSignal,this,&loginw::changePage);
    connect(loginingPage,&Page_Login_Logining::closeWindow,this,&loginw::closeWindow);
    connect(loginingPage,&Page_Login_Logining::animationFinished,this,&loginw::sltGetOffLineMsg);
    connect(this,&loginw::loginSuccess,loginingPage,&Page_Login_Logining::loginSuccess);
    connect(loginMainPage,&Page_login::changeLoginingHead,
            loginingPage,&Page_Login_Logining::updateHead);


    this->addWidget(loginMainPage);
    this->addWidget(loginingPage);
}


void loginw::sltTcpStatus(const quint8 &state)
{
    switch (state) {
    case DisConnectedHost: {
        connected = false;
        showNotifyMsg(tr("服务器已断开"));
        break;
    }

    case ConnectedHost:{
        connected = true;
        timer->stop();
        showNotifyMsg(tr("已连接服务器"));
        break;
    }

    case LoginSuccess:{
        // 登陆验证成功
        disconnect(tcpSocket,&clientSock::signalStatus, this, &loginw::sltTcpStatus);
        hideNotifyMsg();

        // 登录成功后，保存当前用户
        MyApp::m_nId = loginMainPage->getID().toInt();
        MyApp::m_strPassword = loginMainPage->getPassword();
        MyApp::saveConfig();

        //全局收发文件的socket,比如用户获取自己的头像，好友和群的头像等
        globalFileSocket = new clientFileSock();
        globalFileSocket->connectToServer(MyApp::m_strHostAddr,MyApp::m_nFilePort,-2);
        connect(globalFileSocket,&clientFileSock::signalFileRecvOk,
                this,&loginw::sltFileRecvFinished);
        //        myHelper::Sleep(1000);

        //如果头像不存在，则向服务器获取头像
        if (!QFile::exists(MyApp::m_strHeadPath + MyApp::m_strHeadFile) || MyApp::m_strHeadFile.isEmpty()) {

            qDebug() << MyApp::m_strHeadPath + MyApp::m_strHeadFile
                     << "头像文件不存在，正在向服务器获取...";

            QJsonObject json;
            json.insert("tag",-2);
            json.insert("from", MyApp::m_nId);
            json.insert("id", -2);
            json.insert("who", MyApp::m_nId);

            tcpSocket->sendMsg(GetPicture, json);

            //            myHelper::Sleep(500);
        }

        emit loginSuccess();
        break;
    }

    case LoginPasswdError:{
        //QMessageBox::information(this, "错误", "登录失败，密码错误！");
        emit loginingPage->cancelSignal();
        showNotifyMsg(tr("登录失败，密码错误！"));
        break;
    }

    case LoginRepeat:{
        //QMessageBox::information(this, "错误", "登录失败，该账户已登录！");
        emit loginingPage->cancelSignal();
        showNotifyMsg(tr("登录失败，该账户已登录！"));
        break;
    }

    case UserNotExist:{
        //QMessageBox::information(this, "错误", "登录失败，该账户不存在！");
        emit loginingPage->cancelSignal();
        showNotifyMsg(tr("登录失败，该账户不存在！"));
        break;
    }

    case RegisterOk:{
        QMessageBox::information(this,"注册成功", "该账号注册成功！请点击登录！");
        break;
    }

    case RegisterFailed:{
        QMessageBox::information(this, "错误", "该账号已经注册！请点击登录！");
        break;
    }

    default:
        break;
    }
}


void loginw::slotTimeout()
{
    if(!connected)
        tcpSocket->connectServer(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
}

void loginw::sltFileRecvFinished(quint8,QString,int)
{
    qDebug() << "globalFileSocket 接受文件成功";
    //    myHelper::printLogFile("globalFileSocket 接受文件成功");
    MyApp::m_strHeadFile = QString::number(MyApp::m_nId) + ".png";
}


void loginw::checkAutoLogin()
{
    loginMainPage->checkAutoLogin();
}

void loginw::sltRegister(const QJsonValue &json)
{
    //    tcpSocket->sltSendMessage(Register, json);
    tcpSocket->sendMsg(Register,json);
}

void loginw::sltChangePwd(const QJsonValue &json)
{
    //    tcpSocket->sltSendMessage(ChangePasswd,json);
    tcpSocket->sendMsg(ChangePasswd,json);
}

void loginw::writeOffLineMsgToDatabase(const QJsonValue &dataVal)
{
    qDebug() << "recv offline msg success,begin to write offline msg to database,time:"
             << QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss.zzz");

    int cnt = 0;
    if (dataVal.isArray()) {
        QJsonArray array = dataVal.toArray();
        cnt = array.size();
        for(int i = 0; i < cnt;i++){
            QJsonObject json = array.at(i).toObject();
            //qDebug() << "offline msg:" << json;
            int senderID = json.value("senderID").toInt();
            int receiverID = json.value("receiverID").toInt();
            int groupID = json.value("groupID").toInt();
            int type = json.value("type").toInt();
            qint64 time = json.value("time").toInt();
            QString msg = json.value("msg").toString();
            int tag = json.value("tag").toInt();
            qint64 fileSize = json.value("fileSize").toInt();

            BubbleInfo *info = new BubbleInfo;
            info->sender = You;
            info->myID = receiverID;
            info->yourID = senderID;
            info->groupID = groupID;
            info->tag = tag;
            info->msg = msg;
            info->fileSize = fileSize;
            info->downloaded = false;
            info->time = time;

            if(type == SendMsg || type == SendGroupMsg){
                info->msgType = Text;
            }else if(type == SendFile){
                info->msgType = Files;
                qDebug()<<"GetFile";
            }else if(type == SendPicture){
                info->msgType = Picture;
                //需要主动接收图片
                QJsonObject json;
                json.insert("from",info->yourID);
                json.insert("to",info->myID);
                json.insert("group",info->groupID);
                json.insert("time",info->time);
                json.insert("tag",info->tag);
                json.insert("flag",-1);//表示该文件由gloabalFileSocket接收，不是由聊天窗口的fileSocket接收

                tcpSocket->sendMsg(GetFile,json);//向服务器发送消息获取图片文件
                qDebug()<<"GetPicture";
                info->downloaded = true;
                info->msg = MyApp::m_strRecvPath + info->msg;//记录图片地址
            }else{
                //目前不支持其他离线消息的加载
                continue;
            }

            sql_manage::Instance()->addHistoryMsg(info);//把一条离线消息添加到本地历史记录中
        }
    }

    if(cnt == 0){
        qDebug() << "no offline msg available" ;
    }else{
        qDebug() << "write offline msg to database success,begin to show MainUI,time:"
                 << QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss.zzz")
            ;
    }

    showMainUI();
}

void loginw::sltGetOffLineMsg()
{
    //加载离线消息
    QJsonObject json;
    json.insert("id",MyApp::m_nId);
    json.insert("msg","request for loading offline msg");
    qDebug() << "begin to load offline msg from server,time:"
             << QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss.zzz");
    tcpSocket->sendMsg(GetOfflineMsg,json);

    //    myHelper::Sleep(2000);//等待2秒
}

void loginw::paintEvent(QPaintEvent *e)
{
    QBitmap maskBmp(this->size());
    maskBmp.fill();
    QPainter maskBmpPainter(&maskBmp);
    maskBmpPainter.setPen(Qt::NoPen);
    maskBmpPainter.setBrush(Qt::black);
    maskBmpPainter.setRenderHint(QPainter::Antialiasing, true); //抗锯齿
    maskBmpPainter.drawRoundedRect(this->rect(), 10, 1);
    setMask(maskBmp);

    return QStackedWidget::paintEvent(e);
}

void loginw::changePage()
{
    if(sender() == loginingPage){
        setCurrentWidget(loginMainPage);
    } else {
        if(connected){
            //向服务器发送登陆消息，同时登陆界面切换到登录中界面
            QJsonObject json;
            tcpSocket->setID(loginMainPage->getID().toInt());

            json.insert("id",loginMainPage->getID().toInt());
            json.insert("password",loginMainPage->getPassword());
            tcpSocket->sendMsg(Login,json);
            qDebug()<<"change";
            setCurrentWidget(loginingPage);
        }else{
            showNotifyMsg(tr("未连接至服务器，请检查服务器地址是否配置正确，正在尝试重新连接..."));
            QMessageBox::information(this,"connect","未连接至服务器，请检查服务器地址是否配置正确，正在尝试重新连接...");

            timer->start();
        }
    }
}

void loginw::showNotifyMsg(QString msg)
{
    this->setFixedSize(870, 520);
    m_notifyMsg->move(0, 330);
    m_notifyMsg->setText("  " + msg);
    m_notifyMsg->show();
}

void loginw::hideNotifyMsg()
{
    this->setFixedSize(870, 520);
    m_notifyMsg->hide();
}

void loginw::showMainUI()
{
    MainWindow *mainUI = new MainWindow;
    disconnect(globalFileSocket,&clientFileSock::signalFileRecvOk,
               this,&loginw::sltFileRecvFinished);
    mainUI->setMainSocket(tcpSocket,globalFileSocket);

    qDebug() << "login success! close Login Window..."
             << ".........................................................................."
        ;

    qDebug() << "show MainUI..." ;
    mainUI->show();

    emit closeWindow();
}
