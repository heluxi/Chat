#include "personmsgdlg.h"
#include "ui_personmsgdlg.h"
#include"myapp.h"

personMsgDlg::personMsgDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personMsgDlg)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowTitle("个人信息");

    QString userName=MyApp::m_strUserName;
    ui->uNameLab->setText(userName);
    QString id=QString::number(MyApp::m_nId);
    ui->idLabel->setText("ID号："+id);
    QString headPath=QString("border-image: url(%1);").arg(MyApp::m_strHeadPath);
    ui->headBtn->setStyleSheet(headPath);




}

personMsgDlg::~personMsgDlg()
{
    delete ui;
}
