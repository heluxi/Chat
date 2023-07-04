#include "chatwindow.h"
#include "qpushbutton.h"
#include "qtextedit.h"
#include "bubble/bubblelist.h"
#include "rightw/mytextedit.h"
#include "tcp_manage.h"
#include "type.h"
#include "ui_chatwindow.h"
#include "searchbar.h"
#include "myapp.h"
#include "sql_manage.h"
#include"CutScreen/screen.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QTime>
#include <QDir>
#include <QMessageBox>
#include <QJsonArray>

ChatWindow::ChatWindow(QWidget *parent,Cell *c) :
    QWidget(parent),cell(c),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);

//    QStringList tmp;
//    tmp << ":/Icons/MainWindow/arrow_close.png"
//        << ":/Icons/MainWindow/arrow_close2.png"
//        << ":/Icons/MainWindow/arrow_close.png";
//    ui->listbtn = new MyButton(nullptr,tmp,QSize(40,30),NormalBtn);

    connect(ui->msgWindow,&BubbleList::signalSendMessage,
            this,&ChatWindow::signalSendMessage);


    groupList = new GroupList;

    //只有群聊才显示群列表
    if(cell->type == Cell_GroupChat){
        ui->namelabel->setText(cell->name);
//        uicenterLayout->addWidget(groupList);
        InitGroupList();
    }
    else{
        ui->namelabel->setText(cell->name);
        ui->listbtn->setEnabled(false);
        ui->listbtn->setVisible(false);
    }


//    connect(ui->textEdit,&MyTextEdit::mousePressed,this,&ChatWindow::changeColor);
//    connect(ui->textEdit,&MyTextEdit::focusOut,this,&ChatWindow::restoreColor);
    connect(ui->btn_emoj,&QPushButton::clicked,this,&ChatWindow::sendMsg);
    connect(ui->listbtn,&QPushButton::clicked,this,&ChatWindow::on_listbtn_clicked);

    connect(ui->fileButton,&QPushButton::clicked,this,&ChatWindow::sendMsg);
    connect(ui->btn_pic,&QPushButton::clicked,this,&ChatWindow::sendMsg);
    connect(ui->sendBut,&QPushButton::clicked,this,&ChatWindow::sendMsg);
//    connect(ui->textEdit,&MyTextEdit::sendMsg,this,&ChatWindow::sendMsg);

    //tcp file transfer
    fileType = 0;
    tcpFileSocket = new clientFileSock(this);
    tcpFileSocket->connectToServer(MyApp::m_strHostAddr,MyApp::m_nFilePort,cell->id);

    connect(tcpFileSocket,&clientFileSock::signalFileArrived,
            this,&ChatWindow::sltFileArrived);
    connect(tcpFileSocket,&clientFileSock::signalFileRecvOk,
            this,&ChatWindow::sltRecvFileFinished);
    connect(tcpFileSocket,&clientFileSock::signalSendFinished,
            this,&ChatWindow::sltSendFileFinished);
    connect(tcpFileSocket,&clientFileSock::signalUpdateProgress,
            this, &ChatWindow::sltUpdateProgress);
#if 0
    loadingMovie = new QMovie(this);
    loadingMovie->setFileName(":/Icons/MainWindow/loading2.gif");

    loadingLabel = new QLabel(this);
    loadingLabel->setMovie(loadingMovie);
    loadingLabel->setFixedSize(50,50);
    loadingLabel->setAttribute(Qt::WA_TranslucentBackground,true);
    loadingLabel->setAutoFillBackground(false);
    loadingMovie->start();
    loadingLabel->setVisible(true);//动画开始
    loadingLabel->setGeometry(this->width()/2 - 25,this->height()/2 - 100,50,50);

#endif
}

ChatWindow::~ChatWindow()
{
    delete ui;
}


