#include "tcpserver.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QTcpSocket>

TcpServer::TcpServer(QObject *parent)
    : QObject{parent}
{

}

bool TcpServer::listen(int port)
{
    return m_tcpServer->listen(QHostAddress::Any, quint16(port));
}

void TcpServer::closeListen()
{
    m_tcpServer->close();
}


//msgServer

TcpMsgServer::TcpMsgServer(QObject *parent):TcpServer(parent)
{

}

void TcpMsgServer::sltNewConnection()
{
    //有新客户端连接
    QTcpSocket* sockCln=nullptr;
    sockCln=m_tcpServer->nextPendingConnection();
    QString ip=sockCln->peerAddress().toString();
    int port=sockCln->peerPort();
    QString showClint=QString("ip:%1 port:%2").arg(ip).arg(port);
    ui->textEdit->append(showClint);

    sockLists.append(sockCln);

    connect(sockCln, SIGNAL(signalConnected()), this, SLOT(sltConnected()));
    connect(sockCln, SIGNAL(signalDisConnected()), this, SLOT(sltDisConnected()));

}
