#include "customer.h"

// Method to create a customer object and get its attributes.

// COnstructor will assign the parameters to its private variables.
Customer::Customer(QString nameP, int lLnum, int expiry, QString adrs, int card, int id, QString user, QString pass) {
    name = nameP;
    liquorLicenseNum = lLnum;
    llExpDate = expiry;
    businessAdrs = adrs;
    creditCardInfo = card;
    customerID = id;
    username = user;
    password = pass;
}

// Getter for name
QString Customer::getName() {
    return name;
}

// Getter for liquorLicenseNum
int Customer::getLiquorLicenseNum() {
    return liquorLicenseNum;
}

// Getter for llExpDate
int Customer::getLLExpDate() {
    return llExpDate;
}

// Getter for businessAdrs
QString Customer::getBusinessAdrs() {
    return businessAdrs;
}

// Getter for creditCardInfo
int Customer::getCreditCardInfo() {
    return creditCardInfo;
}

// Getter for customerID
int Customer::getCustomerID() {
    return customerID;
}

// Getter for username
QString Customer::getUsername() {
    return username;
}

// Getter for password
QString Customer::getPassword() {
    return password;
}
