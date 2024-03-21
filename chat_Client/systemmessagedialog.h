#ifndef SYSTEMMESSAGEDIALOG_H
#define SYSTEMMESSAGEDIALOG_H


#include <QWidget>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QMutex>



namespace Ui {
class SystemMessageDialog;
}

class SystemMessageDialog : public QWidget
{
    Q_OBJECT

public:
    explicit SystemMessageDialog(QWidget *parent = 0);
    ~SystemMessageDialog();



    void showMessages(const QString &text, const QString &title = "");
    void quitSystem();
private:
    Ui::SystemMessageDialog *ui;



private slots:




};


#endif // SYSTEMMESSAGEDIALOG_H
