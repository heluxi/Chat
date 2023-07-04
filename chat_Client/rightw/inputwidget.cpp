#include "inputwidget.h"
#include "myapp.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QDateTime>
#include <QActionGroup>
#include <QMenu>

InputWidget::InputWidget(QWidget *parent)
    : QWidget(parent)
{


}

void InputWidget::restoreColor()
{
    setStyleSheet("border: none;background-color:#F0F0F0;");
    setStyleSheet("border-top:1px solid #E6E6E6");
    textEdit->setStyleSheet("border: none;background-color:#F0F0F0;");
}

void InputWidget::saveSendWay(QAction *action)
{
    if(!action->text().compare("按Enter键发送消息")){
        MyApp::sendWay = true;
    }else {
        MyApp::sendWay = false;
    }
    MyApp::saveConfig();
}


