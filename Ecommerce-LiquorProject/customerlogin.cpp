#include <customerlogin.h>
#include <optional>
#include<customertable.h>

// This class is for managing a customer login.

// COnstructor calls parent constructor to initialize username and password.
customerLogin::customerLogin(QString name, QString pass)
    : AccountLogin(name, pass){}


// Method to authenticate a customer
bool customerLogin::authenticate() {

    // Create customerTable object
    CustomerTable customerTable;

    // Create query to search for the customer logging in with given username and passowrd.
    QString query = QString("SELECT * FROM Customers WHERE Username = '%1' AND Password = '%2'")
    .arg(username, password);

    // Execute the query.
    std::optional<Customer> customer = customerTable.getCustomer(query);


    if (customer.has_value()) {
        // If a matching customer is found return true.
        return true;
    } else {
        // If no matching customer is found return false.
        return false;
    }
}

