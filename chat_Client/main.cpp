#include "mainwindow.h"

#include <QApplication>
#include"sql_manage.h"
#include"page_login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载数据库
    sql_manage::getinstance()->openUserdb();
    sql_manage::getinstance()->openMsgdb();

    Page_login login;
    login.show();
    MainWindow w;
    w.show();
    return a.exec();
}
