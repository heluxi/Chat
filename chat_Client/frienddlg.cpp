#include "frienddlg.h"
#include "ui_frienddlg.h"

#include <QMouseEvent>
FriendDlg::FriendDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendDlg)
{
    ui->setupUi(this);
}

FriendDlg::~FriendDlg()
{
    delete ui;
}

void FriendDlg::mousePressEvent(QMouseEvent *event)
{
    //获得部件当前位置
    this->windowPos=this->pos();
    //获得鼠标位置
    this->mousePos=event->globalPos();
    //移动后部件所在的位置
    this->dPos=mousePos-windowPos;
}

void FriendDlg::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-this->dPos);
}
