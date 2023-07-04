#ifndef SELECTFRDLIST_H
#define SELECTFRDLIST_H

#include <QWidget>

namespace Ui {
class selectFrdList;
}

class selectFrdList : public QWidget
{
    Q_OBJECT

public:
    explicit selectFrdList(QWidget *parent = nullptr);
    ~selectFrdList();

private:
    Ui::selectFrdList *ui;
};

#endif // SELECTFRDLIST_H
