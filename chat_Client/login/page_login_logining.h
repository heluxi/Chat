#ifndef PAGE_LOGIN_LOGINING_H
#define PAGE_LOGIN_LOGINING_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Page_Login_Logining;
}

class Page_Login_Logining : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login_Logining(QWidget *parent = nullptr);
    ~Page_Login_Logining();

protected:
    virtual void hideEvent(QHideEvent *) override;

signals:
    void cancelSignal();
    void closeWindow();
    void hideWindow();
    void animationFinished();


public slots:
    void changePoints();
//    void cancelButtonClicked(bool);
    void showMainUI();
    void loginSuccess();

    void updateHead();

private slots:
    void on_btn_cancel_clicked(bool);

private:
    Ui::Page_Login_Logining *ui;

    QTimer*          m_loginingTimer;    // 登录中动画计时器
    QString          m_points;           // 登录中后面的小点
};

#endif // PAGE_LOGIN_LOGINING_H
