#ifndef MYEMOTIONWIDGET_H
#define MYEMOTIONWIDGET_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QMovie>

namespace Ui {
class MyEmotionWidget;
}

class MyEmotionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyEmotionWidget(QWidget *parent = nullptr);
    ~MyEmotionWidget();
    void addEmotionItem(QString fileName);
    void addLikesItem(QString fileName);
    void initEmotion();
    void initLikes();
    void closeEvent();
    QString currentFileName;
//    QString getCurrentfileName();
private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_clicked();

    void on_tableWidget_2_cellClicked(int row, int column);

signals:
    void SendEmojoyMessage();
private:
    Ui::MyEmotionWidget *ui;
    QList<QString> m_emotionList;
    QList<QString> m_likesList;

};

#endif // MYEMOTIONWIDGET_H
