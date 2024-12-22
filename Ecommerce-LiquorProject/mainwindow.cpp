#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "customerlogin.h"
#include "database.h"
#include "customertable.h"
#include "managerlogin.h"
#include "register.h"
#include "customer.h"
#include "manwindow.h"
#include "ui_manwindow.h"
#include "cuswindow.h"
#include "ui_cuswindow.h"

// This is the main window, here you login or register a new customer.

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}


// This method logs in a customer when the login button is clicked.
void MainWindow::on_loginButto_clicked()
{
    // Set up database and customer table.
    Database* db;
    CustomerTable customerTable;
    db = Database::getInstance();
    customerTable.createTable();

    // Get username and password.
    QString username = ui->nameLine->text();
    QString password = ui->passLine->text();

    // Login
    customerLogin login(username, password);

    // Get the customer who logged in.
    QString query = QString("SELECT * FROM Customers WHERE Username = '%1' AND Password = '%2'")
                        .arg(username, password);

    auto cus = customerTable.getCustomer(query);
    Customer cus2 = cus.value();

    // If login succed go to the customer window, else state the failure.
    if (login.login()){
        ui->resultLabel->setText("Login successful!");
        managerWindow *manWindow = new managerWindow(cus2.getCustomerID(), nullptr); // Pass customerId
        manWindow->show();

        // Close the current window
        qDebug() << "Manager Window Shown: " << cus2.getCustomerID();

        this->close();
    }
    else{
        ui->resultLabel->setText("Login Fail!");
    }
}

// Method to switch tabs.
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->tabWidget->setCurrentIndex(index);

}


// Method to register when reg button is clicked.
void MainWindow::on_regButton_clicked()
{
    // Get database and customer table, also register.
    Database* db;
    CustomerTable customerTable;
    db = Database::getInstance();
    customerTable.createTable();
    Register reg;

    // Get all ui inputs, and make a customer
    QString user = ui->regUser->text();
    QString pass = ui->regPass->text();
    int llNum = ui->regLnum->text().toInt();
    int llDate = ui->regLdate->text().toInt();
    QString bus = ui->regAdrs->text();
    QString card = ui->regCard->text();
    QString name = ui->regName->text();

    Customer cus(name, llNum, llDate, bus, card, 0, user, pass);

    // Register customer, if success state it and if failure state it.
    if (reg.registerCustomer(cus)){
        ui->regResult->setText("Success!");
    }
    else{
        ui->regResult->setText("Failure!");
    }
}


// Method to login for manager when button is clicked.
void MainWindow::on_mLoginButton_clicked()
{
    // Get username and passwords - Manager, SecretPassword, SuperSecretPassword.
    QString username = ui->mUser->text();
    QString password = ui->mP1->text();
    QString p2 = ui->mP2->text();

    // login
    managerLogin login(username, password, p2);

    // if login is succesful open the manager window else state the failure.
    if (login.login()){
        ui->mResult->setText("Login successful!");
        CustomerWindow *customerWindow = new CustomerWindow();
        customerWindow->show();

        // Close the current window
        this->close();
    }
    else{
        ui->mResult->setText("Login Fail!");
    }
}

