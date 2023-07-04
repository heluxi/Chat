#include "messagedlg.h"
#include "ui_messagedlg.h"

#include <QJsonObject>
#include <QSqlQuery>
#include"myapp.h"
#include"type.h"
#include"sql_manage.h"
#include<QMessageBox>

MessageDlg::MessageDlg(QWidget *parent,int id,QString name) :
    QWidget(parent),id{id},name{name},
    ui(new Ui::MessageDlg)
{
    ui->setupUi(this);
    ui->idLabel->setText(QString::number(this->id));
    ui->userName->setText(this->name);


}

MessageDlg::~MessageDlg()
{
    delete ui;
}

void MessageDlg::setTitle(const QString &newTitle)
{
    title = newTitle;
    ui->timeLabel->setText(newTitle);
}

void MessageDlg::setMsg(const QString &newMsg)
{
    msg = newMsg;
    ui->msgLabel->setText(newMsg);
}

void MessageDlg::on_agreeBtn_clicked()
{
    //更新本地服务器
    qDebug()<<sql_manage::Instance()->UserdbIsOpen();
    QSqlQuery query;
    query.prepare("INSERT INTO MyFriend (id, name, head, subgroup, tag, lastMsg, lastTime) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?);");
    query.bindValue(0, id);
    query.bindValue(1, name);
//    query.bindValue(2, cell->iconPath);
    query.bindValue(3, "默认分组");
    query.bindValue(4, 0);
    query.bindValue(5, "");
    query.bindValue(6, "");
    query.exec();

    //通知服务器，已同意
    QJsonObject json;
    json.insert("userID1",id);//好友ID
    json.insert("userID2",MyApp::m_nId);
    json.insert("time",QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss"));
    emit signalAddFriend(AddFriendRequist,json);

//    //通知中栏添加与该用户的聊天格子
//    Cell *c = new Cell;
//    c->type = Cell_FriendChat;
//    c->id = cell->id;
//    c->name = cell->name;
//    c->iconPath = cell->iconPath;
//    c->isClicked = false;
//    c->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");
//    c->msg = "你和" + QString::number(c->id) + "已经成为好友了！";
//    c->status = OnLine;
//    emit signalAddChat(c);

    QMessageBox::information(nullptr,"sucess","你和" + QString::number(id) + "已经成为好友了！",QMessageBox::Ok);
    this->close();

}

