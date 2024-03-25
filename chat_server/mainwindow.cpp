#include "mainwindow.h"
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
#include"iconhelper.h"
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


//    //隐藏表头
//    ui->treeWidget->setHeaderHidden(true);



//    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);

    ui->stackedWidgetMain->setCurrentIndex(0);//设置当前显示界面为登陆界面

    m_model = new QStandardItemModel(this); //保存数据

    ui->tableViewUsers->setModel(m_model);  //显示数据

    // 设置几张表格的属性不可编辑
    ui->tableViewUsers->setEditTriggers(QTableView::NoEditTriggers);
    // 设置几张表格的属性选择整行
    ui->tableViewUsers->setSelectionBehavior(QTableView::SelectRows);
    connect(ui->tableViewUsers, SIGNAL(clicked(QModelIndex)), this, SLOT(SltTableClicked(QModelIndex)));

    ui->lineEditBackup->setText(MyApp::m_strBackupPath);//配置目录

    // 初始化网络
    InitNetwork();

    //tool
    QStatusBar *bar=this->statusBar();


    modifDlg=new modifDialog(this);

// 显示系统时间
    lb_time=new QLabel(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss ddd"));
    bar->addWidget(lb_time);        //left
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        QDateTime time = QDateTime::currentDateTime();
        QString text = time.toString("yyyy-MM-dd hh:mm:ss");
        lb_time->setText(text);
    });
    timer->start(1000); // 每秒更新一次

    m_nTimerId = startTimer(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


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

//初始化导航栏菜单
void MainWindow::initButtons()
{
        //设置弱属性以便应用样式
        ui->widget_8->setProperty("flag", "left");

        IconHelper::StyleColor styleColor;
        styleColor.defaultBorder = true;
        styleColor.position = "left";
        styleColor.iconSize = 25;
        styleColor.iconWidth = 25;
        styleColor.iconHeight = 25;
        styleColor.borderWidth = 3;
        styleColor.borderColor = "#A279C5";
        styleColor.setColor("#292929", "#B6D7E3", "#10689A", "#F0F0F0");
        QString position = styleColor.position;
        quint32 btnWidth = styleColor.btnWidth;
        quint32 btnHeight = styleColor.btnHeight;
        quint32 borderWidth = styleColor.borderWidth;

        //根据不同的位置计算边框
        QString strBorder;
        if (position == "top") {
            strBorder = QString("border-width:%1px 0px 0px 0px;padding-top:%1px;padding-bottom:%2px;")
                            .arg(borderWidth).arg(borderWidth * 2);
        } else if (position == "right") {
            strBorder = QString("border-width:0px %1px 0px 0px;padding-right:%1px;padding-left:%2px;")
                            .arg(borderWidth).arg(borderWidth * 2);
        } else if (position == "bottom") {
            strBorder = QString("border-width:0px 0px %1px 0px;padding-bottom:%1px;padding-top:%2px;")
                            .arg(borderWidth).arg(borderWidth * 2);
        } else if (position == "left") {
            strBorder = QString("border-width:0px 0px 0px %1px;padding-left:%1px;padding-right:%2px;")
                            .arg(borderWidth).arg(borderWidth * 2);
        }

        //如果图标是左侧显示则需要让没有选中的按钮左侧也有加深的边框,颜色为背景颜色
        //如果图标在文字上面而设置的边框是 top bottom 也需要启用加深边框
        QStringList qss;
        if (styleColor.defaultBorder) {
            qss << QString("QWidget[flag=\"%1\"] QAbstractButton{border-style:solid;border-radius:0px;%2border-color:%3;color:%4;background:%5;}")
                       .arg(position).arg(strBorder).arg(styleColor.normalBgColor).arg(styleColor.normalTextColor).arg(styleColor.normalBgColor);
        } else {
            qss << QString("QWidget[flag=\"%1\"] QAbstractButton{border-style:none;border-radius:0px;padding:5px;color:%2;background:%3;}")
                       .arg(position).arg(styleColor.normalTextColor).arg(styleColor.normalBgColor);
        }

        //悬停+按下+选中
        qss << QString("QWidget[flag=\"%1\"] QAbstractButton:hover{border-style:solid;%2border-color:%3;color:%4;background:%5;}")
                   .arg(position).arg(strBorder).arg(styleColor.borderColor).arg(styleColor.hoverTextColor).arg(styleColor.hoverBgColor);
        qss << QString("QWidget[flag=\"%1\"] QAbstractButton:pressed{border-style:solid;%2border-color:%3;color:%4;background:%5;}")
                   .arg(position).arg(strBorder).arg(styleColor.borderColor).arg(styleColor.pressedTextColor).arg(styleColor.pressedBgColor);
        qss << QString("QWidget[flag=\"%1\"] QAbstractButton:checked{border-style:solid;%2border-color:%3;color:%4;background:%5;}")
                   .arg(position).arg(strBorder).arg(styleColor.borderColor).arg(styleColor.checkedTextColor).arg(styleColor.checkedBgColor);

        //窗体背景颜色+按钮背景颜色
        qss << QString("QWidget#%1{background:%2;}")
                   .arg(ui->widget_8->objectName()).arg(styleColor.normalBgColor);
        qss << QString("QWidget>QAbstractButton{border-width:0px;background-color:%1;color:%2;}")
                   .arg(styleColor.normalBgColor).arg(styleColor.normalTextColor);
        qss << QString("QWidget>QAbstractButton:hover{background-color:%1;color:%2;}")
                   .arg(styleColor.hoverBgColor).arg(styleColor.hoverTextColor);
        qss << QString("QWidget>QAbstractButton:pressed{background-color:%1;color:%2;}")
                   .arg(styleColor.pressedBgColor).arg(styleColor.pressedTextColor);
        qss << QString("QWidget>QAbstractButton:checked{background-color:%1;color:%2;}")
                   .arg(styleColor.checkedBgColor).arg(styleColor.checkedTextColor);

        //按钮宽度高度
        if (btnWidth > 0) {
            qss << QString("QWidget>QAbstractButton{min-width:%1px;}").arg(btnWidth);
        }
        if (btnHeight > 0) {
            qss << QString("QWidget>QAbstractButton{min-height:%1px;}").arg(btnHeight);
        }

        //设置样式表
        ui->widget_8->setStyleSheet(qss.join(""));


        //默认选中某个按钮
        ui->searchBtn->click();
}

void MainWindow::initBtn(QButtonGroup *btnGroup, bool textBesideIcon)
{
        QList<QAbstractButton *> btns = btnGroup->buttons();
        foreach (QAbstractButton *btn, btns) {
            QToolButton *b = (QToolButton *)btn;
            //关联按钮单击事件
            connect(b, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
            b->setCheckable(true);
            b->setToolButtonStyle(textBesideIcon ? Qt::ToolButtonTextBesideIcon : Qt::ToolButtonTextUnderIcon);
        }
}


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
    initButtons();
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

//备份数据库
void MainWindow::on_btn_backUp_clicked()
{

    QString strNewFile = MyApp::m_strBackupPath + QString("info_%1.bak").arg(QDate::currentDate().toString("yyyy_MM_dd"));
    if (QFile::exists(strNewFile)) {
        QFile::remove(strNewFile);
    }
    bool bOk = QFile::copy(MyApp::m_strDatabasePath + "server.db", strNewFile);
    QMessageBox::information(this,"backup", bOk ? tr("数据备份成功") : tr("数据备份失败"));
}

//备份还原

void MainWindow::on_btn_backUndo_clicked()
{
    if (QMessageBox::Accepted == QMessageBox::question(this,"Undo", tr("是否还原数据库，该操作不可逆，请确认?")))
    {
        Database::Instance()->closeDb();
        bool bOk = QFile::remove(MyApp::m_strDatabasePath + "server.db");
        if (bOk) {
            QString strFile = QFileDialog::getOpenFileName(this, tr("选择还原文件"),
                                                           MyApp::m_strBackupPath,
                                                           tr("备份(*.bak)"));
            if (strFile.isEmpty()) {
                QMessageBox::information(this,"undo", tr("备份文件选择错误，还原终止！"));
                // 加载数据库
                Database::Instance()->openDb(MyApp::m_strDatabasePath + "server.db");
                return;
            }

            bOk = QFile::copy(strFile, MyApp::m_strDatabasePath + "server.db");
            QMessageBox::information(this,"undo", bOk ? tr("数据还原成功！") : tr("数据还原失败！"));
        }
        else
        {
            QMessageBox::information(this, tr("提示"), tr("删除文件错误，还原终止！"));
        }

        // 重新打开数据库
        Database::Instance()->openDb(MyApp::m_strDatabasePath + "server.db");
    }
}

//用户管理
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
        ui->lineEditAddPasswd->clear();
        ui->lineEditPasswd->clear();
    }
}


