#include "mainwindow.h"
#include "leftw.h"
#include "midw.h"
#include "qabstractbutton.h"
#include "qbuttongroup.h"
#include "rightw/rightw.h"
#include "tcp_manage.h"
#include "type.h"
#include "ui_mainwindow.h"
#include<QFileInfo>
#include<QDateTime>
#include <QJsonValue>
#include <QSqlQuery>
#include <QHBoxLayout>
#include"frienddlg.h"
#include"myapp.h"
#include "sql_manage.h"
#include "cell.h"
#include"myHelper.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //resize(1600, 800);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
    fileInfo=nullptr;
    this->setFixedWidth(1320);
    ui->centralwidget->setFixedWidth(1320);
    setWindowIcon(QIcon(":/res/Icons/MainWindow/title.png"));
    leftbar = new leftBar;

    midBar = new midw;

    rightBar = new rightw;

    leftbar->setFixedSize(83,890);
    midBar->setFixedSize(380,890);

    QHBoxLayout *layout = new QHBoxLayout(this);

    layout->addWidget(leftbar);
    layout->addWidget(midBar);
    layout->addWidget(rightBar);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    ui->centralwidget->setLayout(layout);

//    connect(rightBar,SIGNAL(stayOnTop(bool)),this,SLOT(stayOnTop(bool)));
    connect(rightBar,&rightw::updateMidBarTime,
            midBar,&midw::updateTime);
//        connect(leftBar->m_btnGroup, &QButtonGroup::buttonClicked,
//                this, &MainWindow::onleftBtnClicked);
//    connect(leftBar->m_btnGroup, SIGNAL(buttonClicked(int)),
//            this, SLOT(onBtnClicked(int)));
    connect(leftbar->m_btnGroup, &QButtonGroup::idClicked,
            this, &MainWindow::onleftBtnClicked);
    connect(leftbar,&leftBar::changeBackgroundColor,rightBar,&rightw::sltchangeBackgroundColor);
    connect(leftbar,&leftBar::changeleftBuble,rightBar,&rightw::sltchangeleftBuble);
    connect(leftbar,&leftBar::changerightBuble,rightBar,&rightw::sltchangerightBuble);

    connect(midBar,&midw::openDialog,[&](Cell *cell){
        if(cell == nullptr){
            rightBar->resetPage();
            rightBar->setCurrentPage(0);
        }else{
            qDebug() << cell->id << "is opening...";
            rightBar->switchPage(cell); //点击中栏的聊天对话列表，切换右栏中的聊天界面
            onleftBtnClicked(0);
        }
    });

    connect(midBar,&midw::resetRightPage,[&](){
        rightBar->resetPage();
        rightBar->setCurrentPage(0);
    });


    connect(midBar,&midw::contactBtnClicked,[&](){
        onleftBtnClicked(1);
    });

    connect(this,&MainWindow::updateUserHead,midBar,&midw::sltupdateUserHead);
    connect(rightBar,&rightw::closeWindow,this,[=](){
        this->showMinimized();
    });
   // connect(rightBar,&rightw::fullBtnclicked,this,&MainWindow::showMaximized);
    connect(rightBar,&rightw::exitApp,this,[=](){
        delete midBar;
        m_tcp->sltSendOffline();
        this->hide();//延迟一会 方便通知服务器和其他用户我下线了
        myHelper::Sleep(1000);
        exit(0);


    });

    connect(this,&MainWindow::updateFriendStatus,midBar,&midw::UpdateFriendStatus) ;
    connect(this,&MainWindow::update,midBar,&midw::update);

    connect(rightBar,&rightw::stayOnTop,this,&MainWindow::stayOnTop);
    connect(rightBar,&rightw::Maxmin,this,&MainWindow::sltMaxMin);

}

MainWindow::~MainWindow()
{
    delete ui;
#if 0
    delete leftBar;
    delete midBar;
    delete rightBar;
#endif
}

