#include "wtheatherdlg.h"
#include "ui_wtheatherdlg.h"

wtheatherDlg::wtheatherDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wtheatherDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("天气"));

    netThread = new NET_THREAD(this);

    timShowMessage = new QTimer(this);

    timShowMessage->start(5000);

    /* 关联槽函数 */
    connect(ui->label_refresh, SIGNAL(mouse_clicked()), netThread->weather, SLOT(slot_refresh_manually()));
    connect(netThread->weather, SIGNAL(signal_emit_weather_info(WEATHER_INFO *)), this, SLOT(slot_get_weather_info(WEATHER_INFO *)));
    connect(ui->label_local_city, SIGNAL(mouse_clicked()), this, SLOT(slot_change_local_city()));
    connect(timShowMessage, SIGNAL(timeout()), this, SLOT(slot_show_message()));

    netThread->startThread();
}

wtheatherDlg::~wtheatherDlg()
{
    delete ui;
}

void wtheatherDlg::pushListWeak()
{

}

void wtheatherDlg::pushListDate()
{

}

void wtheatherDlg::pushListWeatherType()
{

}

void wtheatherDlg::slot_read_network_data(QNetworkReply *reply)
{
    QByteArray get_network = reply->readAll();
    dbg("reply finished", 0);
}
/**
 * @brief 获取温度信息-槽函数
 * @param info
 */
void wtheatherDlg::slot_get_weather_info(WEATHER_INFO * info)
{
    dbg("get weather info", 0);

    QString pixmap;

    showMessageList.clear();

    ui->label_city_name->setText(info->cityName);
    ui->label_real_time_temp->setText(info->realTime.temp);
    ui->label_temp_1->setText(info->forecast[0].temp);
    ui->label_weather_type_1->setText(info->forecast[0].weatherType);

    showMessageList.append("今天是 " + info->forecast[0].dataAndWeek);
    showMessageList.append(tr("今天空气质量") + info->realTime.airQuality);
    showMessageList.append(info->forecast[0].windDirAndPower);
    showMessageList.append(info->forecast[0].notice);

    if(info->forecast[0].weatherType.contains("多云"))
    {
        pixmap = ":/icons/weather_icons/duoyun.png";
    }
    else if(info->forecast[0].weatherType.contains("晴"))
    {
        pixmap = ":/icons/weather_icons/qing.png";
    }



    ui->label_weather_icon->setPixmap(QPixmap(pixmap));
}

void wtheatherDlg::slot_change_local_city()
{
    dbg("clicked", 0);

    dialog_change_city = new Dialog_Change_City;
    dialog_change_city->show();

    connect(dialog_change_city, SIGNAL(signal_emit_city_name(QString)), netThread->weather, SLOT(slot_change_local_city(QString)));
}



void wtheatherDlg::slot_show_message()
{
    static quint8 index = 0;

    if(showMessageList.isEmpty() == true)
    {
        return;
    }

    ui->label_show_message->setText(showMessageList.at(index));

    index ++;

    if(index >= showMessageList.size())
    {
        index = 0;
    }
}
