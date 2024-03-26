#include "leftbar.h"
#include "ui_leftbar.h"
#include"mybutton.h"
#include"personmsgdlg.h"
#include"myapp.h"
#include<QVBoxLayout>
#include<QFileInfo>
#include"headedit.h"
#include"myHelper.h"
#include"type.h"
leftBar::leftBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftBar)
{
    ui->setupUi(this);
    //QString headPath = "image:url(:"+MyApp::m_strHeadPath + MyApp::m_strHeadFile+");";
    //qDebug()<<headPath;
    //ui->headBtn->setStyleSheet(headPath);
    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    qDebug()<<headPath<<"....\n";
//    //头像不存在就是默认头像
//    QFileInfo fileInfo(headPath);
//    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty()){
//        MyApp::m_strHeadFile = "default.png";
//        headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
//    }

    QString head=QString("border-image: url(%1);"
                           "background-color: rgb(255, 255, 255);border-radius:30px;").arg(headPath);
    ui->headBtn->setStyleSheet(head);







    QStringList tmp;
    tmp << ":/res/pic/Chat.png"
        << ":/Icons/MainWindow/chat2.png"
        << ":/res/pic/Chat.png";

    btn_chat=new MyButton(nullptr,tmp,QSize(63,41));
    tmp.clear();
    tmp << ":/res/pic/\347\224\250\346\210\267.png"
        << ":/Icons/MainWindow/chat2.png"
        << ":/res/pic/\347\224\250\346\210\267.png";
    btn_contact = new MyButton(nullptr,tmp,QSize(63,41));


    tmp.clear();
    tmp << ":/res/pic/3.1 \350\256\276\347\275\256.png"
        << ":/Icons/MainWindow/chat2.png"
        << ":/res/pic/3.1 \350\256\276\347\275\256.png";
    btn_settings = new MyButton(nullptr,tmp,QSize(63,41));

    tmp.clear();
    tmp << ":/天气.svg"
        << ":/天气.svg"
        << ":/天气.svg";
    btn_weather=new MyButton(nullptr,tmp,QSize(63,41));





    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(btn_chat);
    layout->addStretch();
    layout->addWidget(btn_contact);
    layout->addStretch();
    layout->addWidget(btn_weather);
    layout->addStretch();
    layout->addWidget(btn_settings);

    ui->widget->setLayout(layout);


    m_btnGroup = new QButtonGroup(this);
    m_btnGroup->setExclusive(true);
    m_btnGroup->addButton(btn_chat, 0);
    m_btnGroup->addButton(btn_contact, 1);
    m_btnGroup->addButton(btn_settings, 2);

    connect(btn_settings,&QPushButton::clicked,this,[=](){

        sysSet.show();

    });

    connect(&sysSet,&SystemSetting::changeBackgroundColor,this,&leftBar::changeBackgroundColor);
    connect(&sysSet,&SystemSetting::changeleftBuble,this,&leftBar::changeleftBuble);
    connect(&sysSet,&SystemSetting::changerightBuble,this,&leftBar::changerightBuble);

    connect(btn_weather,&MyButton::clicked,this,[=](){

        WDlg.show();
    });

    btn_chat->onBtnClicked();//默认选中会话列表按钮
}

leftBar::~leftBar()
{
    delete ui;
}

void leftBar::on_headBtn_clicked()
{
    //显示当前用户个人信息

    pMsgDlg=new personMsgDlg(this);
    pMsgDlg->show();
    pMsgDlg->move(30,30);
    connect(pMsgDlg,&personMsgDlg::chanageHead,this,&leftBar::sltheadChange);


}

void leftBar::sltheadChange(QString headPath)
{
    //更新当前组件的头像
    QString head=QString("border-image: url(%1);").arg(headPath);
    ui->headBtn->setStyleSheet(head);

    QFileInfo info(headPath);
    QString fileName=info.fileName();

    QFile souceFile(headPath);
    QFile targetFile(MyApp::m_strHeadPath+MyApp::m_strHeadFile);

    if(!souceFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"souce文件打开失败";
    }
    if(!targetFile.open(QIODevice::WriteOnly))
    {
        qDebug()<<"target 文件打开失败";
    }
    QDataStream in(&souceFile);
    QDataStream out(&targetFile);
    out.setVersion(QDataStream::Qt_6_4);
    while(!in.atEnd())
    {
        QByteArray data=souceFile.read(1024);
        out.writeRawData(data.constData(),data.size());
    }
    souceFile.close();
    souceFile.close();


    //通知服务器更新头像
    emit UpdateHeadPic();

//    myHelper::Sleep(1000);
    headedit.show();


}

