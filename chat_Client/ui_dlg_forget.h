/********************************************************************************
** Form generated from reading UI file 'dlg_forget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_FORGET_H
#define UI_DLG_FORGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dlg_forget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_forget_sure;
    QPushButton *btn_forget_cancel;
    QSpacerItem *verticalSpacer_2;
    QLabel *lb_Ensure;
    QLabel *lb_newPassword;
    QLineEdit *le_user;
    QLineEdit *le_newPassword;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLineEdit *le_Ensure;
    QLabel *lb_image;
    QLabel *lb_user;
    QLabel *lb_title;

    void setupUi(QDialog *Dlg_forget)
    {
        if (Dlg_forget->objectName().isEmpty())
            Dlg_forget->setObjectName("Dlg_forget");
        Dlg_forget->resize(800, 600);
        Dlg_forget->setMinimumSize(QSize(800, 600));
        Dlg_forget->setMaximumSize(QSize(800, 600));
        gridLayout_2 = new QGridLayout(Dlg_forget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(Dlg_forget);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 100));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(4, 4, 4, 1);
        btn_forget_sure = new QPushButton(widget);
        btn_forget_sure->setObjectName("btn_forget_sure");
        btn_forget_sure->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(14);
        btn_forget_sure->setFont(font);

        gridLayout->addWidget(btn_forget_sure, 1, 0, 1, 1);

        btn_forget_cancel = new QPushButton(widget);
        btn_forget_cancel->setObjectName("btn_forget_cancel");
        btn_forget_cancel->setMinimumSize(QSize(0, 35));
        btn_forget_cancel->setFont(font);

        gridLayout->addWidget(btn_forget_cancel, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 8, 1, 1, 1);

        lb_Ensure = new QLabel(Dlg_forget);
        lb_Ensure->setObjectName("lb_Ensure");
        lb_Ensure->setMaximumSize(QSize(16777215, 28));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        lb_Ensure->setFont(font1);

        gridLayout_2->addWidget(lb_Ensure, 6, 1, 1, 1);

        lb_newPassword = new QLabel(Dlg_forget);
        lb_newPassword->setObjectName("lb_newPassword");
        lb_newPassword->setMaximumSize(QSize(16777215, 28));
        lb_newPassword->setFont(font1);

        gridLayout_2->addWidget(lb_newPassword, 4, 1, 1, 1);

        le_user = new QLineEdit(Dlg_forget);
        le_user->setObjectName("le_user");
        le_user->setMinimumSize(QSize(322, 37));
        le_user->setMaximumSize(QSize(322, 16777215));

        gridLayout_2->addWidget(le_user, 3, 1, 1, 1);

        le_newPassword = new QLineEdit(Dlg_forget);
        le_newPassword->setObjectName("le_newPassword");
        le_newPassword->setMinimumSize(QSize(0, 37));
        le_newPassword->setMaximumSize(QSize(322, 16777215));

        gridLayout_2->addWidget(le_newPassword, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer, 9, 1, 1, 1);

        le_Ensure = new QLineEdit(Dlg_forget);
        le_Ensure->setObjectName("le_Ensure");
        le_Ensure->setMinimumSize(QSize(0, 37));
        le_Ensure->setMaximumSize(QSize(322, 16777215));

        gridLayout_2->addWidget(le_Ensure, 7, 1, 1, 1);

        lb_image = new QLabel(Dlg_forget);
        lb_image->setObjectName("lb_image");
        lb_image->setMinimumSize(QSize(350, 550));
        lb_image->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(lb_image, 0, 0, 10, 1);

        lb_user = new QLabel(Dlg_forget);
        lb_user->setObjectName("lb_user");
        lb_user->setMaximumSize(QSize(16777215, 28));
        lb_user->setFont(font1);

        gridLayout_2->addWidget(lb_user, 2, 1, 1, 1);

        lb_title = new QLabel(Dlg_forget);
        lb_title->setObjectName("lb_title");
        lb_title->setFont(font1);

        gridLayout_2->addWidget(lb_title, 0, 1, 1, 1);


        retranslateUi(Dlg_forget);

        QMetaObject::connectSlotsByName(Dlg_forget);
    } // setupUi

    void retranslateUi(QDialog *Dlg_forget)
    {
        Dlg_forget->setWindowTitle(QCoreApplication::translate("Dlg_forget", "Dialog", nullptr));
        btn_forget_sure->setText(QCoreApplication::translate("Dlg_forget", "Sure", nullptr));
        btn_forget_cancel->setText(QCoreApplication::translate("Dlg_forget", "Cancel", nullptr));
        lb_Ensure->setText(QCoreApplication::translate("Dlg_forget", "Ensure your newPassword", nullptr));
        lb_newPassword->setText(QCoreApplication::translate("Dlg_forget", "NewPassword", nullptr));
        lb_image->setText(QString());
        lb_user->setText(QCoreApplication::translate("Dlg_forget", "Username", nullptr));
        lb_title->setText(QCoreApplication::translate("Dlg_forget", "Have you \n"
"    forgotten your \n"
"               password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_forget: public Ui_Dlg_forget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_FORGET_H
