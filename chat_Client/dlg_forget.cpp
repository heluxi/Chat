#include "dlg_forget.h"
#include "ui_dlg_forget.h"
#include <QMessageBox>
//#include "stusql.h"
#include <QFile>

Dlg_forget::Dlg_forget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_forget)
{
    ui->setupUi(this);

    QFile file;
    file.setFileName(":/forget.css");
    file.open(QIODevice::ReadOnly);    //只读,true
    QString strQss=file.readAll();
    setStyleSheet(strQss);

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
//    userInfo info;
//    auto ptr=stusql::getinstance();

//    QString username=ui->le_user->text();
//    QString newPassword=ui->le_newPassword->text();
//    QString rePassword=ui->le_Ensure->text();

//    if(newPassword==rePassword){
//        info.username=username;
//        info.password=newPassword;
//        bool success=ptr->updateUser(info);
//        if(success){
//             //成功修改
//            QMessageBox::information(this,"修改","修改成功！！！");
//            this->hide();
//        }
//        else{
//            //失败就提示
//            QMessageBox::information(this,"修改","修改失败！！！");
//        }
//    }
}


void Dlg_forget::on_btn_forget_cancel_clicked()
{
    //返回主界面
    this->hide();
}

