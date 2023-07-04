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
    this->setStyleSheet("border-radius:10px;");
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);
    ui->label_2->setPalette(palette);
    ui->label->setPalette(palette);
    ui->label_3->setPalette(palette);
    ui->label_4->setPalette(palette);
    ui->label_5->setPalette(palette);
    ui->portLineEdit->setStyleSheet("border-radius:15px;");
    ui->filePortEdit->setStyleSheet("border-radius:15px;");
    //方正魏碑_GBK
    QFont font( "TSCu_Times", 19, QFont::Normal);
    QFont font_headline( "TSCu_Times", 30, QFont::Normal);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font_headline);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
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

