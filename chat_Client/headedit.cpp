#include "headedit.h"
#include "ui_headedit.h"

#include "photoshotdialog.h"
#include "myapp.h"
#include<QStyleOption>
#include <QFileDialog>

headEdit::headEdit(QWidget *parent) :
   QWidget(parent),
    ui(new Ui::headEdit)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    pdialog = NULL;
    on_btnLoad_clicked();

}

headEdit::~headEdit()
{
    delete ui;
}

void headEdit::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void headEdit::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    //    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void headEdit::mouseMoveEvent(QMouseEvent *e)
{

    if (m_mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();

        if ("MainWindow" == this->objectName()) {
            QPoint pos = e->globalPos() - mousePoint;
            MyApp::m_nWinX = pos.x();
            MyApp::m_nWinY = pos.y();
        }
    }
}

void headEdit::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void headEdit::mouseReleaseEvent(QMouseEvent *)
{
 m_mousePressed = false;
}

void headEdit::SltCutDlgMoved(QRect rect)
{
    QPixmap pix = scaledPix.copy(rect);
    //剪切出的图片的保存地址
    ui->label64->setPixmap(pix.scaled(64, 64));
    ui->label48->setPixmap(pix.scaled(48, 48));
}

void headEdit::on_btnLoad_clicked()
{
    // 加载图片
    static QString s_strPath = "./";
//     QString strFileName=QFileDialog::getOpenFileName(this,tr("select image"),"/",tr("Image Fles(*.png *.jpg)"));
//    QString strFileName = QFileDialog::getOpenFileName(this,
//                                                       tr("选择图片"),
//                                                       s_strPath,
//                                                       tr("图片(*.jpg;*.png)"));
    // 如果没选择文件直接退出
//    if (strFileName.isEmpty()) {
//        return;
//    }
    QString strFileName=MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    s_strPath =  MyApp::m_strHeadPath + MyApp::m_strHeadFile;
    qDebug()<<strFileName;
    // 这里是原图的地址
    QPixmap pixmap(strFileName);
    // 非空判断
    if (!pixmap.isNull())
    {
        qDebug()<<"非空";
        int nW = ui->widgetLoad->width();
        int nH = ui->widgetLoad->height();
        if ((pixmap.width() > nW) && (pixmap.height() > nH))
        {
            ui->labelPreview->resize(QSize(nW, nH));
            scaledPix = pixmap.scaled(nW, nH, Qt::KeepAspectRatio);
        }
        else {
            ui->labelPreview->resize(pixmap.size());
            scaledPix = pixmap;
        }

        ui->labelPreview->setPixmap(scaledPix);
    }

    if (NULL == pdialog) {
        //该类为剪切框
        pdialog = new PhotoShotDialog(ui->labelPreview);
        connect(pdialog, SIGNAL(signalMoved(QRect)), this, SLOT(SltCutDlgMoved(QRect)));
        pdialog->show();
    }
}

void headEdit::on_btnSave_clicked()
{
    if (NULL == pdialog) return;

    QPixmap pixmap = scaledPix.copy(pdialog->getShotGeometry()).scaled(64, 64);
    if (!pixmap.isNull()) {
//        pixmap.save(MyApp::m_strHeadPath + QString("%1_head_64.png").arg(MyApp::m_nId), "png");
//        MyApp::m_strHeadFile = MyApp::m_strHeadPath + QString("%1_head_64.png").arg(MyApp::m_nId);
    }

    // 聊天窗口需求的图片
    pixmap = scaledPix.copy(pdialog->getShotGeometry()).scaled(48, 48);
    if (!pixmap.isNull()) {
//        pixmap.save(MyApp::m_strHeadPath + QString("%1_head_48.png").arg(MyApp::m_nId), "png");
    }

    this->close();
    Q_EMIT signalCutHeadOk();
}