void ChatWindow::InitGroupList()
{
    //设置聊天列表中的格子右击菜单
    QMenu *sonMenu = new QMenu(this);
    sonMenu->addAction(tr("发送消息"));
    sonMenu->addSeparator();
    sonMenu->addAction(tr("查看资料"));
    sonMenu->addAction(tr("加为好友"));

    connect(sonMenu,SIGNAL(triggered(QAction*)),
            this,SLOT(onSonMenuSelected(QAction*)));
    groupList->memberList->setSonPopMenu(sonMenu);

    //查询数据库初始化群列表成员

    //向服务器发消息，请求获取该群的群成员
    QJsonObject json;
    json.insert("id",MyApp::m_nId);
    json.insert("groupid",cell->id);

    emit signalSendMessage(GetGroupMembers,json);
}

void ChatWindow::sendTimeMsg(qint64 time, QString msg)
{
    bool send = false;
    if(ui->msgWindow->count() > 0){
        send = ( (time - lastMsgTime) > 60 );
    }else{
        send = true;
    }

    lastMsgTime = time;
    emit updateMidBarTime(cell->id,time,msg);

    if(send){
        BubbleInfo *info = new BubbleInfo;

        info->msg = QDateTime::fromSecsSinceEpoch(time).toString("hh:mm:ss");
        info->sender = System;
        info->myID = MyApp::m_nId;
        if(tag == 0)
            info->yourID = cell->id;
        if(tag == 1)
            info->groupID = cell->id;
        info->msgType = Notice;

        info->tag = tag;

        ui->msgWindow->insertBubble(info);
        writeMsgToDatabase(info);
    }
}

void ChatWindow::refreshGroupList(QJsonValue &dataVal)
{
    if (dataVal.isArray()) {
        QJsonArray array = dataVal.toArray();
        int cnt = array.size();
        int onlineCnt = 0;

        for(int i = 0;i < cnt;i++){
            QJsonObject json = array.at(i).toObject();
            int id = json.value("id").toInt();
            QString name = json.value("name").toString();
            QString head = json.value("head").toString();
            int status = json.value("status").toInt();
            int groupid = json.value("groupid").toInt();

            Cell *c = new Cell;
            c->type = Cell_FriendContact;
            c->id = id;
            c->groupid = groupid;
            c->name = name;
            c->status = status;
            if(c->status == OnLine)
                onlineCnt++;
            c->iconPath = MyApp::m_strHeadPath + head;

            QFileInfo fileinfo(c->iconPath);
            if(head.isEmpty() || !fileinfo.exists()){

                //头像文件不存在，向服务器获取
                QJsonObject json;
                json.insert("tag",-2);
                json.insert("from",MyApp::m_nId);
                json.insert("id",-2);
                json.insert("who",c->id);
                emit signalSendMessage(GetPicture, json);

//                myHelper::Sleep(500);//等待500毫秒

                if(!fileinfo.exists()){
                    head = "default.png";
                    c->iconPath = MyApp::m_strHeadPath + head;//没有收到则显示默认头像
                }
            }

            cell->childs.append(c);
            groupList->memberList->insertCell(c);
        }

        QString text = "群成员 (" + QString::number(onlineCnt) + "/" + QString::number(cnt) + ")";
                                                                          groupList->groupListLabel->setText(text);
    }
}

void ChatWindow::addCellToGroupList(Cell *c)
{
    QList<Cell*> cells = groupList->memberList->getAllCells();
    int onlineCnt = 0;
    int cnt = cells.size();

    for(int i = 0;i < cnt;i++){
        if(cells.at(i)->status == OnLine)
            onlineCnt++;

        if(cells.at(i)->id == c->id)
            return;
    }

    groupList->memberList->insertCell(c);
    cnt++;
    onlineCnt++;

    QString text = "群成员 (" + QString::number(onlineCnt) + "/" + QString::number(cnt) + ")";
                                                                      groupList->groupListLabel->setText(text);
}

