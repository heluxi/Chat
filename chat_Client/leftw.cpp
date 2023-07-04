#include "leftw.h"
#include "ui_leftw.h"


leftw::leftw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftw)
{
    ui->setupUi(this);

    button=new QPushButton();
    button->setStyleSheet("QPushButton { border-image: url(:/icons/weather_icons/duoyun.png); }");
    button->setMinimumSize(50,45);

    favoritButton=new QPushButton();
    favoritButton->setMinimumSize(40,40);
//    favoritButton->setStyleSheet("QPushButton {border-image: url(:/res/pic/control_11.jpg);}");

    phoneButton=new QPushButton();
    phoneButton->setMinimumSize(40,300);
//    phoneButton->setStyleSheet("QPushButton { border-image: url(:/res/pic/control_09.jpg); }");

    fileButton=new QPushButton();
    fileButton->setMinimumSize(40,40);
//    fileButton->setStyleSheet("QPushButton { border-image: url(:/res/pic/文件夹.png); }");



    QVBoxLayout *layout = new QVBoxLayout(this); // 创建垂直布局

    layout->addWidget(button); // 将按钮添加到布局中
    layout->addWidget(favoritButton);


    layout->addWidget(ui->widget_4);

    layout->addWidget(fileButton);
    layout->addWidget(phoneButton);

    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    connect(button,&QPushButton::clicked,this,[=](){WDlg.show();});
//    QStringList tmp;
//    tmp << ":/res/pic/Chat.png"
//        << ":/Icons/MainWindow/chat2.png"
//        << ":/res/pic/Chat.png";
//    ui->btn_chat = new MyButton(nullptr,tmp,QSize(63,41));
//    qDebug()<<"errorrr1";

//    tmp.clear();
//    tmp << ":/res/pic/\347\224\250\346\210\267.png"
//        << ":/Icons/MainWindow/chat2.png"
//        << ":/res/pic/\347\224\250\346\210\267.png";
//    ui->btn_contact = new MyButton(nullptr,tmp,QSize(63,41));

//    tmp.clear();
//    tmp << ":/res/pic/3.1 \350\256\276\347\275\256.png"
//        << ":/Icons/MainWindow/chat2.png"
//        << ":/res/pic/3.1 \350\256\276\347\275\256.png";
//    ui->btn_settings = new MyButton(nullptr,tmp,QSize(63,41));
//    button=new QPushButton();
//    button->setFixedSize(40,40);


    m_btnGroup = new QButtonGroup(this);
    m_btnGroup->setExclusive(true);
    m_btnGroup->addButton(ui->btn_chat, 0);
    m_btnGroup->addButton(ui->btn_contact, 1);
    m_btnGroup->addButton(ui->btn_settings, 2);


    ui->btn_chat->onBtnClicked();//默认选中会话列表按钮

//    QPalette palette;
//    palette.setColor(QPalette::Window, QColor(40, 41, 45));//110, 123, 139
//    setAutoFillBackground(true);  //一定要这句，否则不行
//    setPalette(palette);

//    setFocusPolicy(Qt::StrongFocus);

}

leftw::~leftw()
{
    delete ui;
}



void leftw::on_weatherButton_clicked()
{

}

