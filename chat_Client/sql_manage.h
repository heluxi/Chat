#ifndef SQL_MANAGE_H
#define SQL_MANAGE_H

#include <QMutex>
#include <QObject>
#include<QSqlDatabase>

#include "rightw/bubble/bubbleinfo.h"


class sql_manage : public QObject
{
    Q_OBJECT

public:
    //单实例运行
    static sql_manage *ptrsql;
    static sql_manage *Instance()
    {
        static QMutex mutex;
        if (ptrsql == nullptr) {
            QMutexLocker locker(&mutex);

            if (!ptrsql) {
                ptrsql = new sql_manage();
            }
        }
        return ptrsql;
    }
    explicit sql_manage(QObject *parent = nullptr);
    ~sql_manage();
    bool openUserdb(const QString &dataName);

    bool UserdbIsOpen();


//    void addFriend(int id,int userid,QString name);
    // 添加好友
    void addFriend(const int &myID, const int &friendID);

    bool deleFriend(int id,int friendID);

    bool isMyFriend(int friendId);
    bool isInGroup(int friendID);
    // 判断是否是一个群的群主
    bool isAdmin(int id,int groupID);

    // 添加群组
    void AddGroup(const int &id, const int &userId, const QString &name);
    // 获取好友信息
    QJsonObject getFriendInfo(int id) const;
    // 获取群信息
    QJsonObject getGroupInfo(int id) const;

    // 获取我的分组
    QJsonArray getMySubgroup() const;
    // 获取我的好友
    QJsonArray getMyFriends() const;
    // 获取我的群组
    QJsonArray getMyGroups() const;
    // 获取我的历史聊天列表
    QJsonArray getMyChatList() const;

    void updateFileMsg(BubbleInfo *info);

    // 添加历史聊天记录
    void addHistoryMsg(BubbleInfo *info);
    // 获取历史聊天记录,id表示聊天窗口好友或者群的id,tag标记这是私聊还是群聊窗口,count表示最近的记录数
    QVector<BubbleInfo *> queryHistory(int id,int tag, int count);

signals:

private:
    QSqlDatabase userdb;

};

#endif // SQL_MANAGE_H
