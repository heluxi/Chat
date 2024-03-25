#ifndef MODIFDIALOG_H
#define MODIFDIALOG_H

#include <QDialog>

namespace Ui {
class modifDialog;
}

class modifDialog : public QDialog
{
    Q_OBJECT

public:
    explicit modifDialog(QWidget *parent = nullptr);
    ~modifDialog();

private slots:

    void on_cancelButton_clicked();

    void on_okButton_clicked();

signals:
    void modifSuccess();

private:
    Ui::modifDialog *ui;
};

#endif // MODIFDIALOG_H
