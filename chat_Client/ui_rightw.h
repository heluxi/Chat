/********************************************************************************
** Form generated from reading UI file 'rightw.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTW_H
#define UI_RIGHTW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rightw
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_4;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *rightw)
    {
        if (rightw->objectName().isEmpty())
            rightw->setObjectName("rightw");
        rightw->resize(818, 832);
        rightw->setMinimumSize(QSize(818, 832));
        verticalLayout = new QVBoxLayout(rightw);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(rightw);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        horizontalLayout = new QHBoxLayout(widget_10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(568, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\350\247\243\351\231\244\345\233\272\345\256\232,\345\233\276\351\222\211.png);"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget_10);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\207\217\345\217\267.png);"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(widget_10);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\224\276\345\244\247.png);"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_4 = new QPushButton(widget_10);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\210\240\351\231\2442.png);"));

        horizontalLayout->addWidget(pushButton_4);


        horizontalLayout_2->addWidget(widget_10);


        verticalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(rightw);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(818, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
""));

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(rightw);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(rightw);
    } // setupUi

    void retranslateUi(QWidget *rightw)
    {
        rightw->setWindowTitle(QCoreApplication::translate("rightw", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rightw: public Ui_rightw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTW_H
