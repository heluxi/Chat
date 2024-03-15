/********************************************************************************
** Form generated from reading UI file 'personmsgdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONMSGDLG_H
#define UI_PERSONMSGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personMsgDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *transBtn;
    QPushButton *msgBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *uNameLab;
    QLabel *idLabel;
    QPushButton *headBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *positionLab;
    QWidget *widget;

    void setupUi(QDialog *personMsgDlg)
    {
        if (personMsgDlg->objectName().isEmpty())
            personMsgDlg->setObjectName("personMsgDlg");
        personMsgDlg->resize(403, 322);
        personMsgDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(personMsgDlg);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 6, 20, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        transBtn = new QPushButton(personMsgDlg);
        transBtn->setObjectName("transBtn");
        transBtn->setMinimumSize(QSize(40, 35));
        transBtn->setMaximumSize(QSize(50, 50));
        transBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/\350\275\254\345\217\221.svg);"));

        horizontalLayout_3->addWidget(transBtn);

        msgBtn = new QPushButton(personMsgDlg);
        msgBtn->setObjectName("msgBtn");
        msgBtn->setMinimumSize(QSize(45, 45));
        msgBtn->setMaximumSize(QSize(45, 45));
        msgBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/\346\266\210\346\201\257.svg);"));

        horizontalLayout_3->addWidget(msgBtn);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        uNameLab = new QLabel(personMsgDlg);
        uNameLab->setObjectName("uNameLab");
        uNameLab->setStyleSheet(QString::fromUtf8("font: 700 italic 16pt \"Noto Sans\";"));

        verticalLayout->addWidget(uNameLab);

        idLabel = new QLabel(personMsgDlg);
        idLabel->setObjectName("idLabel");
        idLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Noto Sans\";"));

        verticalLayout->addWidget(idLabel);


        horizontalLayout->addLayout(verticalLayout);

        headBtn = new QPushButton(personMsgDlg);
        headBtn->setObjectName("headBtn");
        headBtn->setMinimumSize(QSize(75, 75));
        headBtn->setMaximumSize(QSize(75, 75));
        headBtn->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/Customer Copy.png);"));

        horizontalLayout->addWidget(headBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(personMsgDlg);
        label->setObjectName("label");
        label->setMinimumSize(QSize(40, 0));
        label->setMaximumSize(QSize(50, 50));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Noto Sans\";"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        positionLab = new QLabel(personMsgDlg);
        positionLab->setObjectName("positionLab");
        positionLab->setMaximumSize(QSize(16777215, 50));
        positionLab->setStyleSheet(QString::fromUtf8("font: 12pt \"Noto Sans\";"));

        horizontalLayout_2->addWidget(positionLab);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        widget = new QWidget(personMsgDlg);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 1));
        widget->setMaximumSize(QSize(16777215, 0));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);"));

        gridLayout->addWidget(widget, 3, 0, 1, 1);


        retranslateUi(personMsgDlg);

        QMetaObject::connectSlotsByName(personMsgDlg);
    } // setupUi

    void retranslateUi(QDialog *personMsgDlg)
    {
        personMsgDlg->setWindowTitle(QCoreApplication::translate("personMsgDlg", "Dialog", nullptr));
        transBtn->setText(QString());
        msgBtn->setText(QString());
        uNameLab->setText(QCoreApplication::translate("personMsgDlg", "userName", nullptr));
        idLabel->setText(QCoreApplication::translate("personMsgDlg", "ID\345\217\267\357\274\232", nullptr));
        headBtn->setText(QString());
        label->setText(QCoreApplication::translate("personMsgDlg", "\345\234\260\345\214\272\357\274\232", nullptr));
        positionLab->setText(QCoreApplication::translate("personMsgDlg", "\346\234\252\347\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personMsgDlg: public Ui_personMsgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONMSGDLG_H
