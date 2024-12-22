#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
class Product
{

private:

    // Private variables of a Product
    QString productName;
    QString brand;
    QString type;  // Type of alcohol. Wine, beer, or vodka.
    QString size;  // Size of packaged product. Small, medium, or large.
    double price;  // Price per unit.
    int productId;
public:

    Product();
    // COnstructor to initialize all Product attributes.
    Product(QString nameP, QString brandP, QString typeP, QString sizeP, double priceP, int idP);

    // Getters for all Product attributes.
    QString getProductName();
    QString getBrand();
    QString getType();
    QString getSize();
    double getPrice();
    int getProductId();
};

#endif // PRODUCT_H
