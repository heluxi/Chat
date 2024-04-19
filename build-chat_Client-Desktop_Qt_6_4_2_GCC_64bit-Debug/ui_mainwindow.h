/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_7;
    QWidget *widget_16;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_emoj;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_pic;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *fileButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_screenshot;
    QPushButton *sendBut;
    QTextEdit *textEdit;
    QLabel *label;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_4;
    QListWidget *listWidget;
    QWidget *widget_6;
    QLineEdit *searchlineEdit;
    QListWidget *listWidget_message;
    QWidget *widget_12;
    QPushButton *btn_add;
    QWidget *widget;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_chat;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_user;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_settings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1234, 682);
        MainWindow->setMinimumSize(QSize(1234, 682));
        MainWindow->setMaximumSize(QSize(1234, 682));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("border-radius:1px;"));
        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(410, 10, 821, 651));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        widget_16 = new QWidget(widget_7);
        widget_16->setObjectName("widget_16");
        widget_16->setGeometry(QRect(10, 430, 801, 211));
        widget_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_8 = new QWidget(widget_16);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(0, 0, 181, 49));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget_8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_emoj = new QPushButton(widget_8);
        btn_emoj->setObjectName("btn_emoj");
        btn_emoj->setMinimumSize(QSize(41, 31));
        btn_emoj->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\350\241\250\346\203\205.png);"));

        horizontalLayout_2->addWidget(btn_emoj);

        horizontalSpacer_4 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_pic = new QPushButton(widget_8);
        btn_pic->setObjectName("btn_pic");
        btn_pic->setMinimumSize(QSize(41, 31));
        btn_pic->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\233\276\347\211\207.png);"));

        horizontalLayout_2->addWidget(btn_pic);

        horizontalSpacer_5 = new QSpacerItem(2, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        fileButton = new QPushButton(widget_8);
        fileButton->setObjectName("fileButton");
        fileButton->setMinimumSize(QSize(41, 31));
        fileButton->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\226\207\344\273\266\345\244\271.png);"));

        horizontalLayout_2->addWidget(fileButton);

        horizontalSpacer_6 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btn_screenshot = new QPushButton(widget_8);
        btn_screenshot->setObjectName("btn_screenshot");
        btn_screenshot->setMinimumSize(QSize(41, 31));
        btn_screenshot->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\210\252\345\233\276.png);"));

        horizontalLayout_2->addWidget(btn_screenshot);

        sendBut = new QPushButton(widget_16);
        sendBut->setObjectName("sendBut");
        sendBut->setGeometry(QRect(650, 170, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223_GBK")});
        font.setPointSize(12);
        sendBut->setFont(font);
        sendBut->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(240, 240, 240);\n"
"border-radius:2px;\n"
""));
        textEdit = new QTextEdit(widget_16);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 60, 781, 101));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(widget_7);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 141, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        widget_10 = new QWidget(widget_7);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(690, 0, 131, 41));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        horizontalLayout = new QHBoxLayout(widget_10);
        horizontalLayout->setObjectName("horizontalLayout");
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

        listWidget = new QListWidget(widget_7);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 70, 811, 351));
        listWidget->setMinimumSize(QSize(811, 341));
        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(90, 10, 321, 651));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
""));
        searchlineEdit = new QLineEdit(widget_6);
        searchlineEdit->setObjectName("searchlineEdit");
        searchlineEdit->setGeometry(QRect(10, 30, 261, 41));
        QFont font2;
        font2.setPointSize(12);
        searchlineEdit->setFont(font2);
        searchlineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);\n"
"border-radius:20px;\n"
""));
        listWidget_message = new QListWidget(widget_6);
        listWidget_message->setObjectName("listWidget_message");
        listWidget_message->setGeometry(QRect(10, 80, 301, 561));
        listWidget_message->setMaximumSize(QSize(301, 561));
        listWidget_message->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);"));
        widget_12 = new QWidget(widget_6);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(20, 30, 31, 41));
        widget_12->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\220\234\347\264\242.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        btn_add = new QPushButton(widget_6);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(270, 30, 41, 41));
        btn_add->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/ic_add_2.png);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 81, 651));
        widget->setMinimumSize(QSize(81, 651));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 41, 45);"));
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 20, 79, 311));
        widget1->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(widget1);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(61, 61));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:30px;\n"
"image: url(:/res/pic/\345\244\251\347\214\253.png);"));

        verticalLayout->addWidget(widget_2);

        verticalSpacer_3 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        btn_chat = new QPushButton(widget1);
        btn_chat->setObjectName("btn_chat");
        btn_chat->setMinimumSize(QSize(51, 41));
        btn_chat->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/Chat.png);"));

        verticalLayout->addWidget(btn_chat);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btn_user = new QPushButton(widget1);
        btn_user->setObjectName("btn_user");
        btn_user->setMinimumSize(QSize(51, 41));
        btn_user->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\347\224\250\346\210\267.png);"));
        btn_user->setCheckable(false);
        btn_user->setChecked(false);

        verticalLayout->addWidget(btn_user);

        verticalSpacer = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_settings = new QPushButton(widget1);
        btn_settings->setObjectName("btn_settings");
        btn_settings->setMinimumSize(QSize(51, 41));
        btn_settings->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/3.1 \350\256\276\347\275\256.png);"));

        verticalLayout->addWidget(btn_settings);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_emoj->setText(QString());
        btn_pic->setText(QString());
        fileButton->setText(QString());
        btn_screenshot->setText(QString());
        sendBut->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBut->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "UserName", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        searchlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "             \346\220\234\347\264\242...", nullptr));
        btn_add->setText(QString());
        btn_chat->setText(QString());
        btn_user->setText(QString());
        btn_settings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
