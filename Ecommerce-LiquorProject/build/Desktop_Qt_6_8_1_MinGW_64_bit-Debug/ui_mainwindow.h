/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Login;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameLine;
    QLabel *label_2;
    QLineEdit *passLine;
    QPushButton *loginButto;
    QLabel *resultLabel;
    QWidget *Register;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *regUser;
    QLabel *label_4;
    QLineEdit *regPass;
    QLabel *label_5;
    QLineEdit *regLnum;
    QLabel *label_6;
    QLineEdit *regLdate;
    QLabel *label_7;
    QLineEdit *regAdrs;
    QLabel *label_8;
    QLineEdit *regCard;
    QLabel *label_10;
    QLineEdit *regName;
    QLabel *label_9;
    QPushButton *regButton;
    QLabel *regResult;
    QWidget *MLogin;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLineEdit *mUser;
    QLabel *label_12;
    QLineEdit *mP1;
    QLabel *label_13;
    QLineEdit *mP2;
    QPushButton *mLoginButton;
    QLabel *mResult;
    QMenuBar *menubar;
    QMenu *menuEcomLiq;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(514, 438);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        Login = new QWidget();
        Login->setObjectName("Login");
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 30, 191, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nameLine = new QLineEdit(verticalLayoutWidget);
        nameLine->setObjectName("nameLine");
        nameLine->setEnabled(true);
        nameLine->setAutoFillBackground(false);

        verticalLayout->addWidget(nameLine);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passLine = new QLineEdit(verticalLayoutWidget);
        passLine->setObjectName("passLine");
        passLine->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passLine);

        loginButto = new QPushButton(verticalLayoutWidget);
        loginButto->setObjectName("loginButto");
        loginButto->setMinimumSize(QSize(50, 0));
        loginButto->setMaximumSize(QSize(60, 20));

        verticalLayout->addWidget(loginButto, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        resultLabel = new QLabel(verticalLayoutWidget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        tabWidget->addTab(Login, QString());
        Register = new QWidget();
        Register->setObjectName("Register");
        verticalLayoutWidget_2 = new QWidget(Register);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(110, 10, 281, 341));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        regUser = new QLineEdit(verticalLayoutWidget_2);
        regUser->setObjectName("regUser");

        verticalLayout_2->addWidget(regUser);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        regPass = new QLineEdit(verticalLayoutWidget_2);
        regPass->setObjectName("regPass");

        verticalLayout_2->addWidget(regPass);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        regLnum = new QLineEdit(verticalLayoutWidget_2);
        regLnum->setObjectName("regLnum");

        verticalLayout_2->addWidget(regLnum);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        regLdate = new QLineEdit(verticalLayoutWidget_2);
        regLdate->setObjectName("regLdate");

        verticalLayout_2->addWidget(regLdate);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        regAdrs = new QLineEdit(verticalLayoutWidget_2);
        regAdrs->setObjectName("regAdrs");

        verticalLayout_2->addWidget(regAdrs);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        regCard = new QLineEdit(verticalLayoutWidget_2);
        regCard->setObjectName("regCard");

        verticalLayout_2->addWidget(regCard);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        regName = new QLineEdit(verticalLayoutWidget_2);
        regName->setObjectName("regName");

        verticalLayout_2->addWidget(regName);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        regButton = new QPushButton(Register);
        regButton->setObjectName("regButton");
        regButton->setGeometry(QRect(410, 130, 80, 18));
        regResult = new QLabel(Register);
        regResult->setObjectName("regResult");
        regResult->setGeometry(QRect(406, 160, 81, 21));
        tabWidget->addTab(Register, QString());
        MLogin = new QWidget();
        MLogin->setObjectName("MLogin");
        verticalLayoutWidget_3 = new QWidget(MLogin);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(139, 0, 221, 291));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");

        verticalLayout_3->addWidget(label_11);

        mUser = new QLineEdit(verticalLayoutWidget_3);
        mUser->setObjectName("mUser");

        verticalLayout_3->addWidget(mUser);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName("label_12");

        verticalLayout_3->addWidget(label_12);

        mP1 = new QLineEdit(verticalLayoutWidget_3);
        mP1->setObjectName("mP1");
        mP1->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(mP1);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName("label_13");

        verticalLayout_3->addWidget(label_13);

        mP2 = new QLineEdit(verticalLayoutWidget_3);
        mP2->setObjectName("mP2");
        mP2->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(mP2);

        mLoginButton = new QPushButton(verticalLayoutWidget_3);
        mLoginButton->setObjectName("mLoginButton");
        mLoginButton->setMinimumSize(QSize(50, 0));

        verticalLayout_3->addWidget(mLoginButton, 0, Qt::AlignmentFlag::AlignHCenter);

        mResult = new QLabel(verticalLayoutWidget_3);
        mResult->setObjectName("mResult");

        verticalLayout_3->addWidget(mResult);

        tabWidget->addTab(MLogin, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 514, 17));
        menuEcomLiq = new QMenu(menubar);
        menuEcomLiq->setObjectName("menuEcomLiq");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEcomLiq->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        nameLine->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        passLine->setInputMask(QString());
        passLine->setText(QString());
        loginButto->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Awaiting Login ...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Login), QCoreApplication::translate("MainWindow", "CLogin", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Liquor License Number:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Liquor License Expiry Year:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Business Adderess", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Credit Card Number", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_9->setText(QString());
        regButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        regResult->setText(QCoreApplication::translate("MainWindow", "Result...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Register), QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Second Password:", nullptr));
        mLoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        mResult->setText(QCoreApplication::translate("MainWindow", "Result...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MLogin), QCoreApplication::translate("MainWindow", "MLogin", nullptr));
        menuEcomLiq->setTitle(QCoreApplication::translate("MainWindow", "EcomLiq", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
