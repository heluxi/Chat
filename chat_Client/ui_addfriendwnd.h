/********************************************************************************
** Form generated from reading UI file 'addfriendwnd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWND_H
#define UI_ADDFRIENDWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addFriendWnd
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *timeLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QWidget *widget;
    QLabel *userName;
    QLabel *idLabel;
    QFrame *head;
    QLabel *msgLabel;
    QPushButton *agreeBtn;
    QPushButton *rejectBtn;

    void setupUi(QDialog *addFriendWnd)
    {
        if (addFriendWnd->objectName().isEmpty())
            addFriendWnd->setObjectName("addFriendWnd");
        addFriendWnd->resize(479, 316);
        addFriendWnd->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 207, 255);"));
        verticalLayout = new QVBoxLayout(addFriendWnd);
        verticalLayout->setObjectName("verticalLayout");
        widget_3 = new QWidget(addFriendWnd);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        timeLabel = new QLabel(widget_3);
        timeLabel->setObjectName("timeLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(timeLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QWidget(addFriendWnd);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(461, 211));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 124);\n"
"border-radius:10px;"));
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 60, 361, 81));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        userName = new QLabel(widget);
        userName->setObjectName("userName");
        userName->setGeometry(QRect(90, 10, 59, 21));
        idLabel = new QLabel(widget);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(100, 50, 101, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("URW Bookman")});
        font1.setPointSize(15);
        font1.setItalic(true);
        idLabel->setFont(font1);
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        head = new QFrame(widget);
        head->setObjectName("head");
        head->setGeometry(QRect(10, 0, 81, 81));
        head->setStyleSheet(QString::fromUtf8("border-image: url(:/res/pic/Customer Copy.png);"));
        msgLabel = new QLabel(widget_2);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setGeometry(QRect(10, 10, 101, 21));
        msgLabel->setFont(font1);
        msgLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        agreeBtn = new QPushButton(widget_2);
        agreeBtn->setObjectName("agreeBtn");
        agreeBtn->setGeometry(QRect(250, 160, 91, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        agreeBtn->setFont(font2);
        agreeBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        rejectBtn = new QPushButton(widget_2);
        rejectBtn->setObjectName("rejectBtn");
        rejectBtn->setGeometry(QRect(350, 160, 91, 41));
        rejectBtn->setFont(font2);
        rejectBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));

        verticalLayout->addWidget(widget_2);


        retranslateUi(addFriendWnd);

        QMetaObject::connectSlotsByName(addFriendWnd);
    } // setupUi

    void retranslateUi(QDialog *addFriendWnd)
    {
        addFriendWnd->setWindowTitle(QCoreApplication::translate("addFriendWnd", "Dialog", nullptr));
        timeLabel->setText(QCoreApplication::translate("addFriendWnd", "TextLabel", nullptr));
        userName->setText(QString());
        idLabel->setText(QCoreApplication::translate("addFriendWnd", "TextLabel", nullptr));
        msgLabel->setText(QCoreApplication::translate("addFriendWnd", "TextLabel", nullptr));
        agreeBtn->setText(QCoreApplication::translate("addFriendWnd", "Accept", nullptr));
        rejectBtn->setText(QCoreApplication::translate("addFriendWnd", "Reject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addFriendWnd: public Ui_addFriendWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWND_H
