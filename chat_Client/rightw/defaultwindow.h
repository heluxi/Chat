#ifndef DEFAULTWINDOW_H
#define DEFAULTWINDOW_H

#include <QWidget>

class DefaultWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DefaultWindow(QWidget *parent = nullptr);

protected:
//    void mousePressEvent(QMouseEvent *event);

signals:

};

#endif // DEFAULTWINDOW_H
