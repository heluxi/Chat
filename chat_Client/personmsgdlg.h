#ifndef PERSONMSGDLG_H
#define PERSONMSGDLG_H

#include <QDialog>
#include"headedit.h"


namespace Ui {
class personMsgDlg;
}

class personMsgDlg : public QDialog
{
    Q_OBJECT

public:
    explicit personMsgDlg(QWidget *parent = nullptr);
    ~personMsgDlg();

private slots:
    void on_headBtn_clicked();


signals:
    void chanageHead(QString headPath);
private:
    Ui::personMsgDlg *ui;
    headEdit headeditDlg;

};

#endif // PERSONMSGDLG_H