void MainWindow::setMainSocket(clientSock *socket, clientFileSock *filesocket)
{

//        this->m_tcp=m_tcp;
//        this->m_fileTcp=m_fileTcp;
//        qDebug()<<this->m_tcp<<this->m_fileTcp;

    if(socket != nullptr && filesocket != nullptr){
        m_tcp = socket;

        connect(m_tcp, &clientSock::signalMessage,
                this, &MainWindow::sltTcpReply);
        connect(m_tcp, &clientSock::signalStatus,
                this, &MainWindow::sltTcpStatus);

        connect(rightBar, &rightw::signalSendMessage,
                m_tcp, &clientSock::sendMsg);

        connect(midBar,&midw::signalSendMessage,
                m_tcp, &clientSock::sendMsg);
        connect(midBar,&midw::signalAddChat,this,&MainWindow::sltAddChat);
//        connect(midBar,&midw::signalCreateGroup,this,&MainWindow::sltCreateGroup);
        connect(m_tcp,&clientSock::signalFindFriendReply,
                midBar,&midw::signalFindFriendReply);

        m_fileTcp = filesocket;
        connect(m_fileTcp,&clientFileSock::signalFileRecvOk,
                this,&MainWindow::sltFileRecvFinished);


        connect(leftbar,&leftBar::UpdateHeadPic,this,[=](){

            // 构建 Json 对象
            QJsonObject json;
            QFileInfo fileInfo(MyApp::m_strHeadFile);

            json.insert("id",  MyApp::m_nId);
            json.insert("head", fileInfo.fileName());
            json.insert("friends", sql_manage::Instance()->GetMyFriend());

            qDebug() << "upload head" << json;
            qint64 curTime = QDateTime::currentSecsSinceEpoch();//时间戳

            //发送更新的头像到服务器
            filesocket->sendFile(MyApp::m_strHeadPath+MyApp::m_strHeadFile,curTime,SendPicture);
            myHelper::Sleep(500);
            m_tcp->sendMsg(UpdateHeadPic, json);//主要是为了通知其他用户我更新了头像 去下载我的头像
        });

        initUI();
    }
}

void MainWindow::initUI()
{
    //加载左栏的头像 ok
    qDebug()<<"MainWindow initUI";

    midBar->InitContactList();//加载好友列表和群列表
    midBar->InitChatList();//加载中栏的历史聊天记录框
}




void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);


//    ui->textEdit->resize(this->width() - 20, ui->widget->height() - 20);
//    ui->textEdit->move(10, 10);

//    ui->sendBut->move(ui->textEdit->width()+ui->textEdit->x() - ui->sendBut->width() - 10,
//                         ui->textEdit->height()+ui->textEdit->y() - ui->sendBut->height() - 10);


//    for(int i = 0; i < ui->listWidget->count(); i++) {
//        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(ui->listWidget->item(i));
//        QListWidgetItem* item = ui->listWidget->item(i);

//        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
//    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //获得部件当前位置
    this->windowPos=this->pos();
    //获得鼠标位置
    this->mousePos=event->globalPos();
    //移动后部件所在的位置
    this->dPos=mousePos-windowPos;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-this->dPos);
}

//void MainWindow::on_btn_add_clicked()
//{
//    addFriWin.show();
//}

