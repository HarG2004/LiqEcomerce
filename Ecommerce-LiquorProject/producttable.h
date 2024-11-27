#ifndef PRODUCTTABLE_H
#define PRODUCTTABLE_H

#include <table.h>
#include <product.h>

// Inherits Table
class ProductTable : public Table
{
public:

    // Overided method to create a table for products in the database.
    void createTable() override;

    // Method to add a product to the database.
    bool addProduct(QString name, QString brand, QString type, QString size, double price);
};

#endif // PRODUCTTABLE_H
