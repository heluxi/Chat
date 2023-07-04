#include "contactwidget.h"
#include "listwidget.h"
#include "mybutton.h"
#include "qbuttongroup.h"
#include "qmenu.h"
#include "qpushbutton.h"
#include "ui_contactwidget.h"
#include "sql_manage.h"
#include "addsubgroup.h"
#include "myapp.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QDebug>
#include <QButtonGroup>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlQuery>
#include <QMessageBox>

ContactWidget::ContactWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactWidget)
{
    ui->setupUi(this);

//    QStringList tmp;
//    tmp << ":/Icons/MainWindow/friend.png"
//        << ":/Icons/MainWindow/friend2.png"
//        << ":/Icons/MainWindow/friend3.png";
//    ui->btn_friend = new MyButton(nullptr,tmp,QSize(48,48));

//    tmp.clear();

//    tmp << ":/Icons/MainWindow/group.png"
//        << ":/Icons/MainWindow/group2.png"
//        << ":/Icons/MainWindow/group3.png";
//    ui->btn_group = new MyButton(nullptr,tmp,QSize(48,48));

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->btn_friend, 0);
    ui->btn_friend->onBtnClicked();
    btnGroup->addButton(ui->btn_group, 1);
    connect(btnGroup, &QButtonGroup::idClicked, this, &ContactWidget::onSwitchPage);


    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->friendList,&ListWidget::popMenuToShow,
            this,&ContactWidget::setPopMenuCell);

    connect(ui->groupList,&ListWidget::popMenuToShow,
            this,&ContactWidget::setPopMenuCell);

//    this->setContentsMargins(0,0,0,0);
}

ContactWidget::~ContactWidget()
{
    delete ui;
}



