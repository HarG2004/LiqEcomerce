#include "shoppingcart.h"
#include <QDebug>

// Class to create and manage the customer's shopping cart.

// Method to add a product to the cart.
bool ShoppingCart::addProduct(Product item, int qt) {

    if (qt < 1) {
        // Do not add if the quantity of product is less than 1.
        return false;
    }

    // variable to hold total qt.
    int totalQuantity = 0;

    // Iterate through the shoppingCart map
    for (const auto& item : shoppingCart) {
        // add each qt to total
        totalQuantity += item.second.second;
    }

    if (totalQuantity + qt > 100){
        return false;
    }

    // Find the product if it exists in the cart.
    auto it = shoppingCart.find(item.getProductId());
    if (it != shoppingCart.end()) {

        // Product exists, increase the quantity.
        it->second.second += qt;
    } else {

        // Product doesn't exist, add a new product to the cart.
        shoppingCart.insert(std::make_pair(item.getProductId(), std::make_pair(item, qt)));
    }
    // Return true once the change has been made to the cart.
    return true;
}


// Method to remove a product from the cart.
bool ShoppingCart::removeProduct(int productId, int qt) {
    if (qt < 1) {
        // Do not process if the quantity of product to remove is less than 1.
        return false;
    }

    // Find the product in the cart.
    auto it = shoppingCart.find(productId);
    if (it != shoppingCart.end()) {

        // Product exists in the cart.
        if (it->second.second > qt) {

            // If the product qt is more than the amount being removed then reduce product qt.
            it->second.second -= qt;
        } else {
            // Remove the product if the quantity reaches 0 or below.
            shoppingCart.erase(it);
        }
        // Return true once the change has been made to the cart.
        return true;
    }

    // Product was not found in the cart
    return false;
}

// Getter for shoppingCart.
std::map<int, std::pair<Product, int>> ShoppingCart::getCart(){
    return shoppingCart;
}

// Method to calculate the subtotal, taxes, and total of the cart.
std::tuple<double, double, double> ShoppingCart::calculatePriceSummary() {

    // Variables to hold, subtotal, total, tax rate, adn tax amount.
    double subtotal = 0;
    const double tax = 0.13;
    double total;
    double taxAmount;

    // Go through all the products in the cart.
    for (auto it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {

        // Get the product and its quantity.
        Product product = it->second.first;
        int quantity = it->second.second;

        // Add the total of the product to subtotal.
        subtotal += product.getPrice() * quantity;
    }

    // Calculate taxAmount and total.
    taxAmount = subtotal * tax;
    total = subtotal + taxAmount;

    // Return a tuple of the three amounts.
    return std::make_tuple(subtotal, taxAmount, total);
}

