#include "midw.h"
#include "addfriendwnd.h"
#include "cell.h"
#include "contactwidget.h"
#include "findfriendwnd.h"
#include "listwidget.h"
#include "qdebug.h"
#include "qwidget.h"
#include "sql_manage.h"
#include "ui_midw.h"
#include<QSqlQuery>
#include <QJsonArray>
#include <QMessageBox>

midw::midw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::midw)
{
    ui->setupUi(this);

    this->setFixedWidth(345);
    ui->chatList->setFixedWidth(345);
    ui->chatListW->setFixedWidth(345);
    ui->stackedWidget->setFixedWidth(345);

    connect(ui->chatList,&ListWidget::popMenuToShow,
            this,&midw::setPopMenuCell);
    connect(ui->chatList,&ListWidget::signalOpenDialog,
            this,&midw::sltAddFriend);
    connect(ui->chatList,&ListWidget::sonDoubleClicked,[&](Cell* cell){
        qDebug() << "打开聊天对话框：" << cell->name;
        selectedCell = cell;
        emit openDialog(cell);
    });

    //添加子菜单
    addMenu = new QMenu(this);
    addMenu->addAction(tr("添加好友"));
    addMenu->addAction(tr("添加群"));
    addMenu->addSeparator();
    addMenu->addAction(tr("创建群"));
    connect(addMenu,&QMenu::triggered,this,&midw::sltMenuSelected);


    connect(ui->btn_add,&MyButton::clicked,[&](){
        addMenu->exec(QCursor::pos());
    });


    contactWidget = new ContactWidget;

    ui->stackedWidget->addWidget(contactWidget);
    ui->stackedWidget->setCurrentIndex(0);//默认打开chatList列表


    connect(contactWidget,&ContactWidget::signalSendMessage,
            this,&midw::signalSendMessage);
    connect(contactWidget,&ContactWidget::openDialog,this,&midw::sltOpenDialog);
    connect(contactWidget,&ContactWidget::deleteChat,this,&midw::deleteChatCell);

    newGroup = new CreateGroupWnd;
    connect(newGroup,SIGNAL(signalCreateGroup(const QJsonValue &)),
            this,SLOT(sltCreateGroup(const QJsonValue &)));

    newGroup->hide();
//    connect(this,&midw::createGroupSucess,newGroup,[=](int groupid){

//        newGroup->close();
//        QMessageBox::information(this,"Sucess","创建群聊成功！");
//                                                      });

}

midw::~midw()
{
    qDebug()<<"midw析构函数的调用";
    QString sqlQuery = "update myFriend set tag = 0;";
    QString sqlQuery2 = "update myGroup set tag = 0;";
    QSqlQuery query;
    query.exec(sqlQuery);
    query.exec(sqlQuery2);

    QList<Cell*> cells = ui->chatList->getAllCells();
    int cnt = cells.size();
    for(int i = 0;i < cnt;i++){
        if(cells.at(i)->type == Cell_FriendChat){
            QString sqlQuery = "update myFriend set tag = 1, lastMsg = '";
            sqlQuery.append(cells.at(i)->msg + "', lastTime = '");
            sqlQuery.append(cells.at(i)->subTitle + "'");
            sqlQuery.append(" where id=");
            sqlQuery.append(QString::number(cells.at(i)->id));

            query.exec(sqlQuery);
            //qDebug() << "sql error:" << query.lastError().text();
        }else if(cells.at(i)->type == Cell_GroupChat){
            QString sqlQuery = "update myGroup set tag = 1, lastMsg = '";
            sqlQuery.append(cells.at(i)->msg + "', lastTime = '");
            sqlQuery.append(cells.at(i)->subTitle + "'");
            sqlQuery.append(" where id=");
            sqlQuery.append(QString::number(cells.at(i)->id));

            query.exec(sqlQuery);
            //qDebug() << "sql error:" << query.lastError().text();
        }
    }
    delete ui;
}

