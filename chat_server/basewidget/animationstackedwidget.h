#ifndef ANIMATIONSTACKEDWIDGET_H
#define ANIMATIONSTACKEDWIDGET_H

#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include "qtmetamacros.h"

//增加切换动画效果
class AnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    enum AnimationType
    {
        TopToBottom,    ///Animation from top to bottom
        BottomToTop,    ///Animation from bottom to top
        LeftToRight,    ///Animation from left to right
        RightToLeft     ///Animation from right to left
    };

    explicit AnimationStackedWidget(QWidget *parent = nullptr);
    ~ AnimationStackedWidget();

    static QString getClassName();
    /*!
     * Get class object name.
     */

    void start(int index);
    /*!
     * Start to anmiation by index.
     */
    void setIndex(int previous, int current);
    /*!
     * Set previoud and current index.
     */
    void setLength(int length, AnimationType type);
    /*!
     * Set animation start and end pos distance and animation type.
     */

    void setDuration(int duration);
    /*!
     * Set animation duration.
     */
    int getDuration() const;
    /*!
     * Get animation duration.
     */

private slots:
    void valueChanged(const QVariant &value);
    /*!
     * Animation value changed.
     */
    void animationFinished();
    /*!
     * Animation finished.
     */

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    /*!
     * Override the widget event.
     */
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    /*!
     * Render previous widget.
     */
    void renderCurrentWidget(QPainter &painter, QTransform &transform);
    /*!
     * Render current widget.
     */

    bool m_isAnimating;     //是否在动画
    float m_currentValue;      //被animation动画改变的值
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;    //动画框架
};

#endif // ANIMATIONSTACKEDWIDGET_H
