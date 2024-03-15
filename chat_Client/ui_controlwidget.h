/********************************************************************************
** Form generated from reading UI file 'controlwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWIDGET_H
#define UI_CONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *rectangleBtn;
    QToolButton *drawRoundBtn;
    QToolButton *arrowBtn;
    QToolButton *drawLineBtn;
    QToolButton *mosaicBtn;
    QToolButton *textEditBtn;
    QToolButton *returneditBtn;
    QToolButton *saveBtn;
    QToolButton *toolButton_7;
    QToolButton *toolButton_6;
    QToolButton *toolButton;
    QToolButton *cancelBtn;
    QPushButton *finishBtn;

    void setupUi(QWidget *ControlWidget)
    {
        if (ControlWidget->objectName().isEmpty())
            ControlWidget->setObjectName("ControlWidget");
        ControlWidget->resize(561, 32);
        horizontalLayout = new QHBoxLayout(ControlWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 0, 6, 0);
        rectangleBtn = new QToolButton(ControlWidget);
        rectangleBtn->setObjectName("rectangleBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/pic/control_01.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleBtn->setIcon(icon);
        rectangleBtn->setIconSize(QSize(25, 25));
        rectangleBtn->setAutoRaise(true);

        horizontalLayout->addWidget(rectangleBtn);

        drawRoundBtn = new QToolButton(ControlWidget);
        drawRoundBtn->setObjectName("drawRoundBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/pic/control_02.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        drawRoundBtn->setIcon(icon1);
        drawRoundBtn->setIconSize(QSize(25, 25));
        drawRoundBtn->setAutoRaise(true);

        horizontalLayout->addWidget(drawRoundBtn);

        arrowBtn = new QToolButton(ControlWidget);
        arrowBtn->setObjectName("arrowBtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/pic/control_03.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        arrowBtn->setIcon(icon2);
        arrowBtn->setIconSize(QSize(25, 25));
        arrowBtn->setAutoRaise(true);

        horizontalLayout->addWidget(arrowBtn);

        drawLineBtn = new QToolButton(ControlWidget);
        drawLineBtn->setObjectName("drawLineBtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/pic/control_04.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        drawLineBtn->setIcon(icon3);
        drawLineBtn->setIconSize(QSize(25, 25));
        drawLineBtn->setAutoRaise(true);

        horizontalLayout->addWidget(drawLineBtn);

        mosaicBtn = new QToolButton(ControlWidget);
        mosaicBtn->setObjectName("mosaicBtn");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/pic/control_05.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        mosaicBtn->setIcon(icon4);
        mosaicBtn->setIconSize(QSize(25, 25));
        mosaicBtn->setAutoRaise(true);

        horizontalLayout->addWidget(mosaicBtn);

        textEditBtn = new QToolButton(ControlWidget);
        textEditBtn->setObjectName("textEditBtn");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/pic/control_06.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        textEditBtn->setIcon(icon5);
        textEditBtn->setIconSize(QSize(25, 25));
        textEditBtn->setAutoRaise(true);

        horizontalLayout->addWidget(textEditBtn);

        returneditBtn = new QToolButton(ControlWidget);
        returneditBtn->setObjectName("returneditBtn");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/pic/control_07.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        returneditBtn->setIcon(icon6);
        returneditBtn->setIconSize(QSize(25, 25));
        returneditBtn->setAutoRaise(true);

        horizontalLayout->addWidget(returneditBtn);

        saveBtn = new QToolButton(ControlWidget);
        saveBtn->setObjectName("saveBtn");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/pic/control_08.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveBtn->setIcon(icon7);
        saveBtn->setIconSize(QSize(25, 25));
        saveBtn->setAutoRaise(true);

        horizontalLayout->addWidget(saveBtn);

        toolButton_7 = new QToolButton(ControlWidget);
        toolButton_7->setObjectName("toolButton_7");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/pic/control_09.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon8);
        toolButton_7->setIconSize(QSize(25, 25));
        toolButton_7->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_7);

        toolButton_6 = new QToolButton(ControlWidget);
        toolButton_6->setObjectName("toolButton_6");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/pic/control_10.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon9);
        toolButton_6->setIconSize(QSize(25, 25));
        toolButton_6->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_6);

        toolButton = new QToolButton(ControlWidget);
        toolButton->setObjectName("toolButton");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/pic/control_11.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon10);
        toolButton->setIconSize(QSize(25, 25));
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton);

        cancelBtn = new QToolButton(ControlWidget);
        cancelBtn->setObjectName("cancelBtn");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/pic/control_12.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon11);
        cancelBtn->setIconSize(QSize(25, 25));
        cancelBtn->setAutoRaise(true);

        horizontalLayout->addWidget(cancelBtn);

        finishBtn = new QPushButton(ControlWidget);
        finishBtn->setObjectName("finishBtn");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/res/pic/control_13.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        finishBtn->setIcon(icon12);
        finishBtn->setFlat(true);

        horizontalLayout->addWidget(finishBtn);


        retranslateUi(ControlWidget);

        QMetaObject::connectSlotsByName(ControlWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlWidget)
    {
        ControlWidget->setWindowTitle(QCoreApplication::translate("ControlWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        rectangleBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\347\224\273\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        rectangleBtn->setText(QString());
#if QT_CONFIG(tooltip)
        drawRoundBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\347\224\273\345\234\206", nullptr));
#endif // QT_CONFIG(tooltip)
        drawRoundBtn->setText(QString());
#if QT_CONFIG(tooltip)
        arrowBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\347\224\273\347\256\255\345\244\264", nullptr));
#endif // QT_CONFIG(tooltip)
        arrowBtn->setText(QString());
#if QT_CONFIG(tooltip)
        drawLineBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\347\224\273\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        drawLineBtn->setText(QString());
#if QT_CONFIG(tooltip)
        mosaicBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\351\251\254\350\265\233\345\205\213", nullptr));
#endif // QT_CONFIG(tooltip)
        mosaicBtn->setText(QString());
#if QT_CONFIG(tooltip)
        textEditBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\346\267\273\345\212\240\346\226\207\345\255\227", nullptr));
#endif // QT_CONFIG(tooltip)
        textEditBtn->setText(QString());
#if QT_CONFIG(tooltip)
        returneditBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\346\222\244\351\224\200\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
        returneditBtn->setText(QString());
#if QT_CONFIG(tooltip)
        saveBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\344\277\235\345\255\230\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        saveBtn->setText(QString());
        toolButton_7->setText(QString());
        toolButton_6->setText(QString());
        toolButton->setText(QString());
#if QT_CONFIG(tooltip)
        cancelBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\351\200\200\345\207\272\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        cancelBtn->setText(QString());
#if QT_CONFIG(tooltip)
        finishBtn->setToolTip(QCoreApplication::translate("ControlWidget", "\345\256\214\346\210\220\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        finishBtn->setText(QCoreApplication::translate("ControlWidget", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlWidget: public Ui_ControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWIDGET_H
