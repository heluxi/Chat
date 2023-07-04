/********************************************************************************
** Form generated from reading UI file 'contactwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWIDGET_H
#define UI_CONTACTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "listwidget.h"
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ContactWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    MyButton *btn_friend;
    QSpacerItem *horizontalSpacer;
    MyButton *btn_group;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    ListWidget *friendList;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    ListWidget *groupList;

    void setupUi(QWidget *ContactWidget)
    {
        if (ContactWidget->objectName().isEmpty())
            ContactWidget->setObjectName("ContactWidget");
        ContactWidget->resize(311, 771);
        ContactWidget->setMinimumSize(QSize(311, 771));
        verticalLayout = new QVBoxLayout(ContactWidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(ContactWidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        QStringList tmp;
        tmp << ":/Icons/MainWindow/friend.png"
            << ":/Icons/MainWindow/friend2.png"
            << ":/Icons/MainWindow/friend3.png";
        btn_friend = new MyButton(nullptr,tmp,QSize(48,48));
//        btn_friend = new MyButton(widget);
        btn_friend->setObjectName("btn_friend");
        btn_friend->setMinimumSize(QSize(48, 48));

        horizontalLayout->addWidget(btn_friend);

        horizontalSpacer = new QSpacerItem(43, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);



        tmp.clear();

        tmp << ":/Icons/MainWindow/group.png"
            << ":/Icons/MainWindow/group2.png"
            << ":/Icons/MainWindow/group3.png";
        btn_group = new MyButton(nullptr,tmp,QSize(48,48));
//        btn_group = new MyButton(widget);
        btn_group->setObjectName("btn_group");
        btn_group->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(btn_group);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(ContactWidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        friendList = new ListWidget(page);
        friendList->setObjectName("friendList");

        verticalLayout_2->addWidget(friendList);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupList = new ListWidget(page_2);
        groupList->setObjectName("groupList");

        verticalLayout_3->addWidget(groupList);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ContactWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ContactWidget);
    } // setupUi

    void retranslateUi(QWidget *ContactWidget)
    {
        ContactWidget->setWindowTitle(QCoreApplication::translate("ContactWidget", "Form", nullptr));
        btn_friend->setText(QCoreApplication::translate("ContactWidget", "friend", nullptr));
        btn_group->setText(QCoreApplication::translate("ContactWidget", "group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactWidget: public Ui_ContactWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWIDGET_H
