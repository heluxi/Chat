#ifndef RIGHTW_H
#define RIGHTW_H

#include <QWidget>
#include "chatwindow.h"
#include "defaultwindow.h"

namespace Ui {
class rightw;
}

class rightw : public QWidget
{
    Q_OBJECT

public:

    explicit rightw(QWidget *parent = nullptr);
    ~rightw();

    void switchPage(Cell *);
    void resetPage();
    void restorePage();
    void setCurrentPage(int page){currentPage = page;}

    void startLoadingAnimation();
    void stopLoadingAnimation();

    void allowSendMsg(int id);
    void msgconfirmed(QJsonValue dataVal);//这是服务器回的确认收到本机发出去的消息
    void msgReceived(Cell *c,QJsonValue dataVal);//这是服务器转发给我的消息，是我的好友或者群发给我的消息

    void addNewUserToGroupList(int groupID,Cell *newUser);//新用户入群
signals:
//    void stayOnTop(bool);
    void signalSendMessage(const quint8 &, const QJsonValue &);
    void updateMidBarTime(int id,qint64 time,QString msg);
private slots:
    void on_pushButton_4_clicked();

private:
    Ui::rightw *ui;
    ChatWindow *chatWindow;
    DefaultWindow *defaultPage;

    QLabel *loadingLabel;
    QMovie *loadingMovie;

     QList<ChatWindow*> chatWindowList;

    QHash<int,int> hash;//用户对应id到聊天窗口的映射
    int cnt = 1;
    int currentPage = 0;
};

#endif // RIGHTW_H
