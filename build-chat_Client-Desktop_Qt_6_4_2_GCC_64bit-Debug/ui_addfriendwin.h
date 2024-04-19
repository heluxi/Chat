/********************************************************************************
** Form generated from reading UI file 'addfriendwin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWIN_H
#define UI_ADDFRIENDWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWin
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *findUser;
    QGridLayout *gridLayout_3;
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
    QWidget *findGroup;

    void setupUi(QWidget *AddFriendWin)
    {
        if (AddFriendWin->objectName().isEmpty())
            AddFriendWin->setObjectName("AddFriendWin");
        AddFriendWin->resize(500, 408);
        AddFriendWin->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 201, 167, 128);"));
        gridLayout = new QGridLayout(AddFriendWin);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(AddFriendWin);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("border-radius:1px;"));
        findUser = new QWidget();
        findUser->setObjectName("findUser");
        gridLayout_3 = new QGridLayout(findUser);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(findUser);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 70));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 30, 341, 31));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgba(255, 255, 255, 78);"));
        searchBut = new QPushButton(widget);
        searchBut->setObjectName("searchBut");
        searchBut->setGeometry(QRect(360, 20, 91, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        searchBut->setFont(font1);
        searchBut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 30, 41, 31));
        widget_2->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\346\220\234\347\264\242.png);\n"
"background-color: rgba(255, 255, 255, 0);"));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        resultBut = new QWidget(findUser);
        resultBut->setObjectName("resultBut");
        resultBut->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 155);\n"
"border-radius:10px;"));
        resultLabel = new QLabel(resultBut);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(10, 0, 91, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Bookman")});
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(true);
        resultLabel->setFont(font2);
        resultLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        nameLabel = new QLabel(resultBut);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(20, 90, 61, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Noto Sans Adlam")});
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(true);
        nameLabel->setFont(font3);
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        idLabel = new QLabel(resultBut);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(210, 90, 61, 31));
        idLabel->setFont(font3);
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        headLabel = new QLabel(resultBut);
        headLabel->setObjectName("headLabel");
        headLabel->setGeometry(QRect(20, 170, 61, 31));
        headLabel->setFont(font3);
        headLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        addBtn = new QPushButton(resultBut);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(350, 210, 91, 41));
        addBtn->setFont(font1);
        addBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));

        gridLayout_3->addWidget(resultBut, 1, 0, 1, 1);

        tabWidget->addTab(findUser, QString());
        findGroup = new QWidget();
        findGroup->setObjectName("findGroup");
        tabWidget->addTab(findGroup, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(AddFriendWin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddFriendWin);
    } // setupUi

    void retranslateUi(QWidget *AddFriendWin)
    {
        AddFriendWin->setWindowTitle(QCoreApplication::translate("AddFriendWin", "\346\237\245\346\211\276", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("AddFriendWin", "          \350\257\267\350\276\223\345\205\245ID\345\217\267", nullptr));
        searchBut->setText(QCoreApplication::translate("AddFriendWin", "search", nullptr));
        resultLabel->setText(QCoreApplication::translate("AddFriendWin", "result:", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddFriendWin", "name:", nullptr));
        idLabel->setText(QCoreApplication::translate("AddFriendWin", "ID:", nullptr));
        headLabel->setText(QCoreApplication::translate("AddFriendWin", "head:", nullptr));
        addBtn->setText(QCoreApplication::translate("AddFriendWin", "add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(findUser), QCoreApplication::translate("AddFriendWin", "\346\211\276\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(findGroup), QCoreApplication::translate("AddFriendWin", "\346\211\276\347\276\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendWin: public Ui_AddFriendWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWIN_H
