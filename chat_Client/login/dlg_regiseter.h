#ifndef DLG_REGISETER_H
#define DLG_REGISETER_H

#include <QDialog>
#include "page_login.h"

namespace Ui {
class Dlg_regiseter;
}

class Dlg_regiseter : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_regiseter(QWidget *parent = nullptr);
    ~Dlg_regiseter();

private slots:
    void on_btn_register_sure_clicked();

    void on_btn_reg_cancel_clicked();
signals:
    void userRegister(QString name,QString password);
    void registerok();
//    void closeWindow();
    void signalRegister(const QJsonValue &jsonVal);
    void returnPageLogin();
    void registSuccess();

public slots:
//    void sltCloseWnd();
    void sltRegisterOK(const QJsonValue&);
private:
    Ui::Dlg_regiseter *ui;
    Page_login m_dlogin;

};

#endif // DLG_REGISETER_H
