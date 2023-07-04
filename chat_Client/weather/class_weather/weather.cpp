#include "weather.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
//#include <QTextCodec>

WEATHER::WEATHER(QObject *parent) : QObject(parent)
{
    setCurrentProvince("广东");
    setCurrentCity("宝安");
}

WEATHER::~WEATHER()
{
    delete weather_info;

    delete manager;
}

QString WEATHER::getCityIdFromJson(QString province, QString city)
{
    QJsonParseError error;
    QByteArray      jsonDate;
    QJsonArray      jsonArray;
    QString appPath = QDir::currentPath();
    QString filePath;

    filePath = tr(":/jsonCity/city.json");

    QFile jsonFile(filePath);

    jsonFile.open(QIODevice::ReadOnly);

    jsonDate = jsonFile.readAll();

    jsonFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonDate, &error);

    if(error.error != QJsonParseError::NoError)
    {
        dbg("json read error",0);
    }

    QJsonObject jsonObejct = jsonDoc.object();
    jsonArray = jsonObejct.value("cityName").toArray();
    QJsonObject dateObj = jsonArray.at(0).toObject();
    QString     date = dateObj.value("provinceZh").toString();
    QString     cityId;

    for(int i=0; i<jsonArray.size(); i++)
    {
        dateObj = jsonArray.at(i).toObject();

        if(dateObj.value("cityZh").toString().contains(city)
        && dateObj.value("provinceZh").toString().contains(province))
        {
            cityId = dateObj.value("id").toString();
            break;
        }
    }

    return cityId;
}


/**
 * @brief WEATHER::airQualityIndexResult
 * @param aqi
 * @param i
 */
void WEATHER::airQualityIndexResult(int aqi, int i)
{

}

/**
 * @brief WEATHER::weatherTypeResult
 * @param type
 * @param i
 */
void WEATHER::weatherTypeResult(QString type, int i)
{

}

/**
 * @brief WEATHER::parsingNetworkResult
 * @param data
 */
void WEATHER::parsingNetworkResult(QByteArray data)
{
    QJsonParseError error;

    /* 从解析的文件里获取 */
    QJsonDocument  jsonDoc = QJsonDocument::fromJson(data, &error);

    if(error.error != QJsonParseError::NoError)
    {
        dbg("json error", 0);
    }
    else
    {
        dbg("json no error", 0);
    }

    dbg("data:",data);

    /* 获取json对象 */
    QJsonObject jsonObejct = jsonDoc.object();

    /* 根据json对象，获取json数据里的城市 */
    weather_info->cityName = getcityName(jsonObejct);

    dbg("city name:", weather_info->cityName);

    /* 根据json对象，获取json数据里的城市 */
    weather_info->realTime.temp = getRealTimeTemp(jsonObejct);

    dbg("temp:", weather_info->realTime.temp);

    weather_info->realTime.airQuality = getRealTimeAirQuality(jsonObejct);

    dbg("air quality:", weather_info->realTime.airQuality);

    weather_info->realTime.updateTime = getUpdateTime(jsonObejct);

    dbg("update time:", weather_info->realTime.updateTime);

    weather_info->dataAndTime = getDataAndTime(jsonObejct);

    dbg("date time:", weather_info->dataAndTime);

    weather_info->forecast[0].temp = getForecastTemp(jsonObejct, 0);

    weather_info->forecast[0].weatherType = getForecastWeatherType(jsonObejct, 0);

    weather_info->forecast[0].dataAndWeek = getForecastDataAndWeek(jsonObejct, 0);

    weather_info->forecast[0].windDirAndPower = getForecastWindDirAndPower(jsonObejct, 0);

    weather_info->forecast[0].notice = getForecastWeatherNotice(jsonObejct, 0);

    emit signal_emit_weather_info(weather_info);
}

void WEATHER::sendNetworkRequest(QString procince, QString city)
{
    QNetworkRequest  request;
    QString url;

    url.append(weather_api);

    url.append(getCityIdFromJson(procince, city));

    dbg("url:", url);
    request.setUrl(QUrl(url));

    manager->get(request);
}

/**
 * @brief 获取当前城市
 * @param obj
 * @return 城市名字
 */
QString WEATHER::getcityName(QJsonObject obj)
{
    QJsonObject cityInfoObj;

    QString cityName;

    cityInfoObj = obj.value("cityInfo").toObject();

    cityName = cityInfoObj.value("city").toString();

    return cityName;
}

/**
 * @brief 获取天气信息更新时间
 * @param obj
 * @return 时间
 */
QString WEATHER::getUpdateTime(QJsonObject obj)
{
    QJsonObject cityInfoObj;

    QString updateTime;

    cityInfoObj = obj.value("cityInfo").toObject();

    updateTime = cityInfoObj.value("updateTime").toString();

    return updateTime;
}

/**
 * @brief 获取当前时间和日期
 * @param obj
 * @return 年月日 时分
 */
QString WEATHER::getDataAndTime(QJsonObject obj)
{
    QString date;
    QString time;
    QString dateAndTime;

    date = obj.value("time").toString().mid(0, 10);
    time = obj.value("time").toString().mid(11, 5);

    date = date.replace(4, 1, tr("年"));
    date = date.replace(7, 1, tr("月"));
    date.append(tr("日"));

    dateAndTime = date + " " + time;

    return dateAndTime;
}

/**
 * @brief 获取实时温度
 * @param obj
 * @return 实时温度值，qstring
 */
QString WEATHER::getRealTimeTemp(QJsonObject obj)
{
    QJsonObject dataObj;

    QString realTimeTemp;

    dataObj = obj.value("data").toObject();

    realTimeTemp = dataObj.value("wendu").toString();

    return realTimeTemp;
}

