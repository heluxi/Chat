#ifndef WTHEATHERDLG_H
#define WTHEATHERDLG_H

#include <QWidget>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QUrl>
#include <QDebug>
#include "weather/global.h"
#include <QTimer>
#include"weather/class_net_thread/net_thread.h"
#include"weather/dialog_change_city/dialog_change_city.h"

namespace Ui {
class wtheatherDlg;
}

class wtheatherDlg : public QWidget
{
    Q_OBJECT

public:
    explicit wtheatherDlg(QWidget *parent = nullptr);
    ~wtheatherDlg();
    QStringList showMessageList;

    QTimer * timShowMessage = nullptr;

    /* 插入weak label */
    void pushListWeak();

    void pushListDate();

    void pushListWeatherType();
private slots:

    /* 网络获取的信息槽函数 */
    void slot_read_network_data(QNetworkReply * reply);

    void slot_get_weather_info(WEATHER_INFO *);

    void slot_change_local_city();

    void slot_show_message();

private:
    Ui::wtheatherDlg *ui;
    NET_THREAD * netThread = nullptr;

    Dialog_Change_City * dialog_change_city = nullptr;
};

#endif // WTHEATHERDLG_H
