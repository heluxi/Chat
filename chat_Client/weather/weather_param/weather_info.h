#ifndef WEATHER_PARAM_H
#define WEATHER_PARAM_H

#include <qglobal.h>
#include <qstring.h>
#include <qstringlist.h>

typedef struct
{
    QString temp;           //温度

    QString weatherType;    //天气类型，多云，晴...

    QString airQuality;     //空气质量

    QString updateTime;     //更新时间

}REAL_TIME;

typedef struct
{
    QString temp;               //温度

    QString weatherType;        //天气类型

    QString windDirAndPower;    //风向和风力

    QString notice;             //提示

    QString dataAndWeek;        //日期和星期

}FORECAST_WEATHER;

typedef struct
{
    QString dataAndTime;            //日期&时间

    QString week;                   //星期

    QString cityName;               //城市名字

    REAL_TIME realTime;             //实时

    FORECAST_WEATHER forecast[5];   //预报

}WEATHER_INFO;

#endif // WEATHER_PARAM_H
