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

void Dlg_forget::sltForgetPwdReply(const QJsonValue &jsonVal)
{
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        int code = json.value("code").toInt();
        QString newpwd = json.value("newpwd").toString();
        if(code == 0){
            qDebug() << "修改密码成功!";
            ui->le_user->setVisible(false);
            ui->le_newPassword->setVisible(false);
            ui->le_Ensure->setVisible(false);


            disconnect(ui->btn_forget_sure,SIGNAL(clicked(bool)),this,SLOT(sltOKBtnClicked()));
            ui->btn_forget_sure->setText("返回登陆");
            connect(ui->btn_forget_sure,&QPushButton::clicked,this,[=]{this->hide();});
        }else if(code == -1){
            //原密码不正确
            QMessageBox::information(this,"forget","用户名不存在！！！");
//            this->setFixedSize(430,350);
//            m_notifyMsg->move(0,330);
//            m_notifyMsg->setText("该账户原密码错误!");
//            m_notifyMsg->show();
        }else if(code == -2){
            //用户名不存在
            QMessageBox::information(this,"forget","用户名不存在！！！");
//            this->setFixedSize(430,350);
//            m_notifyMsg->move(0,330);
//            m_notifyMsg->setText("该账户不存在!");
//            m_notifyMsg->show();
        }
    }
}

