#include "systemsetting.h"
#include "ui_systemsetting.h"
#include"myapp.h"

#include"myHelper.h"
#include<QMessageBox>
#include<QColorDialog>

SystemSetting::SystemSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemSetting)
{
    ui->setupUi(this);
    this->setWindowTitle("设置");
    //加载之前的设置

    ui->lineEditHostAddr->setText(MyApp::m_strHostAddr);
    ui->lineEditHostMsgPort->setText(QString::number(MyApp::m_nMsgPort));
    ui->lineEditHostFilePort->setText(QString::number(MyApp::m_nFilePort));

}

SystemSetting::~SystemSetting()
{
    delete ui;
}

//保存ip地址配置
void SystemSetting::on_btnSaveSetting_clicked()
{

    QString strHost = ui->lineEditHostAddr->text();

    // 判断是否ip地址
    if (!myHelper::IsIP(strHost))
    {
        QMessageBox::information(nullptr, "warning","IP地址设置有误!");
        return;
    }

    int nMsgPort = ui->lineEditHostMsgPort->text().toInt();
    if (nMsgPort > 65535 || nMsgPort < 100) {
        QMessageBox::information(nullptr, "warning",tr("端口设置有误!"));
        return;
    }

    int nFilePort = ui->lineEditHostFilePort->text().toInt();
    if (nFilePort > 65535 || nFilePort < 100) {
        QMessageBox::information(nullptr, "warning",tr("端口设置有误!"));
        return;
    }

    if (nMsgPort == nFilePort) {
        QMessageBox::information(nullptr,"warning", tr("2个端口不能设置一样!"));
        return;
    }

    MyApp::m_strHostAddr = strHost;
    MyApp::m_nMsgPort    = nMsgPort;
    MyApp::m_nFilePort   = nFilePort;

    // 保存配置
    MyApp::saveConfig();

    QMessageBox::information(nullptr, "Sucess",tr("配置保存成功，重启生效!"));
}

//颜色配置
void SystemSetting::on_toolButton_clicked()
{

    QString strClr = ui->lineEditClrBackground->text();

    QColor color = QColorDialog::getColor(QColor(strClr), this, tr("背景色配置"));
    if (!color.isValid()) {
        return;
    }

    ui->lineEditClrBackground->setText(color.name().toUpper());
    ui->labelBackground->setStyleSheet(QString("background-color: %1").arg(color.name()));
    emit changeBackgroundColor(color.name());
}

//气泡颜色设置
void SystemSetting::on_toolBtnLeftClr_clicked()
{
    QString strClr = ui->lineEditLeftBubble->text();

    QColor color = QColorDialog::getColor(QColor(strClr), this, tr("气泡颜色配置"));
    if (!color.isValid()) {
        return;
    }

    ui->lineEditLeftBubble->setText(color.name().toUpper());
    ui->labelLeftBubbleClr->setStyleSheet(QString("background-color: %1").arg(color.name()));
    emit changeleftBuble(color.name());
}


void SystemSetting::on_toolBtnClr_clicked()
{
    QString strClr = ui->lineEditRightBubble->text();

    QColor color = QColorDialog::getColor(QColor(strClr), this, tr("气泡颜色配置"));
    if (!color.isValid()) {
        return;
    }

    ui->lineEditRightBubble->setText(color.name().toUpper());
    ui->labelRightBubbleClr->setStyleSheet(QString("background-color: %1").arg(color.name()));
    emit changerightBuble(color.name());
}

