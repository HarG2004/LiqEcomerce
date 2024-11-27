#include "producttable.h"

// CLass to create a table for and manage products in the database.

// Method to create product table.
void ProductTable::createTable() {

    // Create query and table template.
    QSqlQuery query;
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS Products (
            ProductID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            Brand TEXT NOT NULL,
            Type TEXT NOT NULL,
            Size TEXT NOT NULL,
            Price REAL NOT NULL
        )
    )";

    // Execute table, send debug messege if failure occurs.
    if (!query.exec(createTableSQL)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    } else {
        qDebug() << "Table created successfully!";
    }
}


// Method to add a product to the databse.
bool ProductTable::addProduct(QString name, QString brand, QString type, QString size, double price) {

    // Crate query and check query.
    QSqlQuery query;
    QSqlQuery checkQuery;

    // Check query string to find if given product already exists.
    checkQuery.prepare("SELECT COUNT(*) FROM Products WHERE Name = :name AND Brand = :brand AND Type = :type");
    checkQuery.bindValue(":name", name);
    checkQuery.bindValue(":brand", brand);
    checkQuery.bindValue(":type", type);

    // Check if product already exists, if so return false.
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "Product already exists.";
        return false;
    }

    // Validate size.
    if (size != "small" && size != "medium" && size != "large") {
        qDebug() << "Size of inputted product is not possible.";
        return false;
    }

    // Validate type.
    if (type != "beer" && type != "wine" && type != "vodka") {
        qDebug() << "Type of inputted product is not possible.";
        return false;
    }

    // Validate price.
    if (price <= 0.00) {
        qDebug() << "Price of inputted product is not possible.";
        return false;
    }

    // Create string to add the product if it passes validation.
    query.prepare("INSERT INTO Products (Name, Brand, Type, Size, Price) "
                  "VALUES (:name, :brand, :type, :size, :price)");

    query.bindValue(":name", name);
    query.bindValue(":brand", brand);
    query.bindValue(":type", type);
    query.bindValue(":size", size);
    query.bindValue(":price", price);

    // Add product to the database, if failure occurs return false, if not return true.
    if (!query.exec()) {
        return false;
    }
    return true;
}
