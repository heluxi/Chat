/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatList
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *imgaeBut;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *userName;
    QLabel *timeLabel;
    QLabel *msgLabel;

    void setupUi(QWidget *chatList)
    {
        if (chatList->objectName().isEmpty())
            chatList->setObjectName("chatList");
        chatList->resize(241, 60);
        chatList->setMaximumSize(QSize(320, 60));
        chatList->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        gridLayout_2 = new QGridLayout(chatList);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        imgaeBut = new QPushButton(chatList);
        imgaeBut->setObjectName("imgaeBut");
        imgaeBut->setMaximumSize(QSize(50, 50));
        imgaeBut->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\215\241\351\200\232\345\244\264\345\203\217.png);"));

        gridLayout_2->addWidget(imgaeBut, 0, 0, 1, 1);

        widget = new QWidget(chatList);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        userName = new QLabel(widget);
        userName->setObjectName("userName");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        userName->setFont(font);

        gridLayout->addWidget(userName, 0, 0, 1, 1);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName("timeLabel");
        QFont font1;
        font1.setBold(true);
        timeLabel->setFont(font1);
        timeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(timeLabel, 0, 1, 1, 1);

        msgLabel = new QLabel(widget);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setFont(font1);

        gridLayout->addWidget(msgLabel, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 1, 1, 1);


        retranslateUi(chatList);

        QMetaObject::connectSlotsByName(chatList);
    } // setupUi

    void retranslateUi(QWidget *chatList)
    {
        chatList->setWindowTitle(QCoreApplication::translate("chatList", "Form", nullptr));
        imgaeBut->setText(QString());
        userName->setText(QCoreApplication::translate("chatList", "userName", nullptr));
        timeLabel->setText(QCoreApplication::translate("chatList", "TextLabel", nullptr));
        msgLabel->setText(QCoreApplication::translate("chatList", "msg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatList: public Ui_chatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
