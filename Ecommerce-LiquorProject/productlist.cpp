#include "productlist.h"
#include <QCoreApplication>
#include <QDebug>
#include "database.h"

// CLass to create and filter product lists as required by the system.

// Constructor to create a list of all products in the database.
ProductList::ProductList() {

    //. Create query to go through all products.
    QSqlQuery query("SELECT * FROM Products");

    // Execute query and send debug messege if failed.
    if (!query.exec()) {
        qDebug() << "Failed to retrieve products from database:" << query.lastError().text();
        return;
    }

    // Go through all products in the databse.
    while (query.next()) {

        // Extract data from the databse products.
        QString productName = query.value("Name").toString();
        QString brand = query.value("Brand").toString();
        QString type = query.value("Type").toString();
        QString size = query.value("Size").toString();
        double price = query.value("Price").toDouble();
        int productId = query.value("ProductID").toInt();

        // Create a Product object and add it to the class' products vector.
        products.emplace_back(productName, brand, type, size, price, productId);
    }
}

// Getter for products vecotr.
std::vector<Product> ProductList::getProducts(){
    return products;
}


// Method to filter products with a minimum price.
std::vector<Product> ProductList::MinFilter(double min){

    // Create vector to hold filtered products.
    std::vector<Product> filteredList;

    // Filter and add products meeting the requirments to the filteredList.
    for (int i = 0; i < products.size(); i++){
        if (products[i].getPrice() >= min){
            filteredList.push_back(products[i]);
        }
    }
    // Return the filtered list.
    return filteredList;
}

// Method to filter products with a maximum price.
std::vector<Product> ProductList::MaxFilter(double max){

    // Create vector to hold filtered products.
    std::vector<Product> filteredList;

    // Filter and add products meeting the requirments to the filteredList.
    for (int i = 0; i < products.size(); i++){
        if (products[i].getPrice() <= max){
            filteredList.push_back(products[i]);
        }
    }
    // Return the filtered list.
    return filteredList;
}

// Method to filter products based of type.
std::vector<Product> ProductList::TypeFilter(QString type){

    // Create vector to hold filtered products.
    std::vector<Product> filteredList;

    // Filter and add products meeting the requirments to the filteredList.
    for (int i = 0; i < products.size(); i++){
        if (products[i].getType() == type){
            filteredList.push_back(products[i]);
        }
    }
    // Return the filtered list.
    return filteredList;
}

// Method to filter products based of brand.
std::vector<Product> ProductList::BrandFilter(QString brand){

    // Create vector to hold filtered products.
    std::vector<Product> filteredList;

    // Filter and add products meeting the requirments to the filteredList.
    for (int i = 0; i < products.size(); i++){
        if (products[i].getBrand() == brand){
            filteredList.push_back(products[i]);
        }
    }
    // Return the filtered list.
    return filteredList;
}

// Method to filter products based of size.
std::vector<Product> ProductList::SizeFilter(QString size){

    // Create vector to hold filtered products.
    std::vector<Product> filteredList;

    // Filter and add products meeting the requirments to the filteredList.
    for (int i = 0; i < products.size(); i++){
        if (products[i].getSize() == size){
            filteredList.push_back(products[i]);
        }
    }
    // Return the filtered list.
    return filteredList;
}

