#ifndef LEFTBAR_H
#define LEFTBAR_H

#include <QWidget>
#include <QWidget>
#include <QButtonGroup>
#include<systemsetting.h>
#include"weather/wtheatherdlg.h"
#include"headedit.h"


class personMsgDlg;

class MyButton;
namespace Ui {
class leftBar;
}

class leftBar : public QWidget
{
    Q_OBJECT

public:
    explicit leftBar(QWidget *parent = nullptr);
    ~leftBar();
    QButtonGroup *m_btnGroup;

    void DownloadFriendHead(const int &userId);


private slots:
    void on_headBtn_clicked();
    void sltheadChange(QString headPath);
signals :
    void  UpdateHeadPic();
    void changeBackgroundColor(QString color);
    void changeleftBuble(QString color);
    void changerightBuble(QString color);

private:
    Ui::leftBar *ui;
    wtheatherDlg WDlg;
    MyButton *btn_chat;
    MyButton *btn_contact;
    MyButton *btn_settings;
    QPushButton *btn_weather;
    personMsgDlg *pMsgDlg;
    SystemSetting sysSet;
    headEdit headedit;

};

#endif // LEFTBAR_H
