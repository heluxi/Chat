#include "sql_manage.h"
#include "myapp.h"

#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include <QDateTime>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonArray>


#define DATE_TME_FORMAT     QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")

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


}

bool sql_manage::openUserdb(const QString &dataName)
{
    userdb=QSqlDatabase::addDatabase("QSQLITE");
    userdb.setDatabaseName(dataName);
    if (!userdb.open()) {
        qDebug() << userdb.lastError();
        return false;
    }

    // 添加数据表
    QSqlQuery query(userdb);
    // 创建我的好友表 id为好友id,group为该好友所在的分组,
    // tag记录关闭程序时聊天列表是否已经有与该用户的对话框，目的是下次打开时初始化聊天列表用的,以下相同
    query.exec("CREATE TABLE MyFriend (id INT PRIMARY KEY, name varchar(50), head varchar(20), subgroup varchar(20), "
               "tag bit ,lastMsg varchar(50), lastTime varchar(20) )");

    // 创建群组表 id为群组id,
    query.exec("CREATE TABLE MyGroup (id INT PRIMARY KEY, name varchar(50), admin INT, head varchar(20), "
               "tag bit ,lastMsg varchar(50), lastTime varchar(20) )");

    query.exec("CREATE TABLE MySubgroup (name varchar(20) PRIMARY KEY, datetime varchar(20) )");

    query.exec(QString("insert into MySubgroup values('默认分组','") + DATE_TME_FORMAT + "')");
    query.exec(QString("insert into MySubgroup values('黑名单','") + DATE_TME_FORMAT + "')");

    // 创建历史聊天表 tag = 0表示私聊消息,tag = 1表示群聊消息,
    // sender = 0表示是我发的消息,sender = 1表示是对方发的消息,sender = 2表示是系统发的消息
    query.exec("CREATE TABLE MsgHistory (id INT PRIMARY KEY, sender INT, "
               "myID INT, yourID INT, groupID INT, tag bit, "
               "type INT, content varchar(500), filesize varchar(30), download bit, "
               "datetime BIGINT)");

    return true;
}



bool sql_manage::UserdbIsOpen()
{
    return userdb.isOpen();
}

//添加好友
void sql_manage::addFriend(const int &myID, const int &friendID)
{
    QString strQuery = "SELECT * FROM MyFriend ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(friendID));

//    QSqlQuery query(userdb);
    //查找是否有该好友
//   QString sqlSelect=QString("select * from friend where id=%1 and userId=%2").arg(id).arg(userid);

    QSqlQuery query(strQuery);
    if (query.next()) {
        // 查询到有该用户，不添加
        qDebug() << "已经是好友了，无法再次添加" << query.value(0).toString();
            return;
    }

    // 根据新ID重新创建用户
    query.prepare("INSERT INTO MyFriend (id, name, head, group) "
                  "VALUES (?, ?, ?, ?);");
    query.bindValue(0, friendID);
    query.bindValue(1, "");
    query.bindValue(2, "");
    query.bindValue(3, "我的好友");

    query.exec();

    //此处再向服务器添加一条好友信息

//   if(!query.exec(sqlSelect))
//    {   qDebug()<<"select friend error"<<userdb.lastError();
//       return ;
//    }
//    else
//   {
//       if(query.next())
//       {
//           qDebug()<<"You have already add this friend!\n";
//           QMessageBox::warning(NULL,"Warning","你已经添加过该好友",QMessageBox::Cancel);
//           return;
//       }

//       QString sqlInsert=QString("insert into friend (id,userId,name) values(%1,%2,'%3');").arg(id).arg(userid).arg(name);

//       if(!query.exec(sqlInsert))
//       {
//           qDebug()<<"add friend error"<<userdb.lastError();
//       }
//       else
//       {
//           QMessageBox::information(NULL,"Sucessful","添加好友成功",QMessageBox::Cancel);
//       }
//   }


}

bool sql_manage::deleFriend(int id, int friendID)
{

    QString strQuery = "SELECT * FROM MyFriend ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(friendID));


    QSqlQuery query(strQuery);
    // 删除
    if (query.next()) {
       strQuery = "DELETE FROM MyFriend WHERE id=";
       strQuery.append(QString::number(friendID));

       query = QSqlQuery(strQuery);
       return query.exec();
    }

    // 没有查询到有该用户
    // 向服务器更新消息
    return false;
}

bool sql_manage::isMyFriend(int friendId)
{
    QString strQuery = "SELECT * FROM MyFriend ";
    strQuery.append("WHERE id = ");
    strQuery.append(QString::number(friendId));
    strQuery.append(";");

    QSqlQuery query(strQuery);
    return query.next();
}

