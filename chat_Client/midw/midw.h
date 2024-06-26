#ifndef MIDW_H
#define MIDW_H

#include <QWidget>
#include "contactwidget.h"
#include"creategroupwnd.h"
#include"rightw/personalinfo.h"


namespace Ui {
class midw;
}

class midw : public QWidget
{
    Q_OBJECT

public:
    explicit midw(QWidget *parent = nullptr);
    ~midw();
    void MainPageChanged(int page);

    void InitChatList();
    void InitContactList();

    void insertCell(Cell *c);
    void switchToChatList();

    void addCellToContact(Cell*);
    void deleteFriend(int id);

    Cell* isIDExist(int id);

    QList<Cell*> getList();

signals:
    void openDialog(Cell*);
    void signalSendMessage(const quint8 &, const QJsonValue &);
    void signalFindFriendReply(const QJsonValue &);
    void signalAddChat(Cell*);
    void resetRightPage();
    void contactBtnClicked();
    void createGroupSucess(int);
    void UpdateFriendStatus(const quint8 &nStatus, const QJsonValue &dataVal);
    void update(const QJsonValue &dataVal);


public slots:
    void updateTime(int,qint64,QString);

    void onSonMenuSelected(QAction*);
    void sltOpenDialog(Cell*);
    void setPopMenuCell(Cell*,QMenu*);

    void sltMenuSelected(QAction*);

    void sltFind(const QJsonValue&);

    void sltCreateGroup(const QJsonValue &jsonVal);

    void sltAddFriend(Cell *cell);

    void deleteChatCell(int);
    void sltupdateUserHead(const int &userId, const QString &strHead);



private:
    Ui::midw *ui;
    ContactWidget *contactWidget;
    CreateGroupWnd *newGroup;
    Cell *popMenuCell = nullptr;
    Cell *selectedCell = nullptr;//选中的格子，即如果右边有对话框时，对应中间的格子就是这个,初始化时没有被选中的

    QMenu *addMenu;
    personalInfo p;


};

#endif // MIDW_H
