#include "account.h"
#include <iostream>
#include <string>

// This class is meant to manage an account logging in.

// Constructor that gets the username and password.
AccountLogin::AccountLogin(QString name, QString pass) {
    username = name;
    password = pass;
    std::cout << "Account created." << std::endl;
}

// Destructor implementation
AccountLogin::~AccountLogin() {
    std::cout << "Account destroyed." << std::endl;
}

// Method to tell if login was succesful or not.
bool AccountLogin::login() {
    if (authenticate()) { // Checks if account info like username and password are correct.
        std::cout << "Login success." << std::endl;
        return true; // Return true is login is succesful.
    }
    else{
        std::cout << "Login fail." << std::endl;
        return false; // Return false if login is unsucessful.
    }
}





