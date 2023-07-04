#ifndef DEFINE_QLABEL_H
#define DEFINE_QLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

class DEFINE_QLABEL : public QLabel
{
    Q_OBJECT
public:
    DEFINE_QLABEL(QWidget * parent = 0);

protected:
    virtual void mouseReleaseEvent(QMouseEvent * ev);

signals:

    void mouse_clicked();
};

#endif // DEFINE_QLABEL_H
