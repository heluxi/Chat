#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QWidget>

namespace Ui {
class SystemSetting;
}

class SystemSetting : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSetting(QWidget *parent = nullptr);
    ~SystemSetting();

private slots:
    void on_btnSaveSetting_clicked();

    void on_toolButton_clicked();

    void on_toolBtnLeftClr_clicked();

    void on_toolBtnClr_clicked();
signals:
    void changeBackgroundColor(QString color);
    void changeleftBuble(QString color);
    void changerightBuble(QString color);

private:
    Ui::SystemSetting *ui;
};

#endif // SYSTEMSETTING_H
