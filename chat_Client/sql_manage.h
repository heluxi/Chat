#ifndef SQL_MANAGE_H
#define SQL_MANAGE_H

#include <QObject>
#include<QSqlDatabase>



class sql_manage : public QObject
{
    Q_OBJECT

public:
    //单实例运行
    static sql_manage *ptrsql;
    static sql_manage *getinstance()
    {
        if(ptrsql==nullptr)
        {
            ptrsql= new sql_manage;
        }
        return ptrsql;
    }
    explicit sql_manage(QObject *parent = nullptr);
    ~sql_manage();
    bool openUserdb();
    bool openMsgdb();


    void addFriend(int id,int userid,QString name);
    void deleFriend(int id,int userid);


signals:

private:
    QSqlDatabase userdb;
    QSqlDatabase msgdb;
};

#endif // SQL_MANAGE_H
