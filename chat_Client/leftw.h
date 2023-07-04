#ifndef LEFTW_H
#define LEFTW_H

#include <QWidget>
#include <QButtonGroup>
#include"weather/wtheatherdlg.h"

namespace Ui {
class leftw;
}

class leftw : public QWidget
{
    Q_OBJECT

public:
    explicit leftw(QWidget *parent = nullptr);
    ~leftw();

    QButtonGroup *m_btnGroup;

    void DownloadFriendHead(const int &userId);

private slots:
    void on_weatherButton_clicked();

private:
    Ui::leftw *ui;
    wtheatherDlg WDlg;
    QPushButton *button;
    QPushButton *favoritButton;
    QPushButton *phoneButton;
    QPushButton *fileButton;
};

#endif // LEFTW_H
