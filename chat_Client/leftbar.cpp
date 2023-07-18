#include "leftbar.h"
#include "ui_leftbar.h"
#include"mybutton.h"
#include<QVBoxLayout>

leftBar::leftBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftBar)
{
    ui->setupUi(this);


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

    connect(btn_weather,&MyButton::clicked,this,[=](){

        WDlg.show();
    });

    btn_chat->onBtnClicked();//默认选中会话列表按钮
}

leftBar::~leftBar()
{
    delete ui;
}
