/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "rightw/bubble/bubblelist.h"
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QGridLayout *gridLayout;
    BubbleList *msgWindow;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *namelabel;
    MyButton *listbtn;
    QSpacerItem *horizontalSpacer;
    QWidget *inputWidget;
    QPushButton *sendBut;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_emoj;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_pic;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *fileButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_screenshot;
    QTextEdit *textEdit;

    void setupUi(QWidget *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(818, 800);
        ChatWindow->setMinimumSize(QSize(818, 800));
        gridLayout = new QGridLayout(ChatWindow);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        msgWindow = new BubbleList(ChatWindow);
        msgWindow->setObjectName("msgWindow");
        msgWindow->setMinimumSize(QSize(800, 440));

        gridLayout->addWidget(msgWindow, 1, 0, 1, 1);

        widget = new QWidget(ChatWindow);
        widget->setObjectName("widget");
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        namelabel = new QLabel(widget);
        namelabel->setObjectName("namelabel");
        namelabel->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        namelabel->setFont(font);

        gridLayout_3->addWidget(namelabel, 0, 0, 1, 1);

        QStringList tmp;
        tmp << ":/Icons/MainWindow/arrow_close.png"
            << ":/Icons/MainWindow/arrow_close2.png"
            << ":/Icons/MainWindow/arrow_close.png";
        listbtn = new MyButton(nullptr,tmp,QSize(40,30),NormalBtn);
//        listbtn = new MyButton(widget);
        listbtn->setObjectName("listbtn");
        QFont font1;
        font1.setPointSize(16);
        listbtn->setFont(font1);

        gridLayout_3->addWidget(listbtn, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        inputWidget = new QWidget(ChatWindow);
        inputWidget->setObjectName("inputWidget");
        inputWidget->setMinimumSize(QSize(800, 241));
        inputWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        sendBut = new QPushButton(inputWidget);
        sendBut->setObjectName("sendBut");
        sendBut->setGeometry(QRect(680, 190, 103, 38));
        sendBut->setMinimumSize(QSize(103, 38));
        sendBut->setMaximumSize(QSize(120, 38));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223_GBK")});
        font2.setPointSize(15);
        sendBut->setFont(font2);
        sendBut->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(240, 240, 240);\n"
"border-radius:2px;\n"
""));
        widget_8 = new QWidget(inputWidget);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(0, 0, 251, 40));
        widget_8->setMaximumSize(QSize(16777215, 40));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget_8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_emoj = new QPushButton(widget_8);
        btn_emoj->setObjectName("btn_emoj");
        btn_emoj->setMinimumSize(QSize(41, 31));
        btn_emoj->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\350\241\250\346\203\205.png);"));

        horizontalLayout_2->addWidget(btn_emoj);

        horizontalSpacer_4 = new QSpacerItem(3, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_pic = new QPushButton(widget_8);
        btn_pic->setObjectName("btn_pic");
        btn_pic->setMinimumSize(QSize(41, 31));
        btn_pic->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\233\276\347\211\207.png);"));

        horizontalLayout_2->addWidget(btn_pic);

        horizontalSpacer_5 = new QSpacerItem(3, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        fileButton = new QPushButton(widget_8);
        fileButton->setObjectName("fileButton");
        fileButton->setMinimumSize(QSize(41, 31));
        fileButton->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\226\207\344\273\266\345\244\271.png);"));

        horizontalLayout_2->addWidget(fileButton);

        horizontalSpacer_6 = new QSpacerItem(3, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btn_screenshot = new QPushButton(widget_8);
        btn_screenshot->setObjectName("btn_screenshot");
        btn_screenshot->setMinimumSize(QSize(41, 31));
        btn_screenshot->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\210\252\345\233\276.png);"));

        horizontalLayout_2->addWidget(btn_screenshot);

        textEdit = new QTextEdit(inputWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 49, 781, 131));

        gridLayout->addWidget(inputWidget, 2, 0, 1, 1);


        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "Form", nullptr));
        namelabel->setText(QCoreApplication::translate("ChatWindow", "UserName", nullptr));
        listbtn->setText(QCoreApplication::translate("ChatWindow", "...", nullptr));
        sendBut->setText(QCoreApplication::translate("ChatWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBut->setShortcut(QCoreApplication::translate("ChatWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_emoj->setText(QString());
        btn_pic->setText(QString());
        fileButton->setText(QString());
        btn_screenshot->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
