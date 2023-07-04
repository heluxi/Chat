
//#include"mainwindow.h"
#include <QApplication>
#include"sql_manage.h"
#include "rotatingstackedwidget.h"
#include "myapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyApp::initApp(a.applicationDirPath());


    //加载数据库
    sql_manage::Instance()->openUserdb(MyApp::m_strDatabasePath + "user.db");



    //显示登陆界面
    RotatingStackedWidget launcher;
    launcher.show();
//    MainWindow w;

    return a.exec();
}