void ChatWindow::removeCellFromGroupList(int id)
{
    QList<Cell*> cells = groupList->memberList->getAllCells();
    int cnt = cells.size();
    for(int i = 0;i < cnt;i++){
        if(cells.at(i)->id == id){
            groupList->memberList->removeCell(cells.at(i));

            //通知消息
            qint64 time = QDateTime::currentSecsSinceEpoch();
            QString msg = "用户" + QString::number(id) + "已退出该群";

            QString text = "群成员 (" + QString::number(cnt-1) + "/" + QString::number(cnt-1) + ")";
                                                                            groupList->groupListLabel->setText(text);

            //sendTimeMsg(time,msg);
            emit updateMidBarTime(cell->id,time,msg);
            addSystemMsg(msg);

            return;
        }
    }
}

void ChatWindow::forbidSendMsg()
{
    cell->deleted = true;
    BubbleInfo *info = new BubbleInfo;
    info->sender = System;
    info->msg = "你和用户" + QString::number(cell->id) + "已经不是好友了，无法继续聊天";
    ui->msgWindow->insertBubble(info);
    writeMsgToDatabase(info);

    qint64 time = QDateTime::currentSecsSinceEpoch();
    sendTimeMsg(time,"用户" + QString::number(cell->id) + "已经将你删除");
}

void ChatWindow::allowSendMsg()
{
    cell->deleted = false;
}

void ChatWindow::addSystemMsg(QString msg)
{
    BubbleInfo *info = new BubbleInfo;

    info->msg = msg;
    info->sender = System;
    info->myID = MyApp::m_nId;
    if(tag == 0)
        info->yourID = cell->id;
    if(tag == 1)
        info->groupID = cell->id;
    info->msgType = Notice;

    info->tag = tag;

    ui->msgWindow->insertBubble(info);
    writeMsgToDatabase(info);
}

void ChatWindow::msgReceived(QJsonValue &value)
{
    if(value.isObject()){
        QJsonObject json = value.toObject();
        BubbleInfo *info = new BubbleInfo;
        info->sender = You;
        info->myID = MyApp::m_nId;
        info->tag = tag;
        info->msgType = MessageType(json.value("type").toInt());
        if(tag == 1)
            info->groupID = cell->id;

        QString msg;

        if(info->msgType == Text){
            info->yourID = json.value("id").toInt();
            info->name = json.value("name").toString();
            info->headIcon = MyApp::m_strHeadPath + json.value("head").toString();
            info->showAnimation = false;
            info->msg = json.value("msg").toString();

            if(tag == 0)
                msg = "对方:" + info->msg;
                                  else
                                  msg = QString::number(info->yourID) + ":" + info->msg;
        }else if(info->msgType == Files){
            qDebug() << "客户端收到文件下载通知：";
//            myHelper::printLogFile("客户端收到文件下载通知：");
            info->time = json.value("time").toInt();
            info->yourID = json.value("id").toInt();
            qDebug() << "file sent time:" << info->time << " sender:" << info->yourID;
//            myHelper::printLogFile("file sent time: " + QString::number(info->time)
//                                   + " sender:" + QString::number(info->yourID));

            info->msg = json.value("fileName").toString();
            info->fileSize = json.value("fileSize").toInt();
            if(tag == 0)
                info->headIcon = cell->iconPath;
            else if(tag == 1){
                info->headIcon = MyApp::m_strHeadPath +
                                 QString::number(info->yourID) + ".png";//本地发送该群消息的用户的头像地址
                info->groupID = cell->id;//如果是群聊，则在bubble中记录群id，否则不记录
            }
            info->showAnimation = false;
            info->showProgressBar = false;
            info->showDownload = true;

            if(tag == 0)
                msg = QString("对方:") + "[文件]";
            else
                msg = QString::number(info->yourID) + ":" + "[文件]";
        }else if(info->msgType == Picture){
            //照片不在这处理
            qDebug() << "收到照片:" << value;
                if(tag == 1)
                info->groupID = cell->id;
            return;
        }else if(info->msgType == Notice){
            info->sender = System;
            info->msg = json.value("msg").toString();
        }

        if(info->msgType != Notice){
            //发消息之前先处理时间
            qint64 curTime = QDateTime::currentSecsSinceEpoch(); //时间戳
            info->time = json.value("time").toInt();

            sendTimeMsg(curTime,msg);
        }else{
            int noticeType = json.value("noticeType").toInt();
            if(noticeType == NewFriend){
                //发消息之前先处理时间
                qint64 curTime = QDateTime::currentSecsSinceEpoch(); //时间戳
                info->time = json.value("time").toInt();
                int id = json.value("id").toInt();
                msg = "你和用户" + QString::number(id) + "已经成为好友了";
                sendTimeMsg(curTime,msg);
            }else if(noticeType == NewMember){
                //发消息之前先处理时间
                qint64 curTime = QDateTime::currentSecsSinceEpoch(); //时间戳
                info->time = json.value("time").toInt();
                int id = json.value("id").toInt();
                if(id == MyApp::m_nId)
                    msg = "你已经加入该群";
                else
                    msg = "用户" + QString::number(id) + "已经加入该群";

                sendTimeMsg(curTime,msg);
            }
        }

        ui->msgWindow->insertBubble(info);
        writeMsgToDatabase(info);
    }
}



