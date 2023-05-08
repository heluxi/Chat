#ifndef FRIENDDLG_H
#define FRIENDDLG_H

#include <QWidget>

namespace Ui {
class FriendDlg;
}

class FriendDlg : public QWidget
{
    Q_OBJECT

public:
    explicit FriendDlg(QWidget *parent = nullptr);
    ~FriendDlg();

private:
    Ui::FriendDlg *ui;
};

#endif // FRIENDDLG_H
