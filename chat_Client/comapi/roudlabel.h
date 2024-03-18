#ifndef ROUDLABEL_H
#define ROUDLABEL_H

#include <QLabel>
#include <QPixmap>

class RoundLabel : public QLabel
{
    Q_OBJECT

public:
    RoundLabel(QWidget *parent = nullptr,QString iconPath = "");
    void setPixmap(QString iconpath);

private:
    QPixmap pixmap;

protected:
    void paintEvent(QPaintEvent*);
};
#endif // ROUDLABEL_H