void ContactWidget::InitList()
{
    //---------------------好友列表------------------------
    //设置好友列表抽屉右击菜单
    QMenu *dadMenu = new QMenu(this);
    dadMenu->addAction(tr("刷新"));
    dadMenu->addSeparator();
    dadMenu->addAction(tr("添加分组"));
    dadMenu->addAction(tr("删除该组"));
    QMenu *friendSortMenu = new QMenu(tr("排序"));
    dadMenu->addMenu(friendSortMenu);
    friendSortMenu->addAction(tr("按id排序"));
    friendSortMenu->addAction(tr("按名字排序"));

    connect(dadMenu,&QMenu::triggered,
            this,&ContactWidget::onFriendDadMenuSelected);
    ui->friendList->setDadPopMenu(dadMenu);

    //设置好友列表中的好友格子右击菜单
    QMenu *sonMenu = new QMenu(this);
    sonMenu->addAction(tr("发消息"));
    sonMenu->addSeparator();
    sonMenu->addAction(tr("移动至黑名单"));
    sonMenu->addAction(tr("删除联系人"));
    QMenu *sonGroupListMenu = new QMenu(tr("移动联系人至"));
    sonMenu->addMenu(sonGroupListMenu);

    connect(sonMenu,SIGNAL(triggered(QAction*)),
            this,SLOT(onSonMenuSelected(QAction*)));
    ui->friendList->setSonPopMenu(sonMenu);

    //查询本地数据库获取我的好友分组
    QJsonArray mySubgroup = sql_manage::Instance()->getMySubgroup();
    for(int i = 0; i < mySubgroup.size(); i++){
        Cell *c = new Cell;
        QJsonObject json = mySubgroup.at(i).toObject();

        c->type = Cell_FriendDrawer;
        c->groupName = json.value("name").toString();
        c->id = 0;
        c->name = json.value("name").toString();
        c->isOpen = false;
        c->subTitle = QString("(0/0)");
        QList<Cell*> childs;
        c->childs = childs;

        hash.insert(c->groupName,c);//建立名字到cell的映射
        ui->friendList->insertCell(c);

        sonGroupListMenu->addAction(c->groupName);
    }

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

            emit signalSendMessage(GetPicture, json);

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

        hash[c->groupName]->childs.append(c);//添加至相应的抽屉下
    }

    ui->friendList->refreshList();

    connect(ui->friendList,&ListWidget::sonDoubleClicked,
            this,&ContactWidget::onSonDoubleClicked);


    //------------------------群列表------------------------
    //设置群列表抽屉右击菜单
    QMenu *groupDadMenu = new QMenu(this);
    groupDadMenu->addAction(tr("刷新"));
    QMenu *groupSortMenu = new QMenu(tr("排序"));
    groupDadMenu->addMenu(groupSortMenu);
    groupSortMenu->addAction(tr("按id排序"));
    groupSortMenu->addAction(tr("按名字排序"));

    connect(groupDadMenu,SIGNAL(triggered(QAction*)),
            this,SLOT(onGroupDadMenuSelected(QAction*)));
    ui->groupList->setDadPopMenu(groupDadMenu);

    //设置群列表中的群格子右击菜单
    QMenu *groupSonMenu = new QMenu(this);
    groupSonMenu->addAction(tr("发送群消息"));
    groupSonMenu->addAction(tr("退出该群"));
    ui->groupList->setSonPopMenu(groupSonMenu);
    connect(groupSonMenu,SIGNAL(triggered(QAction*)),
            this,SLOT(onSonMenuSelected(QAction*)));

    //添加默认项
    Cell *myGroup = new Cell;
    myGroup->groupName = QString(tr("我的群组"));
    myGroup->isOpen = false;
    myGroup->type = Cell_GroupDrawer;
    myGroup->id = 0;
    myGroup->name = QString(tr("我的群组"));
    myGroup->subTitle = QString("(0/0)");
    ui->groupList->insertCell(myGroup);
    connect(ui->groupList,&ListWidget::sonDoubleClicked,
            this,&ContactWidget::onSonDoubleClicked);

    QList<Cell*> childs;
    myGroup->childs = childs;

    //查询本地数据库获取我的群
    QJsonArray myGroups = sql_manage::Instance()->getMyGroups();
    for(int i = 0;i < myGroups.size();i++){
        QJsonObject json = myGroups.at(i).toObject();
        Cell *c = new Cell;
        c->id = json.value("id").toInt();
        c->name = json.value("name").toString();
        c->groupName = "我的群组";
        c->iconPath = json.value("head").toString();
        c->type = Cell_GroupContact;
        c->status = OnLine;

        QFileInfo fileInfo(c->iconPath);
        if(c->iconPath.isEmpty() || !fileInfo.exists()){
            //头像文件不存在，向服务器获取
            //c->iconPath = ":/Icons/MainWindow/default_head_icon.png";
            QJsonObject json;
            json.insert("tag",-2);
            json.insert("from",MyApp::m_nId);
            json.insert("id",-2);
            json.insert("who",c->id);

            signalSendMessage(GetPicture, json);
//            myHelper::Sleep(500);//等待半秒

            QString headPath = MyApp::m_strHeadPath + QString::number(c->id) + ".png";
            QFileInfo fileInfo_(headPath);
            if(!fileInfo_.exists()){
                c->iconPath = ":/Icons/MainWindow/default_head_icon.png";//没有收到则显示默认头像
            }else{
                c->iconPath = headPath;
                QSqlQuery query;

                //更新本地数据库
                QString strSql = "UPDATE MyGroup SET head='";
                strSql += headPath;
                strSql += QString("' WHERE id=");
                strSql += QString::number(c->id);

                query.exec(strSql);
            }
        }
        myGroup->childs.append(c);
    }
    ui->groupList->refreshList();
}

void ContactWidget::addCell(Cell *c)
{
    if(c->type == Cell_FriendContact){
        ui->friendList->insertCell(c);
        ui->friendList->refreshList();
    }else if(c->type == Cell_GroupContact){
        ui->groupList->insertCell(c);
        ui->groupList->refreshList();
    }
}

