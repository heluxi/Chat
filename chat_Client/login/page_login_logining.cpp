#include "page_login_logining.h"
#include "ui_page_login_logining.h"
#include "myapp.h"

#include <QFileInfo>


Page_Login_Logining::Page_Login_Logining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login_Logining)
{
    ui->setupUi(this);

    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    //qDebug() << "headPath:" << headPath;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty())
        headPath = ":/loginwnd/defalut_head";
    ui->lb_head->setText(headPath);

    m_loginingTimer = new QTimer(this);
    QObject::connect(m_loginingTimer, &QTimer::timeout, this, &Page_Login_Logining::changePoints);
    m_loginingTimer->start(1000);

}

Page_Login_Logining::~Page_Login_Logining()
{
    delete ui;
}

void Page_Login_Logining::hideEvent(QHideEvent *)
{
    m_loginingTimer->stop();
    emit hideWindow();
}

void Page_Login_Logining::changePoints()
{
    m_points.append('.');
    if(m_points.size() > 3){
        m_points.clear();
    }
    ui->lb_logining->setText(tr("Logining")+m_points);
}

void Page_Login_Logining::showMainUI()
{
    emit animationFinished();
}

void Page_Login_Logining::loginSuccess()
{
    m_loginingTimer->stop();
    ui->lb_logining->setText(tr("登录成功！"));
    //m_headLabel->updateHead();
    QTimer::singleShot(1000,this,&Page_Login_Logining::showMainUI);
}

void Page_Login_Logining::updateHead()
{
    QString headPath = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    //qDebug() << "headPath:" << headPath;
    QFileInfo fileInfo(headPath);
    if(!fileInfo.exists() || MyApp::m_strHeadFile.isEmpty())
//        headPath = ":/loginwnd/defalut_head";
        headPath=":/login.jpg";

    //设置图片
    QPixmap *pix=new QPixmap(headPath);
    QSize sz=ui->lb_head->size();
    ui->lb_head->setPixmap(pix->scaled(sz));

//    ui->lb_head->changeHead(headPath);
//    ui->lb_head->setText(headPath);
}

void Page_Login_Logining::on_btn_cancel_clicked(bool)
{
    emit cancelSignal();
}

