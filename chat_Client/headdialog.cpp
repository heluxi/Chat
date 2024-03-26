#include "headdialog.h"
#include "ui_headdialog.h"

HeadDialog::HeadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeadDialog)
{
    ui->setupUi(this);
}

HeadDialog::~HeadDialog()
{
    delete ui;
}

void HeadDialog::on_btnLoad_clicked()
{

}


void HeadDialog::on_btnSave_clicked()
{

}