void midw::MainPageChanged(int page)
{
    if(page == 0){
        qDebug() << "显示聊天列表";
        int cnt = ui->chatList->getAllCells().size();
        if(cnt == 0){
            qDebug()<<"1111";
            ui->stackedWidget->setCurrentIndex(1);
            qDebug()<<ui->stackedWidget->currentIndex();
            qDebug()<<ui->stackedWidget->currentWidget();
        }else{
            qDebug()<<"0000";
            ui->stackedWidget->setCurrentIndex(0);
            qDebug()<<ui->stackedWidget->currentIndex();
            qDebug()<<ui->stackedWidget->currentWidget();
        }
    }else if(page == 1){
        qDebug() << "显示联系人列表" ;
        ui->stackedWidget->setCurrentIndex(2);
    }else if(page == 2){
        qDebug() << "显示设置界面" ;

    }
}

void midw::InitChatList()
{
    //设置聊天列表中的格子右击菜单
    QMenu *sonMenu = new QMenu(this);
    sonMenu->addAction(tr("会话置顶"));
    sonMenu->addAction(tr("取消置顶"));
    sonMenu->addSeparator();
    sonMenu->addAction(tr("关闭会话"));
    sonMenu->addAction(tr("关闭全部会话"));
    connect(sonMenu,SIGNAL(triggered(QAction*)),
            this,SLOT(onSonMenuSelected(QAction*)));
    ui->chatList->setSonPopMenu(sonMenu);

    //查询本地数据库获取我的好友和群聊
    QJsonArray myChatList = sql_manage::Instance()->getMyChatList();
    int cnt = myChatList.size();
    if(cnt == 0){
        qDebug()<<"cnt==0";
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }

    for(int i = 0;i < cnt;i++){
        QJsonObject json = myChatList.at(i).toObject();
        Cell *c = new Cell;
        c->id = json.value("id").toInt();
        c->name = json.value("name").toString();
        c->iconPath = json.value("head").toString();
        qDebug()<<c->iconPath;
        qDebug()<<json.value("lastMsg").toString();
        c->msg = json.value("lastMsg").toString();
        c->subTitle = json.value("lastTime").toString();
        int tag = json.value("tag").toInt();
        if(tag == 0){
            c->type = Cell_FriendChat;
            c->groupName = json.value("subgroup").toString();
        }else if(tag == 1){
            c->type = Cell_GroupChat;
        }

        ui->chatList->insertCell(c);
    }

    ui->chatList->refreshList();
}

void midw::InitContactList()
{
    contactWidget->InitList();
}

void midw::insertCell(Cell *c)
{
    QList<Cell*> cells = ui->chatList->getAllCells();
    int cnt = cells.size();
    if(c->type == Cell_AddFriend){
        for(int i = 0;i < cnt;i++){
            if(cells.at(i)->id == c->id && (cells.at(i)->type == Cell_AddFriend ||
                                             cells.at(i)->type == Cell_AddGroup)){
                cells.at(i)->done = false;
                return;
            }
        }

        ui->chatList->insertCell(c);
    }else if(c->type == Cell_AddGroup){
        for(int i = 0;i < cnt;i++){
            if(cells.at(i)->id == c->id && cells.at(i)->groupid == c->groupid &&
                (cells.at(i)->type == Cell_AddFriend || cells.at(i)->type == Cell_AddGroup)){
                cells.at(i)->done = false;
                return;
            }
        }

        ui->chatList->insertCell(c);
    }else if(c->type == Cell_FriendChat || c->type == Cell_GroupChat){
        for(int i = 0;i < cnt;i++){
            if(cells.at(i)->id == c->id && (cells.at(i)->type == Cell_FriendChat ||
                                             cells.at(i)->type == Cell_GroupChat)){
                return;
            }
        }

        ui->chatList->insertCell(c);
    }
}

void midw::switchToChatList()
{
    //中栏切换到聊天列表
    ui->stackedWidget->setCurrentIndex(0);
}

void midw::addCellToContact(Cell *c)
{
    contactWidget->addCell(c);
}

Cell *midw::isIDExist(int id)
{
    QList<Cell*> cells = ui->chatList->getAllCells();
    for(int i = 0;i < cells.size();i++){
        if(cells[i]->id == id && (cells[i]->type == Cell_FriendChat ||
                                   cells[i]->type == Cell_GroupChat))
            return cells[i];
    }
    return nullptr;
}

