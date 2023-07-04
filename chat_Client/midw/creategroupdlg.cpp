#include "creategroupdlg.h"
#include "ui_creategroupdlg.h"
#include"sql_manage.h"

#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlQuery>
#include <cell.h>
#include <myapp.h>

CreateGroupDlg::CreateGroupDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroupDlg)
{
    ui->setupUi(this);
    initial();

}

CreateGroupDlg::~CreateGroupDlg()
{
    delete ui;
}

void CreateGroupDlg::initial()
{
    //查询本地数据库获取我的好友
    QJsonArray myFriends = sql_manage::Instance()->getMyFriends();
    for(int i = 0;i < myFriends.size();i++){
        QJsonObject json = myFriends.at(i).toObject();
        Cell *c = new Cell;
        c->id = json.value("id").toInt();
        c->name = json.value("name").toString();
        c->iconPath = json.value("head").toString();
        c->groupName = json.value("subgroup").toString();
        c->type = Cell_FriendContact;
        c->status = OnLine;

        QFileInfo fileInfo(c->iconPath);
        if(c->iconPath.isEmpty() || !fileInfo.exists()){
            //头像文件不存在，向服务器获取
            //c->iconPath = ":/Icons/MainWindow/default_head_icon.png";
            qDebug() << c->iconPath << "头像文件不存在，正在向服务器获取...";

            QJsonObject json;
            json.insert("tag",-2);
            json.insert("from",MyApp::m_nId);
            json.insert("id",-2);
            json.insert("who",c->id);

//            emit signalSendMessage(GetPicture, json);

            //            myHelper::Sleep(500);//等待500毫秒

            QString headPath = MyApp::m_strHeadPath + QString::number(c->id) + ".png";
            QFileInfo fileInfo_(headPath);
            if(!fileInfo_.exists()){
                c->iconPath = ":/Icons/MainWindow/default_head_icon.png";//没有收到则显示默认头像
            }else{
                c->iconPath = headPath;
                QSqlQuery query;

                //更新本地数据库
                QString strSql = "UPDATE MyFriend SET head='";
                strSql += headPath;
                strSql += QString("' WHERE id=");
                strSql += QString::number(c->id);

                query.exec(strSql);
            }
        }
//        QListWidgetItem l;
//        l.listWidget(c);
//        ui->listWidget->setItemWidget();

    }
}

void CreateGroupDlg::on_pushButton_2_clicked()
{
    this->close();
}

