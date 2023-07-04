#include "mainwindow.h"

#include<database.h>
#include <QApplication>
#include "myapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //初始化程序
    MyApp::InitApp(a.applicationDirPath());
    qDebug() << "初始化路径完毕，当前路径为:" << a.applicationDirPath();

    // 加载数据库
    Database::Instance()->openDb(MyApp::m_strDatabasePath+"server.db");

    MainWindow w;
    w.show();

    return a.exec();
}
