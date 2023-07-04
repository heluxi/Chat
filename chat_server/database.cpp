#include "database.h"
#include "qdebug.h"
#include"type.h"
#include<QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlQuery>
#include "myapp.h"
#include <QFile>

#define DATE_TME_FORMAT     QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")

Database *Database::self = nullptr;

Database::Database(QObject *parent)
    : QObject{parent}
{

}

Database::~Database()
{
    if (userdb.isOpen()) {
        userdb.close();
    }
}

bool Database::openDb(const QString &dataName)
{
    userdb = QSqlDatabase::addDatabase("QSQLITE");
    userdb.setDatabaseName(dataName);
    if (!userdb.open()) {
        qDebug() << "Open database failed";
        return false;
    }

    // 添加数据表
    QSqlQuery query;

    //创建用户信息表(id,name,passwd,head,status,groupId,lasttime),
    query.exec("CREATE TABLE UserInfo( id INT PRIMARY KEY, "
               "name varchar(20), passwd varchar(20), "
               "head varchar(20), status INT, groupId INT,lasttime DATETIME );");
//    query.exec("CREATE TABLE USERINFO (id INT PRIMARY KEY, name varchar(20), "
//               "passwd varchar(20), head varchar(20), status INT, groupId INT, lasttime DATETIME);");

    //创建群信息表(id,name,head,adminID,memberCnt,createTime)
    query.exec("CREATE TABLE GroupInfo( id INT PRIMARY KEY, "
               "name varchar(20), head varchar(20), "
               "adminID INT, memberCnt INT,createTime DATETIME )");

    //创建好友关系信息表
    query.exec("CREATE TABLE Friendship( userID1 INT,userID2 INT, "
               "createTime DATETIME, PRIMARY KEY(userID1,userID2), "
               "constraint id_fk1 foreign key (userID1) references UserInfo(id), "
               "constraint id_fk2 foreign key (userID2) references UserInfo(id) )");

    //创建群组成员信息表
    query.exec("CREATE TABLE GroupUser( groupID INT,userID INT, "
               "joinTime DATETIME,PRIMARY KEY(groupID,userID), "
               "constraint id_fk1 foreign key (groupID) references GroupInfo(id), "
               "constraint id_fk2 foreign key (userID) references UserInfo(id) )");

    //创建用户发送文件信息表
    // tag用于表示该文件是否被用户接收(0表示未接收,1表示已接收)
    // type表示该文件是私聊文件还是群聊文件(0表示私聊文件,1表示群聊文件)
    // filename 表示文件的名字，注意是指单纯的文件名字，不包含文件路径
    // filepath 表示文件在服务器上的路径，注意，路径长度最长100个字符
    // (senderID,receiverID,time)可唯一地标注一条文件信息，time用户发送该文件的时间
    query.exec("CREATE TABLE FileSent( senderID int,receiverID int,GroupID int,"
               "filename varchar(50),filesize bigint,filepath varchar(100),"
               "time DATETIME,tag bit,type bit,PRIMARY KEY(senderID,receiverID,time),"
               "constraint id_fk1 foreign key (senderID) references UserInfo(id),"
               "constraint id_fk2 foreign key (receiverID) references UserInfo(id),"
               "constraint id_fk3 foreign key (GroupID) references GroupInfo(id) )");

    //消息缓存表，把未发给用户的消息缓存在此张表中
    //如果是普通的文本消息，则在msg字段写入文本，如果是文件或者图片，则写入该文件在服务器上的存储地址
    //tag = 0表示私聊消息，tag = 1表示群聊消息
    query.exec("CREATE TABLE UnreadMsg( senderID int,receiverID int,"
               "groupID int,type int,time bigint,"
               "msg varchar(200),tag bit,fileSize bigint,"
               "PRIMARY KEY(senderID,receiverID,time),"
               "constraint id_fk1 foreign key (senderID) references UserInfo(id),"
               "constraint id_fk2 foreign key (receiverID) references UserInfo(id),"
               "constraint id_fk3 foreign key (groupID) references GroupInfo(id) )");

    //往用户信息表中插入一条管理员记录
    query.exec("INSERT INTO UserInfo VALUES(100000, 'admin', '123456', '', 0, '','');");

    qDebug() << "初始化数据库完毕";

    // 更新状态,避免有些客户端异常退出没有更新下线状态
//    changeAllUserStatus();
    //queryAll();
    return true;
}