void ContactWidget::deleteFriend(int id)
{
    QList<Cell*> drawerList = ui->friendList->getAllCells();
    int cnt = drawerList.size();
    for(int i = 0;i < cnt;i++){
        QList<Cell*> childList = drawerList.at(i)->childs;
        int childSize = childList.size();
        for(int j = 0;j < childSize;j++){
            if(childList.at(j)->id == id){
                ui->friendList->removeCell(childList.at(j));

                //更新本地数据库
                QSqlQuery query;
                QString sql;
                sql = "delete from myFriend where id=";
                sql.append(QString::number(id));
                query.exec(sql);

                return;
            }
        }
    }
}

void ContactWidget::onFriendDadMenuSelected(QAction *action)
{
    if(!action->text().compare(tr("添加分组"))){
        qDebug() << "添加分组";
        AddSubGroup w;
        connect(&w,SIGNAL(updateList(QString)),this,SLOT(sltUpdateFriendList(QString)));

        w.exec();
    }else if(!action->text().compare(tr("刷新"))){
        qDebug() << "刷新";
    }else if(!action->text().compare(tr("删除该组"))){
        qDebug() << "删除该组";
        if(!popMenuCell->name.compare(tr("默认分组"))){
            QMessageBox::information(this,"错误","<默认分组>不可删除!");
        }else if(!popMenuCell->name.compare(tr("黑名单"))){
            QMessageBox::information(this,"错误","<黑名单>不可删除!");
        } else {
            Cell *dad = hash[popMenuCell->groupName];
            int cnt = dad->childs.size();
            for(int i = 0;i < cnt;i++){//把该分组下的好友全部移到默认分组下面
                hash["默认分组"]->childs.append(dad->childs.at(i));

                //注意还要更新本地数据库MyFriend
                QSqlQuery query;
                QString strSql = "UPDATE MyFriend SET subgroup='默认分组'";
                strSql += QString(" WHERE id=");
                strSql += QString::number(dad->childs.at(i)->id);
                query.exec(strSql);
            }

            ui->friendList->removeCell(dad);//界面上移除该分组并刷新列表

            //注意还要更新本地数据库MySubgroup
            QSqlQuery query;
            QString strSql = "delete from MySubgroup where name='";
            strSql += popMenuCell->groupName + "'";
            query.exec(strSql);
        }
    }else if(!action->text().compare(tr("按id排序"))){
        popMenuCell->sortById();
        ui->friendList->refreshList();
    }else if(!action->text().compare(tr("按名字排序"))){
        popMenuCell->sortByName();
        ui->friendList->refreshList();
    }

    if(popMenuCell != nullptr){
        qDebug() << "当前右击的Cell是:" << popMenuCell->id << popMenuCell->name;
    }
}

void ContactWidget::onGroupDadMenuSelected(QAction *action)
{
    qDebug() << action->text();
    if(!action->text().compare(tr("刷新"))){
    }else if(!action->text().compare(tr("按id排序"))){
        popMenuCell->sortById();
        ui->groupList->refreshList();
    }else if(!action->text().compare(tr("按名字排序"))){
        popMenuCell->sortByName();
        ui->groupList->refreshList();
    }

    if(popMenuCell != nullptr){
        qDebug() << "当前右击的Cell是:" << popMenuCell->id << popMenuCell->name;
    }
}

