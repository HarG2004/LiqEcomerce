#ifndef ORDERTABLE_H
#define ORDERTABLE_H

#include <vector>
#include <order.h>
#include <table.h>

// Inherits Table
class OrderTable : public Table
{
public:
    // Overided method to create a table for orders in the database.
    virtual void createTable();

    // Method to add an order to the Orders table.
    bool addOrder(int customerID, double subtotal, double tax, double total, QString arrivalDate);

    // Method to get all orders for a specific customer.
    std::optional<std::vector<Order>> getCustomerOrders(int customerID);

};

#endif // ORDERTABLE_H
