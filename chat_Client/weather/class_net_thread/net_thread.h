#ifndef NET_THREAD_H
#define NET_THREAD_H

#include <QObject>
#include <QThread>

//#include <class_weather/weather.h>
#include"weather/class_weather/weather.h"

class NET_THREAD : public QObject
{
    Q_OBJECT
public:
    explicit NET_THREAD(QObject *parent = nullptr);
    ~NET_THREAD();

    QThread * qThread = nullptr;

    WEATHER * weather = nullptr;

    void startThread();

    void stopThread();

signals:

};

#endif // NET_THREAD_H
