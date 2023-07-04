#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
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
//#include <weather_param/weather_info.h>
#include"weather/weather_param/weather_info.h"

class WEATHER : public QObject
{
    Q_OBJECT
public:
    explicit WEATHER(QObject *parent = nullptr);

    ~WEATHER();

    QNetworkAccessManager * manager;

    WEATHER_INFO * weather_info;

    QString getCityIdFromJson(QString province, QString city);

    /* 空气质量指数结果 */
    void airQualityIndexResult(int aqi, int i);

    /* 天气类型结果 */
    void weatherTypeResult(QString type, int i);

    /* 解析查询结果 */
    void parsingNetworkResult(QByteArray);

    /* 发送网络请求，请求获取天气信息 */
    void sendNetworkRequest(QString procince, QString city);

    /* 获取城市名称 */
    QString getcityName(QJsonObject obj);

    /* 获取更新时间 */
    QString getUpdateTime(QJsonObject obj);

    /* 获取当前时间 */
    QString getDataAndTime(QJsonObject obj);

    /* 获取实时温度信息 */
    QString getRealTimeTemp(QJsonObject obj);

    /* 获取空气质量 */
    QString getRealTimeAirQuality(QJsonObject obj);

    /* 获取天气提示 */
    QString getWeatherNotice(QJsonObject obj);

    /* 获取预报温度 */
    QString getForecastTemp(QJsonObject obj, quint8 index);

    /* 获取预报天气类型 */
    QString getForecastWeatherType(QJsonObject obj, quint8 index);

    /* 获取预报日期 */
    QString getForecastDataAndWeek(QJsonObject obj, quint8 index);

    /* 获取预报风向及风力 */
    QString getForecastWindDirAndPower(QJsonObject obj, quint8 index);

    /* 获取天气提示 */
    QString getForecastWeatherNotice(QJsonObject obj, quint8 index);

    /* 获取当前的状态下的省份 */
    QString getCurrentProvince() const;

    /* 设置当前的状态下的省份 */
    void setCurrentProvince(const QString &value);

    /* 获取当前的状态下的城市 */
    QString getCurrentCity() const;

    /* 设置当前的状态下的城市 */
    void setCurrentCity(const QString &value);

signals:

    void signal_emit_weather_info(WEATHER_INFO *);

private slots:

    void slot_new_obj();

    void slot_refresh_manually();

    void slot_manager_read_finished(QNetworkReply *reply);

    void slot_change_local_city(QString);

    void slot_tim_update_weather();

private:

    QTimer * timForRefresh = nullptr;

    QString currentProvince;

    QString currentCity;

};

#endif // WEATHER_H
