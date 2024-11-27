#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include "account.h"

// Inherits AccountLogin
class customerLogin : public AccountLogin
{
public:

    // Constructor to initialize.
    customerLogin(QString name, QString pass);

protected:

    // Overided method to authenticate a customer.
    bool authenticate() override;
};

#endif // CUSTOMERLOGIN_H