void ChatWindow::msgconfirmed(qint64 time)
{
    ui->msgWindow->msgConfirmed(time);
}

void ChatWindow::writeMsgToDatabase(BubbleInfo *info)
{
    if(!info->showError){
        //showError表示未发送成功的消息
        sql_manage::Instance()->addHistoryMsg(info);
    }
}

void ChatWindow::loadMsgFromDatabase()
{
    QVector<BubbleInfo*> bubbles = sql_manage::Instance()->queryHistory(cell->id,tag,0);
    int cnt = bubbles.size();
    for(int i = 0;i < cnt;i++){//耗时较长，需要放到一个单独的线程中处理
//        myHelper::Sleep(10);
        ui->msgWindow->insertBubble(bubbles.at(i));

        if(i == cnt-1){//最后一条消息更新中栏
            BubbleInfo *info = bubbles.at(i);
            QString msg;
            int id = 0;
            if(info->msgType == Files){
                if(info->sender == Me){
                    msg = QString("我:") + "[文件]";
                }else{
                    if(tag == 0){
                        msg = QString("对方:") + "[文件]";
                    }else{
                        msg = QString::number(info->yourID) + ":" + "[文件]";
                    }
                }
            }else if(bubbles.at(i)->msgType == Picture){
                if(info->sender == Me){
                    msg = QString("我:") + "[图片]";
                }else{
                    if(tag == 0){
                        msg = QString("对方:") + "[图片]";
                    }else{
                        msg = QString::number(info->yourID) + ":" + "[图片]";
                    }
                }
            }else if(bubbles.at(i)->msgType == Text){
                if(info->sender == Me){
                    msg = QString("我:") + info->msg;
                }else{
                    if(tag == 0){
                        msg = QString("对方:") + info->msg;
                    }else{
                        msg = QString::number(info->yourID) + ":" + info->msg;
                    }
                }
            }else if(bubbles.at(i)->msgType == Notice){
                msg = info->msg;
            }

            if(tag == 0){
                id = info->yourID;
            }else if(tag == 1){
                id = info->groupID;
            }

            emit updateMidBarTime(id,info->time,msg);
        }
    }
}

void ChatWindow::stopLoadingAnimation()
{
    loadingMovie->stop();
    loadingLabel->setVisible(false);
}

