/********************************************************************************
** Form generated from reading UI file 'messagedlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDLG_H
#define UI_MESSAGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageDlg
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QLabel *userName;
    QLabel *idLabel;
    QFrame *head;
    QLabel *msgLabel;
    QPushButton *agreeBtn;
    QLabel *timeLabel;

    void setupUi(QWidget *MessageDlg)
    {
        if (MessageDlg->objectName().isEmpty())
            MessageDlg->setObjectName("MessageDlg");
        MessageDlg->resize(498, 290);
        MessageDlg->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 201, 167, 128);"));
        widget_2 = new QWidget(MessageDlg);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 60, 461, 211));
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
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Bookman")});
        font.setPointSize(15);
        font.setItalic(true);
        idLabel->setFont(font);
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        head = new QFrame(widget);
        head->setObjectName("head");
        head->setGeometry(QRect(10, 0, 81, 81));
        head->setStyleSheet(QString::fromUtf8("border-image: url(:/res/pic/Customer Copy.png);"));
        msgLabel = new QLabel(widget_2);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setGeometry(QRect(10, 10, 101, 21));
        msgLabel->setFont(font);
        msgLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        agreeBtn = new QPushButton(widget_2);
        agreeBtn->setObjectName("agreeBtn");
        agreeBtn->setGeometry(QRect(350, 160, 91, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        agreeBtn->setFont(font1);
        agreeBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        timeLabel = new QLabel(MessageDlg);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(180, 10, 141, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        timeLabel->setFont(font2);
        timeLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(MessageDlg);

        QMetaObject::connectSlotsByName(MessageDlg);
    } // setupUi

    void retranslateUi(QWidget *MessageDlg)
    {
        MessageDlg->setWindowTitle(QCoreApplication::translate("MessageDlg", "Form", nullptr));
        userName->setText(QString());
        idLabel->setText(QCoreApplication::translate("MessageDlg", "TextLabel", nullptr));
        msgLabel->setText(QCoreApplication::translate("MessageDlg", "TextLabel", nullptr));
        agreeBtn->setText(QCoreApplication::translate("MessageDlg", "Accept", nullptr));
        timeLabel->setText(QCoreApplication::translate("MessageDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageDlg: public Ui_MessageDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDLG_H
