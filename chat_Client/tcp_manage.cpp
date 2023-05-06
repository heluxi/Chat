#include "tcp_manage.h"
#include<QMessageBox>

QTcpSocket* tcp_manage::tcpSocket=nullptr;

tcp_manage::tcp_manage(QObject *parent)
    : QObject{parent}
{
    if(tcpSocket==nullptr)
    {
        tcpSocket = new QTcpSocket(this);
    }

    connect(tcpSocket,&QTcpSocket::connected,this,[=](){
        emit connectSucess();
        qDebug()<<"连接成功";
        QMessageBox::information(NULL,"sucess","连接成功！",QMessageBox::Ok);
    });
    connect(tcpSocket,&QTcpSocket::readyRead,this,&tcp_manage::recvMsg);

}

void tcp_manage::connectServer(const QString &host, const int &port)
{
    tcpSocket->connectToHost(QHostAddress(host), quint16(port));

}

void  tcp_manage:: sendMsg(QString msg)
{
        QString sendmsg=QString("[%1]:%2").arg(name).arg(msg);
        tcpSocket->write(sendmsg.toUtf8());

}

QByteArray tcp_manage::recvMsg()
{

    QByteArray data=tcpSocket->readAll();
    emit recvFormServre(data);
    return data;
}



