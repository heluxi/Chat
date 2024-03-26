#ifndef HEADEDIT_H
#define HEADEDIT_H

#include <QWidget>
#include "customwidget.h"

class CutDialog;
class PhotoShotDialog;

namespace Ui {
class headEdit;
}

class headEdit : public QWidget{
    Q_OBJECT

public:
    explicit headEdit(QWidget *parent = nullptr);
    ~headEdit();
signals:
    void signalCutHeadOk();
    void signalClose();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
protected:
    QPoint mousePoint;
    bool m_mousePressed;

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void SltCutDlgMoved(QRect rect);

    void on_btnLoad_clicked();

    void on_btnSave_clicked();

private:
    Ui::headEdit *ui;
    QPixmap scaledPix;
    PhotoShotDialog *pdialog;
};

#endif // HEADEDIT_H
