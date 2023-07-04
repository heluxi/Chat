/********************************************************************************
** Form generated from reading UI file 'addsubgroup.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUBGROUP_H
#define UI_ADDSUBGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddSubGroup
{
public:
    QLabel *lb_name;
    QLineEdit *le_name;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;

    void setupUi(QDialog *AddSubGroup)
    {
        if (AddSubGroup->objectName().isEmpty())
            AddSubGroup->setObjectName("AddSubGroup");
        AddSubGroup->resize(400, 300);
        lb_name = new QLabel(AddSubGroup);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(50, 50, 71, 22));
        le_name = new QLineEdit(AddSubGroup);
        le_name->setObjectName("le_name");
        le_name->setGeometry(QRect(150, 50, 113, 30));
        btn_ok = new QPushButton(AddSubGroup);
        btn_ok->setObjectName("btn_ok");
        btn_ok->setGeometry(QRect(90, 180, 97, 30));
        btn_cancel = new QPushButton(AddSubGroup);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(240, 180, 97, 30));

        retranslateUi(AddSubGroup);

        QMetaObject::connectSlotsByName(AddSubGroup);
    } // setupUi

    void retranslateUi(QDialog *AddSubGroup)
    {
        AddSubGroup->setWindowTitle(QCoreApplication::translate("AddSubGroup", "Dialog", nullptr));
        lb_name->setText(QCoreApplication::translate("AddSubGroup", "TextLabel", nullptr));
        btn_ok->setText(QCoreApplication::translate("AddSubGroup", "ok", nullptr));
        btn_cancel->setText(QCoreApplication::translate("AddSubGroup", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSubGroup: public Ui_AddSubGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUBGROUP_H