void MainWindow::sltTcpReply(quint8 type, QJsonValue dataVal)
{
    switch (type) {
    case UserOnLine:
    {
        UpdateFriendStatus(OnLine, dataVal);
    }
    break;
    case UserOffLine:
    {
        UpdateFriendStatus(OffLine, dataVal);
    }
    break;
    case GetFriendStatus:
    {
        //sql_manage::Instance()->updateFriendStatus();
    }
    break;
    case UpdateHeadPic:
    {
         //你的好友更新了头像

        ParseUpFriendHead(dataVal);
    }
    break;
    case AddFriend:
    {
        parseAddFriendReply(dataVal);
    }
    break;
    case AddGroup://群主才会收到这条消息请求
    {
        parseAddGroupReply(dataVal);
    }
    break;

    case AddFriendRequist:
    {
        parseAddFriendRequestConfirmed(dataVal);
    }
    break;
    case AddGroupRequist:
    {
        parseAddGroupRequestConfirmed(dataVal);
    }
    break;

    case CreateGroup:
    {
        parseCreateGroupReply(dataVal);
    }
    break;
    case GetMyFriends:
    {
        //ParseGetFriendsReply(dataVal);
    }
    break;
    case GetMyGroups:
    {
        //ParseGetGroupFriendsReply(dataVal);
    }
    break;
    case GetGroupMembers:
    {
        parseGetGroupMembersReply(dataVal);
    }
    break;
    case RefreshFriends:
    {
        ParseRefreshFriendsReply(dataVal);
    }
    break;
    case RefreshGroups:
    {
//        ParseRefreshGroupFriendsReply(dataVal);
    }
    break;
    case SendMsg:
    {
        parseFriendMessageReply(dataVal);//收到私聊消息
    }
    break;
    case SendGroupMsg:
    {
        parseGroupMessageReply(dataVal);//收到群聊消息
    }
    break;
    case SendFile:
    case SendPicture:
    {
        parseSendFileReply(dataVal);//收到服务器文件下载通知
    }
    break;
    case MsgReceived:
    {
        rightBar->msgconfirmed(dataVal);
    }
    break;
    case DeleteFriend:
    {
        parseDeleteFriendReply(dataVal);
    }
    break;
    case DeleteGroup:
    {
        parseDeleteGroupReply(dataVal);
    }
    break;
    default:
        break;
    }
}

void MainWindow::sltTcpStatus(quint8)
{

}

void MainWindow::sltAddChat(Cell *cell)
{
    if(cell->type == Cell_FriendChat){
        //切换左栏按钮
        onleftBtnClicked(0);

        //中栏插入聊天格子
        midBar->insertCell(cell);
        midBar->switchToChatList();

        //右栏聊天窗口增加一条消息
        QJsonObject jsonObj;
        jsonObj.insert("type",Notice);
        jsonObj.insert("noticeType",NewFriend);
        jsonObj.insert("id",cell->id);
        jsonObj.insert("msg","你和" + QString::number(cell->id) + "已经成为好友了，开始聊天吧！");
        //qDebug()<<"同意添加，右边聊天窗口显示";
        rightBar->allowSendMsg(cell->id);//允许和此用户聊天
        rightBar->msgReceived(cell,jsonObj);

        //更新联系人列表
        Cell* c = new Cell;
        c->type = Cell_FriendContact;
        c->groupName = "默认分组";
        c->id = cell->id;
        c->iconPath = cell->iconPath;
        c->name = cell->name;
        c->isClicked = false;
        c->status = OnLine;
        midBar->addCellToContact(c);//更新联系人列表
    }else if(cell->type == Cell_GroupChat){
        //切换左栏按钮
        onleftBtnClicked(0);

        Cell* c = midBar->isIDExist(cell->id);
        if(c == nullptr){
            //说明中栏目前没有此聊天格子
            //中栏插入聊天格子
            midBar->insertCell(cell);
            midBar->switchToChatList();

            //右栏聊天窗口增加一条消息
            QJsonObject jsonObj;
            jsonObj.insert("type",Notice);
            jsonObj.insert("noticeType",NewMember);
            jsonObj.insert("id",cell->newUserID);
            jsonObj.insert("msg",cell->msg);

            rightBar->msgReceived(cell,jsonObj);
        }else{
            c->msg = cell->msg;
            c->subTitle = cell->subTitle;

            //刷新聊天窗口的群成员列表
            Cell* newUser = new Cell;
            newUser->type = Cell_FriendChat;
            newUser->id = cell->newUserID;
            newUser->name = cell->newUserName;
            newUser->iconPath = cell->newUserHead;
            newUser->status = OnLine;
            rightBar->addNewUserToGroupList(cell->id,newUser);

            //右栏聊天窗口增加一条消息
            QJsonObject jsonObj;
            jsonObj.insert("type",Notice);
            jsonObj.insert("noticeType",NewMember);
            jsonObj.insert("id",cell->newUserID);
            jsonObj.insert("msg",c->msg);
            rightBar->msgReceived(c,jsonObj);
        }
    }
}

