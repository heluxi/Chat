#include "personmsgdlg.h"
#include "ui_personmsgdlg.h"
#include<QFileInfo>
#include<QFileDialog>
#include<QMessageBox>
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


    //QString headPath=MyApp::m_strHeadFile+MyApp::m_strHeadPath;
    //QFileInfo fileInfo(headPath);
    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists()||MyApp::m_strHeadFile.isEmpty())
    {

        headPath =":/默认头像.svg";
    }
    QString style=QString("border-image: url(%1);").arg(headPath);
    ui->headBtn->setStyleSheet(style);





}

personMsgDlg::~personMsgDlg()
{
    delete ui;
}

void personMsgDlg::on_headBtn_clicked()
{



    QString headPath=QFileDialog::getOpenFileName(this,tr("select image"),"/",tr("Image Fles(*.png *.jpg)"));
    qDebug()<<"select image :"<<headPath;
    if(headPath=="")
    {
        qDebug()<<"没有选择图片";
        return;
    }
    else
    {

        QMessageBox::information(this,"Sucess","修改头像成功!");
    }
    QString head=QString("border-image: url(%1);").arg(headPath);
    ui->headBtn->setStyleSheet(head);
    //qDebug()<<QFileDialog::getOpenFileUrl();
//    QPixmap p(headPath);
//    QIcon icon(p.scaled(QSize(75,75)));
//    ui->headBtn->setIcon(icon);
//    ui->headBtn->setIconSize(QSize(75,75));
    emit chanageHead(headPath);



}

