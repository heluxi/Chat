#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QButtonGroup>
#include <QWidget>
#include "cell.h"

namespace Ui {
class ContactWidget;
}

class ContactWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContactWidget(QWidget *parent = nullptr);
    ~ContactWidget();
    void InitList();
    void addCell(Cell*);
    void deleteFriend(int id);

private:
    Ui::ContactWidget *ui;
    QButtonGroup *btnGroup;

    QHash<QString,Cell*> hash;//通过分组名找到对应的cell抽屉
    Cell *popMenuCell = nullptr;

signals:
    void signalSendMessage(const quint8 &, const QJsonValue &);
    void openDialog(Cell*);
    void deleteChat(int id);

public slots:
    void onFriendDadMenuSelected(QAction*);
    void onGroupDadMenuSelected(QAction*);
    void onSonMenuSelected(QAction*);
    void onSonDoubleClicked(Cell*);//双击好友格子
    void onSwitchPage(int);
    void setPopMenuCell(Cell*,QMenu*);
    void sltUpdateFriendList(QString);
};

#endif // CONTACTWIDGET_H
