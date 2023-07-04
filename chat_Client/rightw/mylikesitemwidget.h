#ifndef MYLIKESITEMWIDGET_H
#define MYLIKESITEMWIDGET_H

#include <QLabel>

class MyLikesItemWidget : public QLabel
{
public:
    MyLikesItemWidget(QString fileName);
    QString getFileName();
private:
    QString fileName;
};

#endif // MYLIKESITEMWIDGET_H
