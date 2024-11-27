#include <managerlogin.h>
#include <cstring>

// Class to manage a manager login.

// COnstructor to initialize name and passwords.
managerLogin::managerLogin(QString name, QString pass, QString pass2)
    : AccountLogin(name, pass)
{
    secondPassword = pass2;
}


// Method to authenticate the login attempt.
bool managerLogin::authenticate(){

    // Variables to check that the username and passwords match up.
    bool nameCheck = (username == "Manager");
    bool passCheck = (password == "SecretPassword");
    bool pass2Check = (secondPassword == "SuperSecretPassword");

    // Return true if username and passwords are correct, flase if not.
    if (nameCheck && passCheck && pass2Check){
        return true;
    }
    else{
        return false;
    }
}
