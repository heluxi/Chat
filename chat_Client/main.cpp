#include "mainwindow.h"

#include <QApplication>
#include"sql_manage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载数据库
    sql_manage::getinstance()->openUserdb();
    sql_manage::getinstance()->openMsgdb();

    MainWindow w;
    w.show();
    return a.exec();
}
