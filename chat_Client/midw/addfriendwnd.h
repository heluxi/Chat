#ifndef ADDFRIENDWND_H
#define ADDFRIENDWND_H

#include <QDialog>
#include<QJsonObject>
#include<QJsonValue>
#include "cell.h"

namespace Ui {
class addFriendWnd;
}

class addFriendWnd : public QDialog
{
    Q_OBJECT

public:
    explicit addFriendWnd(Cell *cell);
    ~addFriendWnd();
signals:
    void signalAddFriend(const quint8 &,const QJsonValue&);
    void signalAddChat(Cell*);

private slots:


    void on_agreeBtn_clicked();

    void on_rejectBtn_clicked();

private:
    Ui::addFriendWnd *ui;



    Cell *cell;
};

#endif // ADDFRIENDWND_H
