#ifndef MYEMOTIONITEMWIDGET_H
#define MYEMOTIONITEMWIDGET_H

#include <QLabel>
#include <QWidget>

class MyEmotionItemWidget : public QLabel
{
public:
    MyEmotionItemWidget(QString fileName);
    QString getFileName();

//     void enterEvent(QEvent* event);
//     void leaveEvent(QEvent* event);
 private:
     QString fileName;
};

#endif // MYEMOTIONITEMWIDGET_H
