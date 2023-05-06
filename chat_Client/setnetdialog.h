#ifndef SETNETDIALOG_H
#define SETNETDIALOG_H

#include <QDialog>
#include"tcp_manage.h"

using std::string;

namespace Ui {
class setnetDialog;
}

class setnetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setnetDialog(QWidget *parent = nullptr);
    ~setnetDialog();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();
signals:
    void sendIpandAdd(unsigned short port,string ip);
private:
    Ui::setnetDialog *ui;
    tcp_manage *m_tcp;
};

#endif // SETNETDIALOG_H
