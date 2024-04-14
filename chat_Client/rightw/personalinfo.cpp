#include "personalinfo.h"
#include "ui_personalinfo.h"

personalInfo::personalInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personalInfo)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowTitle("个人信息");
}

personalInfo::~personalInfo()
{
    delete ui;
}

void personalInfo::setName(QString name)
{
    ui->uNameLab->setText(name);
}

void personalInfo::setId(int id)
{
    QString nid=QString::number(id);
    ui->idLabel->setText("ID号："+nid);
}

void personalInfo::sethead(QString headPath)
{
    QString style=QString("border-image: url(%1);").arg(headPath);
    ui->headBtn->setStyleSheet(style);

}
