/********************************************************************************
** Form generated from reading UI file 'frienddlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDDLG_H
#define UI_FRIENDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendDlg
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QListWidget *listWidget;
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *widget_3;
    QLabel *label_2;
    QWidget *widget_4;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QWidget *widget_5;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *FriendDlg)
    {
        if (FriendDlg->objectName().isEmpty())
            FriendDlg->setObjectName("FriendDlg");
        FriendDlg->resize(301, 604);
        FriendDlg->setMinimumSize(QSize(301, 561));
        FriendDlg->setStyleSheet(QString::fromUtf8("border-radius:1px;\n"
"background-color: rgb(226, 226, 226);\n"
""));
        pushButton = new QPushButton(FriendDlg);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 20, 211, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:4px;"));
        frame = new QFrame(FriendDlg);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(90, 20, 21, 41));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-radius:10px;\n"
"image: url(:/res/pic/\345\244\232\344\272\272 \347\224\250\346\210\267.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        listWidget = new QListWidget(FriendDlg);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 350, 301, 251));
        widget = new QWidget(FriendDlg);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 110, 51, 51));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        widget_2 = new QWidget(FriendDlg);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 70, 301, 121));
        widget_2->setStyleSheet(QString::fromUtf8("border-radius:1px;"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 50, 301, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 229, 229);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 91, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(102, 102, 102);"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 50, 61, 51));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/\351\200\232\350\256\257\345\275\225_\345\241\253\345\205\205.png);"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 50, 91, 51));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);
        widget_4 = new QWidget(FriendDlg);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 190, 301, 121));
        widget_4->setStyleSheet(QString::fromUtf8("border-radius:1px;"));
        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 50, 301, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 229, 229);"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 91, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(102, 102, 102);"));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(10, 50, 61, 51));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"image: url(:/res/pic/\347\276\244\350\201\212.png);\n"
"border-radius:15px;"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 50, 91, 51));
        label_4->setFont(font1);
        label_5 = new QLabel(FriendDlg);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 310, 91, 41));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(102, 102, 102);"));

        retranslateUi(FriendDlg);

        QMetaObject::connectSlotsByName(FriendDlg);
    } // setupUi

    void retranslateUi(QWidget *FriendDlg)
    {
        FriendDlg->setWindowTitle(QCoreApplication::translate("FriendDlg", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FriendDlg", "   \351\200\232\350\256\257\345\275\225\347\256\241\347\220\206", nullptr));
        pushButton_2->setText(QString());
        label->setText(QCoreApplication::translate("FriendDlg", "\346\226\260\347\232\204\346\234\213\345\217\213", nullptr));
        label_2->setText(QCoreApplication::translate("FriendDlg", "\346\226\260\347\232\204\346\234\213\345\217\213", nullptr));
        pushButton_3->setText(QString());
        label_3->setText(QCoreApplication::translate("FriendDlg", "\347\276\244\350\201\212", nullptr));
        label_4->setText(QCoreApplication::translate("FriendDlg", "\350\201\212\345\244\251\345\256\244", nullptr));
        label_5->setText(QCoreApplication::translate("FriendDlg", "\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendDlg: public Ui_FriendDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDDLG_H
