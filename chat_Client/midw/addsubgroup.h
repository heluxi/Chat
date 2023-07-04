#ifndef ADDSUBGROUP_H
#define ADDSUBGROUP_H

#include <QDialog>

namespace Ui {
class AddSubGroup;
}

class AddSubGroup : public QDialog
{
    Q_OBJECT

public:
    explicit AddSubGroup(QWidget *parent = nullptr);
    ~AddSubGroup();

signals:
    void updateList(QString);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::AddSubGroup *ui;
};

#endif // ADDSUBGROUP_H
