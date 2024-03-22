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

    QFont font = QFont("Microsoft YaHei", 22, 50, false);
    QFont font2 = QFont("Microsoft YaHei", 12, 48, false);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("查找");
    this->setFixedSize(600,400);
    this->setStyleSheet("");

    //关闭按钮
    m_menuCloseBtn = new QPushButton(this);
    m_menuCloseBtn->setFlat(true);
    m_menuCloseBtn->setFixedSize(30, 32);
    m_menuCloseBtn->move(570, 0);
    m_menuCloseBtn->setStyleSheet("QPushButton{ border-image: url(:/res/menu_btn/close_normal.png); }"
                                  "QPushButton:hover:!pressed{ border-image: url(:/res/menu_btn/close_hover); }"
                                  "QPushButton:hover:pressed{ border-image: url(:/res/menu_btn/close_press); border-style:none; }");
    connect(m_menuCloseBtn, &QPushButton::pressed, this, &FindFriendWnd::close);

    //缩放按钮
    m_menuMinBtn = new QPushButton(this);
    m_menuMinBtn->setFlat(true);
    m_menuMinBtn->setFixedSize(30, 32);
    m_menuMinBtn->move(540, 0);
    m_menuMinBtn->setStyleSheet("QPushButton{ border-image: url(:/res/menu_btn/min_normal); }"
                                "QPushButton:hover:!pressed{ border-image: url(:/res/menu_btn/min_hover); }"
                                "QPushButton:hover:pressed{ border-image: url(:/res/menu_btn/min_press); border-style:none; }");
    connect(m_menuMinBtn, &QPushButton::pressed, this, &FindFriendWnd::showMinimized);


    ui->widget_2->move(13,20);
    ui->addBtn->move(465,210);
    ui->searchBut->move(465,15);
    ui->lineEdit->setStyleSheet("background:transparent;color:white;border:1px solid white;border-style:outset");
    ui->addBtn->setStyleSheet("QPushButton{border:1px solid #86949e;background-color:#f4f4f4;border-radius:3px}"
                              "QPushButton:hover{background-color:#bee7fd;}"
                              "QPushButton:pressed{background-color:#f4f4f4}");
    ui->searchBut->setStyleSheet("QPushButton{border:1px solid #86949e;background-color:#f4f4f4;border-radius:3px}"
                                 "QPushButton:hover{background-color:#bee7fd;}"
                                 "QPushButton:pressed{background-color:#f4f4f4}");
    ui->addBtn->setFont(font2);
    ui->searchBut->setFont(font2);

    if(tag == 0)
        ui->label->setText("找好友");
    else if(tag == 1)
        ui->label->setText("找群");
    ui->headLabel->clear();
    ui->idLabel->clear();
    ui->resultLabel->clear();
    ui->nameLabel->clear();
    ui->idLabel->setFixedWidth(100);
    ui->nameLabel->setFixedWidth(200);
    ui->headLabel->setFixedSize(100,100);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/backgroud3.jpg").
                                              scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));// 使用平滑的缩放方式
    this->setPalette(palette);// 给widget加上背景图
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
//        bool flag = sql_manage::Instance()->isInGroup(friendID);
//        if(flag){
//            QMessageBox::information(this,"错误","您已经加入该群了");
//        }else{
//            msgLabel->setVisible(true);
            ui->addBtn->setVisible(false);
            emit signalSendMessage(AddGroup, json);
//        }
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
                                head = ":/res/Icons/MainWindow/contact3_.png";//没有收到则显示默认头像
                            }else{
                                head = headPath;
                            }
                        }else{
                            head = MyApp::m_strHeadPath + head;
                        }

            ui->resultLabel->setText("查询到下列信息");
            ui->resultLabel->setVisible(true);
            ui->idLabel->setText("ID:"+QString::number(id));
            ui->idLabel->setVisible(true);
            ui->nameLabel->setText("Name:"+name);
            ui->nameLabel->setVisible(true);
            qDebug() << "head path:" << head;
            QPixmap p=head;
            ui->headLabel->setFixedSize(110,100);
            ui->headLabel->move(15,140);
            ui->headLabel->setPixmap(p);
            ui->headLabel->setScaledContents(true);
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

