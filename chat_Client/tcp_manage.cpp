#include "tcp_manage.h"
#include<QMessageBox>


tcp_manage::tcp_manage(QObject *parent)
    : QObject{parent}
{

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&tcp_manage::recvMsg);

}

void tcp_manage::connectServer(const QString &host, const int &port)
{
    tcpSocket->connectToHost(host, quint16(port));
}

int tcp_manage::sendMsg(QString msg)
{
        QString sendmsg=name+msg;
        tcpSocket->write(msg.toUtf8());

}

QByteArray tcp_manage::recvMsg()
{

    QByteArray data=tcpSocket->readAll();
    emit recvFormServre(data);
    return data;
}



