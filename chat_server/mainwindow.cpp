#include "mainwindow.h"
#include "clientsocket.h"
#include "qabstractitemmodel.h"
#include "qlabel.h"
#include "qmessagebox.h"
#include "qstatusbar.h"
#include "qtableview.h"
#include "tcpServer.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "myapp.h"
#include "type.h"

#include<QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>
#include <QMessageBox>
#include <QModelIndex>
#include <QFileDialog>
#include <QJsonArray>

#include<tcpServer.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFile=false;

//    sockSer=new QTcpServer(this);
//    sockSer->listen(QHostAddress::Any,quint16(8888));
//    connect(sockSer,&QTcpServer::newConnection,this,&MainWindow::newConnect);
//    connect(&timer,&QTimer::timeout,this,[=](){
//        qDebug()<<"开始发送文件";
//        timer.stop();
//        sendfile(curScok);
//    });
//    msgServer=new TcpMsgSever(this);
//    fileServer=new TcpFileSever(this);


//    ui->treeWidget->setColumnCount(1);

    //隐藏表头
    ui->treeWidget->setHeaderHidden(true);

//    QStringList l;
//    l<<"ATAW Server";
//    QTreeWidgetItem *qf=new QTreeWidgetItem(ui->treeWidget,l);
//    ui->treeWidget->addTopLevelItem(qf);

//    l.clear();
//    l<<"用户信息";
//    QTreeWidgetItem *q1=new QTreeWidgetItem(qf,l);
//    qf->addChild(q1);
//    //    ui->treeWidget->setItemWidget(q1,0,ui->tableWidget);

//    l.clear();
//    l<<"服务配置";
//    QTreeWidgetItem *q2=new QTreeWidgetItem(qf,l);
//    qf->addChild(q2);

//    l.clear();
//    l<<"用户管理";
//    QTreeWidgetItem *q3=new QTreeWidgetItem(qf,l);
//    qf->addChild(q3);

//    l.clear();
//    l<<"密码修改";
//    QTreeWidgetItem *q4=new QTreeWidgetItem(qf,l);
//    qf->addChild(q4);

//    l.clear();
//    l<<"数据备份";
//    QTreeWidgetItem *q5=new QTreeWidgetItem(qf,l);
//    qf->addChild(q5);

    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);

    ui->stackedWidgetMain->setCurrentIndex(0);  //

    m_model = new QStandardItemModel(this); //保存数据

    ui->tableViewUsers->setModel(m_model);  //显示数据

    // 设置几张表格的属性不可编辑
    ui->tableViewUsers->setEditTriggers(QTableView::NoEditTriggers);
    // 设置几张表格的属性选择整行
    ui->tableViewUsers->setSelectionBehavior(QTableView::SelectRows);
    connect(ui->tableViewUsers, SIGNAL(clicked(QModelIndex)), this, SLOT(SltTableClicked(QModelIndex)));

    ui->lineEditBackup->setText(MyApp::m_strBackupPath);

    // 初始化网络
    InitNetwork();

    //tool
    QStatusBar *bar=this->statusBar();