void MainWindow::sltCreateGroup()
{
//    QString text = CInputDialog::GetInputText(this, "我的朋友们");
//    if (!text.isEmpty()) {

//        // 构建 Json 对象
//        QJsonObject json;
//        json.insert("id", m_tcp->GetID());
//        json.insert("name", text);

//        m_tcp->sendMsg(CreateGroup, json);
//    }
}

//好友更新了头像 去服务器下载头像
void MainWindow::ParseUpFriendHead(const QJsonValue &dataVal)
{
    if (!dataVal.isObject()) return;
    QJsonObject jsonObj = dataVal.toObject();
    int nId = jsonObj.value("id").toInt();
    QString strHead = jsonObj.value("head").toString();

    DownloadFriendHead(nId, strHead);
}

QString MainWindow::GetHeadPixmap(const QString &name) const
{
    if (QFile::exists(MyApp::m_strHeadPath + name)) {
        return MyApp::m_strHeadPath + name;
    }

    return ":/resource/head/1.bmp";
}

//到服务器下载用户头像
void MainWindow::DownloadFriendHead(const int &userId, const QString &strHead)
{
        int id = userId;
        QJsonObject json;
        json.insert("tag",-2);
        json.insert("from",MyApp::m_nId);
        json.insert("id",-2);
        json.insert("who",id);

        m_tcp->sendMsg(GetPicture,json);
        qDebug()<<"到服务器下载用户头像......";
        myHelper::Sleep(500);//等待半秒


    //更新列表


}

void MainWindow::parseAddFriendReply(QJsonValue dataVal)
{
    //好友接受端

//    if(dataVal.isObject()){
//        QJsonObject json = dataVal.toObject();

//        int id = json.value("id").toInt();//  请求端Id
//        QString head = json.value("head").toString();
//        QString name = json.value("name").toString();

//        msgDlg=new MessageDlg(nullptr,id,name);
//        msgDlg->setTitle(QDateTime::currentDateTime().toString("hh:mm:ss"));
//        msgDlg->setMsg( QString::number(id) + "请求添加好友");

//        msgDlg->show();
//        connect(msgDlg,&MessageDlg::signalAddFriend,m_tcp,&clientSock::sendMsg);
//    }

    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();

        int id = json.value("id").toInt();
        QString head = json.value("head").toString();
        QString name = json.value("name").toString();

        Cell *cell = new Cell;
        cell->id = id;
        cell->iconPath = MyApp::m_strHeadPath + head;
        cell->name = name;
        cell->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");
        cell->msg = QString::number(id) + "请求添加好友";
        cell->type = Cell_AddFriend;

        midBar->insertCell(cell);
        midBar->switchToChatList();
    }
}

void MainWindow::parseAddGroupReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();

        int id = json.value("id").toInt();
        QString name = json.value("name").toString();
        QString head = json.value("head").toString();

        int groupid = json.value("group").toInt();
        QString groupHead = json.value("groupHead").toString();
        QString groupName = json.value("groupName").toString();

        Cell *cell = new Cell;
        cell->id = id;
        cell->name = name;
        cell->iconPath = MyApp::m_strHeadPath + head;
        QFileInfo fileInfo(cell->iconPath);
        if(!fileInfo.exists() || head == ""){
            //头像文件不存在，向服务器获取
            qDebug() << cell->iconPath << "头像文件不存在，正在向服务器获取...";

            QJsonObject json;
            json.insert("tag",-2);
            json.insert("from",MyApp::m_nId);
            json.insert("id",-2);
            json.insert("who",cell->id);
            m_tcp->sendMsg(GetPicture,json);

            myHelper::Sleep(500);//等待500毫秒
        }

        cell->groupid = groupid;
        cell->groupname_ = groupName;
        cell->groupHead = MyApp::m_strHeadPath + groupHead;

        cell->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");
        cell->msg = QString::number(id) + "请求加入群：" + QString::number(groupid);
        cell->type = Cell_AddGroup;

        midBar->insertCell(cell);
        midBar->switchToChatList();
    }
}

