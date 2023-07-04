/********************************************************************************
** Form generated from reading UI file 'midw.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDW_H
#define UI_MIDW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "listwidget.h"

QT_BEGIN_NAMESPACE

class Ui_midw
{
public:
    QStackedWidget *stackedWidget;
    QWidget *chatListW;
    QGridLayout *gridLayout;
    ListWidget *chatList;
    QWidget *blankpage;
    QLineEdit *searchlineEdit;
    QPushButton *btn_add;

    void setupUi(QWidget *midw)
    {
        if (midw->objectName().isEmpty())
            midw->setObjectName("midw");
        midw->resize(321, 832);
        midw->setMinimumSize(QSize(321, 832));
        midw->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);"));
        stackedWidget = new QStackedWidget(midw);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-3, 60, 331, 771));
        stackedWidget->setMinimumSize(QSize(311, 771));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);"));
        chatListW = new QWidget();
        chatListW->setObjectName("chatListW");
        chatListW->setMinimumSize(QSize(300, 560));
        gridLayout = new QGridLayout(chatListW);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        chatList = new ListWidget(chatListW);
        chatList->setObjectName("chatList");
        chatList->setMinimumSize(QSize(300, 560));
        chatList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));

        gridLayout->addWidget(chatList, 0, 0, 1, 1);

        stackedWidget->addWidget(chatListW);
        blankpage = new QWidget();
        blankpage->setObjectName("blankpage");
        stackedWidget->addWidget(blankpage);
        searchlineEdit = new QLineEdit(midw);
        searchlineEdit->setObjectName("searchlineEdit");
        searchlineEdit->setGeometry(QRect(0, 10, 261, 41));
        searchlineEdit->setMinimumSize(QSize(261, 41));
        QFont font;
        font.setPointSize(12);
        searchlineEdit->setFont(font);
        searchlineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(218, 217, 215);\n"
"border-radius:20px;\n"
""));
        btn_add = new QPushButton(midw);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(270, 10, 41, 41));
        btn_add->setMinimumSize(QSize(41, 41));
        btn_add->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/ic_add_2.png);"));

        retranslateUi(midw);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(midw);
    } // setupUi

    void retranslateUi(QWidget *midw)
    {
        midw->setWindowTitle(QCoreApplication::translate("midw", "Form", nullptr));
        searchlineEdit->setPlaceholderText(QCoreApplication::translate("midw", "             \346\220\234\347\264\242...", nullptr));
        btn_add->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class midw: public Ui_midw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDW_H
