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

   void connectServer(const QString &host, const int &port);
   void sendMsg(QString msg);
   QByteArray recvMsg();

signals:
void recvFormServre(QByteArray);
void connectSucess();
private:
    static QTcpSocket *tcpSocket;
    QString name="default";


};

#endif // TCP_MANAGE_H
