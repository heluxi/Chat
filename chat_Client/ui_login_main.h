/********************************************************************************
** Form generated from reading UI file 'login_main.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_MAIN_H
#define UI_LOGIN_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_main
{
public:
    QGridLayout *gridLayout;
    QLabel *lb_title;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QCheckBox *cb_remember;
    QPushButton *bin_login;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btn_forget;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *padLabel;
    QLabel *accountLabel;
    QLineEdit *accountEdit;
    QLineEdit *pwdEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lb_image;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *setNetBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitBtn;

    void setupUi(QWidget *login_main)
    {
        if (login_main->objectName().isEmpty())
            login_main->setObjectName("login_main");
        login_main->resize(961, 721);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/pic/Chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        login_main->setWindowIcon(icon);
        login_main->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background-color:white;\n"
"}\n"
"/*QPushButton{border-radius:6px;color:white;background-color:#1abc9c;}*/\n"
"QPushButton{\n"
"    background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994 rgba(64,145,252,255),stop:1 rgba(255,255,255,255));\n"
"/*    color:rgb(255,255,255,255);*/\n"
"    color:white;\n"
"    border:0px groove gray;\n"
"    border-radius:7px;\n"
"    padding:2px 4px;\n"
"/*    font:16pt \"Candara\";*/\n"
"    font: 87 16pt \"Arial Black\";\n"
"}\n"
"QPushButton#btn_forget{\n"
"    background-color:white;\n"
"    color: rgb(91, 156, 200);\n"
"    font: 87 14pt \"Arial Black\";\n"
"}\n"
"\n"
"QCheckBox#cb_remember{\n"
"    color: rgb(91, 156, 200);\n"
"    font: 87 14pt \"Arial Black\";\n"
"}\n"
"\n"
"/*QLabel{color:#1abc9c;}*/\n"
"QLabel#lb_title{\n"
"    font: 87 26pt \"Arial Black\";\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
"}\n"
"QLabel#lb1{\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
""
                        "    font-size:24;\n"
"    font-weight:bold;\n"
"}\n"
"QLabel#lb2{\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
"    font-size:24;\n"
"    font-weight:bold;\n"
"}\n"
"/*QLineEdit{border: 2px solid #2ecc71;border-radius:6px;min-height:25;}*/\n"
"QLineEdit{\n"
"    background-color:rgb(247,247,247);\n"
"    border:1px groove gray;\n"
"    border-radius:7px;\n"
"    padding:2px 4px;\n"
"    font:14pt \"Candara\";\n"
"}\n"
""));
        gridLayout = new QGridLayout(login_main);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        lb_title = new QLabel(login_main);
        lb_title->setObjectName("lb_title");
        lb_title->setMinimumSize(QSize(0, 50));
        lb_title->setMaximumSize(QSize(16777215, 140));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(50);
        font.setBold(false);
        font.setItalic(false);
        lb_title->setFont(font);
        lb_title->setStyleSheet(QString::fromUtf8("\n"
"font: 87 50pt \"Arial Black\";\n"
"    color: rgb(91, 156, 200);"));
        lb_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_title, 1, 0, 1, 1);

        widget = new QWidget(login_main);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 45));
        widget->setMaximumSize(QSize(16777215, 200));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(-1, 0, -1, -1);
        cb_remember = new QCheckBox(widget);
        cb_remember->setObjectName("cb_remember");
        cb_remember->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(cb_remember, 1, 1, 1, 1);

        bin_login = new QPushButton(widget);
        bin_login->setObjectName("bin_login");
        bin_login->setMinimumSize(QSize(150, 50));
        bin_login->setMaximumSize(QSize(150, 16777215));
        bin_login->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(bin_login, 3, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 3, 5, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_5->addItem(verticalSpacer_6, 4, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_5->addItem(verticalSpacer_5, 2, 4, 1, 1);

        btn_register = new QPushButton(widget);
        btn_register->setObjectName("btn_register");
        btn_register->setMinimumSize(QSize(150, 50));
        btn_register->setMaximumSize(QSize(150, 16777215));
        btn_register->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(btn_register, 3, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 3, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 1, 2, 1, 2);

        btn_forget = new QPushButton(widget);
        btn_forget->setObjectName("btn_forget");
        btn_forget->setStyleSheet(QString::fromUtf8("QPushButton#btn_forget{\n"
"    background-color:white;\n"
"    color: rgb(91, 156, 200);\n"
"    font: 87 14pt \"Arial Black\";\n"
"}"));

        gridLayout_5->addWidget(btn_forget, 1, 4, 1, 2);


        gridLayout->addWidget(widget, 3, 0, 1, 1);

        widget_2 = new QWidget(login_main);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setMaximumSize(QSize(16777215, 150));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_4->addItem(verticalSpacer_3, 1, 1, 1, 1);

        padLabel = new QLabel(widget_2);
        padLabel->setObjectName("padLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Noto Rashi Hebrew Light")});
        font1.setPointSize(14);
        padLabel->setFont(font1);
        padLabel->setStyleSheet(QString::fromUtf8("color: rgb(91, 156, 200);"));
        padLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(padLabel, 3, 0, 1, 1);

        accountLabel = new QLabel(widget_2);
        accountLabel->setObjectName("accountLabel");
        accountLabel->setFont(font1);
        accountLabel->setStyleSheet(QString::fromUtf8("color: rgb(91, 156, 200);\n"
"\n"
""));
        accountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(accountLabel, 0, 0, 1, 1);

        accountEdit = new QLineEdit(widget_2);
        accountEdit->setObjectName("accountEdit");
        accountEdit->setMinimumSize(QSize(0, 42));
        accountEdit->setMaxLength(8);

        gridLayout_4->addWidget(accountEdit, 0, 1, 1, 1);

        pwdEdit = new QLineEdit(widget_2);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setMinimumSize(QSize(0, 42));
        pwdEdit->setMaxLength(8);
        pwdEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(pwdEdit, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout->addWidget(widget_2, 2, 0, 1, 1);

        lb_image = new QLabel(login_main);
        lb_image->setObjectName("lb_image");
        lb_image->setMinimumSize(QSize(400, 500));
        lb_image->setMaximumSize(QSize(400, 16777215));
        lb_image->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/res/pic/matthew-kane-278419-unsplash.jpg);\n"
