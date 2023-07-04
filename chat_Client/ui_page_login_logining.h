/********************************************************************************
** Form generated from reading UI file 'page_login_logining.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_LOGINING_H
#define UI_PAGE_LOGIN_LOGINING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_Login_Logining
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLabel *lb_head;
    QSpacerItem *verticalSpacer;
    QLabel *lb_logining;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Page_Login_Logining)
    {
        if (Page_Login_Logining->objectName().isEmpty())
            Page_Login_Logining->setObjectName("Page_Login_Logining");
        Page_Login_Logining->resize(870, 520);
        Page_Login_Logining->setMinimumSize(QSize(870, 520));
        gridLayout = new QGridLayout(Page_Login_Logining);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(Page_Login_Logining);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName("btn_cancel");
        QFont font;
        font.setPointSize(20);
        btn_cancel->setFont(font);

        gridLayout_2->addWidget(btn_cancel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout->addWidget(widget, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        label_2 = new QLabel(Page_Login_Logining);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lb_head = new QLabel(Page_Login_Logining);
        lb_head->setObjectName("lb_head");
        lb_head->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lb_head, 0, 1, 6, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        lb_logining = new QLabel(Page_Login_Logining);
        lb_logining->setObjectName("lb_logining");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Abadi MT")});
        font2.setPointSize(35);
        lb_logining->setFont(font2);
        lb_logining->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_logining, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);


        retranslateUi(Page_Login_Logining);

        QMetaObject::connectSlotsByName(Page_Login_Logining);
    } // setupUi

    void retranslateUi(QWidget *Page_Login_Logining)
    {
        Page_Login_Logining->setWindowTitle(QCoreApplication::translate("Page_Login_Logining", "Form", nullptr));
        btn_cancel->setText(QCoreApplication::translate("Page_Login_Logining", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("Page_Login_Logining", "ATAW Chat", nullptr));
        lb_head->setText(QCoreApplication::translate("Page_Login_Logining", "head", nullptr));
        lb_logining->setText(QCoreApplication::translate("Page_Login_Logining", "Logining......", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_Login_Logining: public Ui_Page_Login_Logining {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_LOGINING_H
