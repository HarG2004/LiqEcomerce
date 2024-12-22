#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer
{
private:

    QString name;                // Customer's name
    int liquorLicenseNum;    // Liquor license number
    int llExpDate;           // Liquor license expiry date
    QString businessAdrs;        // Business address
    QString creditCardInfo;      // Credit card information
    int customerID;          // Customer ID
    QString username;            // Username for login
    QString password;            // Password for login

public:

    // Constructor to initialize Customer object.
    Customer(QString nameP, int lLnum, int expiry, QString adrs, QString card, int id, QString user, QString pass);

    // Getters for all private variables of Customer.
    QString getName();
    int getLiquorLicenseNum();
    int getLLExpDate();
    QString getBusinessAdrs();
    QString getCreditCardInfo();
    int getCustomerID();
    QString getUsername();
    QString getPassword();
};

#endif // CUSTOMER_H