QList<Cell*> midw::getList()
{
    return ui->chatList->getAllCells();
}


void midw::updateTime(int id, qint64 time,QString msg)
{
    qDebug() << id << "聊天窗口收到新消息"
             << "time:" << QDateTime::fromSecsSinceEpoch(time).toString("hh:mm:ss")
             << "msg:" << msg
             << "更新中栏相应的聊天格子..." ;

    ui->chatList->refreshCellTime(id,time,msg);
}

void midw::onSonMenuSelected(QAction *action)
{
    if(!action->text().compare(tr("会话置顶"))){
        qDebug() << "会话置顶";
        ui->chatList->setCellToTop(popMenuCell);
    }else if(!action->text().compare(tr("取消置顶"))){
        qDebug() << "取消置顶";
        ui->chatList->cancelCellOnTop(popMenuCell);
    }else if(!action->text().compare(tr("关闭会话"))){
        qDebug() << "关闭会话";
        if(popMenuCell != nullptr){
            QList<Cell*> cells = ui->chatList->getAllCells();
            int cnt = cells.size();
            if(cnt == 1){
                emit openDialog(nullptr);
            }else{
                for(int i = 0;i < cnt;i++){
                    if(cells.at(i) == popMenuCell){
                        if(i != cnt-1){//不是最后一个格子，关闭该格子后打开下一个
                            if(selectedCell != nullptr){
                                ui->chatList->resetCellState();
                                cells.at(i+1)->isClicked = true;
                                ui->chatList->refreshList();

                                //打开新的聊天对话框
                                if(cells.at(i+1)->type != Cell_AddFriend &&
                                    cells.at(i+1)->type != Cell_AddGroup){
                                    emit openDialog(cells.at(i+1));
                                }else{
                                    emit resetRightPage();
                                }
                            }else{
                                emit resetRightPage();
                            }
                        }else{//是最后一个格子，关闭该格子后打开上一个
                            if(selectedCell != nullptr){
                                ui->chatList->resetCellState();
                                cells.at(i-1)->isClicked = true;
                                ui->chatList->refreshList();

                                //打开新的聊天对话框
                                if(cells.at(i-1)->type != Cell_AddFriend &&
                                    cells.at(i-1)->type != Cell_AddGroup){
                                    emit openDialog(cells.at(i-1));
                                }else{
                                    emit resetRightPage();
                                }
                            }else{
                                emit resetRightPage();
                            }
                        }
                    }
                }
            }

            ui->chatList->removeCell(popMenuCell);

            int cnt2 = ui->chatList->getAllCells().size();
            if(cnt2 == 0){
                ui->stackedWidget->setCurrentIndex(2);
            }
        }
    }else if(!action->text().compare(tr("关闭全部会话"))){
        qDebug() << "关闭全部会话";
        ui->chatList->removeAllCells();
        emit openDialog(nullptr);

        ui->stackedWidget->setCurrentIndex(2);
    }
}

void midw::sltOpenDialog(Cell *c)
{
    ui->stackedWidget->setCurrentIndex(0);//中栏切换到聊天列表
    ui->chatList->resetCellState();

    //注意cell从联系人列表切换到聊天列表时需要转换cell的类型
    Cell *cell = isIDExist(c->id);
    if(cell == nullptr){//证明聊天列表中没有和该用户的聊天记录
        cell = new Cell;
        cell->id = c->id;
        cell->name = c->name;
        cell->iconPath = c->iconPath;
        if(c->type == Cell_FriendContact){
            cell->type = Cell_FriendChat;
        }else if(c->type == Cell_GroupContact){
            cell->type = Cell_GroupChat;
        }
        insertCell(cell);
    }
    cell->isClicked = true;

    ui->chatList->refreshList();

    emit openDialog(cell);
}

void midw::setPopMenuCell(Cell *cell, QMenu *)
{
    qDebug() << "popMenu show on cell:" << cell->id << cell->name;
    popMenuCell = cell;
}

