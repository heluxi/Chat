#include "rightw.h"
#include "rightw/chatwindow.h"
#include "rightw/defaultwindow.h"
#include "ui_rightw.h"
#include"myapp.h"
#include<QJsonArray>

rightw::rightw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rightw)
{
    ui->setupUi(this);
    this->setFixedWidth(870);
    defaultPage = new DefaultWindow;
    ui->stackedWidget->addWidget(defaultPage);
    ui->stackedWidget->setCurrentIndex(0);
    this->setContentsMargins(0,0,1,0);
    ui->stackedWidget->setFixedWidth(870);


    loadingMovie = new QMovie(this);
    loadingMovie->setFileName(":/res/Icons/MainWindow/loading2.gif");

    loadingLabel = new QLabel(this);
    loadingLabel->setMovie(loadingMovie);
    loadingLabel->setFixedSize(50,50);
    loadingLabel->setAttribute(Qt::WA_TranslucentBackground,true);
    loadingLabel->setAutoFillBackground(false);
    loadingMovie->start();
    loadingLabel->setVisible(false);

    connect(ui->closeBtn,&QPushButton::clicked,this,&rightw::sltcloseBtnclicked);
    connect(ui->fullBtn,&QPushButton::clicked,this,&rightw::sltfullBtnclicked);
    connect(ui->pushButton,&QPushButton::clicked,this,&rightw::sltOnTopBtnclicked);


}

rightw::~rightw()
{
    delete ui;
}

void rightw::switchPage(Cell *c)
{
    if(c == nullptr){
        resetPage();
        qDebug()<<"return";
        return;
    }

    if(hash.contains(c->id)){
        qDebug()<<"test";
        currentPage = hash[c->id];
        ui->stackedWidget->setCurrentIndex(currentPage);
    }else{
        ChatWindow *newWindow = new ChatWindow(nullptr,c);
        qDebug()<<"222";

        //ChatWindow的消息借用Rightw中转，最后传递给Mainwindow，因为发送消息的tcpsocket在Mainwindow类中
        connect(newWindow,&ChatWindow::signalSendMessage,
                this,&rightw::signalSendMessage);
        connect(newWindow,&ChatWindow::updateMidBarTime,
                this,&rightw::updateMidBarTime);

        if(c->type == Cell_FriendChat)
            newWindow->setTag(0);//标记为私聊窗口
        else if(c->type == Cell_GroupChat){
            newWindow->setTag(1);//标记为群聊窗口
            newWindow->InitGroupList();
        }

        chatWindowList.append(newWindow);
        hash.insert(c->id,cnt);

        ui->stackedWidget->addWidget(newWindow);
        currentPage = cnt;
        ui->stackedWidget->setCurrentIndex(currentPage);
        cnt++;

        this->startLoadingAnimation();
        newWindow->loadMsgFromDatabase();
        this->stopLoadingAnimation();
    }
}

void rightw::resetPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void rightw::restorePage()
{
    ui->stackedWidget->setCurrentIndex(currentPage);
}

void rightw::startLoadingAnimation()
{
    loadingLabel->setVisible(true);
    loadingLabel->setGeometry(this->width()/2 - 25,this->height()/2 - 100,50,50);
}

void rightw::stopLoadingAnimation()
{
    loadingMovie->stop();
    loadingLabel->setVisible(false);
}

void rightw::allowSendMsg(int id)
{
    int cnt = chatWindowList.size();
    for(int i = 0;i < cnt;i++){
        if(id == chatWindowList.at(i)->getID()){
            chatWindowList.at(i)->allowSendMsg();
            return;
        }
    }
}

void rightw::msgconfirmed(QJsonValue dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int reveiverID = json.value("to").toInt();
        qint64 time = json.value("time").toInt();
        for(int i = 0;i < chatWindowList.size();i++){
            if(chatWindowList.at(i)->getID() == reveiverID){//找到了该条消息对应的聊天窗口
                //消除动画
                chatWindowList.at(i)->msgconfirmed(time);
                return;
            }
        }
    }
}

void rightw::msgReceived(Cell *c, QJsonValue dataVal)
{

    for(int i = 0;i < chatWindowList.size();i++){
        if(c->id == chatWindowList.at(i)->getID()){
            chatWindowList.at(i)->msgReceived(dataVal);//聊天窗口添加一条消息
            return;
        }
    }

    //证明没有打开与该用户的聊天框
    ChatWindow *newWindow = new ChatWindow(nullptr,c);

    //ChatWindow的消息借用RightBar中转，最后传递给MainUI，因为发送消息的tcpsocket在MainWindow类中
    connect(newWindow,&ChatWindow::signalSendMessage,
            this,&rightw::signalSendMessage);
    connect(newWindow,&ChatWindow::updateMidBarTime,
            this,&rightw::updateMidBarTime);

    if(c->type == Cell_FriendChat)
        newWindow->setTag(0);
    else if(c->type == Cell_GroupChat){
        newWindow->setTag(1);
        newWindow->InitGroupList();
    }

    chatWindowList.append(newWindow);
    hash.insert(c->id,cnt);
    ui->stackedWidget->addWidget(newWindow);
    ui->stackedWidget->setCurrentIndex(currentPage);
    cnt++;

    this->startLoadingAnimation();
    newWindow->loadMsgFromDatabase();
    this->stopLoadingAnimation();

    qDebug()<<"loadMsgFromDataBase";

    newWindow->msgReceived(dataVal);//聊天窗口添加一条消息
}

void rightw::addNewUserToGroupList(int groupID, Cell *newUser)
{
    int cnt = chatWindowList.size();
    for(int i = 0;i < cnt;i++){
        if(groupID == chatWindowList.at(i)->getID()){
            chatWindowList.at(i)->addCellToGroupList(newUser);
            return;
        }
    }
}

void rightw::refreshGroupList(QJsonValue dataVal)
{
    if (dataVal.isArray()) {
        QJsonArray array = dataVal.toArray();
        int cnt = array.size();
        if(cnt > 0){
            QJsonObject json = array.at(0).toObject();//提取群号
            int groupid = json.value("groupid").toInt();

            for(int i = 0;i < chatWindowList.size();i++){
                if(groupid == chatWindowList.at(i)->getID()){
                    chatWindowList.at(i)->refreshGroupList(dataVal);//刷新聊天窗口的群列表
                    qDebug() << "群聊窗口" << groupid << "正在刷新群员列表" ;
                    return;
                }
            }
        }
    }
}

void rightw::on_pushButton_4_clicked()
{

    //通知主窗口销毁 执行析构函数和一些数据的记录
    emit exitApp();
    exit(0);
}

void rightw::sltcloseBtnclicked()
{
    emit closeWindow();
}

void rightw::sltfullBtnclicked()
{
    emit fullBtnclicked();
}

void rightw::sltOnTopBtnclicked()
{
    qDebug()<<"设置置顶";
    if(isOntop)
    {
        //取消置顶
        isOntop=false;
        setWindowFlags(this->windowFlags() &~Qt::WindowStaysOnTopHint);
    }else{
        //设置置顶
        isOntop=true;
       setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    }

}

void rightw::sltchangeBackgroundColor(QString color)
{

    MyApp::m_backgroundColor=color;
    //保存设置
    MyApp::saveConfig();
}

void rightw::sltchangeleftBuble(QString color)
{
    MyApp::m_leftBubleColor=color;
    MyApp::saveConfig();

}

void rightw::sltchangerightBuble(QString color)
{
    MyApp::m_rightBubleColor=color;
    MyApp::saveConfig();
}




