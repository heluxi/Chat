#include "define_qlabel.h"
#include <QDebug>
#include <QWidget>

DEFINE_QLABEL::DEFINE_QLABEL(QWidget * parent): QLabel(parent)
{
}

void DEFINE_QLABEL::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    emit mouse_clicked();
}
