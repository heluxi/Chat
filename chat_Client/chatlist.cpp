#include "chatlist.h"
#include "ui_chatlist.h"

chatList::chatList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatList)
{
    ui->setupUi(this);
}

chatList::~chatList()
{
    delete ui;
}
