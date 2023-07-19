#ifndef PERSONMSGDLG_H
#define PERSONMSGDLG_H

#include <QDialog>

namespace Ui {
class personMsgDlg;
}

class personMsgDlg : public QDialog
{
    Q_OBJECT

public:
    explicit personMsgDlg(QWidget *parent = nullptr);
    ~personMsgDlg();

private:
    Ui::personMsgDlg *ui;
};

#endif // PERSONMSGDLG_H
