#include "rotatingstackedwidget.h"
#include <QVariant>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPainter>
#include <QParallelAnimationGroup>
#include <QTransform>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include "dlg_forget.h"
#include "dlg_regiseter.h"
#include "loginw.h"
#include "page_login.h"
#include "qdebug.h"
#include "qpropertyanimation.h"
#include "qstackedwidget.h"
#include "qvariantanimation.h"
#include "qwidget.h"
#include "setnetdialog.h"

RotatingStackedWidget::RotatingStackedWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    m_isRoratingWindow = false;
    m_nextPageIndex = 0;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    // 给窗口设置rotateValue属性;
    this->setProperty("rotateValue", 0);

    initRotateWindow();
}

RotatingStackedWidget::~RotatingStackedWidget()
{

}

// 初始化旋转的窗口;
void RotatingStackedWidget::initRotateWindow()
{
    loginWnd = new loginw(this);
    // 这里定义了两个信号，需要自己去发送信号;
    connect(loginWnd, &loginw::rotateWindow, this, &RotatingStackedWidget::onRotateWindow);
    connect(loginWnd, &loginw::closeWindow, this, &RotatingStackedWidget::close);
    connect(loginWnd, &loginw::hideWindow, this, &RotatingStackedWidget::onHideWindow);
    connect(loginWnd, &loginw::openRegisterWnd, this, &RotatingStackedWidget::sltOpenRegisterWnd);
    connect(loginWnd, &loginw::openForgetPasswordWnd,
            this, &RotatingStackedWidget::sltOpenForgetPasswordWnd);


    netWorkSetWnd = new setnetDialog(this);
    connect(netWorkSetWnd, &setnetDialog::rotateWindow, this, &RotatingStackedWidget::onRotateWindow);
//    connect(netWorkSetWnd, &setnetDialog::closeWindow, this, &RotatingStackedWidget::close);
//    connect(netWorkSetWnd, &setnetDialog::hideWindow, this, &RotatingStackedWidget::onHideWindow);

    connect(netWorkSetWnd,&setnetDialog::setNetwork,loginWnd,&loginw::slotTimeout);

    this->addWidget(loginWnd);
    this->addWidget(netWorkSetWnd);

    // 这里宽和高都增加，是因为在旋转过程中窗口宽和高都会变化;
    this->setContentsMargins(20,100,20,100);
    qDebug()<<loginWnd->width();
    this->setFixedSize(QSize(loginWnd->width() + 40, loginWnd->height() + 200));

    QTimer::singleShot(1500,this,SLOT(sltAutoLogin()));

    registerWnd = new Dlg_regiseter();
    registerWnd->hide();
//    connect(registerWnd,&Dlg_regiseter::closeWindow,
//            this,&RotatingStackedWidget::sltCloseRegisterWnd);
    connect(registerWnd,&Dlg_regiseter::returnPageLogin,this,[=](){this->show();});
    connect(registerWnd,&Dlg_regiseter::registSuccess,this,[=](){this->show();});

    connect(registerWnd,&Dlg_regiseter::signalRegister,
            loginWnd,&loginw::sltRegister);
    connect(loginWnd,&loginw::signalRegisterOK,
            registerWnd,&Dlg_regiseter::sltRegisterOK);

    forgetPasswordWnd = new Dlg_forget();
//    connect(forgetPasswordWnd,SIGNAL(closeWindow(QPoint)),
//            this,SLOT(sltCloseFindwordWnd(QPoint)));
    connect(forgetPasswordWnd,&Dlg_forget::signalForgetPwd,
            loginWnd,&loginw::sltChangePwd);
    connect(loginWnd,&loginw::signalForgetPwdReply,
            forgetPasswordWnd,&Dlg_forget::sltForgetPwdReply);

    forgetPasswordWnd->hide();
}