void ChatWindow::sendMsg()
{
    BubbleInfo *info = new BubbleInfo;
    info->sender = Me;
    info->myID = MyApp::m_nId;
    info->headIcon = MyApp::m_strHeadPath + MyApp::m_strHeadFile;//我的头像

    QFileInfo headFile(info->headIcon);
    if(!headFile.exists() || MyApp::m_strHeadFile.isEmpty()){
        info->headIcon = MyApp::m_strHeadPath + "default.png";
    }
    info->name = MyApp::m_strUserName;//我的名字
    info->yourID = cell->id;
    if(tag == 1)
        info->groupID = cell->id;
    info->tag = tag;

    //发消息之前先处理时间
    qint64 curTime = QDateTime::currentSecsSinceEpoch();//时间戳
    info->time = curTime;

    if(sender() == ui->sendBut || sender() == ui->textEdit){//发送普通文本消息
        info->msgType = Text;
        info->msg = ui->textEdit->toPlainText();
        ui->textEdit->clear();

        if(!info->msg.isEmpty()){
            //向服务器发消息
            QJsonObject json;
            json.insert("id",info->myID);//发送者的id
            json.insert("name",MyApp::m_strUserName);//发送者的名字
            json.insert("to",info->yourID);//接受者的id
            json.insert("msg",info->msg);
            json.insert("type",Text);
            json.insert("time",info->time);
            json.insert("tag",tag);
            json.insert("head",MyApp::m_strHeadFile);

            if(!cell->deleted){//未删除好友时正常发送消息
                if(tag == 0){
                    //私聊消息
                    emit signalSendMessage(SendMsg,json);
                }else if(tag == 1){
                    //群聊消息
                    json.insert("groupName",cell->name);//发送群消息得带上群的名字
                    emit signalSendMessage(SendGroupMsg,json);
                }

                //在聊天界面添加气泡
                QString msg = "我:" + info->msg;
                                           sendTimeMsg(curTime,msg);
                info->showError = false;
                                           ui->msgWindow->insertBubble(info);
                writeMsgToDatabase(info);
            }else{
                info->showError = true;
                info->showAnimation = false;
                ui->msgWindow->insertBubble(info);
                writeMsgToDatabase(info);
            }
        }

    }else if(sender() == ui->fileButton){//发送文件
        if(!busy && !tcpFileSocket->isBusy()){
            info->msgType = Files;
            QString fileName = QFileDialog::getOpenFileName(this);
            QFileInfo fileInfo = QFileInfo(fileName);
            if(fileInfo.exists()){
                info->fileSize = fileInfo.size();
                info->msg = fileName;
                info->showAnimation = false;

                qDebug() << fileInfo.path() << fileInfo.fileName() <<
                    QString("file size: ")+QString::number(fileInfo.size()) + "bytes"
                         << "file sent time:" << info->time;
//                myHelper::printLogFile(fileInfo.path() + fileInfo.fileName()+
//                                       QString("file size: ")+QString::number(fileInfo.size()) + "bytes" +
//                                       "file sent time:" + QString::number(info->time));

                QString strsize = "文件大小:";
//                strsize += myHelper::CalcSize(fileInfo.size());

                //发送文件大小目前限制在1G内
                if(fileInfo.size() > (1024*1024*1024)){
                    QMessageBox::information(this,tr("错误"),tr("上传文件过大！"));
                    return;
                }

                if(!cell->deleted){
                    info->downloaded = true;
                    curFileBubble = info;
                    QString msg = QString("我:") + "[文件]";
                    sendTimeMsg(curTime,msg);
                    ui->msgWindow->insertBubble(info);
                    writeMsgToDatabase(info);

                    //tcp开始传输文件
                    qDebug() << "starting to tranfer file...";
                    tcpFileSocket->sendFile(fileName,curTime,SendFile);
                    updateTime.restart();
                    fileType = SendFile;
                }else{
                    info->showError = true;
                    info->showAnimation = false;
                    ui->msgWindow->insertBubble(info);
                    writeMsgToDatabase(info);
                }
            }else{
                qDebug() << "file not exist!";
            }
        }else{
            QMessageBox::information(this,"警告","请等待当前文件发送完成!");
        }

    }else if(sender() == ui->btn_pic){//发送图片
        if(!busy && !tcpFileSocket->isBusy()){
            info->msgType = Picture;
            QString fileName = QFileDialog::getOpenFileName(this,"","","picture file(*.png *.jpg)");
            QFileInfo fileInfo = QFileInfo(fileName);
            if(fileInfo.exists()){
                info->fileSize = fileInfo.size();
                info->msg = fileName;
                qDebug() << fileInfo.path() << fileInfo.fileName()
                         << QString("file size: ")+QString::number(fileInfo.size()) + "bytes"
                         << "suffix: " + fileInfo.suffix();

                if(fileInfo.size() > (1024*1024*5)){//图片不能大于5M，否则需要通过传输文件的形式进行
                    QMessageBox::information(this,tr("错误"),tr("图片过大！请通过发送文件的形式传输"));
                    return;
                }

                if(!cell->deleted){
                    curFileBubble = info;
                    QString msg = QString("我:") + "[图片]";
                    sendTimeMsg(curTime,msg);
                    ui->msgWindow->insertBubble(info);
                    writeMsgToDatabase(info);

                    //tcp开始传输文件
                    tcpFileSocket->sendFile(fileName,curTime,SendPicture);
                    updateTime.restart();
                    fileType = SendPicture;
                }else{
                    info->showError = true;
                    info->showAnimation = false;
                    ui->msgWindow->insertBubble(info);
                    writeMsgToDatabase(info);
                }
            }
        }else{
            QMessageBox::information(this,"警告","请等待当前图片发送完成!");
        }
    }else if(sender()==ui->btn_emoj){
        //qDebug()<<"dhajsd";
        //g
        emoj=new MyEmotionWidget;
        emoj->show();
        auto g=[&](){
            qDebug()<<"dhajsd";
            BubbleInfo *info = new BubbleInfo;
            info->sender = Me;
            info->myID = MyApp::m_nId;
            info->headIcon = MyApp::m_strHeadPath + MyApp::m_strHeadFile;//我的头像

            QFileInfo headFile(info->headIcon);
            if(!headFile.exists() || MyApp::m_strHeadFile.isEmpty()){
                info->headIcon = MyApp::m_strHeadPath + "default.png";
            }
            info->name = MyApp::m_strUserName;//我的名字
            info->yourID = cell->id;
            if(tag == 1)
                info->groupID = cell->id;
            info->tag = tag;

            //发消息之前先处理时间
            qint64 curTime = QDateTime::currentSecsSinceEpoch();//时间戳
            info->time = curTime;
            info->msgType = Picture;
            if(!busy && !tcpFileSocket->isBusy()){
                if(emoj->currentFileName!="")
                    fileName =emoj->currentFileName;
                qDebug()<<"currentfilename:"<<fileName;

                QFileInfo fileInfo = QFileInfo(fileName);
                if(fileInfo.exists()){
                    info->fileSize = fileInfo.size();
                    info->msg = fileName;
                    qDebug() << fileInfo.path() << fileInfo.fileName()
                             << QString("file size: ")+QString::number(fileInfo.size()) + "bytes"
                             << "suffix: " + fileInfo.suffix();

                    if(fileInfo.size() > (1024*1024*5)){//图片不能大于5M，否则需要通过传输文件的形式进行
                        QMessageBox::information(this,tr("错误"),tr("图片过大！请通过发送文件的形式传输"));
                        return;
                    }

                    if(!cell->deleted){
                        curFileBubble = info;
                        QString msg = QString("我:") + "[图片]";
                        sendTimeMsg(curTime,msg);
                        ui->msgWindow->insertBubble(info);
                        writeMsgToDatabase(info);

                        //tcp开始传输文件
                        tcpFileSocket->sendFile(fileName,curTime,SendPicture);
                        updateTime.restart();
                        fileType = SendPicture;
                    }else{
                        info->showError = true;
                        info->showAnimation = false;
                        ui->msgWindow->insertBubble(info);
                        writeMsgToDatabase(info);
                    }
                }
            }else{
                QMessageBox::information(this,"警告","请等待当前图片发送完成!");
            }
            //                disconnect(emoj,0,this,0);
            //                emoj->disconnect(this);
            //                emoj->close();
        };
        connect(emoj,&MyEmotionWidget::SendEmojoyMessage,this,g);
        //delete emoj;
    }
}

