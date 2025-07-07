/********************************************************************************
** Form generated from reading UI file 'cuswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSWINDOW_H
#define UI_CUSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *Tabs;
    QWidget *Cedit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *eComponent;
    QLabel *label_2;
    QLineEdit *eNew;
    QPushButton *eEnter;
    QLabel *eResult;
    QWidget *Cshop;
    QTableWidget *productTable;
    QSpinBox *quantity;
    QPushButton *update;
    QLabel *label_3;
    QLabel *statusLabel;
    QWidget *Corders;
    QTableWidget *oTable;
    QWidget *Ccheckout;
    QTableWidget *cartTable;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *sub;
    QLabel *tax;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *total;
    QPushButton *refreshButton;
    QPushButton *oButton;
    QLabel *checkResult;
    QMenuBar *menubar;
    QMenu *menuEcomLiq;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *managerWindow)
    {
        if (managerWindow->objectName().isEmpty())
            managerWindow->setObjectName("managerWindow");
        managerWindow->resize(483, 312);
        managerWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        centralwidget = new QWidget(managerWindow);
        centralwidget->setObjectName("centralwidget");
        Tabs = new QTabWidget(centralwidget);
        Tabs->setObjectName("Tabs");
        Tabs->setGeometry(QRect(9, 0, 461, 271));
        Cedit = new QWidget();
        Cedit->setObjectName("Cedit");
        verticalLayoutWidget = new QWidget(Cedit);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 10, 211, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        eComponent = new QComboBox(verticalLayoutWidget);
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->addItem(QString());
        eComponent->setObjectName("eComponent");

        verticalLayout->addWidget(eComponent);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        eNew = new QLineEdit(verticalLayoutWidget);
        eNew->setObjectName("eNew");

        verticalLayout->addWidget(eNew);

        eEnter = new QPushButton(verticalLayoutWidget);
        eEnter->setObjectName("eEnter");
        eEnter->setMinimumSize(QSize(60, 0));

        verticalLayout->addWidget(eEnter, 0, Qt::AlignmentFlag::AlignHCenter);

        eResult = new QLabel(verticalLayoutWidget);
        eResult->setObjectName("eResult");

        verticalLayout->addWidget(eResult);

        Tabs->addTab(Cedit, QString());
        Cshop = new QWidget();
        Cshop->setObjectName("Cshop");
        productTable = new QTableWidget(Cshop);
        if (productTable->columnCount() < 10)
            productTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        productTable->setObjectName("productTable");
        productTable->setGeometry(QRect(0, 0, 381, 192));
        productTable->setColumnCount(10);
        quantity = new QSpinBox(Cshop);
        quantity->setObjectName("quantity");
        quantity->setGeometry(QRect(30, 200, 42, 22));
        quantity->setMinimum(-100);
        quantity->setMaximum(100);
        update = new QPushButton(Cshop);
        update->setObjectName("update");
        update->setGeometry(QRect(150, 210, 141, 18));
        label_3 = new QLabel(Cshop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 230, 37, 12));
        statusLabel = new QLabel(Cshop);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(310, 220, 151, 16));
        Tabs->addTab(Cshop, QString());
        Corders = new QWidget();
        Corders->setObjectName("Corders");
        oTable = new QTableWidget(Corders);
        if (oTable->columnCount() < 5)
            oTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        oTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        oTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        oTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        oTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        oTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        oTable->setObjectName("oTable");
        oTable->setGeometry(QRect(10, 0, 361, 192));
        Tabs->addTab(Corders, QString());
        Ccheckout = new QWidget();
        Ccheckout->setObjectName("Ccheckout");
        cartTable = new QTableWidget(Ccheckout);
        if (cartTable->columnCount() < 3)
            cartTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        cartTable->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        cartTable->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        cartTable->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        cartTable->setObjectName("cartTable");
        cartTable->setGeometry(QRect(0, 0, 231, 192));
        cartTable->setColumnCount(3);
        verticalLayoutWidget_2 = new QWidget(Ccheckout);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(270, 0, 160, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        sub = new QLabel(verticalLayoutWidget_2);
        sub->setObjectName("sub");

        verticalLayout_2->addWidget(sub);

        tax = new QLabel(verticalLayoutWidget_2);
        tax->setObjectName("tax");

        verticalLayout_2->addWidget(tax);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        total = new QLabel(verticalLayoutWidget_2);
        total->setObjectName("total");

        verticalLayout_2->addWidget(total);

        refreshButton = new QPushButton(verticalLayoutWidget_2);
        refreshButton->setObjectName("refreshButton");

        verticalLayout_2->addWidget(refreshButton);

        oButton = new QPushButton(verticalLayoutWidget_2);
        oButton->setObjectName("oButton");

        verticalLayout_2->addWidget(oButton);

        checkResult = new QLabel(Ccheckout);
        checkResult->setObjectName("checkResult");
        checkResult->setGeometry(QRect(20, 210, 211, 16));
        Tabs->addTab(Ccheckout, QString());
        managerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(managerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 483, 17));
        menuEcomLiq = new QMenu(menubar);
        menuEcomLiq->setObjectName("menuEcomLiq");
        managerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(managerWindow);
        statusbar->setObjectName("statusbar");
        managerWindow->setStatusBar(statusbar);

        menubar->addAction(menuEcomLiq->menuAction());

        retranslateUi(managerWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(managerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *managerWindow)
    {
        managerWindow->setWindowTitle(QCoreApplication::translate("managerWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("managerWindow", "Component To Edit:", nullptr));
        eComponent->setItemText(0, QCoreApplication::translate("managerWindow", "Username", nullptr));
        eComponent->setItemText(1, QCoreApplication::translate("managerWindow", "Password", nullptr));
        eComponent->setItemText(2, QCoreApplication::translate("managerWindow", "Name", nullptr));
        eComponent->setItemText(3, QCoreApplication::translate("managerWindow", "LiquorLicenseNum", nullptr));
        eComponent->setItemText(4, QCoreApplication::translate("managerWindow", "LLExpDate", nullptr));
        eComponent->setItemText(5, QCoreApplication::translate("managerWindow", "BusinessAdrs", nullptr));
        eComponent->setItemText(6, QCoreApplication::translate("managerWindow", "CreditCardInfo", nullptr));

        label_2->setText(QCoreApplication::translate("managerWindow", "New Component Value:", nullptr));
        eEnter->setText(QCoreApplication::translate("managerWindow", "Enter", nullptr));
        eResult->setText(QCoreApplication::translate("managerWindow", "Result...", nullptr));
        Tabs->setTabText(Tabs->indexOf(Cedit), QCoreApplication::translate("managerWindow", "Cedit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = productTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("managerWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = productTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("managerWindow", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = productTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("managerWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = productTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("managerWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = productTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("managerWindow", "Price", nullptr));
        update->setText(QCoreApplication::translate("managerWindow", "Update Shopping Cart", nullptr));
        label_3->setText(QCoreApplication::translate("managerWindow", "Quantity", nullptr));
        statusLabel->setText(QCoreApplication::translate("managerWindow", "Status", nullptr));
        Tabs->setTabText(Tabs->indexOf(Cshop), QCoreApplication::translate("managerWindow", "Cshop", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = oTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("managerWindow", "OrderID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = oTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("managerWindow", "Subtotal", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = oTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("managerWindow", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = oTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("managerWindow", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = oTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("managerWindow", "Arrival", nullptr));
        Tabs->setTabText(Tabs->indexOf(Corders), QCoreApplication::translate("managerWindow", "Corders", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = cartTable->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("managerWindow", "Product", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = cartTable->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("managerWindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = cartTable->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("managerWindow", "Price", nullptr));
        label_4->setText(QCoreApplication::translate("managerWindow", "Subtotal:", nullptr));
        sub->setText(QCoreApplication::translate("managerWindow", "In dollars.", nullptr));
        tax->setText(QCoreApplication::translate("managerWindow", "Tax:", nullptr));
        label_7->setText(QCoreApplication::translate("managerWindow", "In dollars.", nullptr));
        label_8->setText(QCoreApplication::translate("managerWindow", "Total:", nullptr));
        total->setText(QCoreApplication::translate("managerWindow", "In dollars.", nullptr));
        refreshButton->setText(QCoreApplication::translate("managerWindow", "Refresh", nullptr));
        oButton->setText(QCoreApplication::translate("managerWindow", "Order", nullptr));
        checkResult->setText(QCoreApplication::translate("managerWindow", "Result...", nullptr));
        Tabs->setTabText(Tabs->indexOf(Ccheckout), QCoreApplication::translate("managerWindow", "Ccheckout", nullptr));
        menuEcomLiq->setTitle(QCoreApplication::translate("managerWindow", "EcomLiq", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerWindow: public Ui_managerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSWINDOW_H