void Database::closeDb()
{
    userdb.close();
}

void Database::updateUserStatus(const int &id, const quint8 &status)
{
    // 组织sql语句
    QString strSql = "UPDATE UserInfo SET status=";
    strSql += QString::number(status);
    strSql += QString(",lasttime='");
    strSql += DATE_TME_FORMAT;
    strSql += QString("' WHERE id=");
    strSql += QString::number(id);

    // 执行数据库操作
    QSqlQuery query(strSql);
    query.exec();
}

void Database::updateUserHead(const int &id, const QString &strHead)
{
    // 组织sql语句
    QString strSql = "UPDATE UserInfo SET head='";
    strSql += strHead;
    strSql += QString("' WHERE id=");
    strSql += QString::number(id);

    // 执行数据库操作
    QSqlQuery query(strSql);
    bool bOk = query.exec();
    qDebug() << "update head" << bOk << id;
}

QJsonArray Database::getAllUsers()
{
    QSqlQuery query("SELECT * FROM USERINFO ORDER BY id;");
    QJsonArray jsonArr;

    while (query.next()) {
        QJsonObject jsonObj;
        jsonObj.insert("id", query.value("id").toInt());
        jsonObj.insert("name", query.value("name").toString());
        jsonObj.insert("passwd", query.value("passwd").toString());
        jsonObj.insert("head", query.value("head").toString());
        jsonObj.insert("status", query.value("status").toInt());
        jsonObj.insert("groupId", query.value("groupId").toInt());
        jsonObj.insert("lasttime", query.value("lasttime").toString());
        jsonArr.append(jsonObj);
    }

    return jsonArr;
}

QJsonObject Database::getUserStatus(const int &id) const
{
    QJsonObject jsonObj;
    QString strQuery = "SELECT [name],[status],[head] FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    int nStatus = 0;
    QString strName = "";
    QString strHead = "0.bmp";

    QSqlQuery query(strQuery);
    if (query.next()) {
        strName = query.value(0).toString();
        nStatus = query.value(1).toInt();
        strHead = query.value(2).toString();
    }

    // 组合数据
    jsonObj.insert("id", id);
    jsonObj.insert("name", strName);
    jsonObj.insert("head", strHead);
    jsonObj.insert("status", nStatus);

    return jsonObj;
}

