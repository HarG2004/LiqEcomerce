#include "ordertable.h"

// Class to create and manage an order table.
void OrderTable::createTable() {

    // Create query.
    QSqlQuery query;

    // Create table template.
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS Orders (
            OrderID INTEGER PRIMARY KEY AUTOINCREMENT,
            CustomerID INTEGER NOT NULL,
            Subtotal REAL NOT NULL,
            Tax REAL NOT NULL,
            Total REAL NOT NULL,
            ArrivalDate TEXT NOT NULL,
            FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
        )
    )";

    // Create table and check for errors.
    if (!query.exec(createTableSQL)) {
        qDebug() << "Failed to create Orders table:" << query.lastError().text();
    } else {
        qDebug() << "Orders table created successfully!";
    }
}


// Method to add an order to the database.
bool OrderTable::addOrder(int customerID, double subtotal, double tax, double total, QString arrivalDate) {

    // Create query.
    QSqlQuery query;

    // Prepare the query and then bind the parameters to the table values.
    query.prepare("INSERT INTO Orders (CustomerID, Subtotal, Tax, Total, ArrivalDate) "
                  "VALUES (:customerID, :subtotal, :tax, :total, :arrivalDate)");

    query.bindValue(":customerID", customerID);
    query.bindValue(":subtotal", subtotal);
    query.bindValue(":tax", tax);
    query.bindValue(":total", total);
    query.bindValue(":arrivalDate", arrivalDate);

    // Execute the query, return true if succesful and false if not.
    if (!query.exec()) {
        return false;
    }
    return true;
}


// Method to get all orders related to a customer from the database.
std::optional<std::vector<Order>> OrderTable::getCustomerOrders(int customerID) {

    // Create query and create a vector to hold all orders belonging to the customer.
    QSqlQuery query;
    std::vector<Order> orders;

    // Prepare the query to retrieve orders for the given customerID.
    query.prepare("SELECT * FROM Orders WHERE CustomerID = :customerID");
    query.bindValue(":customerID", customerID);

    // Execute the query.
    if (!query.exec()) {
        return std::nullopt; // Return empty if query fails.
    }

    // If query is succesful go through all orders belonging to the customer.
    while (query.next()) {

        // Get all order attributes from the database.
        int orderID = query.value("OrderID").toInt();
        double subtotal = query.value("Subtotal").toDouble();
        double tax = query.value("Tax").toDouble();
        double total = query.value("Total").toDouble();
        QString arrivalDate = query.value("ArrivalDate").toString();

        // Create an Order object and add it to the vector.
        orders.emplace_back(orderID, customerID, subtotal, tax, total, arrivalDate);
    }

    // If no orders are found return empty.
    if (orders.empty()) {
        return std::nullopt;
    }
    return orders; // Return vector if it is not empty.
}