bool sql_manage::isInGroup(int groupID)
{
    QString strQuery = "SELECT * FROM MyGroup ";
    strQuery.append("WHERE id = ");
    strQuery.append(QString::number(groupID));
    strQuery.append(";");

    QSqlQuery query(strQuery);
    return query.next();
}

bool sql_manage::isAdmin(int id, int groupID)
{
    QString strQuery = "SELECT * FROM MyGroup ";
    strQuery.append("WHERE id = ");
    strQuery.append(QString::number(groupID));
    strQuery.append(";");

    QSqlQuery query(strQuery);
    if(query.next()){
       int adminID = query.value(2).toInt();
       if(adminID == id)
           return true;
    }
    return false;
}

void sql_manage::AddGroup(const int &id, const int &userId, const QString &name)
{
    QString strQuery = "SELECT [id] FROM MYGROUP ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));
    strQuery.append(" AND userId=");
    strQuery.append(QString::number(userId));

    QSqlQuery query(strQuery, userdb);
    if (query.next()) {
       // 查询到有该用户，不添加
       qDebug() << "yes" << query.value(0).toString();
       return;
    }

    // 根据新ID重新创建用户
    query.prepare("INSERT INTO MYGROUP (id, userId, name) "
                  "VALUES (?, ?, ?);");
    query.bindValue(0, id);
    query.bindValue(1, userId);
    query.bindValue(2, name);

    query.exec();
}

QJsonObject sql_manage::getFriendInfo(int id) const
{
    QString strQuery = "SELECT * FROM MyFriend where id = ";
    strQuery.append(QString::number(id));
    QSqlQuery query(strQuery);
    QJsonObject json;

    while (query.next()) {
       json.insert("name", query.value(1).toString());
       json.insert("head", query.value(2).toString());
       json.insert("subgroup",query.value(3).toString());
    }
    return json;
}

QJsonObject sql_manage::getGroupInfo(int id) const
{
    QString strQuery = "SELECT * FROM MyGroup where id = ";
    strQuery.append(QString::number(id));
    QSqlQuery query(strQuery);
    QJsonObject json;

    while (query.next()) {
       json.insert("name", query.value(1).toString());
       json.insert("head", query.value(3).toString());
    }
    return json;
}

QJsonArray sql_manage::getMySubgroup() const
{
    QJsonArray  myGroup;

    QString strQuery = "SELECT * FROM MySubgroup";
    QSqlQuery query(strQuery);
    while(query.next()){
       QJsonObject json;
       json.insert("name", query.value(0).toString());
       myGroup.append(json);
    }

    return myGroup;
}

QJsonArray sql_manage::getMyFriends() const
{
    QJsonArray  myFriends;

    QString strQuery = "SELECT * FROM MyFriend ";
    QSqlQuery query(strQuery);

    while (query.next()){
       QJsonObject json;
       json.insert("id",query.value("id").toInt());
       json.insert("head",query.value("head").toString());//本地头像地址
       json.insert("name",query.value("name").toString());
       json.insert("subgroup",query.value("subgroup").toString());
       myFriends.append(json);
    }

    return myFriends;
}

QJsonArray sql_manage::getMyGroups() const
{
    QJsonArray  myGroup;

    QString strQuery = "SELECT * FROM MyGroup";
    QSqlQuery query(strQuery);
    while (query.next()) {
       QJsonObject json;
       json.insert("id", query.value(0).toInt());
       json.insert("name", query.value(1).toString());
       json.insert("admin",query.value(2).toInt());
       json.insert("head", query.value(3).toString());
       myGroup.append(json);
    }

    return myGroup;
}

QJsonArray sql_manage::getMyChatList() const
{
    QJsonArray  myChatList;

    QString strQuery = "SELECT * FROM MyFriend where tag = 1";//表示上次关闭时已打开
    QSqlQuery query(strQuery);
    while(query.next()){
       QJsonObject json;
       json.insert("tag",0);//0表示私聊
       json.insert("id", query.value(0).toInt());
       json.insert("name", query.value(1).toString());
       json.insert("head", query.value(2).toString());
       json.insert("subgroup", query.value(3).toString());
       json.insert("lastMsg",query.value(5).toString());
       json.insert("lastTime",query.value(6).toString());
       myChatList.append(json);
    }

    QString strQuery2 = "SELECT * FROM MyGroup where tag = 1";//表示上次关闭时已打开
    QSqlQuery query2(strQuery2);
    while(query2.next()){
       QJsonObject json;
       json.insert("tag",1);//1表示群聊
       json.insert("id", query2.value(0).toInt());
       json.insert("name", query2.value(1).toString());
       json.insert("admin", query2.value(2).toString());
       json.insert("head", query2.value(3).toString());
       json.insert("lastMsg",query2.value(5).toString());
       json.insert("lastTime",query2.value(6).toString());
       myChatList.append(json);
    }

    return myChatList;
}

