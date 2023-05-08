#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chatlist.h"
#include<QFileInfo>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileInfo=nullptr;

    login.show();

    connect(&login,&Page_login::sendLoginSuccess,this,[=](){
        this->show();
    });

    m_tcp=new clientSock(this);
    m_fileTcp=new clientFileSock(this);

    //聊天信息列表
    chatList *list1=new chatList();
    QListWidgetItem *item1=new QListWidgetItem();
    item1->setSizeHint(QSize(320,60));
    ui->listWidget->addItem(item1);
    ui->listWidget->setItemWidget(item1,list1);

    connect(m_tcp,&clientSock::recvFormServre,this,[=](QString data){
        QDateTime time=QDateTime::currentDateTime();

        QString showData=data+"\t"+time.toString("yyyy-MM-dd hh:mm:ss");
        ui->textBrowser->append(showData);
    });

    connect(m_fileTcp,&clientFileSock::sendFileSucess,[=]()
    {

        ui->textEdit->clear();
    });
    connect(m_fileTcp,&clientFileSock::sucessRecvfile,[=](QString data){
        QDateTime time=QDateTime::currentDateTime();

        QString showData=data+"\t"+time.toString("yyyy-MM-dd hh:mm:ss");
        ui->textBrowser->append(showData);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_sendBut_clicked()
{
   QString msg= ui->textEdit->toPlainText();
   if(msg.isEmpty())
   {
    QMessageBox::warning(this,"warning","输入有空");

   }
   else
   {
       //判断是发送文件还是文字

       if(fileInfo!=nullptr)
       {
           qDebug()<<"sendfile";
            m_fileTcp->sendFile(fileName);
            delete fileInfo;
            fileInfo=nullptr;
            QDateTime time=QDateTime::currentDateTime();
            QString showData=fileName+"\t"+time.toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->append(showData);

       }
       else
       {
            qDebug()<<"sendmsg";
            m_tcp->sendMsg(msg);
            ui->textEdit->clear();
       }

   }
}


void MainWindow::on_fileButton_clicked()
{

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    fileName=dialog.getOpenFileName(this,"选择要发送文件");
    qDebug()<<"fileName"<<fileName;
    fileInfo=new QFileInfo(fileName);
    ui->textEdit->setText(fileInfo->fileName());
}

