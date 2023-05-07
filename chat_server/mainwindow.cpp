#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFile=false;

    sockSer=new QTcpServer(this);
    sockSer->listen(QHostAddress::Any,quint16(8888));
    connect(sockSer,&QTcpServer::newConnection,this,&MainWindow::newConnect);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readMsg()
{
    foreach (QTcpSocket * sockCln, sockLists) {
        qDebug()<<"recv from client";
        QByteArray readmsg=sockCln->readAll();
        ui->textEdit->append(readmsg);
        //解析发送来的数据
        QString message=readmsg;
        if(message.section("##",0,0)=="sendfile")
        {
                fileName=message.section("##",1,1);
                fileSize=message.section("##",2,2).toUInt();
                file.setFileName(fileName);
                if(!file.open(QIODevice::WriteOnly))
                    qDebug()<<"文件打开失败";

               isFile=true;
        }
        else if(isFile)
        {
            qDebug()<<"开始写文件";

            recvSize=0;
            int len=file.write(readmsg);
            recvSize+=len;
            if(recvSize==fileSize)//接受完文件
            {
                isFile=false;
                file.close();
                fileSize=0;
                //发送文件名字给每个客户端
                foreach (QTcpSocket* sock, sockLists) {
                    QString msg=QString("[%1]:%2").arg(sock->peerPort()).arg(fileName);
                    sock->write(msg.toUtf8());

                }
                fileName.clear();
            }

        }
        else//读取文本信息
        {
            foreach (QTcpSocket* sock, sockLists) {
                sock->write(readmsg);
            }


        }
    }

}

void MainWindow::newConnect()
{
        QTcpSocket* sockCln=nullptr;;
        sockCln=sockSer->nextPendingConnection();
        QString ip=sockCln->peerAddress().toString();
        int port=sockCln->peerPort();
        QString showClint=QString("ip:%1 port:%2").arg(ip).arg(port);
        ui->textEdit->append(showClint);

        sockLists.append(sockCln);
        connect(sockCln,&QTcpSocket::readyRead,this,&MainWindow::readMsg);
        connect(sockCln,&QTcpSocket::disconnected,this,&MainWindow::removeSocket);

}

void MainWindow::removeSocket()
{
    int i=0;
    foreach(QTcpSocket* soc, sockLists)
        {
            if(soc->state() == QTcpSocket::UnconnectedState)
            {
                qDebug()<<soc->peerAddress().toString()<<"closed";
                soc->deleteLater();
                sockLists.removeAt(i); //tcpSockets.removeOne(soc);
            }
            i++;

        }

}

