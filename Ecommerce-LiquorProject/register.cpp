#include "register.h"

// Class that registers a person as a customer.

// Validates username (6 or more characters).
bool Register::isUsernameValid(QString username) {
    return username.length() >= 6;
}

// Validates password (6 or more characters).
bool Register::isPasswordValid(QString password) {
    return password.length() >= 6;
}

// Validates credit card number (16 digits).
bool Register::isCreditCardValid(int creditCardNumber) {
    int digits = QString::number(creditCardNumber).length();
    return digits == 16;
}

// Validates liquor license (10-12 digits).
bool Register::isLiquorLicenseValid(int liquorLicenseNum) {
    int digits = QString::number(liquorLicenseNum).length();
    return digits >= 10 && digits <= 12;
}

// Validates expiry date (greater than 2024 and less than 2100).
bool Register::isExpiryDateValid(int expiryDate) {
    return expiryDate > 2024 && expiryDate < 2100;
}

// Method registers the customer if all validations pass.
bool Register::registerCustomer(Customer customer) {

     // Validate the customer.
    if (!isUsernameValid(customer.getUsername())) {
        qDebug() << "Invalid username. Must be 6 or more characters.";
        return false;
    }

    if (!isPasswordValid(customer.getPassword())) {
        qDebug() << "Invalid password. Must be 6 or more characters.";
        return false;
    }

    if (!isCreditCardValid(customer.getCreditCardInfo())) {
        qDebug() << "Invalid credit card number. Must be 16 digits.";
        return false;
    }

    if (!isLiquorLicenseValid(customer.getLiquorLicenseNum())) {
        qDebug() << "Invalid liquor license number. Must be 10-12 digits.";
        return false;
    }

    if (!isExpiryDateValid(customer.getLLExpDate())) {
        qDebug() << "Invalid expiry date. Must be greater than 2024 and less than 2100.";
        return false;
    }

    // If all validations pass, add customer to database.
    bool added = customerTable.addCustomer(
        customer.getLiquorLicenseNum(),
        customer.getLLExpDate(),
        customer.getBusinessAdrs(),
        customer.getName(),
        customer.getCreditCardInfo(),
        customer.getUsername(),
        customer.getPassword()
        );

    // Check if customer succesfully added.
    if (added) {
        qDebug() << "Customer registered successfully!";
        return true;
    } else {
        qDebug() << "Failed to register customer in database.";
        return false;
    }
}
