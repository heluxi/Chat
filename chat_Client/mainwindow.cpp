#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chatlist.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    login.show();

    connect(&login,&Page_login::sendLoginSuccess,this,[=](){
        this->show();
    });

    m_tcp=new tcp_manage(this);

    //聊天信息列表
    chatList *list1=new chatList();
    QListWidgetItem *item1=new QListWidgetItem();
    item1->setSizeHint(QSize(320,60));
    ui->listWidget->addItem(item1);
    ui->listWidget->setItemWidget(item1,list1);

    connect(m_tcp,&tcp_manage::recvFormServre,this,[=](QByteArray data){
        ui->textBrowser->append(data);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_sendBut_clicked()
{
   QString msg= ui->textEdit->toPlainText();
   m_tcp->sendMsg(msg);
   ui->textEdit->clear();
}