void ChatWindow::onSonMenuSelected(QAction *)
{

}

void ChatWindow::sltRecvFileFinished(quint8 type, QString filename,int id)
{
    if(type == Picture){
        BubbleInfo *info = new BubbleInfo;
        info->sender = You;
        info->myID = MyApp::m_nId;
        //info->yourID = cell->id;
        info->tag = tag;
        info->msgType = Picture;
        info->showAnimation = false;
        info->showProgressBar = false;
        info->showDownload = false;

        info->msg = filename;

        if(tag == 0){
            info->yourID = cell->id;
            info->headIcon = cell->iconPath;
        }else{
            info->yourID = id;
            info->groupID = cell->id;
            QJsonObject json = sql_manage::Instance()->getFriendInfo(id);
            info->headIcon = json.value("head").toString();
        }

        //发消息之前先处理时间
        qint64 curTime = QDateTime::currentSecsSinceEpoch(); //时间戳
        info->time = curTime;

        QString msg;
        if(tag == 0)
            msg = QString("对方:") + "[图片]";
        else
            msg = QString::number(info->yourID) + ":" + "[图片]";
        sendTimeMsg(curTime,msg);

        info->downloaded = true;

        ui->msgWindow->insertBubble(info);
        writeMsgToDatabase(info);
    }else if(type == Files){
        //qDebug() << "filename:" << filename << "groupid:" << id;
        curFileBubble->msg = filename;

        curFileBubble->downloaded = true;
        curFileBubble->showProgressBar = false;

        sql_manage::Instance()->updateFileMsg(curFileBubble);//更新本地数据库

        emit curFileBubble->updateProgressBar(0,0);
        emit curFileBubble->updatePopMenu();

        busy = false;
    }
}

