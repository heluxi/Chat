#include "mylikesitemwidget.h"
#include <QMessageBox>
MyLikesItemWidget::MyLikesItemWidget(QString fileName):QLabel(NULL)
{
    this->fileName=fileName;
    this->setMargin(4);
    QImage* img=new QImage;
    if(! ( img->load(fileName) ) ) //加载图像
    {
        QMessageBox::information(this,
                                 tr("打开图像失败"),
                                 tr("打开图像失败!"));
        delete img;
        return;
    }
    *img=img->scaled(80,80,Qt::KeepAspectRatio);
    this->setPixmap(QPixmap::fromImage(*img));
    //this->resize(80,80);
}
QString MyLikesItemWidget::getFileName()
{
        return fileName;
}
