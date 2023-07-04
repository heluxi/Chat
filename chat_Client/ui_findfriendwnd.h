/********************************************************************************
** Form generated from reading UI file 'findfriendwnd.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFRIENDWND_H
#define UI_FINDFRIENDWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindFriendWnd
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLineEdit *lineEdit;
    QPushButton *searchBut;
    QWidget *widget_2;
    QWidget *resultBut;
    QLabel *resultLabel;
    QLabel *nameLabel;
    QLabel *idLabel;
    QLabel *headLabel;
    QPushButton *addBtn;
    QLabel *label;

    void setupUi(QDialog *FindFriendWnd)
    {
        if (FindFriendWnd->objectName().isEmpty())
            FindFriendWnd->setObjectName("FindFriendWnd");
        FindFriendWnd->resize(548, 471);
        FindFriendWnd->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 207, 255);\n"
""));
        gridLayout = new QGridLayout(FindFriendWnd);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(FindFriendWnd);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 70));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 20, 301, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgba(255, 255, 255, 78);"));
        searchBut = new QPushButton(widget);
        searchBut->setObjectName("searchBut");
        searchBut->setGeometry(QRect(410, 20, 91, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        searchBut->setFont(font1);
        searchBut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(60, 20, 41, 31));
        widget_2->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\220\234\347\264\242.png);\n"
"background-color: rgba(255, 255, 255, 0);"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        resultBut = new QWidget(FindFriendWnd);
        resultBut->setObjectName("resultBut");
        resultBut->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 155);\n"
"border-radius:10px;"));
        resultLabel = new QLabel(resultBut);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(10, 0, 401, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Bookman")});
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(true);
        resultLabel->setFont(font2);
        resultLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        nameLabel = new QLabel(resultBut);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(20, 90, 111, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Noto Sans Adlam")});
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(true);
        nameLabel->setFont(font3);
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        idLabel = new QLabel(resultBut);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(210, 90, 111, 31));
        idLabel->setFont(font3);
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        headLabel = new QLabel(resultBut);
        headLabel->setObjectName("headLabel");
        headLabel->setGeometry(QRect(20, 170, 71, 31));
        headLabel->setFont(font3);
        headLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        addBtn = new QPushButton(resultBut);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(350, 210, 91, 41));
        addBtn->setFont(font1);
        addBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));

        gridLayout->addWidget(resultBut, 2, 0, 1, 1);

        label = new QLabel(FindFriendWnd);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 40));
        QFont font4;
        font4.setPointSize(15);
        label->setFont(font4);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(FindFriendWnd);

        QMetaObject::connectSlotsByName(FindFriendWnd);
    } // setupUi

    void retranslateUi(QDialog *FindFriendWnd)
    {
        FindFriendWnd->setWindowTitle(QCoreApplication::translate("FindFriendWnd", "Dialog", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("FindFriendWnd", "          \350\257\267\350\276\223\345\205\245ID\345\217\267", nullptr));
        searchBut->setText(QCoreApplication::translate("FindFriendWnd", "search", nullptr));
        resultLabel->setText(QCoreApplication::translate("FindFriendWnd", "reslut:", nullptr));
        nameLabel->setText(QCoreApplication::translate("FindFriendWnd", "name:", nullptr));
        idLabel->setText(QCoreApplication::translate("FindFriendWnd", "ID:", nullptr));
        headLabel->setText(QCoreApplication::translate("FindFriendWnd", "head:", nullptr));
        addBtn->setText(QCoreApplication::translate("FindFriendWnd", "add", nullptr));
        label->setText(QCoreApplication::translate("FindFriendWnd", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindFriendWnd: public Ui_FindFriendWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFRIENDWND_H
