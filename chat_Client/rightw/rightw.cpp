#include "rightw.h"
#include "rightw/chatwindow.h"
#include "rightw/defaultwindow.h"
#include "ui_rightw.h"

rightw::rightw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rightw)
{
    ui->setupUi(this);

    defaultPage = new DefaultWindow;
    ui->stackedWidget->addWidget(defaultPage);
    ui->stackedWidget->setCurrentIndex(0);

    loadingMovie = new QMovie(this);
    loadingMovie->setFileName(":/Icons/MainWindow/loading2.gif");

    loadingLabel = new QLabel(this);
    loadingLabel->setMovie(loadingMovie);
    loadingLabel->setFixedSize(50,50);
    loadingLabel->setAttribute(Qt::WA_TranslucentBackground,true);
    loadingLabel->setAutoFillBackground(false);
    loadingMovie->start();
    loadingLabel->setVisible(false);

}

rightw::~rightw()
{
    delete ui;
}

void rightw::switchPage(Cell *c)
{
    if(c == nullptr){
        resetPage();
        return;
    }

    if(hash.contains(c->id)){
        currentPage = hash[c->id];
        ui->stackedWidget->setCurrentIndex(currentPage);
    }else{
        ChatWindow *newWindow = new ChatWindow(nullptr,c);

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

void rightw::on_pushButton_4_clicked()
{
    exit(0);
}

