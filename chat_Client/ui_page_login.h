/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_login
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *lb_title;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bin_login;
    QPushButton *btn_forget;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QCheckBox *cb_remember;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QLabel *lb_image;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *le_password;
    QLineEdit *le_username;
    QSpacerItem *verticalSpacer_2;
    QLabel *lb1;
    QLabel *lb2;
    QWidget *widget_3;
    QWidget *widget_4;
    QPushButton *setNetBut;
    QPushButton *exitButton;

    void setupUi(QWidget *Page_login)
    {
        if (Page_login->objectName().isEmpty())
            Page_login->setObjectName("Page_login");
        Page_login->resize(900, 570);
        Page_login->setMinimumSize(QSize(900, 570));
        Page_login->setMaximumSize(QSize(900, 570));
        Page_login->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon"), QSize(), QIcon::Normal, QIcon::Off);
        Page_login->setWindowIcon(icon);
        Page_login->setLayoutDirection(Qt::LeftToRight);
        Page_login->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Page_login);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        lb_title = new QLabel(Page_login);
        lb_title->setObjectName("lb_title");
        lb_title->setMinimumSize(QSize(0, 50));
        lb_title->setMaximumSize(QSize(16777215, 140));
        QFont font;
        font.setPointSize(20);
        lb_title->setFont(font);
        lb_title->setStyleSheet(QString::fromUtf8(""));
        lb_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_title, 6, 0, 1, 1);

        widget = new QWidget(Page_login);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 45));
        widget->setMaximumSize(QSize(16777215, 200));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        btn_register = new QPushButton(widget);
        btn_register->setObjectName("btn_register");
        btn_register->setMinimumSize(QSize(150, 50));
        btn_register->setMaximumSize(QSize(150, 16777215));
        btn_register->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(btn_register, 3, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        bin_login = new QPushButton(widget);
        bin_login->setObjectName("bin_login");
        bin_login->setMinimumSize(QSize(150, 50));
        bin_login->setMaximumSize(QSize(150, 16777215));
        bin_login->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(bin_login, 3, 1, 1, 1);

        btn_forget = new QPushButton(widget);
        btn_forget->setObjectName("btn_forget");
        btn_forget->setMinimumSize(QSize(0, 40));
        btn_forget->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setUnderline(true);
        btn_forget->setFont(font1);
        btn_forget->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_forget, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_4, 2, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer, 4, 3, 1, 1);

        cb_remember = new QCheckBox(widget);
        cb_remember->setObjectName("cb_remember");
        cb_remember->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(cb_remember, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 2);


        gridLayout->addWidget(widget, 10, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_5, 7, 0, 1, 1);

        lb_image = new QLabel(Page_login);
        lb_image->setObjectName("lb_image");
        lb_image->setMinimumSize(QSize(400, 500));
        lb_image->setMaximumSize(QSize(400, 16777215));
        lb_image->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lb_image, 2, 3, 11, 1);

        widget_2 = new QWidget(Page_login);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setMaximumSize(QSize(16777215, 150));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);

        le_password = new QLineEdit(widget_2);
        le_password->setObjectName("le_password");
        le_password->setMinimumSize(QSize(0, 42));
        le_password->setMaxLength(8);
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(le_password, 3, 1, 1, 1);

        le_username = new QLineEdit(widget_2);
        le_username->setObjectName("le_username");
        le_username->setMinimumSize(QSize(0, 42));
        le_username->setMaxLength(8);

        gridLayout_3->addWidget(le_username, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_3->addItem(verticalSpacer_2, 1, 1, 1, 1);

        lb1 = new QLabel(widget_2);
        lb1->setObjectName("lb1");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Noto Rashi Hebrew Light")});
        font2.setPointSize(14);
        lb1->setFont(font2);
        lb1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lb1, 0, 0, 1, 1);

        lb2 = new QLabel(widget_2);
        lb2->setObjectName("lb2");
        lb2->setFont(font2);
        lb2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lb2, 3, 0, 1, 1);


        gridLayout->addWidget(widget_2, 8, 0, 1, 1);

        widget_3 = new QWidget(Page_login);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(widget_3, 0, 4, 1, 2);

        widget_4 = new QWidget(Page_login);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 40));
        setNetBut = new QPushButton(widget_4);
        setNetBut->setObjectName("setNetBut");
        setNetBut->setGeometry(QRect(20, 0, 30, 30));
        setNetBut->setMaximumSize(QSize(30, 35));
        setNetBut->setStyleSheet(QString::fromUtf8("border-image: url(:/\347\275\221\347\273\234\350\256\276\347\275\256.svg);"));
        exitButton = new QPushButton(widget_4);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(800, 0, 28, 30));
        exitButton->setMaximumSize(QSize(28, 30));
        exitButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/pic/\345\210\240\351\231\2442.png);"));

        gridLayout->addWidget(widget_4, 0, 0, 1, 4);

        QWidget::setTabOrder(le_username, le_password);
        QWidget::setTabOrder(le_password, btn_register);

        retranslateUi(Page_login);

        QMetaObject::connectSlotsByName(Page_login);
    } // setupUi

    void retranslateUi(QWidget *Page_login)
    {
        Page_login->setWindowTitle(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        Page_login->setToolTip(QCoreApplication::translate("Page_login", "\350\277\231\346\230\257\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
#endif // QT_CONFIG(tooltip)
        lb_title->setText(QCoreApplication::translate("Page_login", "ATAW Chat", nullptr));
        btn_register->setText(QCoreApplication::translate("Page_login", "Sign up", nullptr));
        bin_login->setText(QCoreApplication::translate("Page_login", "Sign in", nullptr));
        btn_forget->setText(QCoreApplication::translate("Page_login", "forget password?", nullptr));
        cb_remember->setText(QCoreApplication::translate("Page_login", "remember", nullptr));
        lb_image->setText(QString());
        le_password->setPlaceholderText(QCoreApplication::translate("Page_login", "Please input your password", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("Page_login", "Please input your username", nullptr));
        lb1->setText(QCoreApplication::translate("Page_login", "UserName", nullptr));
        lb2->setText(QCoreApplication::translate("Page_login", "Password", nullptr));
        setNetBut->setText(QString());
        exitButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Page_login: public Ui_Page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
