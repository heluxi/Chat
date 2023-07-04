#ifndef MESSAGEDLG_H
#define MESSAGEDLG_H

#include <QWidget>

namespace Ui {
class MessageDlg;
}

class MessageDlg : public QWidget
{
    Q_OBJECT

public:
    explicit MessageDlg(QWidget *parent = nullptr,int id=-1,QString name="");
    ~MessageDlg();

    void setTitle(const QString &newTitle);

    void setMsg(const QString &newMsg);
signals:
    void signalAddFriend(const quint8 &,const QJsonValue&);

private slots:
    void on_agreeBtn_clicked();

private:
    Ui::MessageDlg *ui;
    int id;
    QString name;
    QString title;
    QString msg;
};

#endif // MESSAGEDLG_H
