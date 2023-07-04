#ifndef MIDW_H
#define MIDW_H

#include <QWidget>
#include "addfriendwnd.h"
#include "contactwidget.h"
#include "findfriendwnd.h"
#include"creategroupwnd.h"
//#include"creategroupdlg.h"

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

    Cell* isIDExist(int id);

signals:
    void openDialog(Cell*);
    void signalSendMessage(const quint8 &, const QJsonValue &);
    void signalFindFriendReply(const QJsonValue &);
    void signalAddChat(Cell*);
    void resetRightPage();
    void contactBtnClicked();
    void createGroupSucess(int);


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
private:
    Ui::midw *ui;
    ContactWidget *contactWidget;
    CreateGroupWnd *newGroup;
    Cell *popMenuCell = nullptr;
    Cell *selectedCell = nullptr;//选中的格子，即如果右边有对话框时，对应中间的格子就是这个,初始化时没有被选中的

    QMenu *addMenu;
//    CreateGroupDlg *createDlg;
//    CreateGroupWnd *newGroup;
};

#endif // MIDW_H
