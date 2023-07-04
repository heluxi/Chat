#ifndef ADDFRIENDWIN_H
#define ADDFRIENDWIN_H

#include <QWidget>
#include<QJsonObject>
#include<QJsonValue>
#include "cell.h"

namespace Ui {
class AddFriendWin;
}

class AddFriendWin : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriendWin(QWidget *parent = nullptr);
    ~AddFriendWin();

    void SltfindFrindReply(const QJsonValue& );
private slots:
    void on_searchBut_clicked();

    void on_addBtn_clicked();

signals:
    void signalFind(QJsonObject json);
    void signalSendMessage(const quint8 &, const QJsonValue &);
    void signalAddFriend(const quint8 &,const QJsonValue&);
    void signalAddChat(Cell*);
private:
    Ui::AddFriendWin *ui;
    int tag;//tag 0 添加好友 tag 1 添加群
    int friendID;

    Cell *cell;

};

#endif // ADDFRIENDWIN_H
