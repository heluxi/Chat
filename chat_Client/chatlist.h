#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>

namespace Ui {
class chatList;
}

class chatList : public QWidget
{
    Q_OBJECT

public:
    explicit chatList(QWidget *parent = nullptr);
    ~chatList();

private:
    Ui::chatList *ui;
};

#endif // CHATLIST_H
