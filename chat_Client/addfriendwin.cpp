#include "addfriendwin.h"
#include "cell.h"
#include "ui_addfriendwin.h"
#include <QFileInfo>
#include<QMessageBox>
#include <QSqlQuery>
#include"sql_manage.h"
#include<myapp.h>
#include"type.h"

AddFriendWin::AddFriendWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddFriendWin)
{
    ui->setupUi(this);
    tag=-1;
}

AddFriendWin::~AddFriendWin()
{
    delete ui;
}

void AddFriendWin::SltfindFrindReply(const QJsonValue & jsonVal)
{
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        qDebug() << "findWnd:" << json;


        int code = json.value("code").toInt();
        if(code == -1)
        {
            if(tag == 0)
                ui->resultLabel->setText("没有查询到该用户");
            else if(tag == 1)
                ui->resultLabel->setText("没有查询到该群");
            ui->resultLabel->show();
        }
        else
        {
            int id = json.value("id").toInt();
            QString name = json.value("name").toString();
            QString head = json.value("head").toString();


//            QFileInfo fileInfo(MyApp::m_strHeadPath + head);
//            if(!fileInfo.exists()){
//                QJsonObject json;
//                json.insert("tag",-2);
//                json.insert("from",MyApp::m_nId);
//                json.insert("id",-2);
//                json.insert("who",id);

//                emit signalSendMessage(GetPicture, json);
//                myHelper::Sleep(500);//等待半秒

//                QString headPath = MyApp::m_strHeadPath + QString::number(id) + ".png";
//                QFileInfo fileInfo_(headPath);

//                if(!fileInfo_.exists()){
//                    head = ":/Icons/MainWindow/default_head_icon.png";//没有收到则显示默认头像
//                }else{
//                    head = headPath;
//                }
//            }else{
//                head = MyApp::m_strHeadPath + head;
//            }

            ui->resultLabel->setText("查询到下列信息");
            ui->resultLabel->setVisible(true);
            ui->idLabel->setText(QString::number(id));
            ui->idLabel->setVisible(true);
            ui->nameLabel->setText(name);
            ui->nameLabel->setVisible(true);
            qDebug() << "head path:" << head;
            ui->headLabel->setPixmap(head);
            ui->headLabel->setVisible(true);
            if(tag == 0)
                ui->addBtn->setText("添加好友");
            else if(tag == 1)
                ui->addBtn->setText("加入该群");
            ui->addBtn->setVisible(true);

            friendID = id;
        }
    }
}

void AddFriendWin::on_searchBut_clicked()//搜索要添加的好友ID
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty()) {
        QMessageBox::information(this, "错误", "用户id不能为空");
        return;
    }

    int cnt = text.size();
    for (int i = 0; i < cnt; i++) {
        if (text[i] >= QChar(48) && text[i] <= QChar(57)) {
            continue;
        } else {
            QMessageBox::information(this, "错误", "用户id包含非法字符");
            return;
        }
    }
    int id = text.toInt();
    tag=0;//0 添加好友
    QJsonObject json;
    json.insert("tag",tag);
    json.insert("id",id);

    emit signalFind(json);
}


void AddFriendWin::on_addBtn_clicked()
{
    QJsonObject json;
    json.insert("id",friendID);
    json.insert("sender",MyApp::m_nId);

    if(tag == 0){
        if(friendID == MyApp::m_nId){
            QMessageBox::information(this,"错误","无法添加自己为好友");
        }else{
            bool flag =sql_manage::Instance()->isMyFriend(friendID);
            if(flag){
                QMessageBox::information(this,"错误","您和该用户已经是好友了");
            }else{
//                msgLabel->setVisible(true);
                ui->addBtn->setVisible(false);
                emit signalSendMessage(AddFriend, json);
                qDebug()<<"发送添加好友请求";
            }
        }
    }else if(tag == 1){
        bool flag = sql_manage::Instance()->isInGroup(friendID);
        if(flag){
            QMessageBox::information(this,"错误","您已经加入该群了");
        }else{
//            msgLabel->setVisible(true);
            ui->addBtn->setVisible(false);
            emit signalSendMessage(AddGroup, json);
        }
    }
    this->close();

    if(sender() == ui->addBtn){
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

//            myHelper::Sleep(100);

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

        ui->addBtn->setVisible(false);
//        rejectBtn->setVisible(false);

//        noticeLabel = new QLabel("已同意请求",this);
//        noticeLabel->setStyleSheet("color:#0081ef");
//        noticeLabel->setFont(font);
//        noticeLabel->setVisible(true);
//        noticeLabel->setGeometry(150,150,200,30);
    }else{
        this->close();
    }
}

