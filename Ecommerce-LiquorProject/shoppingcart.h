#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <map>
#include "Product.h"

class ShoppingCart
{
private:

    // Variable to hold all products and their quantities in the shopping cart.
    std::map<int, std::pair<Product, int>> shoppingCart; // ProductId as key, pair<Product, quantity> as value
public:
    // Method to add a product or increase its quantity.
    bool addProduct(Product item, int qt);

    // Method to remove a product or reduce its quantity.
    bool removeProduct(int productId, int qt);

    // Getter for the shopping cart.
    std::map<int, std::pair<Product, int>> getCart();

    // Method to calculate the prices of the shopping cart. Subtotal, taxed amount, and total.
    std::tuple<double, double, double> calculatePriceSummary();
};

#endif // SHOPPINGCART_H
