#ifndef TCP_MANAGE_H
#define TCP_MANAGE_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>


class tcp_manage : public QObject
{
    Q_OBJECT
public:
    explicit tcp_manage(QObject *parent = nullptr);


    void error_handing(QString msg)
    {
        qDebug()<<msg;

    }

   void connectServer(const QString &host, const int &port);
   int sendMsg(QString msg);
   QByteArray recvMsg();

signals:
void recvFormServre(QByteArray);
private:
    QTcpSocket *tcpSocket;
    QString name="default";


};

#endif // TCP_MANAGE_H