void MainWindow::on_btn_delete_clicked()
{

    int id=ui->lineEditID->text().toInt();
    int code=Database::Instance()->deleteUsers(id);
    if(code==-1)
    {
        QMessageBox::warning(nullptr,"提示","用户不存在!");

        return;
    }else{
        QMessageBox::information(nullptr,"提示","删除成功!");
        ui->lineEditAddPasswd->clear();
        ui->lineEditPasswd->clear();
        ui->lineEditID->clear();
        return;
    }

}


void MainWindow::on_btn_modif_clicked()
{

    modifDlg->show();


}

void MainWindow::btnClicked()
{

}


void MainWindow::on_pushButton_clicked()
{
    int id=ui->idslineEdit->text().toInt();
    QJsonObject obj=Database::Instance()->getUserInfo(id);
    if(obj.value("code").toInt()==-1)
    {
        ui->msgLable->setText("未查找到该用户!\n用户可能不存在!\n");
    }else{

        QString name=obj.value("name").toString();
        int status=obj.value("status").toInt();
        QString sta=(OnLine==status?"在线":"离线");
        ui->msgLable->setText("Name:"+name+"\n"+"ID:"+QString::number(id)+"\n"+"状态:"+sta);
    }

}


void MainWindow::on_serverBtn_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void MainWindow::on_searchBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void MainWindow::on_dataBtn_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_5);
}


