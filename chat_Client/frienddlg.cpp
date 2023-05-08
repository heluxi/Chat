#include "frienddlg.h"
#include "ui_frienddlg.h"

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