void ContactWidget::onSonMenuSelected(QAction *action)
{
    qDebug() << action->text();
    if(!action->text().compare(tr("发消息"))){
        emit openDialog(popMenuCell);
    }else if(!action->text().compare(tr("移动至黑名单"))){
        ui->friendList->removeCell(popMenuCell);
        popMenuCell->groupName = "黑名单";
        ui->friendList->insertCell(popMenuCell);//移动至黑名单抽屉下面

        //注意还要更新本地数据库MyFriend
        QSqlQuery query;
        QString strSql = "UPDATE MyFriend SET subgroup='黑名单'";
        strSql += QString(" WHERE id=");
        strSql += QString::number(popMenuCell->id);
        query.exec(strSql);

    }else if(!action->text().compare(tr("删除联系人"))){
        //更新本地数据库
        int id = popMenuCell->id;
        QSqlQuery query;
        QString strSql = "delete from MyFriend where id=";
        strSql.append(QString::number(id));
        query.exec(strSql);

        //删除联系人列表中的该格子
        ui->friendList->removeCell(popMenuCell);

        //删除中栏中的格子
        emit deleteChat(id);
//        myHelper::Sleep(500);

        //通知服务器，删除好友
        QJsonObject json;
        json.insert("userID1",MyApp::m_nId);//我的id
        json.insert("userID2",id);//该好友的id
        emit signalSendMessage(DeleteFriend,json);
    }else if(!action->text().compare(tr("发送群消息"))){
        emit openDialog(popMenuCell);
    }else if(!action->text().compare(tr("退出该群"))){
        //更新本地数据库
        int id = popMenuCell->id;
        bool tag = sql_manage::Instance()->isAdmin(MyApp::m_nId,id);
        if(tag){
            QMessageBox::information(this,"错误","您是该群的群主，不允许退出!");
        }{
            QSqlQuery query;
            QString strSql = "delete from MyGroup where id=";
            strSql.append(QString::number(id));
            query.exec(strSql);

            //删除联系人列表中的该格子
            ui->groupList->removeCell(popMenuCell);

            //删除中栏中的格子
            emit deleteChat(id);
//            myHelper::Sleep(500);

            //通知服务器，退出该群
            QJsonObject json;
            json.insert("id",MyApp::m_nId);//我的id
            json.insert("group",id);//该群的id
            emit signalSendMessage(DeleteGroup,json);
        }
    }else{
        //更改联系人分组
        QString subgroup = action->text();
        qDebug() << "移动联系人" << popMenuCell->id << "至:" << subgroup;
        if(subgroup.compare(popMenuCell->groupName)){
            ui->friendList->removeCell(popMenuCell);
            popMenuCell->groupName = subgroup;
            ui->friendList->insertCell(popMenuCell);//移动至黑名单抽屉下面

            //注意还要更新本地数据库MyFriend
            QSqlQuery query;
            QString strSql = "UPDATE MyFriend SET subgroup='" + subgroup + "'";
            strSql += QString(" WHERE id=");
            strSql += QString::number(popMenuCell->id);
            query.exec(strSql);
        }
    }

    if(popMenuCell != nullptr){
        qDebug() << "当前右击的Cell是:" << popMenuCell->id << popMenuCell->name;
    }
}

void ContactWidget::onSonDoubleClicked(Cell *cell)
{
    //打开私聊或者群聊窗口
    if(cell->type == Cell_FriendContact){
        qDebug() << "打开私聊窗口: " << cell->id;
        emit openDialog(cell);
    }else if(cell->type == Cell_GroupContact){
        qDebug() << "打开群聊窗口: " << cell->id;
        emit openDialog(cell);
    }
}

void ContactWidget::setPopMenuCell(Cell *cell, QMenu *)
{
    qDebug() << "popMenu show on cell:" << cell->id << cell->name;
    popMenuCell = cell;
}

void ContactWidget::sltUpdateFriendList(QString name)
{
    Cell *c = new Cell;
    c->type = Cell_FriendDrawer;
    c->groupName = name;
    c->name = name;
    c->isOpen = false;
    c->subTitle = QString("(0/0)");
    QList<Cell*> childs;
    c->childs = childs;

    hash.insert(c->groupName,c);//建立名字到cell的映射
    ui->friendList->insertCell(c);
}

void ContactWidget::onSwitchPage(int page)
{
    if(page == 0){
        //qDebug() << "显示好友列表";
        ui->btn_friend->onBtnClicked();
        ui->btn_group->restoreBtn();
    }else if(page == 1){
        //qDebug() << "显示群列表";
        ui->btn_friend->restoreBtn();
        ui->btn_group->onBtnClicked();
    }

    ui->stackedWidget->setCurrentIndex(page);
}
