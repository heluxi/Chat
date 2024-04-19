/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendlist
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;

    void setupUi(QWidget *friendlist)
    {
        if (friendlist->objectName().isEmpty())
            friendlist->setObjectName("friendlist");
        friendlist->resize(301, 50);
        friendlist->setStyleSheet(QString::fromUtf8("border-radius:1px;\n"
"background-color: rgb(226, 226, 226);"));
        widget = new QWidget(friendlist);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 40, 51, 51));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        widget_2 = new QWidget(friendlist);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 61, 51));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/Customer Copy.png);"));
        label = new QLabel(friendlist);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 0, 221, 51));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        retranslateUi(friendlist);

        QMetaObject::connectSlotsByName(friendlist);
    } // setupUi

    void retranslateUi(QWidget *friendlist)
    {
        friendlist->setWindowTitle(QCoreApplication::translate("friendlist", "Form", nullptr));
        label->setText(QCoreApplication::translate("friendlist", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendlist: public Ui_friendlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