void MainWindow::parseAddGroupRequestConfirmed(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int id = json.value("id").toInt();      //groupid
        QString name = json.value("name").toString();
        QString head = json.value("head").toString();
        int adminID = json.value("adminID").toInt();

        //更新本地数据库
        QSqlQuery query;
        query.prepare("INSERT INTO MyGroup (id, name, admin, head, tag, lastMsg, lastTime) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, id);
        query.bindValue(1, name);
        query.bindValue(2, adminID);
        query.bindValue(3, MyApp::m_strHeadPath + head);
        query.bindValue(4, 1);
        query.bindValue(5, "");
        query.bindValue(6, "");

        query.exec();

        Cell *cell = new Cell;
        cell->id = id;
        cell->name = name;
        cell->iconPath = MyApp::m_strHeadPath + head;
        cell->type = Cell_GroupChat;
        cell->status = OnLine;
        cell->msg = "你已加入该群";
        cell->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");

        midBar->insertCell(cell);
        midBar->switchToChatList();

        QJsonObject jsonObj;
        jsonObj.insert("type",Notice);
        jsonObj.insert("noticeType",NewMember);
        jsonObj.insert("group",cell->id);
        jsonObj.insert("id",MyApp::m_nId);
        jsonObj.insert("msg",QString("你已经加入该群，") + "开始聊天吧！");

        rightBar->msgReceived(cell,jsonObj);
        onleftBtnClicked(0);

        Cell* c = new Cell;
        c->type = Cell_GroupContact;
        c->groupName = "我的群组";
        c->id = cell->id;
        c->name = cell->name;
        c->iconPath = cell->iconPath;
        c->isClicked = false;
        c->status = OnLine;

        midBar->addCellToContact(c);
    }
}

void MainWindow::parseAddFriendRequestConfirmed(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int id = json.value("id").toInt();
        QString name = json.value("name").toString();
        QString head = json.value("head").toString();

        //更新本地数据库
        QSqlQuery query;
        query.prepare("INSERT INTO MyFriend (id, name, head, subgroup, tag, lastMsg, lastTime) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, id);
        query.bindValue(1, name);
        query.bindValue(2, MyApp::m_strHeadPath + head);
        query.bindValue(3, "默认分组");
        query.bindValue(4, 0);
        query.bindValue(5, "");
        query.bindValue(6, "");

        query.exec();


        Cell *cell = new Cell;
        cell->id = id;
        cell->name = name;
        cell->iconPath = MyApp::m_strHeadPath + head;
        cell->type = Cell_FriendChat;
        cell->status = OnLine;
        cell->msg = "你和" + QString::number(id) + "已经成为好友了！";
        cell->subTitle = QDateTime::currentDateTime().toString("hh:mm:ss");


        midBar->insertCell(cell);
        midBar->switchToChatList();

        QJsonObject jsonObj;
        jsonObj.insert("type",Notice);
        jsonObj.insert("noticeType",NewFriend);
        jsonObj.insert("id",id);
        jsonObj.insert("msg","你和" + QString::number(id) + "已经成为好友了，开始聊天吧！");

        rightBar->allowSendMsg(id);
        rightBar->msgReceived(cell,jsonObj);
        onleftBtnClicked(0);

        Cell* c = new Cell;
        c->type = Cell_FriendContact;
        c->groupName = "默认分组";
        c->id = cell->id;
        c->name = cell->name;
        c->iconPath = cell->iconPath;
        c->isClicked = false;
        c->status = OnLine;
        midBar->addCellToContact(c);
    }
}

