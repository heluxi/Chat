#ifndef HEADDIALOG_H
#define HEADDIALOG_H

#include <QDialog>
#include "customwidget.h"

class CutDialog;
class PhotoShotDialog;
namespace Ui {
class HeadDialog;
}

class HeadDialog : public CustomMoveWidget
{
    Q_OBJECT

public:
    explicit HeadDialog(QWidget *parent = nullptr);
    ~HeadDialog();
signals:
    void signalCutHeadOk();
    void signalClose();

protected:
    void changeEvent(QEvent *e);

private slots:
    void SltCutDlgMoved(QRect rect);

    void on_btnLoad_clicked();

    void on_btnSave_clicked();
private:
    Ui::HeadDialog *ui;
    QPixmap scaledPix;
    PhotoShotDialog *pdialog;
};

#endif // HEADDIALOG_H