void ChatWindow::sltUpdateProgress(qint64 bytes, qint64 total)
{
    if(curFileBubble != nullptr && curFileBubble->msgType == Files)
        emit curFileBubble->updateProgressBar(bytes,total);

    //更新进度条
    //    qDebug() << "更新进度条中..." << "total bytes to send:" << total << "bytes"
    //             << "  already sent:" << bytes << "bytes"
    //             << "  cur time:" << QDateTime::currentDateTime().toString("hh:mm:ss");

    //msgWindow->refreshList();
}

void ChatWindow::sltFileArrived(const QJsonValue &jsonVal)
{
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        int tag = json.value("tag").toInt();
        int type = json.value("type").toInt();
        int senderID = json.value("from").toInt();
        int winID = json.value("winID").toInt();
        qint64 time = json.value("time").toInt();
        qDebug() << "RecvFileSent time:" << time;

        if(type == Files){
            if(tag == 0){
                curFileBubble =  ui->msgWindow->findBubble(winID,time);
            } else if(tag == 1){
                curFileBubble =  ui->msgWindow->findBubble(senderID,time);
            }
            if(curFileBubble != nullptr){
                curFileBubble->showDownload = false;//隐藏未下载Label
                curFileBubble->showProgressBar = true;//显示进度条
            }
        }
    }
}

void ChatWindow::changeColor()
{
    QPalette pal(palette());
    pal.setColor(QPalette::Window, QColor(Qt::white));
    setAutoFillBackground(true);
    setPalette(pal);

    pal.setColor(QPalette::Window, QColor("#F0F0F0"));
//    ui->actionBtn->setAutoFillBackground(true);
//    actionBtn->setPalette(pal);

    ui->sendBut->setAutoFillBackground(true);
    ui->sendBut->setPalette(pal);

    ui->textEdit->setStyleSheet("border: none;background-color:white;");
}

void ChatWindow::restoreColor()
{
    setStyleSheet("border: none;background-color:#F0F0F0;");
    setStyleSheet("border-top:1px solid #E6E6E6");
    ui->textEdit->setStyleSheet("border: none;background-color:#F0F0F0;");
}

