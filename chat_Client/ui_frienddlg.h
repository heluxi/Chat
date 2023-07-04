/********************************************************************************
** Form generated from reading UI file 'frienddlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDDLG_H
#define UI_FRIENDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendDlg
{
public:
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QWidget *widget_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *FriendDlg)
    {
        if (FriendDlg->objectName().isEmpty())
            FriendDlg->setObjectName("FriendDlg");
        FriendDlg->resize(364, 903);
        FriendDlg->setStyleSheet(QString::fromUtf8("border-radius:1px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0,stop:0 rgb(111, 134, 214) stop:0.4 rgb(255, 241, 235), stop:1 rgb(172, 224, 249));\n"
"\n"
"\n"
""));
        lineEdit = new QLineEdit(FriendDlg);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 250, 341, 31));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 94);\n"
"border-radius:15px;\n"
""));
        tabWidget = new QTabWidget(FriendDlg);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 290, 341, 551));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 144);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        treeWidget = new QTreeWidget(tab);
        treeWidget->headerItem()->setText(0, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 157);"));

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        widget_2 = new QWidget(FriendDlg);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(290, -10, 71, 41));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(21, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/\345\207\217\345\217\267.png);"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(21, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/\345\210\240\351\231\2442.png);"));

        horizontalLayout->addWidget(pushButton_2);

        widget_3 = new QWidget(FriendDlg);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(20, 250, 21, 31));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/\346\220\234\347\264\242.png);"));
        widget_5 = new QWidget(FriendDlg);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 70, 366, 137));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget = new QWidget(widget_5);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(81, 81));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/res/pic/CustomerService.png);\n"
"border-radius:38px;\n"
"background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_2->addWidget(widget);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(261, 101));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget_4);
        label->setObjectName("label");
        label->setMinimumSize(QSize(131, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\345\244\247\351\273\221_GBK")});
        font1.setPointSize(20);
        font1.setBold(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(101, 18));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);


        horizontalLayout_2->addWidget(widget_4);

        pushButton_3 = new QPushButton(FriendDlg);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 850, 41, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/pic/\346\262\237\351\200\232\351\241\265_\344\270\211\346\235\241\346\235\240_\350\267\263\350\275\254\351\200\211\346\213\251\345\255\251\345\255\220.png);"));

        retranslateUi(FriendDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FriendDlg);
    } // setupUi

    void retranslateUi(QWidget *FriendDlg)
    {
        FriendDlg->setWindowTitle(QCoreApplication::translate("FriendDlg", "Form", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("FriendDlg", "         \346\220\234\347\264\242", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("FriendDlg", "\351\273\230\350\256\244\345\210\206\347\273\204", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("FriendDlg", "username", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("FriendDlg", "\351\273\221\345\220\215\345\215\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("FriendDlg", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("FriendDlg", "\346\210\221\347\232\204\345\245\275\345\217\213", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FriendDlg", "\345\245\275\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FriendDlg", "\347\276\244\347\273\204", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QCoreApplication::translate("FriendDlg", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("FriendDlg", "signature", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendDlg: public Ui_FriendDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDDLG_H
