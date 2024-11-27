#include "order.h"

// Class that creates Orders and gets their attributes.

// Constructor to initialize the order attribues with the parameters.
Order::Order(int oID, int cID, double sub, double taxP, double totalP, QString arrival) {
    orderID = oID;
    customerID = cID;
    subtotal = sub;
    tax = taxP;
    total = totalP;
    arrivalDate = arrival;
}

// Getters for all the attributes of order.
int Order::getOrderID() {
    return orderID;
}

int Order::getCustomerID() {
    return customerID;
}

double Order::getSubtotal() {
    return subtotal;
}

double Order::getTax() {
    return tax;
}

double Order::getTotal() {
    return total;
}

QString Order::getArrivalDate() {
    return arrivalDate;
}
