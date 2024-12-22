#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

#include "Table.h"
#include "customer.h"

// Inherits Table
class CustomerTable : public Table
{
public:

    // Overides create table to create a table for customers
    void createTable() override;

    // Method to add a customer to the database.
    bool addCustomer(int lLnum, int expiryDate, QString busAdrs, QString name, QString cardInfo, QString username, QString password);



    // Method that gets a customer from the database.
    std::optional<Customer> getCustomer(QString qStr);

};

#endif // CUSTOMERTABLE_H
