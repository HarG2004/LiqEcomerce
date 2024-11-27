#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <iostream>

class AccountLogin
{
protected:

    // Protected variables accessible by subclasses
    QString username; // Username and password to be used to sign in.
    QString password;

    // Virtual method to authenticate person signing in.
    virtual bool authenticate() = 0; // Method facilitates the template pattern.

public:

    // Constructor to initialize private variables.
    AccountLogin(QString name, QString pass);

    // Deconstructor.
    virtual ~AccountLogin();

    // Method to attempt login. Return true if succesful and false if not.
    bool login();
};

#endif // ACCOUNT_H