/**
 * @brief 获取实时空气质量
 * @param obj
 * @return 实时空气质量，qstring
 */
QString WEATHER::getRealTimeAirQuality(QJsonObject obj)
{
    QJsonObject dataObj;

    QString airQuality;

    dataObj = obj.value("data").toObject();

    airQuality = dataObj.value("quality").toString();

    return airQuality;
}

QString WEATHER::getWeatherNotice(QJsonObject obj)
{
    Q_UNUSED(obj)

    return nullptr;
}

QString WEATHER::getForecastTemp(QJsonObject obj, quint8 index)
{
    QJsonArray  forecastTempArray;
    QJsonObject dataObj;
    QJsonObject forecastTempObj;
    QString     forecastTempHigh;
    QString     forecastTempLow;
    QString     forecastTemp;

    dataObj = obj.value("data").toObject();
    forecastTempArray = dataObj.value("forecast").toArray();
    forecastTempObj   = forecastTempArray.at(index).toObject();
    forecastTempLow   = forecastTempObj.value("low").toString().mid(3);
    forecastTempHigh  = forecastTempObj.value("high").toString().mid(3);

    forecastTemp = forecastTempLow + "-" + forecastTempHigh;

    return forecastTemp;
}

QString WEATHER::getForecastWeatherType(QJsonObject obj, quint8 index)
{
    QJsonArray  forecastWeatherTypeArray;
    QJsonObject dataObj;
    QJsonObject forecastWeatherTypeObj;
    QString     forecastWeatherType;

    dataObj = obj.value("data").toObject();
    forecastWeatherTypeArray = dataObj.value("forecast").toArray();
    forecastWeatherTypeObj   = forecastWeatherTypeArray.at(index).toObject();
    forecastWeatherType      = forecastWeatherTypeObj.value("type").toString();

    return forecastWeatherType;
}

QString WEATHER::getForecastDataAndWeek(QJsonObject obj, quint8 index)
{
    QJsonArray  forecastArray;
    QJsonObject dataObj;
    QJsonObject forecastDateAndWeekObj;
    QString     forecastDate;
    QString     forecastWeek;
    QString     forecastDateAndWeek;

    dataObj = obj.value("data").toObject();
    forecastArray = dataObj.value("forecast").toArray();
    forecastDateAndWeekObj = forecastArray.at(index).toObject();
    forecastDate = forecastDateAndWeekObj.value("ymd").toString();
    forecastWeek = forecastDateAndWeekObj.value("week").toString();

    forecastDateAndWeek = forecastDate + " " + forecastWeek;

    return forecastDateAndWeek;
}

QString WEATHER::getForecastWindDirAndPower(QJsonObject obj, quint8 index)
{
    QJsonArray  forecastArray;
    QJsonObject dataObj;
    QJsonObject forecastWindDirAndPowerObj;
    QString     forecastWindDir;
    QString     forecastWindPower;
    QString     forecastWindDirAndPower;

    dataObj = obj.value("data").toObject();
    forecastArray = dataObj.value("forecast").toArray();
    forecastWindDirAndPowerObj = forecastArray.at(index).toObject();
    forecastWindDir = forecastWindDirAndPowerObj.value("fx").toString();
    forecastWindPower = forecastWindDirAndPowerObj.value("fl").toString();

    forecastWindDirAndPower = forecastWindDir + " " + forecastWindPower;

    return forecastWindDirAndPower;
}

QString WEATHER::getForecastWeatherNotice(QJsonObject obj, quint8 index)
{
    QJsonArray  forecastArray;
    QJsonObject dataObj;
    QJsonObject forecastWeatherNoticeObj;
    QString     forecastWeatherNotice;

    dataObj = obj.value("data").toObject();
    forecastArray = dataObj.value("forecast").toArray();
    forecastWeatherNoticeObj = forecastArray.at(0).toObject();

    forecastWeatherNotice = forecastWeatherNoticeObj.value("notice").toString();

    return forecastWeatherNotice;
}

void WEATHER::slot_new_obj()
{
    manager = new QNetworkAccessManager();

    weather_info = new WEATHER_INFO;

    timForRefresh = new QTimer(this);

    connect(timForRefresh, SIGNAL(timeout()), this, SLOT(slot_tim_update_weather()));

    /* 解析完成后，通过槽函数获得数据 */
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(slot_manager_read_finished(QNetworkReply *)));

    sendNetworkRequest(getCurrentProvince(), getCurrentCity());

    timForRefresh->start(1000 * 5 * 60);
}

void WEATHER::slot_refresh_manually()
{
    sendNetworkRequest(getCurrentProvince(), getCurrentCity());
}

void WEATHER::slot_manager_read_finished(QNetworkReply *reply)
{
    parsingNetworkResult(reply->readAll());
}

void WEATHER::slot_change_local_city(QString cityName)
{
    setCurrentProvince(cityName.mid(0, 2));
    setCurrentCity(cityName.mid(3, 2));

    sendNetworkRequest(getCurrentProvince(), getCurrentCity());
}

void WEATHER::slot_tim_update_weather()
{
    sendNetworkRequest(getCurrentProvince(), getCurrentCity());
}

QString WEATHER::getCurrentCity() const
{
    return currentCity;
}

void WEATHER::setCurrentCity(const QString &value)
{
    currentCity = value;
}

QString WEATHER::getCurrentProvince() const
{
    return currentProvince;
}

void WEATHER::setCurrentProvince(const QString &value)
{
    currentProvince = value;
}


