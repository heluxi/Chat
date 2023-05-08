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
    connect(&timer,&QTimer::timeout,this,[=](){
        qDebug()<<"开始发送文件";
        timer.stop();
        sendfile(curScok);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readMsg()
{
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
        connect(sockCln,&QTcpSocket::readyRead,[=](){


                QByteArray readmsg=sockCln->readAll();

                  qDebug()<<"recv from client"<<readmsg<<sockCln->peerPort();
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
                       fileport=sockCln->peerPort();
                }
                else if(isFile)
                {
                    qDebug()<<"开始写文件";

                    recvSize=0;
                    int len=file.write(readmsg);
                    recvSize+=len;
                    if(recvSize==fileSize)//接受完文件
                    {
                        qDebug()<<"接受文件完成";
                        isFile=false;
                        file.close();
                        //发送文件给其他客户端
                        foreach (QTcpSocket* sock, sockLists) {
                            if(sock->peerPort()!=port)
                            {
                                curScok=sock;
                                sendhead(sock);
                            }

                        }
                    }

                }
                else//读取文本信息
                {
                    qDebug()<<"发送文本消息";
                    foreach (QTcpSocket* sock, sockLists) {
                        QString sendmsg=QString("sendmsg##%1").arg(message);
                        sock->write(sendmsg.toUtf8());
                    }


                }
            }

        );




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

void MainWindow::sendfile(QTcpSocket *&sock)
{
     qDebug()<<"send";
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"文件打开失败";
    int len;
    do{

        char buf[4*1024]={0};
        len=0;
        len=file.read(buf,sizeof(buf));
        len=sock->write(buf,len);
        sendSize+=len;
    }while(len>0);
    if(sendSize==fileSize)
    {
        curScok=nullptr;
        file.close();
        sendSize=0;
        qDebug()<<"文件发送成功";
    }

}

void MainWindow::sendhead(QTcpSocket *&sock)
{
    //封装头部信息
    QString head=QString("sendfile##%1##%2").arg(fileName).arg(fileSize);
    sock->write(head.toUtf8());
    timer.start(20);

}

