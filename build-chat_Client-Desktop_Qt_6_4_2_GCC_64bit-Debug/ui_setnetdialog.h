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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_setnetDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QPushButton *cancelButton;
    QComboBox *ipcomboBox;
    QLabel *label;
    QPushButton *okButton;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *filePortEdit;

    void setupUi(QDialog *setnetDialog)
    {
        if (setnetDialog->objectName().isEmpty())
            setnetDialog->setObjectName("setnetDialog");
        setnetDialog->resize(400, 300);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("network-server");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        setnetDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(setnetDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        label_2 = new QLabel(setnetDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        portLineEdit = new QLineEdit(setnetDialog);
        portLineEdit->setObjectName("portLineEdit");

        gridLayout->addWidget(portLineEdit, 2, 1, 1, 1);

        cancelButton = new QPushButton(setnetDialog);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 4, 2, 1, 1);

        ipcomboBox = new QComboBox(setnetDialog);
        ipcomboBox->addItem(QString());
        ipcomboBox->setObjectName("ipcomboBox");
        ipcomboBox->setEditable(true);

        gridLayout->addWidget(ipcomboBox, 1, 1, 1, 1);

        label = new QLabel(setnetDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        okButton = new QPushButton(setnetDialog);
        okButton->setObjectName("okButton");

        gridLayout->addWidget(okButton, 4, 0, 1, 1);

        label_3 = new QLabel(setnetDialog);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 50));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(setnetDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        filePortEdit = new QLineEdit(setnetDialog);
        filePortEdit->setObjectName("filePortEdit");

        gridLayout->addWidget(filePortEdit, 3, 1, 1, 1);


        retranslateUi(setnetDialog);

        QMetaObject::connectSlotsByName(setnetDialog);
    } // setupUi

    void retranslateUi(QDialog *setnetDialog)
    {
        setnetDialog->setWindowTitle(QCoreApplication::translate("setnetDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("setnetDialog", "Port:", nullptr));
        cancelButton->setText(QCoreApplication::translate("setnetDialog", "\345\217\226\346\266\210", nullptr));
        ipcomboBox->setItemText(0, QCoreApplication::translate("setnetDialog", "127.0.0.1", nullptr));

        label->setText(QCoreApplication::translate("setnetDialog", "IP:", nullptr));
        okButton->setText(QCoreApplication::translate("setnetDialog", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QCoreApplication::translate("setnetDialog", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("setnetDialog", "\346\226\207\344\273\266\347\253\257\345\217\243\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setnetDialog: public Ui_setnetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETNETDIALOG_H
