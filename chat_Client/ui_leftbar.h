/********************************************************************************
** Form generated from reading UI file 'leftbar.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTBAR_H
#define UI_LEFTBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leftBar
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QWidget *widget;
    QPushButton *headBtn;

    void setupUi(QWidget *leftBar)
    {
        if (leftBar->objectName().isEmpty())
            leftBar->setObjectName("leftBar");
        leftBar->resize(109, 715);
        verticalLayout = new QVBoxLayout(leftBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(leftBar);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(63, 61));
        widget_4->setMaximumSize(QSize(16777215, 900));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 72, 72);"));
        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 169, 120, 421));
        headBtn = new QPushButton(widget_4);
        headBtn->setObjectName("headBtn");
        headBtn->setGeometry(QRect(10, 20, 65, 65));
        headBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:30px;\n"
"image: url(:/res/pic/Customer Copy.png);"));

        verticalLayout->addWidget(widget_4);


        retranslateUi(leftBar);

        QMetaObject::connectSlotsByName(leftBar);
    } // setupUi

    void retranslateUi(QWidget *leftBar)
    {
        leftBar->setWindowTitle(QCoreApplication::translate("leftBar", "Form", nullptr));
        headBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class leftBar: public Ui_leftBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTBAR_H
