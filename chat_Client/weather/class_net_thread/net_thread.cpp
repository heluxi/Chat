#include "net_thread.h"

NET_THREAD::NET_THREAD(QObject *parent) : QObject(parent)
{
    qThread = new QThread(this);

    weather = new WEATHER;

    weather->moveToThread(qThread);

    connect(qThread, SIGNAL(started()), weather, SLOT(slot_new_obj()));
}

NET_THREAD::~NET_THREAD()
{
    qThread->quit();
    qThread->terminate();
    qThread->wait();
}


void NET_THREAD::startThread()
{
    qThread->start();
}

void NET_THREAD::stopThread()
{
    qThread->quit();
    qThread->terminate();
    qThread->wait();
}
