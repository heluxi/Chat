#include "sql_manage.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>

sql_manage * sql_manage::ptrsql=nullptr;

sql_manage::sql_manage(QObject *parent)
    : QObject{parent}
{



}

sql_manage::~sql_manage()
{
    if (userdb.isOpen()) {
        userdb.close();
    }

    if (msgdb.isOpen()) {
        msgdb.close();
    }
}

bool sql_manage::openUserdb()
{
    userdb=QSqlDatabase::addDatabase("QSQLITE","connectionUser");
    userdb.setDatabaseName("user.db");
    if (!userdb.open()) {
        qDebug() << userdb.lastError();
        return false;
    }

    // 添加数据表
    QSqlQuery query(userdb);

    // 创建我的好友表 id为好友id，userid为当前用户id
    query.exec("CREATE TABLE FRIEND (id INT, userId INT, name varchar(50))");

    // 创建群组表 id为群组id，userid为当前用户id
    query.exec("CREATE TABLE MYGROUP (id INT, userId INT, name varchar(50))");

    // 用户数据保存
    query.exec("CREATE TABLE USERINFO (id INT, name varchar(50), passwd varchar(50))");

    return true;
}

bool sql_manage::openMsgdb()
{
    msgdb = QSqlDatabase::addDatabase("QSQLITE","connectionMsg");
    msgdb.setDatabaseName("message.db");
    if (!msgdb.open()) {
        qDebug() << "Open sql failed";
        return false;
    }

    // 添加数据表
    QSqlQuery query(msgdb);
    // 创建历史聊天表
    query.exec("CREATE TABLE MSGINFO (id INT PRIMARY KEY, userId INT, name varchar(20),"
               "head varchar(50), datetime varchar(20), filesize varchar(30),"
               "content varchar(500), type INT, direction INT)");

    return true;
}
//添加好友
void sql_manage::addFriend(int id, int userid, QString name)
{
    QSqlQuery query(userdb);
    //查找是否有该好友
   QString sqlSelect=QString("select * from friend where id=%1 and userId=%2").arg(id).arg(userid);

   if(!query.exec(sqlSelect))
    {   qDebug()<<"select friend error"<<userdb.lastError();
       return ;
    }
    else
   {
       if(query.next())
       {
           qDebug()<<"You have already add this friend!\n";
           QMessageBox::warning(NULL,"Warning","你已经添加过该好友",QMessageBox::Cancel);
           return;
       }

       QString sqlInsert=QString("insert into friend (id,userId,name) values(%1,%2,'%3');").arg(id).arg(userid).arg(name);

       if(!query.exec(sqlInsert))
       {
           qDebug()<<"add friend error"<<userdb.lastError();
       }
       else
       {
           QMessageBox::information(NULL,"Sucessful","添加好友成功",QMessageBox::Cancel);
       }
   }


}

void sql_manage::deleFriend(int id, int userid)
{
    QSqlQuery query(userdb);
    //查找是否有该好友
   QString sqlSelect=QString("select * from friend where id=%1 and userId=%2").arg(id).arg(userid);

   if(!query.exec(sqlSelect))
    {   qDebug()<<"select friend error"<<userdb.lastError();
       return ;
    }
    else
   {
       if(!query.next())
       {
           QMessageBox::warning(NULL,"Warning","找不到该好友",QMessageBox::Cancel);

       }
       else
       {
           QString sqldelete=QString("delete from friend where id=%1 and userId=%2").arg(id).arg(userid);
           if(!query.exec(sqldelete))
           {
               qDebug()<<"delete error"<<userdb.lastError();
           }
           else
           {
               QMessageBox::information(NULL,"Sucessful","删除好友成功",QMessageBox::Cancel);
           }
       }
   }
}
