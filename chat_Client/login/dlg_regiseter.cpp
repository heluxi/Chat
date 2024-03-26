#include "dlg_regiseter.h"
#include "ui_dlg_regiseter.h"
#include <QMessageBox>
//#include "stusql.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonValue>

Dlg_regiseter::Dlg_regiseter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_regiseter)
{
    ui->setupUi(this);

    this->setWindowTitle("注册");
//    ui->cb_auth->hide();
//    ui->label_4->hide();
    ui->label_3->setText("Confirm your password");
    ui->lb_title2->setText("Welcome to Us");

    QFile file;
    file.setFileName(":/register.css");
    file.open(QIODevice::ReadOnly);    //只读,true
    QString strQss=file.readAll();
    setStyleSheet(strQss);

    //设置图片
    QPixmap *pix=new QPixmap(":/register.jpg");
    QSize sz=ui->lb_reg_image->size();
    ui->lb_reg_image->setPixmap(pix->scaled(sz));
    connect(this,&Dlg_regiseter::registerok,this,&Dlg_regiseter::hide);

}

Dlg_regiseter::~Dlg_regiseter()
{
    delete ui;
}

void Dlg_regiseter::on_btn_register_sure_clicked()
{
//    userInfo info;
//    auto ptr=stusql::getinstance();
     //    获取注册界面的数据
    QString username=ui->le_reg_username->text();
    QString password=ui->le_reg_password->text();
    QString rePassword=ui->le_reg_repassword->text();
    if(username.isEmpty()||password.isEmpty()||rePassword.isEmpty())
    {
        QMessageBox::information(this,"注册","输入有空!\n请重新输入");
        return;
    }
//    QString aut=ui->cb_auth->currentText();

    if(password==rePassword){
        //向服务器发送注册消息
        QJsonObject json;
        json.insert("name",username);
        json.insert("pwd",password);
        emit signalRegister(json);

        ui->le_reg_username->clear();
        ui->le_reg_password->clear();


    }

    else{
        QMessageBox::information(this,"Error","两次密码不一致！！！");
  }

}


void Dlg_regiseter::on_btn_reg_cancel_clicked()
{
    //返回主界面
  this->close();
  emit returnPageLogin();
}

void Dlg_regiseter::sltRegisterOK(const QJsonValue &jsonVal)
{
    if(jsonVal.isObject()){
        QJsonObject json = jsonVal.toObject();
        int id = json.value("id").toInt();
        QString pwd = json.value("pwd").toString();
        QString name = json.value("name").toString();

        qDebug() << "注册成功!"
                 << " id:" << id
                 << " name:" << name
                 << " pwd:" << pwd;

//        welcome->setText("注册成功!");
        ui->le_reg_username->setVisible(false);
        ui->le_reg_password->setVisible(false);
        ui->le_reg_repassword->setVisible(false);
        emit registSuccess();
        this->close();

    }
}

