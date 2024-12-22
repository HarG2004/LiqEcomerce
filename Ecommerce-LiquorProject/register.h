#ifndef REGISTER_H
#define REGISTER_H

#include "customer.h"
#include "customertable.h"

class Register
{
private:

    // Create a customerTable object to use if a new customer needs to be added.
    CustomerTable customerTable;
public:

    // Methods used to validate the attributes of the registering customer.
    bool isUsernameValid(QString username);
    bool isPasswordValid(QString password);
    bool isCreditCardValid(QString creditCardNumber);
    bool isLiquorLicenseValid(int liquorLicenseNum);
    bool isExpiryDateValid(int expiryDate);


    // Method returns true if customer can and is now registered, false if not.
    bool registerCustomer(Customer customer);
};

#endif // REGISTER_H