void MainWindow::on_manageBtn_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_3);
     on_btn_Refresh_clicked();
}


void MainWindow::on_userBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
     m_model2 = new QStandardItemModel(this); //保存数据

     ui->tableView->setModel(m_model2);  //显示数据

     // 设置几张表格的属性不可编辑
     ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
     // 设置几张表格的属性选择整行
     ui->tableView->setSelectionBehavior(QTableView::SelectRows);
     QJsonArray jsonArry = Database::Instance()->getGroupALlInfo();

     m_model2->clear();
     m_model2->setColumnCount(5);
     m_model2->setRowCount(jsonArry.size());
     m_model2->setHorizontalHeaderLabels(QStringList() << "群号" << "群名" << "群主ID" << "群成员" << "创建时间");

     for (int i = 0; i < jsonArry.size(); i++) {
        QJsonObject jsonObj = jsonArry.at(i).toObject();

        m_model2->setData(m_model2->index(i, 0), jsonObj.value("id").toInt());
        m_model2->setData(m_model2->index(i, 1), jsonObj.value("name").toString());
        m_model2->setData(m_model2->index(i, 2), jsonObj.value("adminID").toInt());
        m_model2->setData(m_model2->index(i, 3), jsonObj.value("memberCnt").toInt());
        m_model2->setData(m_model2->index(i, 4), jsonObj.value("createTime").toString());
     }

     ui->tableView->setColumnWidth(4, 150);
}


void MainWindow::on_toolButton_triggered(QAction *arg1)
{
    QString directory = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Open Directory"),
                                                          QDir::homePath());

    if (!directory.isEmpty()) {
        // 用户选择了一个目录，directory 变量包含了目录路径
        // 在这里处理目录
        ui->lineEditBackup->setText(directory);
    }
}


void MainWindow::on_toolButton_clicked()
{

    QString directory = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Open Directory"),
                                                          QDir::homePath());

    if (!directory.isEmpty()) {
        // 用户选择了一个目录，directory 变量包含了目录路径
        // 在这里处理目录
        ui->lineEditBackup->setText(directory);
    }
}

