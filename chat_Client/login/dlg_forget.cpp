#include "dlg_forget.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "ui_dlg_forget.h"
#include <QMessageBox>
//#include "stusql.h"
#include <QFile>
#include <QJsonObject>

Dlg_forget::Dlg_forget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_forget)
{
    ui->setupUi(this);
    this->setWindowTitle("忘记密码");
    //setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏
    QFile file;
    file.setFileName(":/forget.css");
    file.open(QIODevice::ReadOnly);    //只读,true
    QString strQss=file.readAll();
    setStyleSheet(strQss);

    ui->lb_user->setText("Account Number");

    //设置图片
    QPixmap *pix=new QPixmap(":/register.jpg");
    QSize sz=ui->lb_image->size();
    ui->lb_image->setPixmap(pix->scaled(sz));
}

Dlg_forget::~Dlg_forget()
{
    delete ui;
}

void Dlg_forget::on_btn_forget_sure_clicked()
{
    //输入检测
    QString number=ui->le_user->text();
    QString newPwd=ui->le_newPassword->text();
    QString rePwd=ui->le_Ensure->text();
    if(number.isEmpty()||newPwd.isEmpty()||rePwd.isEmpty())
    {
        QMessageBox::information(this,"Warning","输入有空!\n请重新输入");
        return;
    }
    if(!(newPwd==rePwd))
    {
        QMessageBox::information(this,"Waring","两次密码输入不一致!");
        ui->le_newPassword->clear();
        ui->le_Ensure->clear();
        return;
    }
    //向服务器发送修改密码消息
    QJsonObject json;
    json.insert("id",number.toInt());
    json.insert("oldpwd",newPwd);
    json.insert("newpwd",newPwd);

    qDebug() << "开始找回密码";
    emit signalChangePwd(json);


}


void Dlg_forget::on_btn_forget_cancel_clicked()
{
    //返回主界面
    emit forgetCancel();
    this->hide();
}

void Dlg_forget::sltForgetPwdReply(const QJsonValue &jsonVal)
{
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        int code = json.value("code").toInt();
        QString newpwd = json.value("newpwd").toString();
        if(code == 0){
            qDebug() << "修改密码成功!";
            QMessageBox::information(this,"Sucess","修改成功!");

            ui->lb_newPassword->setText("修改密码成功!");
            ui->lb_newPassword->setStyleSheet("font:50 45pt Bahnschrift Light;color:rgb(29,123,255);");
            ui->lb_newPassword->setFixedSize(400,100);

            ui->le_user->setVisible(false);
            ui->lb_user->setVisible(false);
            ui->lb_Ensure->setVisible(false);
            ui->le_user->setVisible(false);
            ui->le_Ensure->setVisible(false);
            ui->le_newPassword->setVisible(false);


            ui->btn_forget_cancel->setText("返回登陆");
            ui->btn_forget_sure->setVisible(false);
            ui->btn_forget_cancel ->setStyleSheet("background-color:rgb(29,123,255);color:rgb(255,255,255);font:25 16pt Bahnschrift Light;border:0px groove gray;border-radius:9px;");
            connect(ui->btn_forget_sure,&QPushButton::clicked,this,[=]{this->hide();
                emit success();
            });
        }
        else if(code == -2){
            //用户名不存在
            QMessageBox::information(this,"Error","用户名不存在！！！");
            ui->le_newPassword->clear();
            ui->le_Ensure->clear();
            return;

        }
    }
    return;
}

