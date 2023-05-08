#include "tcp_manage.h"
#include <QDir>
#include<QMessageBox>

QTcpSocket* clientSock::tcpSocket=nullptr;
QTcpSocket* clientFileSock:: fileSocket=nullptr;

clientSock::clientSock(QObject *parent)
    : QObject{parent}
{
    if(tcpSocket==nullptr)
    {
        tcpSocket = new QTcpSocket(this);
    }

    connect(tcpSocket,&QTcpSocket::connected,this,[=](){
        emit connectSucess();

        QMessageBox::information(NULL,"sucess","连接成功！",QMessageBox::Ok);

    });
    connect(tcpSocket,&QTcpSocket::readyRead,this,&clientSock::recvMsg);

}

void clientSock::connectServer(const QString &host, const int &port)
{
    tcpSocket->connectToHost(QHostAddress(host), quint16(port));

}

void  clientSock:: sendMsg(QString msg)
{
        QString sendmsg=QString("[%1]:%2").arg(name).arg(msg);
        int len=tcpSocket->write(sendmsg.toUtf8());
        if(len<0)
        {
            qDebug()<<"发送失败！";
        }

}

QString clientSock::recvMsg()
{

    QByteArray data=tcpSocket->readAll();
    qDebug()<<"recv msg from server "<<data;
    QString msg=data;
    if(msg.section("##",0,0)=="sendmsg")
    {
        msg=msg.section("##",1,1);
        emit recvFormServre(msg);
        qDebug()<<"recv msg from server "<<msg;
        return msg;
    }
}

QString clientSock::getName()
{
    return name;
}



//发送接受文件的套接字

clientFileSock::clientFileSock(QObject *parent)
    : QObject{parent}
{
    if(fileSocket==nullptr)
        fileSocket=new QTcpSocket(this);
    fileSize=0;
    isfile=false;
    connect(fileSocket,&QTcpSocket::connected,this,[=](){
        qDebug()<<"文件套接字连接成功";
    });
    connect(fileSocket,&QTcpSocket::readyRead,this,&clientFileSock::recvFile);
    connect(&timer,&QTimer::timeout,this,[=](){
        timer.stop();
        int len;
        do{
            char buf[4*1024]={0};
            len=0;
            len=file.read(buf,sizeof(buf));
            fileSocket->write(buf,len);
            sendSize+=len;
        }while(len>0);
        if(sendSize==fileSize)
        {
            file.close();
            emit sendFileSucess(fileName);
        }

    });
}

void clientFileSock::connectServer(const QString &host, const int &port)
{
   fileSocket->connectToHost(QHostAddress(host), quint16(port));
}

void clientFileSock::sendFile(QString filePath)
{

    fileSize=0;
    sendSize=0;
    //获取文件的信息
    QFileInfo info(filePath);
    fileName=info.fileName();
    fileSize=info.size();

    file.setFileName(filePath);
    QString head=QString("sendfile##%1##%2").arg(fileName).arg(fileSize);
    if(!file.open(QIODevice::ReadOnly))
         qDebug()<<"打开文件出错";
    //先发送头部信息
    int len=fileSocket->write(head.toUtf8());
    //发送真正的文件信息，防止Tcp粘包
    if(len>0)
    {
        timer.start(20);
    }
    else
    {
        qDebug()<<"头部信息发送失败";
        file.close();
    }

}

void clientFileSock::recvFile()
{
    QByteArray readMsg=fileSocket->readAll();
    QString msg=readMsg;
    //解析服务器发来的数据
    if(msg.section("##",0,0)=="sendfile")
    {
        recvFileName=msg.section("##",1,1);
        recvFileSize=msg.section("##",2,2).toInt();
        recvfile.setFileName("../"+recvFileName);

        if(!recvfile.open(QIODevice::WriteOnly))
            qDebug()<<"文件打开失败";

        isfile=true;
        qDebug()<<isfile;
    }
    else if(isfile)
    {
        qDebug()<<"读取文件";
        recvSize=0;
        int len=recvfile.write(readMsg);
        recvSize+=len;
        if(recvSize==recvFileSize)
        {
            emit sucessRecvfile(recvFileName);
            recvfile.close();
            recvFileName.clear();
            recvFileSize=0;
            isfile=false;
        }
    }

}
