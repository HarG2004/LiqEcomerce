#ifndef ORDER_H
#define ORDER_H

#include <QString>

class Order
{

private:

    // Private variables to hold attributes of the order.
    int orderID;
    int customerID;
    double subtotal;
    double tax;     // Amount of tax paid.
    double total;   // Total amount paid.
    QString arrivalDate;  // Arrival date of delivery

public:

    // Constructor to initialize Order attributes.
    Order(int oID, int cID, double sub, double taxP, double totalP, QString arrival);

    // Getters for Order attibutes.
    int getOrderID();
    int getCustomerID();
    double getSubtotal();
    double getTax();
    double getTotal();
    QString getArrivalDate();
};

#endif // ORDER_H
