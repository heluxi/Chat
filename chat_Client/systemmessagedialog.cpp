#include "systemmessagedialog.h"
#include "ui_systemmessagedialog.h"

#include <QTimer>
#include <QApplication>
#include <QDesktopServices>
#include <QDebug>
#include <QDateTime>
#include <QMouseEvent>


SystemMessageDialog::SystemMessageDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemMessageDialog)
{
    ui->setupUi(this);
    qDebug()<<"show dialog";

    //    ui->btnClose->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
//    ui->labelMainIcon->setPixmap(QPixmap(":/res/images/cyhc-30.png").scaled(QSize(36, 22)));


}

SystemMessageDialog::~SystemMessageDialog()
{
    delete ui;

}

void SystemMessageDialog::quitSystem()
{


    this->close();
}

void SystemMessageDialog::showMessages(const QString &text, const QString &title)
{
//    if (text.isEmpty()) return;
//    QString dateTime = QDateTime::currentDateTime().toString("yyyy年MM月dd日 ddd hh:ss");

//    ui->labelDateTime->setText(QString("今天是: %1").arg(dateTime));
//    ui->labelContent->setText(text);

//    if (!title.isEmpty()) {
//        ui->labelTitle->setText(title);
//    }

//    this->showNormal();




}
