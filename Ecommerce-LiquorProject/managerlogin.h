#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include "account.h"

// Inherits AccountLogin
class managerLogin : public AccountLogin
{
private:

    // Private variable to hold second passowrd.
    QString secondPassword;

public:

    // Constructor to get username and passwords.
    managerLogin(QString name, QString pass, QString pass2);

protected:

    // Overided method to authenticate a manager.
    bool authenticate() override;
};

#endif // MANAGERLOGIN_H
