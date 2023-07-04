#ifndef CREATEGROUPDLG_H
#define CREATEGROUPDLG_H

#include <QWidget>

namespace Ui {
class CreateGroupDlg;
}

class CreateGroupDlg : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroupDlg(QWidget *parent = nullptr);
    ~CreateGroupDlg();
    void initial();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::CreateGroupDlg *ui;
};

#endif // CREATEGROUPDLG_H
