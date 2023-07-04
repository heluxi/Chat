#ifndef FINDFRIENDWND_H
#define FINDFRIENDWND_H

#include <QDialog>
#include "cell.h"

namespace Ui {
class FindFriendWnd;
}

class FindFriendWnd : public QDialog
{
    Q_OBJECT

public:
    explicit FindFriendWnd(int tag = 0);
    ~FindFriendWnd();


signals:
    void signalFind(const QJsonValue&);
    void signalSendMessage(const quint8 &, const QJsonValue &);
public slots:
    void SltfindFrindReply(const QJsonValue& );
private slots:
    void on_searchBut_clicked();

    void on_addBtn_clicked();



private:
    Ui::FindFriendWnd *ui;

    int tag;//tag 0 添加好友 tag 1 添加群
    int friendID;

    Cell *cell;
};

#endif // FINDFRIENDWND_H
