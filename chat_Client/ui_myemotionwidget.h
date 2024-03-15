/********************************************************************************
** Form generated from reading UI file 'myemotionwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYEMOTIONWIDGET_H
#define UI_MYEMOTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyEmotionWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton;

    void setupUi(QWidget *MyEmotionWidget)
    {
        if (MyEmotionWidget->objectName().isEmpty())
            MyEmotionWidget->setObjectName("MyEmotionWidget");
        MyEmotionWidget->resize(548, 400);
        MyEmotionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        tabWidget = new QTabWidget(MyEmotionWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 20, 531, 371));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 10, 521, 321));
        tableWidget->setRowCount(12);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(45);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setDefaultSectionSize(45);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        if (tableWidget_2->rowCount() < 5)
            tableWidget_2->setRowCount(5);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 0, 511, 321));
        tableWidget_2->setRowCount(5);
        tableWidget_2->setColumnCount(5);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(80);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(95);
        tableWidget_2->horizontalHeader()->setHighlightSections(true);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(80);
        tabWidget->addTab(tab_2, QString());
        pushButton = new QPushButton(MyEmotionWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 0, 31, 26));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/\345\210\240\351\231\2442.png);"));

        retranslateUi(MyEmotionWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MyEmotionWidget);
    } // setupUi

    void retranslateUi(QWidget *MyEmotionWidget)
    {
        MyEmotionWidget->setWindowTitle(QCoreApplication::translate("MyEmotionWidget", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MyEmotionWidget", "QQ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MyEmotionWidget", "likes", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyEmotionWidget: public Ui_MyEmotionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYEMOTIONWIDGET_H
