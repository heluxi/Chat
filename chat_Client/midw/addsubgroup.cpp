#include "addsubgroup.h"
#include "ui_addsubgroup.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QSqlQuery>
#include "sql_manage.h"

AddSubGroup::AddSubGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSubGroup)
{
    ui->setupUi(this);
}

AddSubGroup::~AddSubGroup()
{
    delete ui;
}

void AddSubGroup::on_btn_ok_clicked()
{
    QString text = ui->le_name->text();
    if(text.size() > 20){
        QMessageBox::information(this,"error","分组名不能多于20个字符!");
        return;
    }else {
        QJsonArray jsonArray = sql_manage::Instance()->getMySubgroup();
        int cnt = jsonArray.size();
        for(int i = 0;i < cnt;i++){
            QJsonObject json = jsonArray.at(i).toObject();
            QString name = json.value("name").toString();
            if(text == name){
                QMessageBox::information(this,"error","分组中已存在该分组名!");
                return;
            }
        }

        QSqlQuery query;
        QString sql = "insert into mySubgroup values('" + text + "','" +
                      QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm:ss") + "')";
        query.exec(sql);

        emit updateList(text);

        this->close();
    }
}


void AddSubGroup::on_btn_cancel_clicked()
{
    this->close();
}

