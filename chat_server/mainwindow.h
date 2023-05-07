#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readMsg();
    void newConnect();
    void removeSocket();

private:
    Ui::MainWindow *ui;
    QTcpServer *sockSer;//用于监听
    QList<QTcpSocket*> sockLists;//用于通信
    QFile file;
    QString fileName;
    int fileSize;
    bool isFile;
    int recvSize;
};
#endif // MAINWINDOW_H
