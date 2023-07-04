#ifndef SETNETDIALOG_H
#define SETNETDIALOG_H

#include <QDialog>
#include"tcp_manage.h"


namespace Ui {
class setnetDialog;
}

class setnetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setnetDialog(QWidget *parent = nullptr);
    ~setnetDialog();

    void readConfig();
signals:
    void rotateWindow();
    void setNetwork();


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();
signals:
    void sendPortandAdd(unsigned short port,QString ip,unsigned int fileport);
private:
    Ui::setnetDialog *ui;
    //    clientSock *m_tcp;
    //    clientFileSock *file_sock;
};

#endif // SETNETDIALOG_H
