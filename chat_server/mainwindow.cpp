#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sockSer=new QTcpServer(this);
    sockSer->listen(QHostAddress::Any,quint16(8888));
    connect(sockSer,&QTcpServer::newConnection,this,[=](){

        sockCln=sockSer->nextPendingConnection();
        QString ip=sockCln->peerAddress().toString();
        int port=sockCln->peerPort();
        QString showClint=QString("ip:%1 port:%2").arg(ip).arg(port);
        ui->textEdit->append(showClint);
        connect(sockCln,&QTcpSocket::readyRead,this,[=](){

            QByteArray readmsg=sockCln->readAll();

            sockCln->write(readmsg);
        });
    }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

