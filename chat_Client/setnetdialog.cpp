#include "setnetdialog.h"
#include "ui_setnetdialog.h"
#include<QMessageBox>
#include<tcp_manage.h>

setnetDialog::setnetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setnetDialog)
{
    ui->setupUi(this);
}

setnetDialog::~setnetDialog()
{
    delete ui;
}

void setnetDialog::on_okButton_clicked()
{
    if(!ui->portLineEdit->text().isEmpty())
    {
        m_tcp=new clientSock(this);
        file_sock=new clientFileSock(this);

        int port=ui->portLineEdit->text().toUShort();
        QString ip=ui->ipcomboBox->currentText();
        int  filePort=ui->filePortEdit->text().toUShort();
        m_tcp->connectServer(ip,port);
        file_sock->connectServer(ip,filePort);

        connect(m_tcp,&clientSock::connectSucess,this,[=](){
            this->hide();
        });
    }
    else
    {
        QMessageBox::warning(this,"warning","输入有空请重新输入！",QMessageBox::Ok);
    }
}


void setnetDialog::on_cancelButton_clicked()
{
    this->hide();
}