void ChatWindow::sltSendFileFinished(quint8 type,QString filename)
{
    //qDebug() << "send file finished!" << "type:" << type << " filename:" << filename;
//    myHelper::printLogFile(QString("send file finished!") + "type:" +
//                           QString::number(type) + " filename:" + filename);
    curFileBubble->showProgressBar = false;
    emit curFileBubble->updateProgressBar(0,0);
    busy = false;
}


//-------------------------------------------------------


TopBar::TopBar(QWidget *parent)
    : QWidget(parent)
{
//    QHBoxLayout *topLayout = new QHBoxLayout;
//    nameLabel = new QLabel("XJX");
//    nameLabel->setFont(QFont("Microsoft YaHei", 20, 50, false));
//    QStringList tmp;
//    tmp << ":/Icons/MainWindow/arrow_close.png"
//        << ":/Icons/MainWindow/arrow_close2.png"
//        << ":/Icons/MainWindow/arrow_close.png";
//    listBtn = new MyButton(nullptr,tmp,QSize(20,20),NormalBtn);
//    listBtn->setToolTip("关闭群员列表");
//    topLayout->addWidget(nameLabel);
//    topLayout->addStretch(1);
//    topLayout->addWidget(listBtn);

//    setLayout(topLayout);

//    setStyleSheet("border: none;background-color:#F0F0F0;");//
//    setStyleSheet("border-bottom:1px solid #E6E6E6");

//    setFocusPolicy(Qt::StrongFocus);
}

void TopBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TopBar::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture()){
        QWidget *pWindow = this->window();
        if (pWindow->isTopLevel()){
            SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
    event->ignore();
#endif
}


//--------------------------------------


GroupList::GroupList(QWidget *parent)
    : QWidget(parent)
{
    setFixedWidth(200);
    //-------------rightLayout----------------
    QVBoxLayout *rightLayout = new QVBoxLayout;
    groupListLabel = new QLabel("群成员 (0/0)");
    groupListLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    groupListLabel->setFont(QFont("Microsoft YaHei", 10, 50, false));
    SearchBar *groupSearch = new SearchBar(nullptr,QSize(200,30));
    memberList = new ListWidget(nullptr,1);
    rightLayout->addWidget(groupListLabel);
    rightLayout->addWidget(groupSearch);
    rightLayout->addWidget(memberList);
    rightLayout->setContentsMargins(1,0,0,0);
    rightLayout->setSpacing(3);

    setLayout(rightLayout);

    setStyleSheet("border: none;background-color:#F0F0F0;");//#F0F0F0
    setStyleSheet("border-left:1px solid #E6E6E6");
}

void GroupList::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ChatWindow::on_listbtn_clicked()
{
    if(open){
        groupList->setFixedWidth(0);
        groupList->setVisible(false);
        open = !open;
        QStringList tmp;
        tmp << ":/Icons/MainWindow/arrow_open.png"
            << ":/Icons/MainWindow/arrow_open2.png"
            << ":/Icons/MainWindow/arrow_open.png";
        ui->listbtn->changeIconSet(tmp);
        ui->listbtn->setImage(ui->listbtn->MoveInIcon);
        ui->listbtn->setToolTip("显示群员列表");
    }else{
        groupList->setFixedWidth(200);
        groupList->setVisible(true);
        groupList->memberList->resetCellState();
        groupList->memberList->refreshList();
        open = !open;
        QStringList tmp;
        tmp << ":/Icons/MainWindow/arrow_close.png"
            << ":/Icons/MainWindow/arrow_close2.png"
            << ":/Icons/MainWindow/arrow_close.png";
        ui->listbtn->changeIconSet(tmp);
        ui->listbtn->setImage(ui->listbtn->MoveInIcon);
        ui->listbtn->setToolTip("关闭群员列表");
    }
}


void ChatWindow::on_btn_screenshot_clicked()
{
    screen=new Screen();

    screen->show();
}

