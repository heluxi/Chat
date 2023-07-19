#include "personmsgdlg.h"
#include "ui_personmsgdlg.h"
#include<QFileInfo>
#include<QFileDialog>
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
    QString headPath=MyApp::m_strHeadFile+MyApp::m_strHeadPath;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty())
    {
        qDebug()<<"默认头像\n";
    }
    else
    {
        QString head=QString("border-image: url(%1);").arg(headPath);
        ui->headBtn->setStyleSheet(head);
    }




}

personMsgDlg::~personMsgDlg()
{
    delete ui;
}

void personMsgDlg::on_headBtn_clicked()
{


    QString headPath=QFileDialog::getOpenFileName(this,tr("select image"),"/",tr("Image Fles(*.png *.jpg)"));
    qDebug()<<"select image :"<<headPath;
    QString head=QString("border-image: url(%1);").arg(headPath);
    ui->headBtn->setStyleSheet(head);
    //qDebug()<<QFileDialog::getOpenFileUrl();
    emit chanageHead(headPath);


}

