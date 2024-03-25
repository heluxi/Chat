#include "modifdialog.h"
#include "ui_modifdialog.h"
#include"database.h"
#include<QJsonObject>
#include<QMessageBox>

modifDialog::modifDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifDialog)
{
    ui->setupUi(this);
}

modifDialog::~modifDialog()
{
    delete ui;
}



void modifDialog::on_cancelButton_clicked()
{

    this->close();
}


void modifDialog::on_okButton_clicked()
{
    int id=ui->IDlineEdit->text().toInt();
    QString old=ui->oldPwdlineEdit->text();
    QString newPwd=ui->newPwdlineEdit->text();

    if(ui->IDlineEdit->text().isEmpty()||old.isEmpty()||newPwd.isEmpty())
    {
        QMessageBox::warning(nullptr,"警告","输入有空");
        return;
    }
    QJsonObject obj=Database::Instance()->changePassword(id,old,newPwd);
    int code=obj.value("code").toInt();
    if(code==-2)//用户不存在
    {
        QMessageBox::warning(nullptr,"提示","用户不存在!");
        return;


    }else if(code==-1)//密码不正确
    {
        QMessageBox::warning(nullptr,"提示","密码错误!");
        return;
    }else{
        QMessageBox::information(nullptr,"提示","修改成功!");
        qDebug()<<"code:"<<code;
        emit modifSuccess();
        this->close();
    }
}

