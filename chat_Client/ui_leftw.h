/********************************************************************************
** Form generated from reading UI file 'leftw.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTW_H
#define UI_LEFTW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_leftw
{
public:
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QSpacerItem *verticalSpacer_4;
    MyButton *btn_chat;
    QSpacerItem *verticalSpacer_5;
    MyButton *btn_contact;
    QSpacerItem *verticalSpacer_6;
    MyButton *btn_settings;

    void setupUi(QWidget *leftw)
    {
        if (leftw->objectName().isEmpty())
            leftw->setObjectName("leftw");
        leftw->resize(81, 832);
        leftw->setMinimumSize(QSize(81, 832));
        leftw->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 41, 45);"));
        widget_4 = new QWidget(leftw);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 20, 81, 311));
        widget_4->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(61, 61));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:30px;\n"
"image: url(:/res/pic/\345\244\251\347\214\253.png);"));

        verticalLayout_2->addWidget(widget_5);

        verticalSpacer_4 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        QStringList tmp;
        tmp << ":/res/pic/Chat.png"
            << ":/Icons/MainWindow/chat2.png"
            << ":/res/pic/Chat.png";
        btn_chat = new MyButton(nullptr,tmp,QSize(63,41));
        btn_chat->setObjectName("btn_chat");
        btn_chat->setMinimumSize(QSize(51, 41));
        btn_chat->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/Chat.png);"));

        verticalLayout_2->addWidget(btn_chat);

        verticalSpacer_5 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        tmp.clear();
        tmp << ":/res/pic/\347\224\250\346\210\267.png"
            << ":/Icons/MainWindow/chat2.png"
            << ":/res/pic/\347\224\250\346\210\267.png";
        btn_contact = new MyButton(nullptr,tmp,QSize(63,41));
        btn_contact->setObjectName("btn_contact");
        btn_contact->setMinimumSize(QSize(51, 41));
        btn_contact->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\347\224\250\346\210\267.png);"));

        verticalLayout_2->addWidget(btn_contact);

        verticalSpacer_6 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        tmp.clear();
        tmp << ":/res/pic/3.1 \350\256\276\347\275\256.png"
            << ":/Icons/MainWindow/chat2.png"
            << ":/res/pic/3.1 \350\256\276\347\275\256.png";
        btn_settings = new MyButton(nullptr,tmp,QSize(63,41));
        btn_settings->setObjectName("btn_settings");
        btn_settings->setMinimumSize(QSize(51, 41));
        btn_settings->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/3.1 \350\256\276\347\275\256.png);"));

        verticalLayout_2->addWidget(btn_settings);


        retranslateUi(leftw);

        QMetaObject::connectSlotsByName(leftw);
    } // setupUi

    void retranslateUi(QWidget *leftw)
    {
        leftw->setWindowTitle(QCoreApplication::translate("leftw", "Form", nullptr));
        btn_chat->setText(QString());
        btn_contact->setText(QString());
        btn_settings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class leftw: public Ui_leftw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTW_H
