#include "findfriendwnd.h"
#include "sql_manage.h"
#include "ui_findfriendwnd.h"
#include <QFileInfo>
#include <QJsonObject>
#include <QMessageBox>
#include <QSqlQuery>
#include "myapp.h"

FindFriendWnd::FindFriendWnd(int tag) :
    QDialog(),tag(tag),
    ui(new Ui::FindFriendWnd)
{
    ui->setupUi(this);

    if(tag == 0)
        ui->label->setText("找好友");
    else if(tag == 1)
        ui->label->setText("找群");
}

FindFriendWnd::~FindFriendWnd()
{
    delete ui;
}

void FindFriendWnd::on_searchBut_clicked()
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

    ui->resultLabel->setVisible(false);
    ui->idLabel->setVisible(false);
    ui->nameLabel->setVisible(false);
    ui->headLabel->setVisible(false);
    ui->addBtn->setVisible(false);
//    ui->msgLabel->setVisible(false);

    int id = text.toInt();
    QJsonObject json;
    json.insert("tag",tag);
    json.insert("id",id);

    emit signalFind(json);


}


void FindFriendWnd::on_addBtn_clicked()
{
    QJsonObject json;
    json.insert("id",friendID);
    json.insert("sender",MyApp::m_nId);

    if(tag == 0){
        if(friendID == MyApp::m_nId){
            QMessageBox::information(this,"错误","无法添加自己为好友");
        }else{
            bool flag = sql_manage::Instance()->isMyFriend(friendID);
            if(flag){
                QMessageBox::information(this,"错误","您和该用户已经是好友了");
            }else{
//                msgLabel->setVisible(true);
                ui->addBtn->setVisible(false);
                emit signalSendMessage(AddFriend, json);
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


}

void FindFriendWnd::SltfindFrindReply(const QJsonValue &jsonVal)
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


                        QFileInfo fileInfo(MyApp::m_strHeadPath + head);
                        if(!fileInfo.exists()){
                            QJsonObject json;
                            json.insert("tag",-2);
                            json.insert("from",MyApp::m_nId);
                            json.insert("id",-2);
                            json.insert("who",id);

                            emit signalSendMessage(GetPicture, json);
//                            myHelper::Sleep(500);//等待半秒

                            QString headPath = MyApp::m_strHeadPath + QString::number(id) + ".png";
                            QFileInfo fileInfo_(headPath);

                            if(!fileInfo_.exists()){
                                head = "./res/pic/用户.png";//没有收到则显示默认头像
                            }else{
                                head = headPath;
                            }
                        }else{
                            head = MyApp::m_strHeadPath + head;
                        }

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

