#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <QWidget>

namespace Ui {
class personalInfo;
}

class personalInfo : public QWidget
{
    Q_OBJECT

public:
    explicit personalInfo(QWidget *parent = nullptr);
    ~personalInfo();
    void setName(QString name);
    void setId(int id);
    void sethead(QString);

private:
    Ui::personalInfo *ui;
};

#endif // PERSONALINFO_H