void midw::sltMenuSelected(QAction *action)
{
    qDebug() << action->text();
    if(!action->text().compare(tr("添加好友"))){
        FindFriendWnd *w = new FindFriendWnd(0);

        connect(w,&FindFriendWnd::signalFind,this,
                &midw::sltFind);
        connect(this,&midw::signalFindFriendReply,
                w,&FindFriendWnd::SltfindFrindReply);
        connect(w,&FindFriendWnd::signalSendMessage,
                this,&midw::signalSendMessage);

        w->exec();
    }else if(!action->text().compare(tr("添加群"))){
        FindFriendWnd *w = new FindFriendWnd(1);

        connect(w,&FindFriendWnd::signalFind,this,
                &midw::sltFind);
        connect(this,&midw::signalFindFriendReply,
                w,&FindFriendWnd::SltfindFrindReply);
        connect(w,&FindFriendWnd::signalSendMessage,
                this,&midw::signalSendMessage);

        w->exec();
    }else if(!action->text().compare(tr("创建群"))){
        newGroup->exec();
//        createDlg=new CreateGroupDlg();
//        createDlg->show();


    }
}

void midw::sltFind(const QJsonValue &json)
{
    emit signalSendMessage(FindFriend,json);
}

void midw::sltCreateGroup(const QJsonValue &jsonVal)
{
     emit signalSendMessage(CreateGroup,jsonVal);
}

void midw::sltAddFriend(Cell *cell)
{
    emit resetRightPage();

    addFriendWnd *w = new addFriendWnd(cell);
    connect(w,&addFriendWnd::signalAddFriend,
            this,&midw::signalSendMessage);
    connect(w,&addFriendWnd::signalAddChat,this,&midw::signalAddChat);

    w->exec();
}

void midw::deleteChatCell(int id)
{
    QList<Cell*> cells = ui->chatList->getAllCells();
    int cnt = cells.size();
    for(int i = 0;i < cnt;i++){
        if(cells.at(i)->id == id && (cells.at(i)->type == Cell_FriendChat
                                      || cells.at(i)->type == Cell_GroupChat)){
            //移除中栏中与该联系人的聊天格子
            if(cnt == 1){
                emit openDialog(nullptr);
            }else{
                if(i != cnt-1){//不是最后一个格子，关闭该格子后打开下一个
                    if(selectedCell != nullptr){
                        ui->chatList->resetCellState();
                        cells.at(i+1)->isClicked = true;
                        ui->chatList->refreshList();

                        //打开聊天对话框
                        if(cells.at(i+1)->type != Cell_AddFriend &&
                            cells.at(i+1)->type != Cell_AddGroup){
                            emit openDialog(cells.at(i+1));
                        }else{
                            emit resetRightPage();
                        }

                        //保持在联系人界面
                        emit contactBtnClicked();
                        ui->stackedWidget->setCurrentIndex(1);
                    }else{
                        emit resetRightPage();
                    }
                }else{//是最后一个格子，关闭该格子后打开上一个
                    if(selectedCell != nullptr){
                        ui->chatList->resetCellState();
                        cells.at(i-1)->isClicked = true;
                        ui->chatList->refreshList();

                        //打开聊天对话框
                        if(cells.at(i-1)->type != Cell_AddFriend &&
                            cells.at(i-1)->type != Cell_AddGroup){
                            emit openDialog(cells.at(i-1));
                        }else{
                            emit resetRightPage();
                        }

                        //保持在联系人界面
                        emit contactBtnClicked();
                        ui->stackedWidget->setCurrentIndex(1);
                    }else{
                        emit resetRightPage();
                    }
                }
            }

            ui->chatList->removeCell(cells.at(i));

            return;
        }
    }
}

void midw::sltupdateUserHead(const int &userId, const QString &strHead)
{
    QList<Cell *> friends = ui->chatList->getAllCells();
    foreach (Cell *cell, friends.at(0)->childs) {
        if (cell->id == userId) {
            cell->SetIconPath(strHead);
        }
    }

    //ui->frindListWidget->upload();
    ui->chatList->refreshList();
}








