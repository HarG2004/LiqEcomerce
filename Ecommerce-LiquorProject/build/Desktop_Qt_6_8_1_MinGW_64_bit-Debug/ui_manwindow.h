/********************************************************************************
** Form generated from reading UI file 'manwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANWINDOW_H
#define UI_MANWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *aName;
    QLabel *label_6;
    QLineEdit *aBrand;
    QLabel *label_7;
    QLineEdit *aType;
    QLabel *label_8;
    QLineEdit *aSize;
    QLabel *label_9;
    QLineEdit *aPrice;
    QPushButton *aButton;
    QLabel *aResult;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *eID;
    QLabel *label_2;
    QComboBox *eComponents;
    QLabel *label_3;
    QLineEdit *eNew;
    QPushButton *eEnter;
    QLabel *eResult;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *rID;
    QPushButton *rButton;
    QLabel *rResult;
    QMenuBar *menubar;
    QMenu *menuEcomLIq;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CustomerWindow)
    {
        if (CustomerWindow->objectName().isEmpty())
            CustomerWindow->setObjectName("CustomerWindow");
        CustomerWindow->resize(413, 292);
        CustomerWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: black;\n"
"    color: white;\n"
"}\n"
"/* Customize QPushButton specifically */\n"
"QPushButton {\n"
"    background-color: gray; /* A slightly lighter background for buttons */\n"
"    color: white;\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* Customize QTabWidget */\n"
"QTabWidget::pane {\n"
"    background-color: black;\n"
"    border: 1px solid white;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: gray;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid white;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: white;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 2px;\n"
"}\n"
"font: 900 italic 9pt \"Segoe UI\";"));
        centralwidget = new QWidget(CustomerWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 391, 251));
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(90, 0, 191, 211));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        aName = new QLineEdit(verticalLayoutWidget_3);
        aName->setObjectName("aName");

        verticalLayout_3->addWidget(aName);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);

        aBrand = new QLineEdit(verticalLayoutWidget_3);
        aBrand->setObjectName("aBrand");

        verticalLayout_3->addWidget(aBrand);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName("label_7");

        verticalLayout_3->addWidget(label_7);

        aType = new QLineEdit(verticalLayoutWidget_3);
        aType->setObjectName("aType");

        verticalLayout_3->addWidget(aType);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");

        verticalLayout_3->addWidget(label_8);

        aSize = new QLineEdit(verticalLayoutWidget_3);
        aSize->setObjectName("aSize");

        verticalLayout_3->addWidget(aSize);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName("label_9");

        verticalLayout_3->addWidget(label_9);

        aPrice = new QLineEdit(verticalLayoutWidget_3);
        aPrice->setObjectName("aPrice");

        verticalLayout_3->addWidget(aPrice);

        aButton = new QPushButton(tab);
        aButton->setObjectName("aButton");
        aButton->setGeometry(QRect(300, 90, 80, 18));
        aResult = new QLabel(tab);
        aResult->setObjectName("aResult");
        aResult->setGeometry(QRect(310, 120, 71, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(109, 10, 161, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        eID = new QLineEdit(verticalLayoutWidget);
        eID->setObjectName("eID");

        verticalLayout->addWidget(eID);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        eComponents = new QComboBox(verticalLayoutWidget);
        eComponents->addItem(QString());
        eComponents->addItem(QString());
        eComponents->addItem(QString());
        eComponents->addItem(QString());
        eComponents->addItem(QString());
        eComponents->setObjectName("eComponents");

        verticalLayout->addWidget(eComponents);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        eNew = new QLineEdit(verticalLayoutWidget);
        eNew->setObjectName("eNew");

        verticalLayout->addWidget(eNew);

        eEnter = new QPushButton(verticalLayoutWidget);
        eEnter->setObjectName("eEnter");
        eEnter->setMinimumSize(QSize(50, 0));

        verticalLayout->addWidget(eEnter, 0, Qt::AlignmentFlag::AlignHCenter);

        eResult = new QLabel(verticalLayoutWidget);
        eResult->setObjectName("eResult");

        verticalLayout->addWidget(eResult);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayoutWidget_2 = new QWidget(tab_3);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(99, 10, 181, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        rID = new QLineEdit(verticalLayoutWidget_2);
        rID->setObjectName("rID");

        verticalLayout_2->addWidget(rID);

        rButton = new QPushButton(verticalLayoutWidget_2);
        rButton->setObjectName("rButton");
        rButton->setMinimumSize(QSize(60, 0));

        verticalLayout_2->addWidget(rButton, 0, Qt::AlignmentFlag::AlignHCenter);

        rResult = new QLabel(verticalLayoutWidget_2);
        rResult->setObjectName("rResult");

        verticalLayout_2->addWidget(rResult);

        tabWidget->addTab(tab_3, QString());
        CustomerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CustomerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 413, 17));
        menuEcomLIq = new QMenu(menubar);
        menuEcomLIq->setObjectName("menuEcomLIq");
        CustomerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CustomerWindow);
        statusbar->setObjectName("statusbar");
        CustomerWindow->setStatusBar(statusbar);

        menubar->addAction(menuEcomLIq->menuAction());

        retranslateUi(CustomerWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CustomerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CustomerWindow)
    {
        CustomerWindow->setWindowTitle(QCoreApplication::translate("CustomerWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("CustomerWindow", "Name:", nullptr));
        label_6->setText(QCoreApplication::translate("CustomerWindow", "Brand:", nullptr));
        label_7->setText(QCoreApplication::translate("CustomerWindow", "Type:", nullptr));
        label_8->setText(QCoreApplication::translate("CustomerWindow", "Size:", nullptr));
        label_9->setText(QCoreApplication::translate("CustomerWindow", "Price:", nullptr));
        aButton->setText(QCoreApplication::translate("CustomerWindow", "Add", nullptr));
        aResult->setText(QCoreApplication::translate("CustomerWindow", "Result...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CustomerWindow", "AddP", nullptr));
        label->setText(QCoreApplication::translate("CustomerWindow", "Enter Product ID:", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerWindow", "Product Component To Change:", nullptr));
        eComponents->setItemText(0, QCoreApplication::translate("CustomerWindow", "Size", nullptr));
        eComponents->setItemText(1, QCoreApplication::translate("CustomerWindow", "Price", nullptr));
        eComponents->setItemText(2, QCoreApplication::translate("CustomerWindow", "Brand", nullptr));
        eComponents->setItemText(3, QCoreApplication::translate("CustomerWindow", "Type", nullptr));
        eComponents->setItemText(4, QCoreApplication::translate("CustomerWindow", "Name", nullptr));

        label_3->setText(QCoreApplication::translate("CustomerWindow", "New Component Value:", nullptr));
        eEnter->setText(QCoreApplication::translate("CustomerWindow", "Enter", nullptr));
        eResult->setText(QCoreApplication::translate("CustomerWindow", "Result...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CustomerWindow", "EditP", nullptr));
        label_4->setText(QCoreApplication::translate("CustomerWindow", "Enter ID For Product To Be Removed:", nullptr));
        rButton->setText(QCoreApplication::translate("CustomerWindow", "Enter", nullptr));
        rResult->setText(QCoreApplication::translate("CustomerWindow", "Result...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CustomerWindow", "RemoveP", nullptr));
        menuEcomLIq->setTitle(QCoreApplication::translate("CustomerWindow", "EcomLIq", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerWindow: public Ui_CustomerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANWINDOW_H
