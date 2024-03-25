#include "addfriendwnd.h"
#include "ui_addfriendwnd.h"
#include<QMessageBox>
#include <QSqlQuery>
#include"sql_manage.h"
#include<myapp.h>
#include"type.h"

addFriendWnd::addFriendWnd(Cell *cell) :
    ui(new Ui::addFriendWnd)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(85, 85, 85);");
    ui->widget_2->setStyleSheet("background-color: rgba(255, 255, 255, 124);border-radius:10px;");
//    ui->msgLabel->setStyleSheet("border-image: url(:/添加好友.svg);");
//    ui->msgLabel->setFixedSize(50,50);
    setWindowFlags(Qt::WindowCloseButtonHint);
    this->cell = cell;
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/backgroud3.jpg").
                                              scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));// 使用平滑的缩放方式
    this->setPalette(palette);// 给widget加上背景图
    ui->idLabel->setText("ID:"+QString::number(cell->id));
    ui->userName->setText("Name:"+cell->name);
    ui->idLabel->setFixedWidth(200);
    ui->userName->setFixedWidth(200);
    font = QFont("Microsoft YaHei", 12, 50, false);
    ui->idLabel->setFont(font);
    ui->userName->setFont(font);

    bool tag = cell->done;

    if(tag){
        ui->msgLabel->setText("已处理该请求");
        ui->msgLabel->setFont(font);
        ui->msgLabel->setStyleSheet("color:#0081ef");

    }else{
        ui->msgLabel->setText("未处理的请求");
        ui->msgLabel->setFont(font);
        ui->msgLabel->setStyleSheet("color:#0081ef");
    }


//    ui->head->setPalette();

    if(cell->type == Cell_AddFriend)
    {
        setWindowTitle("申请添加好友");
        ui->timeLabel->setText("申请添加好友");
    }
    else if(cell->type == Cell_AddGroup)
    {

        setWindowTitle("申请加入群：" + QString::number(cell->groupid));
        ui->timeLabel->setText("申请加入群：" + QString::number(cell->groupid));
    }

    ui->agreeBtn->setStyleSheet("QPushButton{border:1px solid #86949e;background-color:#f4f4f4;border-radius:3px}"
                                "QPushButton:hover{background-color:#bee7fd;}"
                                "QPushButton:pressed{background-color:#f4f4f4}");

    ui->rejectBtn->setStyleSheet("QPushButton{border:1px solid #86949e;background-color:#f4f4f4;border-radius:3px}"
                                 "QPushButton:hover{background-color:#bee7fd;}"
                                 "QPushButton:pressed{background-color:#f4f4f4}");
}

addFriendWnd::~addFriendWnd()
{
    delete ui;
}






void addFriendWnd::on_agreeBtn_clicked()
{
    if(cell->type == Cell_AddFriend){
        cell->done = true;

        //更新本地服务器
        QSqlQuery query;
        query.prepare("INSERT INTO MyFriend (id, name, head, subgroup, tag, lastMsg, lastTime) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, cell->id);
        query.bindValue(1, cell->name);
        query.bindValue(2, cell->iconPath);
        query.bindValue(3, "默认分组");
        query.bindValue(4, 0);
        query.bindValue(5, "");
        query.bindValue(6, "");
        query.exec();

        //通知服务器，已同意
        QJsonObject json;
        json.insert("userID1",cell->id);
        json.insert("userID2",MyApp::m_nId);
        json.insert("time",QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss"));
        emit signalAddFriend(AddFriendRequist,json);

        //通知中栏添加与该用户的聊天格子
        Cell *c = new Cell;
        c->type = Cell_FriendChat;
        c->id = cell->id;
        c->name = cell->name;
        c->iconPath = cell->iconPath;
        c->isClicked = false;
        c->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");
        c->msg = "你和" + QString::number(c->id) + "已经成为好友了！";
        c->status = OnLine;
        emit signalAddChat(c);

    }else if(cell->type == Cell_AddGroup){
        cell->done = true;

        //通知服务器，已同意
        QJsonObject json;
        json.insert("groupID",cell->groupid);
        json.insert("userID",cell->id);
        json.insert("time",QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss"));
        emit signalAddFriend(AddGroupRequist,json);

        //延时发送
        QTime dieTime = QTime::currentTime().addMSecs(100);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        //通知中栏添加与该群的聊天格子(如果已存在则只更新格子)
        Cell *c = new Cell;
        c->type = Cell_GroupChat;
        c->id = cell->groupid;//格子的id为群id
        c->name = cell->groupname_;
        c->iconPath = cell->groupHead;
        c->isClicked = false;
        c->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");
        c->msg = "用户" + QString::number(cell->id) + "已经加入该群";
        c->status = OnLine;

        //用于刷新该群的群员列表
        c->newUserID = cell->id;
        c->newUserName = cell->name;
        c->newUserHead = cell->iconPath;

        emit signalAddChat(c);
    }

    ui->agreeBtn->setVisible(false);
    ui->rejectBtn->setVisible(false);

//    ui->noticeLabel = new QLabel("已同意请求",this);
//    ui->noticeLabel->setStyleSheet("color:#0081ef");
//    ui->noticeLabel->setFont(font);
//    ui->noticeLabel->setVisible(true);
//    ui->noticeLabel->setGeometry(150,150,200,30);
}


void addFriendWnd::on_rejectBtn_clicked()
{
    this->close();
}

