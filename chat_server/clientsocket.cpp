#include "clientsocket.h"
#include "type.h"

#include <QJsonDocument>
#include <QJsonObject>

tcpSocket::tcpSocket(QObject *parent,QTcpSocket* tcpsock)
    : QObject{parent},tcpsock{tcpsock}
{
    connect(tcpsock,&QTcpSocket::readyRead,this,&tcpSocket::readMsg);
    connect(tcpsock,&QTcpSocket::disconnected,this,[=](){tcpsock->deleteLater();});
}

void tcpSocket::readMsg()
{
    QByteArray byteArray=tcpsock->readAll();
    //解析数据
    QJsonParseError jsonError;
    QJsonDocument document=QJsonDocument::fromJson(byteArray,&jsonError);

    if((!document.isNull())&&(QJsonParseError::NoError==jsonError.error))
    {
        if(document.isObject())
        {
            QJsonObject jsonObj=document.object();
            ID=jsonObj.value("from").toInt();
            int type=jsonObj.value("type").toInt();
            QString data=jsonObj.value("data").toString();
            int recvID=jsonObj.value("to").toInt();
            switch (type) {
            case SendMsg://私发消息
                emit sendMessagetoClient(data,recvID);//由tcpServer查找发送的目标主机
                break;
            default:
                break;
            }

        }

    }
}

void tcpSocket::sendMessage(QString data)
{
    //封装发送的消息
    QJsonObject jsonObj;
    jsonObj.insert("type",SendMsg);
    jsonObj.insert("from",ID);
    jsonObj.insert("data",data);

    QJsonDocument document;
    document.setObject(jsonObj);

    tcpsock->write(document.toJson(QJsonDocument::Indented));
}

int tcpSocket::getID()
{
    return ID;

}




tcpFileSocket::tcpFileSocket(QObject *parent, QTcpSocket *sock):QObject{parent},fileSock{sock}
{
    ID=-1;
    connect(fileSock,&QTcpSocket::readyRead,this,&tcpFileSocket::readFileMsg);
    connect(fileSock,&QTcpSocket::disconnected,[=](){
        fileSock->deleteLater();
    });
    connect(this,&tcpFileSocket::headmsg,this,&tcpFileSocket::handleHeadmsg);
    connect(&timer,&QTimer::timeout,this,[=](){

        qDebug()<<"send";
       if(!file.open(QIODevice::ReadOnly))
           qDebug()<<"文件打开失败";
       int len;
       do{

           char buf[4*1024]={0};
           len=0;
           len=file.read(buf,sizeof(buf));
           len=fileSock->write(buf,len);
           sendSize+=len;
       }while(len>0);
       if(sendSize==fileSize)
       {
           file.close();
           sendSize=0;
           qDebug()<<"文件发送成功";
       }
    });

}

int tcpFileSocket::getID() const
{
    return ID;
}

void tcpFileSocket::readFileMsg()
{
    QByteArray msg=fileSock->readAll();
    qDebug()<<"recv from client"<<msg;
   //解析发送的消息 是否为文件的头部信息
    QJsonParseError parseError;
    QJsonDocument docuemnt=QJsonDocument::fromJson(msg,&parseError);
    if((!docuemnt.isNull())&&(parseError.error==QJsonParseError::NoError))
    {
        if(docuemnt.isObject())
        {
           QJsonObject JsonObj=docuemnt.object();
           int type=JsonObj.value("type").toInt();
           ID=JsonObj.value("from").toInt();
           recvID=JsonObj.value("to").toInt();
           QString data=JsonObj.value("data").toString();
           switch (type) {
           case SendFileHead:
               emit headmsg(data);//文件头部信息
               break;
           default:

               break;
           }


        }
       return;
    }
    handleFileMsg(msg);

}

void tcpFileSocket::handleHeadmsg(QString data)
{
    fileName=data.section("##",0,0);
    fileSize=data.section("##",1,1).toInt();
    file.setFileName(fileName);
   if(!file.open(QIODevice::WriteOnly))
   {
       qDebug()<<"打开文件失败";
   }


}

void tcpFileSocket::handleFileMsg(QByteArray data)
{

    qDebug()<<"开始写文件";

    recvSize=0;
    int len=file.write(data);
    recvSize+=len;

    if(recvSize==fileSize)//接受完文件
    {
        qDebug()<<"接受文件完成";
        isFile=false;
        file.close();
        //发送文件给用户
        sendFileToUSer(recvID);
    }
}

void tcpFileSocket::sendFile()
{
    //封装发送的头部信息
    QString data=QString("%0##%1").arg(fileName).arg(fileSize);
    QJsonObject JsonObj;
    JsonObj.insert("from",ID);
    JsonObj.insert("type",SendFileHead);
    JsonObj.insert("data",data);
    QJsonDocument document;
    document.setObject(JsonObj);
    int len=fileSock->write(document.toJson(QJsonDocument::Indented));
    if(len>0)
   {
        qDebug()<<"文件的头部的信息发送完成";
        timer.start(20);
    }

}
