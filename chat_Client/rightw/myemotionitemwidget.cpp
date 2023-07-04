#include "myemotionitemwidget.h"
#include <QMovie>
MyEmotionItemWidget::MyEmotionItemWidget(QString fileName)
    : QLabel(NULL)
{    this->fileName=fileName;
    //首先构造函数中进行初始化;

    QMovie* iconMovie = new QMovie;
    iconMovie->setFileName(fileName);
    this->setMovie(iconMovie);
    this->setMargin(4);
    //为了动态图片正常显示，（不加上start图片不显示，不加上stop图片一种处于动态效果）
    iconMovie->start();
   // iconMovie->stop();

}
//// 鼠标进入Label事件
//void MyEmotionItemWidget::enterEvent(QEvent *event)
//{
//    QMovie* movie = this->movie();
//    movie->start();
////    return QWidget::enterEvent(event);
//}
//// 鼠标离开Label事件
//void MyEmotionItemWidget::leaveEvent(QEvent *event)
//{
//    QMovie* movie = this->movie();
//    movie->jumpToFrame(0);
//    movie->stop();
////    return QWidget::leaveEvent(event);
//}
QString MyEmotionItemWidget::getFileName()
{
    return fileName;
}
