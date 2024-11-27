#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <vector>
#include <product.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class ProductList
{
private:

    // Vector to hold all products in the database.
    std::vector<Product> products;
public:

    // Constructor to initialize products variable.
    ProductList();

    // Method to get vector of products private variable.
    std::vector<Product> getProducts();

    // Methods to get filtered products.
    std::vector<Product> MinFilter(double min);
    std::vector<Product> MaxFilter(double max);
    std::vector<Product> TypeFilter(QString type);
    std::vector<Product> BrandFilter(QString brand);
    std::vector<Product> SizeFilter(QString size);
};

#endif // PRODUCTLIST_H
