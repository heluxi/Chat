#include "setnetdialog.h"
#include "ui_setnetdialog.h"
#include<QMessageBox>
#include<tcp_manage.h>
#include "myapp.h"

setnetDialog::setnetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setnetDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("border-radius:10px;background-color: rgb(244, 244, 244);");
    setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏
    this->setFixedSize(600,400);
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::black);

    ui->label_2->setPalette(palette);
    ui->label->setPalette(palette);
    ui->label_3->setPalette(palette);
    ui->label_4->setPalette(palette);
    ui->label_5->setPalette(palette);

    ui->portLineEdit->setStyleSheet("border-radius:15px;border:2px solid black ");
    ui->filePortEdit->setStyleSheet("border-radius:15px;border:2px solid black ");
    ui->cancelButton->setStyleSheet("border-radius:15px; background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994 rgba(64,145,252,255),stop:1 rgba(255,255,255,255));color: rgb(91, 156, 200);");
    ui->okButton->setStyleSheet("border-radius:15px; background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994 rgba(64,145,252,255),stop:1 rgba(255,255,255,255));color: rgb(91, 156, 200);");
    ui->ipcomboBox->setStyleSheet("border-radius:15px;border:2px solid black ");
    ui->okButton->setFixedSize(120,40);
    ui->cancelButton->setFixedSize(120,40);
    ui->label_5->setStyleSheet("image: url(:/网络设置.svg);");

    //方正魏碑_GBK
    QFont font( "TSCu_Times", 20, QFont::Normal);
    QFont font_headline( "TSCu_Times",35, QFont::Normal);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font_headline);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    ui->label->setStyleSheet("color: rgb(91, 156, 200);");
    ui->label_2->setStyleSheet("color: rgb(91, 156, 200);");
    ui->label_3->setStyleSheet("color: rgb(91, 156, 200);");
    ui->label_4->setStyleSheet("color: rgb(91, 156, 200);");
    ui->label_5->setStyleSheet("color: rgb(91, 156, 200);");

    connect(ui->cancelButton,&QPushButton::clicked,this,&setnetDialog::rotateWindow);
}

setnetDialog::~setnetDialog()
{
    delete ui;
}

void setnetDialog::on_okButton_clicked()
{
    if(!ui->portLineEdit->text().isEmpty())
    {
//        m_tcp=new clientSock(this);
//        file_sock=new clientFileSock(this);

        int port=ui->portLineEdit->text().toUShort();
        QString ip=ui->ipcomboBox->currentText();
        int  filePort=ui->filePortEdit->text().toUShort();
//        m_tcp->connectServer(ip,port);
//        file_sock->connectServer(ip,filePort);
        emit sendPortandAdd(port,ip,filePort);
//        connect(m_tcp,&clientSock::connectSucess,this,[=](){
//            this->hide();
//        });
        MyApp::m_strHostAddr = ip;
        MyApp::m_nMsgPort = port;
        MyApp::m_nFilePort = filePort;
    }
    else
    {
        QMessageBox::warning(this,"warning","输入有空请重新输入！",QMessageBox::Ok);
    }

    emit rotateWindow();
    emit setNetwork();
}


void setnetDialog::on_cancelButton_clicked()
{
    emit rotateWindow();
    this->hide();
}

