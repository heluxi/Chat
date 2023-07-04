#include "selectfrdlist.h"
#include "ui_selectfrdlist.h"

selectFrdList::selectFrdList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectFrdList)
{
    ui->setupUi(this);
}

selectFrdList::~selectFrdList()
{
    delete ui;
}