void MainWindow::parseFriendMessageReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int senderID = json.value("id").toInt();//获取消息发送者的ID
        QString name = json.value("name").toString();

        Cell* cell = midBar->isIDExist(senderID);
        if(cell == nullptr){//证明聊天列表中没有和该用户的聊天记录
            cell = new Cell;
            cell->id = senderID;
            QJsonObject json = sql_manage::Instance()->getFriendInfo(senderID);
            cell->name = json.value("name").toString();
            cell->iconPath = json.value("head").toString();
            cell->type = Cell_FriendChat;

            midBar->insertCell(cell);
            midBar->switchToChatList();
            //同时新增一个chatWindow
        }

        rightBar->msgReceived(cell,dataVal);
    }
}

void MainWindow::parseGroupMessageReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int groupid = json.value("group").toInt();
        QString groupName = json.value("groupName").toString();
        int type = json.value("type").toInt();

        //聊天列表是否存在该群的聊天记录
        Cell *cell = midBar->isIDExist(groupid);
        if(cell == nullptr){//证明聊天列表中没有和该用户的聊天记录
            cell = new Cell;
            cell->id = groupid;
            cell->name = groupName;

            QJsonObject json = sql_manage::Instance()->getGroupInfo(groupid);
            cell->name = json.value("name").toString();
            cell->iconPath = json.value("head").toString();
            cell->type = Cell_GroupChat;

            midBar->insertCell(cell);
            midBar->switchToChatList();
        }

        rightBar->msgReceived(cell,dataVal);

        if(type == Notice){
            int noticeType = json.value("noticeType").toInt();
            if(noticeType == NewMember){
                //刷新聊天窗口的群成员列表
                Cell* newUser = new Cell;
                newUser->type = Cell_FriendChat;
                newUser->id = json.value("id").toInt();
                newUser->name = json.value("name").toString();
                newUser->iconPath = MyApp::m_strHeadPath +
                                    json.value("head").toString();
                newUser->status = OnLine;
                rightBar->addNewUserToGroupList(groupid,newUser);
            }
        }
    }
}

void MainWindow::parseCreateGroupReply(const QJsonValue &dataVal)
{
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();

        int nId = dataObj.value("group").toInt();  //groupid
        // 未查询到该用户
        if (-1 == nId) {
            QMessageBox::information(nullptr, "CreateGroup","该群组已经添加!");
            return;
        }else{
            QString message="创建成功!\n 您的群ID为:"+QString::number(nId);

            QMessageBox::information(nullptr,"CreateGroup",message);
        }

        Cell *cell = new Cell;
        cell->groupName = QString(tr("我的群组"));
        cell->iconPath  = GetHeadPixmap(dataObj.value("head").toString());
        cell->type      = Cell_GroupChat;
        cell->name      = dataObj.value("name").toString();
        cell->subTitle  = QString("我的群，我做主...");
        cell->id        = nId;
        cell->status    = OnLine;

        midBar->insertCell(cell);
        midBar->switchToChatList();

        QJsonObject jsonObj;
        jsonObj.insert("type",Notice);
        jsonObj.insert("noticeType",NewGroup);
        jsonObj.insert("id",nId);
        jsonObj.insert("msg","你success create a group!");

        rightBar->allowSendMsg(nId);
        rightBar->msgReceived(cell,jsonObj);
        onleftBtnClicked(0);

        Cell* c = new Cell;
        c->type = Cell_GroupContact;
        c->groupName = "我的群组";
        c->id = cell->id;
        c->name = cell->name;
        c->iconPath = cell->iconPath;
        c->isClicked = false;
        c->status = OnLine;

        midBar->addCellToContact(c);

        // 更新至数据库
        sql_manage::Instance()->AddGroup(cell->id, MyApp::m_nId, cell->name);


    }
}

