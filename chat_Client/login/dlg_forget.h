#ifndef DLG_FORGET_H
#define DLG_FORGET_H

#include <QDialog>

namespace Ui {
class Dlg_forget;
}

class Dlg_forget : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_forget(QWidget *parent = nullptr);
    ~Dlg_forget();
signals:
//    void closeWindow();
    void signalForgetPwd(const QJsonValue &jsonVal);

private slots:
    void on_btn_forget_sure_clicked();

    void on_btn_forget_cancel_clicked();
public slots:
    void sltForgetPwdReply(const QJsonValue &);
//    void sltCloseWnd();
private:
    Ui::Dlg_forget *ui;
};

#endif // DLG_FORGET_H