// 开始旋转窗口;
void RotatingStackedWidget::onRotateWindow()
{
    // 如果窗口正在旋转，直接返回;
    if (m_isRoratingWindow)
        return;

    qDebug() << "start rotating...";

    m_isRoratingWindow = true;
    m_nextPageIndex = (currentIndex() + 1) >= count() ? 0 : (currentIndex() + 1);
    QPropertyAnimation *rotateAnimation = new QPropertyAnimation(this, "rotateValue");
    // 设置旋转持续时间;
    rotateAnimation->setDuration(1000);
    // 设置旋转角度变化趋势;
    rotateAnimation->setEasingCurve(QEasingCurve::InCubic);
    // 设置旋转角度范围;
    rotateAnimation->setStartValue(0);
    rotateAnimation->setEndValue(180);
//    connect(rotateAnimation, &QVariantAnimation::valueChanged, this, &QWidget::repaint);
    connect(rotateAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(repaint()));
    connect(rotateAnimation, &QPropertyAnimation::finished, this, &RotatingStackedWidget::onRotateFinished);
    // 隐藏当前窗口，通过不同角度的绘制来达到旋转的效果;
    currentWidget()->hide();
    rotateAnimation->start();
}

// 旋转结束;
void RotatingStackedWidget::onRotateFinished()
{
    m_isRoratingWindow = false;
    setCurrentWidget(widget(m_nextPageIndex));
    repaint();
}

// 绘制旋转效果;
void RotatingStackedWidget::paintEvent(QPaintEvent *event)
{
    if (m_isRoratingWindow){
        loginWnd->setGraphicsEffect(nullptr);
        netWorkSetWnd->setGraphicsEffect(nullptr);

        int rotateValue = this->property("rotateValue").toInt();
        if (rotateValue <= 90)// 小于90度时;
        {
            QPixmap rotatePixmap(currentWidget()->size());
            currentWidget()->render(&rotatePixmap);
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(rotateValue, Qt::YAxis);
            painter.setTransform(transform);
            painter.drawPixmap(-1 * width() / 2 + 20, 100, rotatePixmap);
        } else {
            // 大于90度时
            QPixmap rotatePixmap(widget(m_nextPageIndex)->size());
            widget(m_nextPageIndex)->render(&rotatePixmap);
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(rotateValue + 180, Qt::YAxis);
            painter.setTransform(transform);
            painter.drawPixmap(-1 * width() / 2 + 20, 100, rotatePixmap);
        }
    } else {
        if(m_nextPageIndex == 0){
            QGraphicsDropShadowEffect *pEffect = new QGraphicsDropShadowEffect(loginWnd);
            pEffect->setOffset(0, 0);
            pEffect->setColor(QColor(QStringLiteral("black")));
            pEffect->setBlurRadius(30);
            loginWnd->setGraphicsEffect(pEffect);
        }else {
            QGraphicsDropShadowEffect *pEffect = new QGraphicsDropShadowEffect(netWorkSetWnd);
            pEffect->setOffset(0, 0);
            pEffect->setColor(QColor(QStringLiteral("black")));
            pEffect->setBlurRadius(30);
            netWorkSetWnd->setGraphicsEffect(pEffect);
        }

        return QWidget::paintEvent(event);
    }
}

void RotatingStackedWidget::onHideWindow()
{
    showMinimized();
}

void RotatingStackedWidget::sltAutoLogin()
{
    loginWnd->checkAutoLogin();
}

void RotatingStackedWidget::sltOpenRegisterWnd()
{
//    registerWnd->move(this->pos().x(),this->pos().y() + 80);
    registerWnd->show();
    this->hide();
}

void RotatingStackedWidget::sltCloseRegisterWnd(QPoint pos)
{
//    this->move(pos.x(),pos.y() - 80);
    this->show();
}

void RotatingStackedWidget::sltOpenForgetPasswordWnd()
{
    forgetPasswordWnd->move(this->pos().x(),this->pos().y() + 80);
    forgetPasswordWnd->show();
    this->hide();
}

void RotatingStackedWidget::sltCloseFindwordWnd(QPoint pos)
{
    this->move(pos.x(),pos.y() - 80);
    this->show();
}

void RotatingStackedWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_pressedPoint = event->globalPos() - this->pos();
        m_isPressed = true;
        event->accept();
    }
}

void RotatingStackedWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    event->accept();
}

void RotatingStackedWidget::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons()&(Qt::LeftButton)) && m_isPressed == true){
        move(event->globalPos() - m_pressedPoint);
        event->accept();
    }
}
