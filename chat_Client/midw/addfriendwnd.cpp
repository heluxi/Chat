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

    this->cell = cell;

    ui->idLabel->setText(QString::number(cell->id));
    ui->userName->setText(cell->name);

    if(cell->type == Cell_AddFriend)
        setWindowTitle("申请添加好友");
    else if(cell->type == Cell_AddGroup)
        setWindowTitle("申请加入群：" + QString::number(cell->groupid));
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

//        myHelper::Sleep(100);

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