//    QLabel *lb_ip=new QLabel(QString("本机IP：") + myHelper::GetIP());
// 显示系统时间
    QLabel *lb_time=new QLabel(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss ddd"));
    bar->addWidget(lb_time);        //left
//    bar->addPermanentWidget(lb_ip); //right

    m_nTimerId = startTimer(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::readMsg()
//{
//}

// 初始化网络
void MainWindow::InitNetwork()
{
    msgServer = new TcpMsgServer(this);     //connect
    bool bOk = msgServer->StartListen(60100);
    ui->textBrowser->setText(tr("服务器通知消息:"));
    ui->textBrowser->append(bOk ? tr("消息服务器监听成功,端口: 60100") : tr("消息服务器监听失败"));

    fileServer = new TcpFileServer(this);       //connect
    bOk = fileServer->StartListen(60101);
    ui->textBrowser->append(bOk ? tr("文件服务器监听成功,端口: 60101") : tr("文件服务器监听失败"));

    connect(msgServer, &TcpMsgServer::signalDownloadFile, fileServer, &TcpFileServer::SltClientDownloadFile);
    connect(msgServer, &TcpMsgServer::signalUserStatus, this, &MainWindow::ShowUserStatus);

    connect(fileServer, &TcpFileServer::signalUserStatus, this, &MainWindow::ShowUserStatus);
    connect(fileServer,&TcpFileServer::signalMsgToClient,
           msgServer,&TcpMsgServer::SltMsgToClient);

    systemTrayIcon = new QSystemTrayIcon(this);
    systemTrayIcon->setIcon(QIcon(":/res/images/ic_app.png"));

    //系统托盘(在应用程序图标那显示
    QMenu *m_trayMenu = new QMenu(this);
    m_trayMenu->addAction("显示主面板");
    m_trayMenu->addSeparator();
    m_trayMenu->addAction("退出");

    systemTrayIcon->setContextMenu(m_trayMenu);
    systemTrayIcon->show();

    connect(systemTrayIcon, &QSystemTrayIcon::activated,this, &MainWindow::SltTrayIcoClicked);
    connect(m_trayMenu, &QMenu::triggered, this, &MainWindow::SltTrayIconMenuClicked);
}


/**
 * @brief MainWindow::SetUserIdentity
 * 根据用户的身份进行界面显示控制
 * @param identity
 */
void MainWindow::SetUserIdentity(const int &identity)
{
//    ui->treeWidget->->setVisible(Mangager == identity);
//    ui->btnUsersPage->setVisible(Administrator == identity);
//    ui->btnUserInfoPage->setVisible(Administrator == identity);
//    ui->btnDataBackup->setVisible(Mangager == identity);

//    // 根据用户权限设定界面功能的使用
//    if (Mangager == identity) ui->stackedWidgetFunc->setCurrentIndex(1);
//    else if (Worker == identity) ui->stackedWidgetFunc->setCurrentIndex(1);
//    else if (Administrator == identity) ui->stackedWidgetFunc->setCurrentIndex(0);
}


void MainWindow::removeSocket()
{
    int i=0;
    foreach(QTcpSocket* soc, sockLists)
        {
            if(soc->state() == QTcpSocket::UnconnectedState)
            {
                qDebug()<<soc->peerAddress().toString()<<"closed";
                soc->deleteLater();
                sockLists.removeAt(i); //tcpSockets.removeOne(soc);
            }
            i++;

        }

}

//void MainWindow::sendfile(QTcpSocket *&sock)
//{
//     qDebug()<<"send";
//    if(!file.open(QIODevice::ReadOnly))
//        qDebug()<<"文件打开失败";
//    int len;
//    do{

//        char buf[4*1024]={0};
//        len=0;
//        len=file.read(buf,sizeof(buf));
//        len=sock->write(buf,len);
//        sendSize+=len;
//    }while(len>0);
//    if(sendSize==fileSize)
//    {
//        curScok=nullptr;
//        file.close();
//        sendSize=0;
//        qDebug()<<"文件发送成功";
//    }

//}

//void MainWindow::sendhead(QTcpSocket *&sock)
//{
//    //封装头部信息
//    QString head=QString("sendfile##%1##%2").arg(fileName).arg(fileSize);
//    sock->write(head.toUtf8());
//    timer.start(20);

//}

//exit
void MainWindow::on_btn_Exit_clicked()
{
    this->close();
}

//login
void MainWindow::on_btn_Login_clicked()
{
    QString name = ui->lineEditUser->text();
    QString passwd = ui->lineEditPasswd->text();
    //
    QJsonObject jsonObje = Database::Instance()->CheckUserLogin(name,passwd);
    int nId = jsonObje.value("id").toInt();
    int identity = jsonObje.value("identity").toInt();

    if (-1 == nId) {
        QMessageBox::information(this, tr("提示"), tr("用户名或密码错误！"));
        return;
    }

    MyApp::m_nId = nId;
    MyApp::m_nIdentyfi = identity;
    //    // 设置权限
//    SetUserIdentity(identity);

    ui->stackedWidgetMain->setCurrentIndex(1);
}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->text(column)=="用户信息"){
//        qDebug()<<item->text(column);
        ui->stackedWidget->setCurrentWidget(ui->page);
    }
    else if(item->text(column)=="服务配置"){
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    }else if(item->text(column)=="用户管理"){
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }    else if(item->text(column)=="密码修改"){
        ui->stackedWidget->setCurrentWidget(ui->page_4);
    }    else if(item->text(column)=="数据备份"){
        ui->stackedWidget->setCurrentWidget(ui->page_5);
    }
}

void MainWindow::SltTableClicked(const QModelIndex &index)
{
    qDebug() << index.row();
}

