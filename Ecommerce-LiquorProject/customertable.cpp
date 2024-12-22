#include "customertable.h"

// This class is to create and manage a customer Table.

// Method to create a table for customers.
void CustomerTable::createTable(){

    // Get query and create table template.
    QSqlQuery query;
    QString createTableSQL = R"(
            CREATE TABLE IF NOT EXISTS Customers (
                CustomerID INTEGER PRIMARY KEY AUTOINCREMENT,
                Name TEXT NOT NULL,
                LiquorLicenseNum INTEGER NOT NULL,
                LLExpDate INTEGER NOT NULL,
                BusinessAdrs TEXT NOT NULL,
                CreditCardInfo TEXT NOT NULL,
                Username TEXT NOT NULL,
                Password TEXT NOT NULL
            )
    )";

    // Try to create table, send qDebug messege with result.
    if (!query.exec(createTableSQL)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    } else {
        qDebug() << "Table created successfully!";
    }
}

// Method to add a customer to the table.
bool CustomerTable::addCustomer(int lLnum, int expiryDate, QString busAdrs, QString name, QString cardInfo, QString username, QString password) {

    // Get query.
    QSqlQuery query;

    // Prepare the query and then bind the parameters to table values.
    query.prepare("INSERT INTO Customers (Name, LiquorLicenseNum, LLExpDate, BusinessAdrs, CreditCardInfo, Username, Password) "
                  "VALUES (:name, :liquorLicenseNum, :llExpDate, :businessAdrs, :creditCardInfo, :username, :password)");

    query.bindValue(":name", name);
    query.bindValue(":liquorLicenseNum", lLnum);
    query.bindValue(":llExpDate", expiryDate);
    query.bindValue(":businessAdrs", busAdrs);
    query.bindValue(":creditCardInfo", cardInfo);
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    // Execute query, return true if succesful and false if not.
    if (!query.exec()) {
        return false;
    }
    return true;
}

// Method to get a customer.
std::optional<Customer> CustomerTable::getCustomer(QString qStr) {

    // Get query.
    QSqlQuery query;

    // Execute given query string.
    if (!query.exec(qStr)) {
        return std::nullopt; // Return empty if execution fails.
    }

    // Check if there is a result.
    if (query.next()) {

        // Get customer data from result.
        QString name = query.value("Name").toString();
        int liquorLicenseNum = query.value("LiquorLicenseNum").toInt();
        int llExpDate = query.value("LLExpDate").toInt();
        QString businessAdrs = query.value("BusinessAdrs").toString();
        QString creditCardInfo = query.value("CreditCardInfo").toString();
        int customerID = query.value("CustomerID").toInt();
        QString username = query.value("Username").toString();
        QString password = query.value("Password").toString();


        // Construct and return a Customer object.
        return Customer(name, liquorLicenseNum, llExpDate, businessAdrs, creditCardInfo, customerID, username, password);
    }
    // Return empty if no results are found.
    return std::nullopt;
}


