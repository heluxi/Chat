#ifndef DIALOG_CHANGE_CITY_H
#define DIALOG_CHANGE_CITY_H

#include <QDialog>
#include <QObject>
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

namespace Ui {
class Dialog_Change_City;
}

class Dialog_Change_City : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Change_City(QWidget *parent = nullptr);
    ~Dialog_Change_City();

    QString matchInputCity(QString city);

private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

signals:

    void signal_emit_city_name(QString);

private:
    Ui::Dialog_Change_City *ui;

    QStringList cityList;
};

#endif // DIALOG_CHANGE_CITY_H