""));

        gridLayout->addWidget(lb_image, 1, 1, 3, 1);

        widget_4 = new QWidget(login_main);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 40));
        widget_4->setMaximumSize(QSize(16777215, 40));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background-color:white;\n"
"}\n"
"/*QPushButton{border-radius:6px;color:white;background-color:#1abc9c;}*/\n"
"QPushButton{\n"
"    background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,stop:0.0112994 rgba(64,145,252,255),stop:1 rgba(255,255,255,255));\n"
"/*    color:rgb(255,255,255,255);*/\n"
"    color:white;\n"
"    border:0px groove gray;\n"
"    border-radius:7px;\n"
"    padding:2px 4px;\n"
"/*    font:16pt \"Candara\";*/\n"
"    font: 87 16pt \"Arial Black\";\n"
"}\n"
"QPushButton#btn_forget{\n"
"    background-color:white;\n"
"    color: rgb(91, 156, 200);\n"
"    font: 87 14pt \"Arial Black\";\n"
"}\n"
"\n"
"QCheckBox#cb_remember{\n"
"    color: rgb(91, 156, 200);\n"
"    font: 87 14pt \"Arial Black\";\n"
"}\n"
"\n"
"/*QLabel{color:#1abc9c;}*/\n"
"QLabel#lb_title{\n"
"    font: 87 26pt \"Arial Black\";\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
"}\n"
"QLabel#lb1{\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
""
                        "    font-size:24;\n"
"    font-weight:bold;\n"
"}\n"
"QLabel#lb2{\n"
"    color: rgb(91, 156, 200);\n"
"/*    background-color: white;*/\n"
"    font-size:24;\n"
"    font-weight:bold;\n"
"}\n"
"/*QLineEdit{border: 2px solid #2ecc71;border-radius:6px;min-height:25;}*/\n"
"QLineEdit{\n"
"    background-color:rgb(247,247,247);\n"
"    border:1px groove gray;\n"
"    border-radius:7px;\n"
"    padding:2px 4px;\n"
"    font:14pt \"Candara\";\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        setNetBtn = new QPushButton(widget_4);
        setNetBtn->setObjectName("setNetBtn");
        setNetBtn->setMinimumSize(QSize(32, 30));
        setNetBtn->setMaximumSize(QSize(35, 35));
        setNetBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/\347\275\221\347\273\234\350\256\276\347\275\256.svg);"));

        horizontalLayout->addWidget(setNetBtn);

        horizontalSpacer = new QSpacerItem(857, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitBtn = new QPushButton(widget_4);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setMinimumSize(QSize(30, 30));
        exitBtn->setMaximumSize(QSize(32, 30));
        exitBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/res/pic/\345\210\240\351\231\2442.png);"));

        horizontalLayout->addWidget(exitBtn);


        gridLayout->addWidget(widget_4, 0, 0, 1, 2);


        retranslateUi(login_main);

        QMetaObject::connectSlotsByName(login_main);
    } // setupUi

    void retranslateUi(QWidget *login_main)
    {
        login_main->setWindowTitle(QCoreApplication::translate("login_main", "Form", nullptr));
        lb_title->setText(QCoreApplication::translate("login_main", "ATAW Chat", nullptr));
        cb_remember->setText(QCoreApplication::translate("login_main", "Remember", nullptr));
        bin_login->setText(QCoreApplication::translate("login_main", "Sign in", nullptr));
        btn_register->setText(QCoreApplication::translate("login_main", "Sign up", nullptr));
        btn_forget->setText(QCoreApplication::translate("login_main", "Forget Password?", nullptr));
        padLabel->setText(QCoreApplication::translate("login_main", "Password", nullptr));
        accountLabel->setText(QCoreApplication::translate("login_main", "Account Number", nullptr));
        accountEdit->setPlaceholderText(QCoreApplication::translate("login_main", "Please input your account", nullptr));
        pwdEdit->setPlaceholderText(QCoreApplication::translate("login_main", "Please input your password", nullptr));
        lb_image->setText(QString());
        setNetBtn->setText(QString());
        exitBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_main: public Ui_login_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_MAIN_H
