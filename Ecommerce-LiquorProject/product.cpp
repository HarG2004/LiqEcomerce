#include "product.h"

// CLass to create a product and get its attributes.
Product::Product() : productName(""), brand(""), type(""),size(""), price(0.0), productId(0) {}

// Constructor to initialize attributes with paramters.
Product::Product(QString nameP, QString brandP, QString typeP, QString sizeP, double priceP, int idP) {
    productName = nameP;
    brand = brandP;
    type = typeP;
    size = sizeP;
    price = priceP;
    productId = idP;
}

// Getter for productName.
QString Product::getProductName(){
    return productName;
}

// Getter for brand.
QString Product::getBrand(){
    return brand;
}

// Getter for type.
QString Product::getType(){
    return type;
}

// Getter for size.
QString Product::getSize(){
    return size;
}

// Getter for price.
double Product::getPrice(){
    return price;
}

// Getter for productId.
int Product::getProductId(){
    return productId;
}
