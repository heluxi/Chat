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
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::FriendDlg *ui;
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // FRIENDDLG_H
