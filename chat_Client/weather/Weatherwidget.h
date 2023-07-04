#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

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



QT_BEGIN_NAMESPACE
namespace Ui { class WeatherWidget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

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

signals:


private:
    Ui::WeatherWidget *ui;

    NET_THREAD * netThread = nullptr;

    Dialog_Change_City * dialog_change_city = nullptr;
};
#endif // WEATHERWIDGET_H