void MainWindow::parseGetGroupMembersReply(const QJsonValue &dataVal)
{
    qDebug() << "收到服务器发来的群成员: "
             << dataVal;
    rightBar->refreshGroupList(dataVal);
}

void MainWindow::parseDeleteFriendReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int id = json.value("id").toInt();

        midBar->deleteFriend(id);//从联系人列表中删除

        rightBar->forbidSendMsg(id);
    }
}

void MainWindow::parseSendFileReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int tag = json.value("tag").toInt();
        int id = json.value("id").toInt();
        int groupid = json.value("group").toInt();
        Cell *cell = nullptr;
        if(tag == 0){//私发文件
            cell = midBar->isIDExist(id);
        }else if(tag == 1){//群发文件
            cell = midBar->isIDExist(groupid);
        }

        if(cell == nullptr){
            cell = new Cell;
            if(tag == 0){//私发文件
                cell->id = id;
                QJsonObject json = sql_manage::Instance()->getFriendInfo(id);
                cell->name = json.value("name").toString();
                cell->iconPath = json.value("head").toString();
                cell->type = Cell_FriendChat;
            }else if(tag == 1){//群发文件
                cell->id = groupid;
                QJsonObject json = sql_manage::Instance()->getGroupInfo(groupid);
                cell->name = json.value("name").toString();
                cell->iconPath = json.value("head").toString();
                cell->type = Cell_GroupChat;
            }
            midBar->insertCell(cell);
            midBar->switchToChatList();
        }

        rightBar->msgReceived(cell,dataVal);
    }
}

void MainWindow::SltUpdateUserHead(const int &userId, const QString &strHead)
{
    emit updateUserHead(userId,strHead);
}

void MainWindow::parseDeleteGroupReply(const QJsonValue &dataVal)
{
    if(dataVal.isObject()){
        QJsonObject json = dataVal.toObject();
        int groupid = json.value("group").toInt();
        QString groupName = json.value("groupName").toString();

        int id = json.value("id").toInt();
        QString name = json.value("name").toString();

        rightBar->removeUserFromGroupList(groupid,id);
    }
}

void MainWindow::sltFileRecvFinished(quint8, QString, int)
{

}

void MainWindow::SltConnectedToServer()
{
    QTimer::singleShot(1000, this, SLOT(SltBeginToSend()));
}

void MainWindow::SltBeginToSend()
{
    //    headupLoadSOcket->sendFile(MyApp::m_strHeadFile);
}


//更新好友状态

void MainWindow::UpdateFriendStatus(const quint8 &nStatus, const QJsonValue &dataVal)
{
    emit updateFriendStatus(nStatus,dataVal);
}

void MainWindow::ParseRefreshFriendsReply(const QJsonValue &dataVal)
{
    emit update(dataVal);
}

//void MainWindow::on_btn_min_clicked()
//{
//    //
//    this->hide();
//}


//void MainWindow::on_btn_max_clicked()
//{

//}

void MainWindow::onleftBtnClicked(int page)
{

    midBar->MainPageChanged(page);

    if(page == 0){//btn_chat clicked
        rightBar->restorePage();
    }else if(page == 1){//btn_contact clicked
        rightBar->resetPage();//btn_settings clied
    }else if(page == 2){
        //        leftBar->chatList->restoreBtn();
        //        leftBar->contacts->restoreBtn();
        //        leftBar->settings->onBtnClicked();
        //        rightBar->resetPage();

        qDebug() << "显示设置面板";

    }
}

void MainWindow::stayOnTop(bool top)
{
    if(top)
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    else
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
    show();
}

void MainWindow::sltMaxMin(bool max)
{

    QWidget *pWindow = this->window();
    if(max)
    {

        pWindow->showFullScreen();
    }else{
        pWindow ->showNormal();
    }
}

