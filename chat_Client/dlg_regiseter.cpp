#include "dlg_regiseter.h"
#include "ui_dlg_regiseter.h"
#include <QMessageBox>
//#include "stusql.h"
#include <QFile>

Dlg_regiseter::Dlg_regiseter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_regiseter)
{
    ui->setupUi(this);

    QFile file;
    file.setFileName(":/register.css");
    file.open(QIODevice::ReadOnly);    //只读,true
    QString strQss=file.readAll();
    setStyleSheet(strQss);

    //设置图片
    QPixmap *pix=new QPixmap(":/register.jpg");
    QSize sz=ui->lb_reg_image->size();
    ui->lb_reg_image->setPixmap(pix->scaled(sz));

}

Dlg_regiseter::~Dlg_regiseter()
{
    delete ui;
}

void Dlg_regiseter::on_btn_register_sure_clicked()
{
//    userInfo info;
//    auto ptr=stusql::getinstance();
//     //    获取注册界面的数据
//    QString username=ui->le_reg_username->text();
//    QString password=ui->le_reg_password->text();
//    QString rePassword=ui->le_reg_repassword->text();
//    QString aut=ui->cb_auth->currentText();

//    if(password==rePassword){
//        if(ptr->user_isExit(username)){
//            QMessageBox::information(this,"注册","该用户已经注册过");
//            this->hide();
//        }
//        else{
//            //数据库添加用户名和密码
//            info.username=username;
//            info.password=password;
//            info.aut=aut;
//            bool is_Exit=ptr->addUser(info);
//            if(is_Exit){
//                 //成功注册
//                QMessageBox::information(this,"注册","注册成功！！！");
//                this->hide();
//            }
//            else{
//                //失败就提示
//                QMessageBox::information(this,"注册","注册失败！！！");
//            }
//        }
//    }
//    else{
//        QMessageBox::information(this,"Error","两次密码不一致！！！");
//    }
}


void Dlg_regiseter::on_btn_reg_cancel_clicked()
{
    //返回主界面
    this->hide();
}