int Database::getUserOnLineStatus(const int &id) const
{
    QString strQuery = "SELECT [status] FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QSqlQuery query(strQuery);
    if (query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}



// 用户校验
QJsonObject Database::checkUserLogin(const int &id, const QString &passwd)
{
    int code;
    QString head = "";
    QString name = "";
    QString strQuery = "SELECT * FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QSqlQuery query(strQuery);
    if (query.next()) {//id存在
        strQuery.append(" AND passwd= '");
        strQuery.append(passwd);
        strQuery.append("'");
        QSqlQuery query2(strQuery);
        qDebug()<<"password:"<<passwd;
        if(query2.next()){
            strQuery.append(" AND status=");
            strQuery.append(QString::number(OnLine));
            QSqlQuery query3(strQuery);
            if(query3.next()){//重复登陆
                code = -3;
            }else{//登陆成功
                code = 0;
                head = query2.value("head").toString();
                name = query2.value("name").toString();
                updateUserStatus(id, OnLine);
            }
        }else{//密码错误
            code = -1;
        }
    }else{//id不存在
        code = -2;
    }

    QJsonObject json;
    json.insert("id",id);
    json.insert("code",code);
    json.insert("head",head);
    json.insert("name",name);

    return json;
}
QJsonObject Database::CheckUserLogin(const QString &name, const QString &passwd)
{
//    QString strQuery = "SELECT [id],[head],[status] FROM USERINFO ";
    QString strQuery = "SELECT * FROM UserInfo ";
    strQuery.append("WHERE name=");
    strQuery.append(name);
    strQuery.append("' AND passwd='");
    strQuery.append(passwd);
    strQuery.append("';");

    QJsonObject jsonObj;
    int nId = 1;
    int code = -1;
    QString strHead = "0.bmp";

    QSqlQuery query(strQuery);
    qDebug()<<strQuery;
    if (query.next()) {
        nId = query.value("id").toInt();
        qDebug()<<nId;
        int nStatus = query.value("status").toInt();
        if (OnLine == nStatus)
        {
            nId = -2;
            code = -2;
        }
        else
        {
            // 更新在线信息
            updateUserStatus(nId, OnLine);
            code = 0;
        }
        strHead = query.value("head").toString();
    }

    // 组织返回
    jsonObj.insert("id", nId);
    jsonObj.insert("msg", nId < 0 ? "error" : "ok");
    jsonObj.insert("head", strHead);
    jsonObj.insert("code", code);

    return jsonObj;
}

int Database::registerUser(QString name, QString pwd)
{
    QString strQuery = "SELECT * FROM UserInfo";
    strQuery.append(" order by id desc");

    int id;
    QSqlQuery query(strQuery);
    if (query.next()) {
        id = query.value(0).toInt();
        id++;//分配给该注册用户的id
    }

    // 根据新ID重新创建用户
    query.prepare("INSERT INTO UserInfo (id, name, passwd, head, status, lasttime) "
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.bindValue(0, id);
    query.bindValue(1, name);
    query.bindValue(2, pwd);
    query.bindValue(3, QString::number(id) + ".png");
    query.bindValue(4, 0);
    query.bindValue(5, DATE_TME_FORMAT);

    query.exec();


//    为用户分配存放头像的目录
    MyApp::createDir(MyApp::m_strHeadPath + QString::number(id) + "/");
    QFile::copy(MyApp::m_strHeadPath + "system/default.png",
                           MyApp::m_strHeadPath + QString::number(id) + "/" + QString::number(id) + ".png");
//    myHelper::CopyFile(MyApp::m_strHeadPath + "system/default.png",
//                       MyApp::m_strHeadPath + QString::number(id) + "/" + QString::number(id) + ".png");

    return id;
}

QJsonObject Database::addFriend(const QString &name)
{
    QString strQuery = "SELECT [id],[status],[head] FROM UserInfo ";
    strQuery.append("WHERE name='");
    strQuery.append(name);
    strQuery.append("';");

    int nId = -1;
    int nStatus = -1;
    QString strHead = "0.bmp";
    QSqlQuery query(strQuery);
    // 查询到有该用户
    if (query.next()) {
        nId     = query.value("id").toInt();
        nStatus = query.value("status").toInt();
        strHead = query.value("head").toString();
    }

    // 构建 Json 对象
    QJsonObject json;
    json.insert("id",  nId);
    json.insert("name", name);
    json.insert("head", strHead);
    json.insert("status", nStatus);

    return json;
}

QJsonObject Database::addGroup(const int &userId, const QString &name)
{
#if 0
    QString strQuery = "SELECT [groupId] FROM GROUPINFO ";
    strQuery.append("WHERE name='");
    strQuery.append(name);
    strQuery.append("' AND userId=");
    strQuery.append(QString::number(userId));

    int nGroupId = -1;
    QString strHead = "1.bmp";

    QSqlQuery query(strQuery);

    // 查询到有该用户组
    if (query.next()) {
        nGroupId = query.value(0).toInt();
        strHead  = query.value(1).toString();
    }
    else {
        // 查询数据库
        query = QSqlQuery("SELECT [id] FROM GROUPINFO ORDER BY id DESC;");
        int nIndex = 0;
        // 查询最高ID
        if (query.next()) {
            nIndex = query.value(0).toInt();
        }

        nIndex   += 1;

        // 查询当前组是否存在
        strQuery = QString("SELECT [groupId] FROM GROUPINFO WHERE name='");
        strQuery.append(name);
        strQuery.append("'");

        query = QSqlQuery(strQuery);
        // 查询最高ID
        if (query.next()) {
            nGroupId = query.value(0).toInt();
            // 根据新ID重新创建用户
            query.prepare("INSERT INTO GROUPINFO (id, groupId, name, userId, identity) "
                          "VALUES (?, ?, ?, ?, ?);");
            query.bindValue(0, nIndex);
            query.bindValue(1, nGroupId);
            query.bindValue(2, name);
            query.bindValue(3, userId);
            query.bindValue(4, 1);
            // 执行插入
            query.exec();
        }
    }
#else
    // 先查询是否有该群组
    QString strQuery = "SELECT [groupId] FROM GroupInfo ";
    strQuery.append("WHERE name='");
    strQuery.append(name);
    strQuery.append("';");

    int nGroupId = -1;
    int nCode    = -1;
    QString strHead = "5.bmp";

    QSqlQuery query(strQuery);

    // 查询到有该用户组
    if (query.next())
    {
        // 查询到有该群组，再判断该用户是否已经加入该群组
        nGroupId = query.value(0).toInt();
        strQuery = QString("SELECT [userId] FROM GroupInfo WHERE groupId=");
        strQuery.append(QString::number(nGroupId));
        strQuery.append("");

        query = QSqlQuery(strQuery);
        // 查询到已经添加到该群组
        if (query.next()) {
            nCode = -2;
        }
        else
        {
            // 查询数据库
            query = QSqlQuery("SELECT [id] FROM GroupInfo ORDER BY id DESC;");
            int nIndex = 0;
            // 查询最高ID
            if (query.next()) {
                nIndex = query.value(0).toInt();
            }

            nIndex   += 1;

            // 根据新ID重新创建用户
            query.prepare("INSERT INTO GroupInfo (id, groupId, name, userId, identity) "
                          "VALUES (?, ?, ?, ?, ?);");
            query.bindValue(0, nIndex);
            query.bindValue(1, nGroupId);
            query.bindValue(2, name);
            query.bindValue(3, userId);
            query.bindValue(4, 3);
            // 执行插入
            query.exec();
        }
    }
#endif
    // 构建 Json 对象
    QJsonObject json;
    json.insert("id",  nGroupId);
    json.insert("name", name);
    json.insert("head", strHead);
    json.insert("code", nCode);

    queryAll();

    return json;
}

QJsonObject Database::createGroup(const int &adminID, const QString &name, qint64 time)
{
//    QString strQuery = "SELECT [id],[groupId],[head] FROM GroupInfo ";

//    strQuery.append("WHERE name='");
//    strQuery.append(name);
//    strQuery.append("' AND userId=");
//    strQuery.append(QString::number(adminID));

//    int nIndex = -1;
//    int nGroupId = -1;
//    QString strHead = "1.bmp";

//    QSqlQuery query(strQuery);
    // 查询到有该用户组
//    if (query.next()) {
//        nIndex   = query.value("id").toInt();
//        nGroupId = query.value("groupId").toInt();
//        strHead  = query.value("head").toString();
//    }
//    else {
//        // 查询数据库
//        query = QSqlQuery("SELECT [id] FROM GroupInfo ORDER BY id DESC;");
//        nIndex = 0;
//        // 查询最高ID
//        if (query.next()) {
//            nIndex = query.value("id").toInt();
//        }

        // 再查询该ID下面的群组
//        nGroupId = 0;
//        strQuery = QString("SELECT [groupId] FROM GroupInfo WHERE userId=");
//        strQuery.append(QString::number(adminID));
//        strQuery.append(" ORDER BY groupId DESC");
//        query = QSqlQuery(strQuery);
//        // 查询最高ID
//        if (query.next()) {
//            nGroupId = query.value("groupId").toInt();
//        }

//        nIndex   += 1;
//        nGroupId += 1;

//        // 根据新ID重新创建用户
//        query.prepare("INSERT INTO GroupInfo (id, groupId, name, head, userId, identity) "
//                      "VALUES (?, ?, ?, ?, ?, ?);");
//        query.bindValue(0, nIndex);
//        query.bindValue(1, nGroupId);
//        query.bindValue(2, name);
//        query.bindValue(3, "1.bmp");
//        query.bindValue(4, adminID);
//        query.bindValue(5, 1);

//        query.exec();
//    }

//    // 构建 Json 对象
//    QJsonObject json;
//    json.insert("id",  nGroupId);
//    json.insert("name", name);
//    json.insert("head", strHead);

//    return json;

    QString strQuery = "SELECT * FROM GroupInfo";
    strQuery.append(" order by id desc");

    int id=0;
    QSqlQuery query(strQuery);
    if (query.next()) {
        id = query.value(0).toInt();
        id++;//分配给该注册用户的id
    }

    QString head = QString::number(id) + ".png";

    // 根据新ID重新创建用户
    query.prepare("INSERT INTO GROUPINFO (id, name, head, adminID, memberCnt,createTime) "
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.bindValue(0, id);
    query.bindValue(1, name);
    query.bindValue(2, head);
    query.bindValue(3, adminID);
    query.bindValue(4, 1);
    query.bindValue(5, QDateTime::fromSecsSinceEpoch(time).toString("yyyy-MM-dd  hh:mm:ss"));

    query.exec();


    //注意，还需要向 群-用户 关系表中插入一条数据
    QSqlQuery query2;
    query2.prepare("INSERT INTO GroupUser (groupID, userID, joinTime) "
                   "VALUES (?, ?, ?);");
    query2.bindValue(0, id);
    query2.bindValue(1, adminID);
    query2.bindValue(2, QDateTime::fromSecsSinceEpoch(time).toString("yyyy-MM-dd  hh:mm:ss"));
    query2.exec();

    QJsonObject json;
    json.insert("group",id);
    json.insert("admin",adminID);
    json.insert("name",name);

    return json;
}

QJsonArray Database::getGroupUsers(const int &groupId)
{
//    QString strQuery = ("SELECT [id],[name] FROM UserInfo WHERE ");
//    strQuery.append(" id=(SELECT [id] FROM GroupInfo WHERE groupId=");
//    strQuery.append(QString::number(groupId));
//    strQuery.append(") AND status=");
//    strQuery.append(QString::number(OffLine));

//    strQuery = "SELECT [userId] FROM GroupInfo WHERE groupId=";
//    strQuery.append(QString::number(groupId));

//    QJsonArray jsonArr;
//    QSqlQuery query(strQuery);
//    jsonArr.append(groupId);
//    // 查询
//    while (query.next()) {
//        int nId = query.value(0).toInt();
//        strQuery = "SELECT [name],[head],[status] FROM UserInfo WHERE id=";
//        strQuery.append(QString::number(nId));

//        QSqlQuery queryUser(strQuery);
//        if (queryUser.next()) {
//            QJsonObject jsonObj;
//            jsonObj.insert("id", nId);
//            jsonObj.insert("name", queryUser.value(0).toString());
//            jsonObj.insert("head", queryUser.value(1).toString());
//            jsonObj.insert("status", queryUser.value(2).toInt());
//            jsonArr.append(jsonObj);
//        }
//    }

//    return jsonArr;

    QString strQuery = ("SELECT [userID] FROM GroupUser WHERE groupID=");
    strQuery.append(QString::number(groupId));

    QJsonArray jsonArr;
    QSqlQuery query(strQuery);
    // 查询
    while (query.next()) {
        int nId = query.value(0).toInt();
        strQuery = "SELECT [name],[head],[status] FROM UserInfo WHERE id=";
        strQuery.append(QString::number(nId));

        QSqlQuery queryUser(strQuery);
        if (queryUser.next()) {
            QJsonObject jsonObj;
            jsonObj.insert("groupid",groupId);
            jsonObj.insert("id", nId);
            jsonObj.insert("name", queryUser.value(0).toString());
            jsonObj.insert("head", queryUser.value(1).toString());
            jsonObj.insert("status", queryUser.value(2).toInt());
            jsonArr.append(jsonObj);
        }
    }

    return jsonArr;
}

QString Database::getSentFile(int senderID, int receiverID, qint64 time)
{
    QString strQuery = ("SELECT * FROM FileSent WHERE senderID=");
    strQuery.append(QString::number(senderID));
    strQuery.append(" AND receiverID=");
    strQuery.append(QString::number(receiverID));
    strQuery.append(" AND time='");
    QString timeStr = QDateTime::fromSecsSinceEpoch(time).toString("yyyy-MM-dd  hh:mm:ss");
    strQuery.append(timeStr + "'");
    qDebug() << "user:" << receiverID << "request for downloading file "
             << "file sent time:" << time << timeStr;
    qDebug() << "database search for file:" << strQuery;

    QSqlQuery query(strQuery);
    while(query.next()){
        QString filepath = query.value(5).toString();
        QString filename = query.value(3).toString();

        return filepath + filename;
    }
    return "";
}

QString Database::getUserName(const int &id) const
{
    QString strQuery = "SELECT [name] FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QSqlQuery query(strQuery);
    if (query.next()) {
        return query.value(0).toString();
    }

    return "";
}

QString Database::getUserHead(const int &id) const
{
    QString strQuery = "SELECT [head] FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QSqlQuery query(strQuery);
    if (query.next()) {
        return query.value(0).toString();
    }

    return "1.bmp";

}

QJsonObject Database::getUserInfo(const int &id) const
{
    QString strQuery = "SELECT * FROM UserInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QJsonObject jsonObj;
    int nCode = -1;
    // 查询数据库
    QSqlQuery query(strQuery);
    // 构建用户的所有信息,不包括密码
    if (query.next()) {
        jsonObj.insert("id", query.value("id").toInt());
        jsonObj.insert("name", query.value("name").toString());
        jsonObj.insert("head", query.value("head").toString());
        jsonObj.insert("status", query.value("status").toInt());
//        jsonObj.insert("groupId", query.value("group").toInt());
        jsonObj.insert("lasttime", query.value("lasttime").toString());
        // 结果代码
        nCode = 0;
    }

    jsonObj.insert("code", nCode);

    return jsonObj;
}

QJsonObject Database::getGroupInfo(const int &id) const
{
    QString strQuery = "SELECT * FROM GroupInfo ";
    strQuery.append("WHERE id=");
    strQuery.append(QString::number(id));

    QJsonObject jsonObj;
    int nCode = -1;
    // 查询数据库
    QSqlQuery query(strQuery);
    // 构建用户的所有信息,不包括密码
    if (query.next()) {
        jsonObj.insert("id", query.value("id").toInt());
        jsonObj.insert("name", query.value("name").toString());
        jsonObj.insert("head", query.value("head").toString());
        jsonObj.insert("adminID", query.value("adminID").toInt());
        jsonObj.insert("memberCnt", query.value("memberCnt").toInt());
        jsonObj.insert("createTime", query.value("createTime").toString());
        // 结果代码
        nCode = 0;
    }

    jsonObj.insert("code", nCode);

    return jsonObj;
}

QJsonArray Database::getOfflineMsg(int id)
{
    QString sql = "select * from UnreadMsg where receiverID=";
    sql.append(QString::number(id));
    sql.append(" ORDER BY time ASC;");//按时间递增

    QJsonArray jsonArr;

    QSqlQuery query(sql);
    query.exec();
    while(query.next()){
        QJsonObject jsonObj;
        jsonObj.insert("senderID", query.value(0).toInt());
        jsonObj.insert("receiverID", query.value(1).toInt());
        jsonObj.insert("groupID", query.value(2).toInt());
        jsonObj.insert("type", query.value(3).toInt());
        jsonObj.insert("time", query.value(4).toInt());
        jsonObj.insert("msg", query.value(5).toString());
        jsonObj.insert("tag", query.value(6).toInt());
        jsonObj.insert("fileSize",query.value(7).toInt());
        jsonArr.append(jsonObj);
    }

    //注意，记得删除已发送给用户的离线消息
    sql = "delete from UnreadMsg where receiverID=";
    sql.append(QString::number(id));
    query.exec(sql);

    return jsonArr;
}

void Database::queryAll()
{
    QSqlQuery query("SELECT * FROM UserInfo ORDER BY id;");
    qDebug() << "query users";
    while (query.next()) {
        qDebug() << query.value(0).toInt() << query.value(1).toString()
                 << query.value(2).toString() << query.value(3).toString()
                 << query.value(4).toString() << query.value(5).toString();
    }
    qDebug() << "query group";
    query = QSqlQuery("SELECT * FROM GroupInfo ORDER BY id;");
    while (query.next()) {
        qDebug() << query.value(0).toInt() << query.value(1).toInt()
                 << query.value(2).toString() << query.value(3).toString()
                 << query.value(4).toInt() << query.value(5).toInt();
    }

    query = QSqlQuery("SELECT * FROM UnreadMsg ORDER BY id;");
    while (query.next()) {
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString() << query.value(2).toString().length()
                 << query.value(2).toString().length();
    }
}
