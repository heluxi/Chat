#include "dialog_change_city.h"
#include "ui_dialog_change_city.h"

#include <QFile>
#include <QDir>

Dialog_Change_City::Dialog_Change_City(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Change_City)
{
    ui->setupUi(this);

    cityList.clear();
}

Dialog_Change_City::~Dialog_Change_City()
{
    delete ui;
}

QString Dialog_Change_City::matchInputCity(QString city)
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

        if(dateObj.value("cityZh").toString().contains(city))
        {
            QString provinceZh = dateObj.value("provinceZh").toString();
            QString cityZh     = dateObj.value("cityZh").toString();
            QString cityAndProvince = provinceZh + "-" + cityZh;
            ui->comboBox->insertItem(0,cityAndProvince);
            ui->comboBox->showPopup();
        }
    }

    return cityId;
}


void Dialog_Change_City::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        return;
    }

    matchInputCity(arg1);
}

void Dialog_Change_City::on_pushButton_clicked()
{
    dbg("send", 0);
    emit signal_emit_city_name(ui->comboBox->currentText());

    this->close();
}