void sql_manage::updateFileMsg(BubbleInfo *info)
{
    if(info->tag == 0){
       //私聊
       int yourID = info->yourID;
       qint64 time = info->time;

       QString strQuery = "update MsgHistory set download = true, content='";
       strQuery.append(info->msg + "'");
       strQuery.append(" where yourID=");
       strQuery.append(QString::number(yourID));
       strQuery.append(" and datetime=");
       strQuery.append(QString::number(time));


       QSqlQuery query(strQuery);
       query.exec();

    }else if(info->tag ==1){
       //群聊
       int yourID = info->yourID;
       int groupID = info->groupID;
       qint64 time = info->time;

       QString strQuery = "update MsgHistory set download = true,  content='";
       strQuery.append(info->msg + "'");
       strQuery.append(" where yourID=");
       strQuery.append(QString::number(yourID));
       strQuery.append(" and groupID=");
       strQuery.append(QString::number(groupID));
       strQuery.append(" and datetime=");
       strQuery.append(QString::number(time));

       QSqlQuery query(strQuery);
       query.exec();
    }
}

void sql_manage::addHistoryMsg(BubbleInfo *info)
{
    // 查询数据库
    QSqlQuery query("SELECT [id] FROM MsgHistory ORDER BY id DESC;");
    int id = 0;//消息序号,为该表的主键
    // 查询最高ID
    if (query.next()) {
       id = query.value(0).toInt();
    }

    query.prepare("INSERT INTO MsgHistory (id, sender, myID, yourID, groupID, tag, "
                  "type, content, filesize, download, datetime) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");

    query.bindValue(0, id + 1);
    query.bindValue(1, info->sender);
    query.bindValue(2, info->myID);
    query.bindValue(3, info->yourID);
    query.bindValue(4, info->groupID);
    query.bindValue(5, info->tag);
    query.bindValue(6, info->msgType);
    query.bindValue(7, info->msg);
    query.bindValue(8, info->fileSize);
    query.bindValue(9, info->downloaded);
    query.bindValue(10,info->time);

    query.exec();

    qDebug() << "add history lastError:" << query.lastError().text();
}

QVector<BubbleInfo *> sql_manage::queryHistory(int id, int tag, int count)
{
    QString strQuery = "SELECT * FROM MsgHistory ";
    if(tag == 0){
       strQuery.append("WHERE yourID=");
       strQuery.append(QString::number(id));
       strQuery.append(" and tag=");
       strQuery.append(QString::number(tag));
       strQuery.append(" ORDER BY id ASC;");//按id递增
    }else if(tag == 1){
       strQuery.append("WHERE groupID=");
       strQuery.append(QString::number(id));
       strQuery.append(" and tag=");
       strQuery.append(QString::number(tag));
       strQuery.append(" ORDER BY id ASC;");
    }

//目前默认加载全部记录，后序可以实现加载固定数目的记录
#if 0
    // 查询前10条
    if (0 != count)
    {
        strQuery.append(" LIMIT ");
        strQuery.append(QString::number(count));
    }
    strQuery.append(";");
#endif

    QVector<BubbleInfo*> bubbles;

    QSqlQuery query(strQuery);
    while (query.next()) {
       // 查看历史记录
       BubbleInfo *bubble = new BubbleInfo;
       bubble->sender = Sender(query.value(1).toInt());
       bubble->myID = query.value(2).toInt();
       bubble->yourID = query.value(3).toInt();
       bubble->groupID = query.value(4).toInt();
       bubble->tag = query.value(5).toInt();
       bubble->msgType = MessageType(query.value(6).toInt());
       bubble->msg = query.value(7).toString();
       bubble->fileSize = query.value(8).toInt();
       bubble->downloaded = query.value(9).toBool();
       bubble->time = query.value(10).toInt();
       bubble->showAnimation = false;
       bubble->showProgressBar = false;
       bubble->showDownload = !bubble->downloaded;

       if(bubble->msgType == Files && bubble->sender == You){
           QFileInfo fileInfo(bubble->msg);
           if(!fileInfo.exists()){
               bubble->downloaded = false;
               bubble->showDownload = true;
           }
       }

       if(bubble->sender == Me){
           bubble->headIcon = MyApp::m_strHeadPath + MyApp::m_strHeadFile;
       }else if(bubble->sender == You){
           bubble->headIcon = MyApp::m_strHeadPath + QString::number(bubble->yourID) + ".png";
       }
       //qDebug() << "bubble headPath:" << bubble->headIcon;

       bubbles.push_back(bubble);
    }

    return bubbles;
}