void MainWindow::ShowUserStatus(const QString &text)
{
    qDebug() << text;
    ui->textBrowser->append(text);
}

// 托盘菜单
void MainWindow::SltTrayIcoClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:      //单击系统托盘
    {
    }
        break;
    case QSystemTrayIcon::DoubleClick:  //双击系统托盘
    {
        if (!this->isVisible())
            this->show();
    }
        break;
    default:
        break;
    }
}

void MainWindow::SltTrayIconMenuClicked(QAction *action)
{
    if ("退出" == action->text()) {
        msgServer->CloseListen();
        fileServer->CloseListen();
        qApp->quit();
    }
    else if ("显示主面板" == action->text()) {
        this->show();
    }
}



void MainWindow::on_btn_quit_clicked()
{
    ui->stackedWidgetMain->setCurrentIndex(0);
}


void MainWindow::on_btn_backUp_clicked()
{
    qDebug()<<" beifen";
    QString strNewFile = MyApp::m_strBackupPath + QString("info_%1.bak").arg(QDate::currentDate().toString("yyyy_MM_dd"));
    if (QFile::exists(strNewFile)) {
        QFile::remove(strNewFile);
    }
    bool bOk = QFile::copy(MyApp::m_strDatabasePath + "info.db", strNewFile);
    QMessageBox::information(this,"backup", bOk ? tr("数据备份成功") : tr("数据备份失败"));
}


void MainWindow::on_btn_backUndo_clicked()
{
    if (QMessageBox::Accepted == QMessageBox::question(this,"Undo", tr("是否还原数据库，该操作不可逆，请确认?")))
    {
        Database::Instance()->closeDb();
        bool bOk = QFile::remove(MyApp::m_strDatabasePath + "info.db");
        if (bOk) {
            QString strFile = QFileDialog::getOpenFileName(this, tr("选择还原文件"),
                                                           MyApp::m_strBackupPath,
                                                           tr("备份(*.bak)"));
            if (strFile.isEmpty()) {
                QMessageBox::information(this,"undo", tr("备份文件选择错误，还原终止！"));
                // 加载数据库
                Database::Instance()->openDb(MyApp::m_strDatabasePath + "info.db");
                return;
            }

            bOk = QFile::copy(strFile, MyApp::m_strDatabasePath + "info.db");
            QMessageBox::information(this,"undo", bOk ? tr("数据还原成功！") : tr("数据还原失败！"));
        }
        else
        {
            QMessageBox::information(this, tr("提示"), tr("删除文件错误，还原终止！"));
        }

        // 重新打开数据库
        Database::Instance()->openDb(MyApp::m_strDatabasePath + "info.db");
    }
}


void MainWindow::on_btn_Refresh_clicked()
{
    QJsonArray jsonArry = Database::Instance()->getAllUsers();

    m_model->clear();
    m_model->setColumnCount(5);
    m_model->setRowCount(jsonArry.size());
    m_model->setHorizontalHeaderLabels(QStringList() << "用户" << "姓名" << "密码" << "状态" << "最后登录时间");

    for (int i = 0; i < jsonArry.size(); i++) {
        QJsonObject jsonObj = jsonArry.at(i).toObject();

        m_model->setData(m_model->index(i, 0), jsonObj.value("id").toInt());
        m_model->setData(m_model->index(i, 1), jsonObj.value("name").toString());
        m_model->setData(m_model->index(i, 2), jsonObj.value("passwd").toString());
        int nStatus = jsonObj.value("status").toInt();
        m_model->setData(m_model->index(i, 3), OnLine == nStatus ? tr("在线") : tr("离线"));
        m_model->setData(m_model->index(i, 4), jsonObj.value("lasttime").toString());
    }

    ui->tableViewUsers->setColumnWidth(4, 150);
}


void MainWindow::on_btn_Insert_clicked()
{
    QString strName = ui->lineEditAddUser->text();
    QString strPasswd = ui->lineEditAddPasswd->text();

    if (strName.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("用户名不能为空"));
        return;
    }

    strPasswd = strPasswd.isEmpty() ? "123456" : strPasswd;

    int nId = Database::Instance()->registerUser(strName, strPasswd);

    // 判断
    QMessageBox::information(this, tr("提示"), -1 == nId ? tr("用户添加失败") : tr("用户添加成功！"));
    if (-1 != nId) {
        on_btn_Refresh_clicked();
    }
}

