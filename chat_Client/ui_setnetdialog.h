/********************************************************************************
** Form generated from reading UI file 'setnetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETNETDIALOG_H
#define UI_SETNETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setnetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QComboBox *ipcomboBox;
    QLineEdit *portLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *filePortEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *setnetDialog)
    {
        if (setnetDialog->objectName().isEmpty())
            setnetDialog->setObjectName("setnetDialog");
        setnetDialog->resize(870, 520);
        setnetDialog->setMinimumSize(QSize(870, 520));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("network-server");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        setnetDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(setnetDialog);
        verticalLayout->setObjectName("verticalLayout");
        label_5 = new QLabel(setnetDialog);
        label_5->setObjectName("label_5");
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        label_3 = new QLabel(setnetDialog);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 60));
        label_3->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(19);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(setnetDialog);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 200));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        ipcomboBox = new QComboBox(widget);
        ipcomboBox->addItem(QString());
        ipcomboBox->setObjectName("ipcomboBox");
        ipcomboBox->setMinimumSize(QSize(0, 40));
        ipcomboBox->setEditable(true);

        gridLayout->addWidget(ipcomboBox, 0, 2, 1, 1);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(portLineEdit, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        filePortEdit = new QLineEdit(widget);
        filePortEdit->setObjectName("filePortEdit");
        filePortEdit->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(filePortEdit, 4, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);


        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        widget_2 = new QWidget(setnetDialog);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        okButton = new QPushButton(widget_2);
        okButton->setObjectName("okButton");
        okButton->setMinimumSize(QSize(100, 0));
        QFont font3;
        font3.setPointSize(18);
        okButton->setFont(font3);

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget_2);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(100, 0));
        cancelButton->setFont(font);

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(setnetDialog);

        QMetaObject::connectSlotsByName(setnetDialog);
    } // setupUi

    void retranslateUi(QDialog *setnetDialog)
    {
        setnetDialog->setWindowTitle(QCoreApplication::translate("setnetDialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("setnetDialog", "ATAW Chat", nullptr));
        label_3->setText(QCoreApplication::translate("setnetDialog", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        ipcomboBox->setItemText(0, QCoreApplication::translate("setnetDialog", "127.0.0.1", nullptr));

        label->setText(QCoreApplication::translate("setnetDialog", "IP:", nullptr));
        label_4->setText(QCoreApplication::translate("setnetDialog", "\346\226\207\344\273\266\347\253\257\345\217\243\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("setnetDialog", "Port:", nullptr));
        okButton->setText(QCoreApplication::translate("setnetDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("setnetDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setnetDialog: public Ui_setnetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETNETDIALOG_H
