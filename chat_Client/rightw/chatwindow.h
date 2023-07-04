#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include "rightw/bubble/bubblelist.h"     //气泡
#include "listwidget.h"
#include "inputwidget.h"
#include "tcp_manage.h"
#include "myemotionwidget.h"
#include"CutScreen/screen.h"
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QTime>
#include <QElapsedTimer>

namespace Ui {
class ChatWindow;
}
class TopBar : public QWidget{
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);


protected:
    virtual void paintEvent(QPaintEvent *) override;

    // 重写鼠标操作以实现移动窗口
    virtual void mousePressEvent(QMouseEvent *event) override;
};

class GroupList : public QWidget
{
    Q_OBJECT
public:
    explicit GroupList(QWidget *parent = nullptr);
    QLabel *groupListLabel;
    ListWidget *memberList;

    void paintEvent(QPaintEvent *);
};

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
//    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
    explicit ChatWindow(QWidget *parent = nullptr,Cell *cell = nullptr);

    void setCell(Cell *c){cell = c;}
    int  getID(){return cell->id;}
    void InitGroupList();
    void sendTimeMsg(qint64 time, QString msg);//更新中栏格子时间并且更新消息内容
    void setTag(int tag){ this->tag = tag;tcpFileSocket->setTag(tag); }
    void refreshGroupList(QJsonValue &dataVal);
    void addCellToGroupList(Cell *);
    void removeCellFromGroupList(int id);
    void forbidSendMsg();
    void allowSendMsg();
    void addSystemMsg(QString msg);
    void msgReceived(QJsonValue &value);//接收服务器转发过来的消息，并在界面上显示出来

    void msgconfirmed(qint64 time);
    void writeMsgToDatabase(BubbleInfo*);//把消息写入本地数据库
    void loadMsgFromDatabase();//从数据库中加载聊天记录
    void startLoadingAnimation();

    GroupList *groupList;

    QLabel *loadingLabel;
    QMovie *loadingMovie;

private:
    bool open = true;
    Cell *cell;//记录该聊天窗口对方的信息
    int tag = 0;//记录该聊天窗口是私聊窗口还是群聊窗口，tag = 0为私聊窗口，tag = 1为群聊窗口

    qint64 lastMsgTime = 0;

    //文件传输
    clientFileSock *tcpFileSocket;
    QString fileName;
//    QTime updateTime;
    QElapsedTimer updateTime;
    quint8 fileType;
    bool busy = false;
    BubbleInfo *curFileBubble;

signals:
    void signalSendMessage(const quint8 &type, const QJsonValue &json);//发消息给服务器
    void updateMidBarTime(int id,qint64 time,QString msg);//更新中栏对应格子的时间

public slots:
    void sendMsg();//发送消息
    void onSonMenuSelected(QAction*);
    void stopLoadingAnimation();

    //文件传输
    void sltSendFileFinished(quint8,QString);
    void sltRecvFileFinished(quint8,QString,int);
    void sltUpdateProgress(qint64 bytes,qint64 total);
    void sltFileArrived(const QJsonValue&);

    //inputwindow
    void changeColor();
    void restoreColor();

private slots:
    void on_listbtn_clicked();

    void on_btn_screenshot_clicked();


private:
    Ui::ChatWindow *ui;
    Screen *screen;
    MyEmotionWidget *emoj;
};

#endif // CHATWINDOW_H










