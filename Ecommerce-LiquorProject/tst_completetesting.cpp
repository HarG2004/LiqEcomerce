#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "database.h"
#include "customertable.h"
#include <QCoreApplication>
#include <QDebug>
#include "producttable.h"
#include "ordertable.h"
#include "register.h"
#include "productlist.h"
#include "shoppingcart.h"
#include <customerlogin.h>
#include <managerlogin.h>

// Here are my tests. They should all work fine though productList tests might need to be run twice to work.
// I don't know why. Mocking also didn't work for me, but Ive checked and everything should work.
// I also used a database viewer to look at my database entries and check that they were correct.
// You will also have to have an empty database to employ these tests.

// Database Singleton Test
TEST(DatabaseTest, SingletonTest) {
    Database* db1 = Database::getInstance();
    Database* db2 = Database::getInstance();

    ASSERT_EQ(db1, db2) << "Database instances are not the same!";
}

// CustomerTable Tests
class CustomerTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        db = Database::getInstance();
        customerTable.createTable();
    }

    Database* db;
    CustomerTable customerTable;
};

// Test Adding a Customer
TEST_F(CustomerTableTest, AddCustomer) {
    bool addResult = customerTable.addCustomer(
        1234567890,      // Liquor License Number
        20251231,        // Expiry Date
        "123 Business Rd", // Business Address
        "John Doe",       // Name
        "1234123412341234", // Credit Card Info
        "john_doe",       // Username
        "securePass123"   // Password
        );
    ASSERT_TRUE(addResult) << "Failed to add customer!";
}

// Test Retrieving a Customer
TEST_F(CustomerTableTest, GetCustomer) {
    QString query = "SELECT * FROM Customers WHERE Username = 'john_doe'";
    auto customerOpt = customerTable.getCustomer(query);
    ASSERT_TRUE(customerOpt.has_value()) << "Failed to retrieve customer!";

    Customer customer = customerOpt.value();
    EXPECT_EQ(customer.getName(), "John Doe");
    EXPECT_EQ(customer.getUsername(), "john_doe");
}

// Test Editing a Customer
TEST_F(CustomerTableTest, EditCustomer) {
    QString editQuery = "UPDATE Customers SET BusinessAdrs = '456 Elm St' WHERE CustomerID = 1";
    bool editSuccess = customerTable.edit(editQuery);
    ASSERT_TRUE(editSuccess) << "Failed to edit customer!";
}

// Test Removing a Customer
TEST_F(CustomerTableTest, RemoveCustomer) {
    QString removeQuery = "DELETE FROM Customers WHERE Username = 'john_doe'";
    bool removeSuccess = customerTable.remove(removeQuery);
    ASSERT_TRUE(removeSuccess) << "Failed to remove customer!";

    // Verify the customer no longer exists
    QString checkQuery = "SELECT * FROM Customers WHERE Username = 'john_doe'";
    auto customerOpt = customerTable.getCustomer(checkQuery);
    ASSERT_FALSE(customerOpt.has_value()) << "Customer was not successfully removed!";
}

// Product Table tests
class ProductTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        db = Database::getInstance();
        productTable.createTable();
    }

    Database* db;
    ProductTable productTable;
};

// Test adding a product.
TEST_F(ProductTableTest, AddValidProduct) {
    bool result = productTable.addProduct("Beer A", "Brand X", "beer", "small", 10.99);
    EXPECT_TRUE(result) << "Failed to add valid product.";
}

// Test adding a duplicate.
TEST_F(ProductTableTest, AddDuplicateProduct) {
    productTable.addProduct("Beer A", "Brand X", "beer", "small", 10.99);
    bool result = productTable.addProduct("Beer A", "Brand X", "beer", "small", 10.99);
    EXPECT_FALSE(result) << "Duplicate product was added when it shouldn't have been.";
}

// Test editing a product.
TEST_F(ProductTableTest, EditProduct) {
    QString editQuery = "UPDATE Products SET Name = 'Beer B', Brand = 'Brand Y', Type = 'wine', Size = 'medium', Price = 12.99 WHERE Name = 'Beer A'";
    bool editResult = productTable.edit(editQuery);
    EXPECT_TRUE(editResult) << "Failed to edit product.";
}

// Test removing a product.
TEST_F(ProductTableTest, RemoveProduct) {
    QString removeQuery = "DELETE FROM Products WHERE Name = 'Beer B'";
    bool removeResult = productTable.remove(removeQuery);
    EXPECT_TRUE(removeResult) << "Failed to remove product.";
}

// Order table tests
class OrderTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        db = Database::getInstance();
        orderTable.createTable();
    }

    Database* db;
    OrderTable orderTable;
};

// Add order test
TEST_F(OrderTableTest, AddOrder) {
    bool result = orderTable.addOrder(1, 100.0, 13.0, 113.0, "2024-01-01");
    EXPECT_TRUE(result) << "Failed to add order.";
}

// Get customer orders test
TEST_F(OrderTableTest, GetCustomerOrders) {
    auto orders = orderTable.getCustomerOrders(1);
    ASSERT_TRUE(orders.has_value()) << "No orders found for CustomerID = 1.";
}

// remove order test
TEST_F(OrderTableTest, RemoveOrder) {
    QString removeQuery = "DELETE FROM Orders WHERE CustomerID = 1";
    bool removeResult = orderTable.remove(removeQuery);
    EXPECT_TRUE(removeResult) << "Failed to remove order.";
}

// Register tests
class RegisterTest : public ::testing::Test {
protected:
    Register reg;

    void SetUp() override {
        // Initialize the database connection
        Database::getInstance()->getConnection();

        // Clean up the test customer if it exists
        QSqlQuery query;
        query.exec("DELETE FROM Customers WHERE Username = 'testuser'");
    }
};

// Valid customer test
TEST_F(RegisterTest, RegisterValidCustomer) {
    Customer validCustomer(
        "John Doe",
        1234567890,          // Valid liquor license
        2025,                // Valid expiry date
        "123 Main Street",
        "1234567812345678",  // Valid credit card
        1,                    // Customer ID (auto-generated)
        "testuser",          // Valid username
        "securepass"       // Valid password
        );

    // Attempt to register the customer
    bool result = reg.registerCustomer(validCustomer);
    EXPECT_TRUE(result) << "Customer registration failed when it should have succeeded.";
}

// Test for invalid customer registration
TEST_F(RegisterTest, RegisterInvalidCustomer) {
    Customer invalidCustomer(
        "Jane Doe",
        123,                 // Invalid liquor license
        2105,                // Invalid expiry date
        "123 Main Street",
        "1234",              // Invalid credit card
        2,                    // Customer ID (auto-generated)
        "usr",               // Invalid username
        "pwd"              // Invalid password
        );

    // Attempt to register the customer
    bool result = reg.registerCustomer(invalidCustomer);
    EXPECT_FALSE(result) << "Customer registration succeeded when it should have failed.";
}

// Customer login tests
class CustomerLoginTest : public ::testing::Test {
protected:

    void SetUp() override {
        // Initialize the database connection
        db = Database::getInstance();
        customerTable.createTable();

        // Add a test customer
        customerTable.addCustomer(1234567890, 2025, "123 Main Street", "John Doe", "1234567812345678", "testuser", "testpassword");
    }

    void TearDown() override {
        bool tear = customerTable.remove(QString("DELETE FROM Customers WHERE Username = 'testuser'"));
    }

    Database* db;
    CustomerTable customerTable;

};

// Test for successful customer login
TEST_F(CustomerLoginTest, ValidCustomerLogin) {
    customerLogin login("testuser", "testpassword");
    EXPECT_TRUE(login.login()) << "Valid customer login failed.";
}

// Test for invalid customer login
TEST_F(CustomerLoginTest, InvalidCustomerLogin) {
    customerLogin login("invaliduser", "wrongpassword");
    EXPECT_FALSE(login.login()) << "Invalid customer login succeeded.";
}

// Manager login tests

// Test for successful manager login
TEST(ManagerLoginTest, ValidManagerLogin) {
    managerLogin login("Manager", "SecretPassword", "SuperSecretPassword");
    EXPECT_TRUE(login.login()) << "Valid manager login failed.";
}

// Test for invalid manager login
TEST(ManagerLoginTest, InvalidManagerLogin) {
    managerLogin login("Manager", "WrongPassword", "WrongSecondPassword");
    EXPECT_FALSE(login.login()) << "Invalid manager login succeeded.";
}


// The product list tests seem to be very weird and seem to have some problems if they are not run multiple times.
// Also if I add a teardown that removes all products then for some reason the tests don't work even though it shouldn't matter
// as setup also clears the product table.
class ProductListTest : public ::testing::Test {
protected:
    ProductList productList;
    ProductTable productTable;

    void SetUp() override {
        // Initialize the database connection
        Database::getInstance()->getConnection();



        // Clear Product table.
        productTable.remove(QString("DELETE FROM Products"));

        // Add test products using ProductTable
        productTable.addProduct("Beer", "BrandA", "beer", "large", 5.5);
        productTable.addProduct("Wine", "BrandB", "wine", "medium", 15.0);
        productTable.addProduct("Vodka", "BrandC", "vodka", "small", 20.0);
    }

};

// Test for getting all products
TEST_F(ProductListTest, GetAllProducts) {
    std::vector<Product> products = productList.getProducts();
    EXPECT_EQ(products.size(), 3) << "Expected 3 products in the list.";
}

// Test for filtering products by minimum price
TEST_F(ProductListTest, MinFilter) {
    std::vector<Product> filteredProducts = productList.MinFilter(10.0);
    EXPECT_EQ(filteredProducts.size(), 2) << "Expected 2 products with price >= 10.0.";
}

// Test for filtering products by maximum price
TEST_F(ProductListTest, MaxFilter) {
    std::vector<Product> filteredProducts = productList.MaxFilter(10.0);
    EXPECT_EQ(filteredProducts.size(), 1) << "Expected 1 product with price <= 10.0.";
}

// Test for filtering products by type
TEST_F(ProductListTest, TypeFilter) {
    std::vector<Product> filteredProducts = productList.TypeFilter("wine");
    EXPECT_EQ(filteredProducts.size(), 1) << "Expected 1 product of type 'wine'.";
}

// Test for filtering products by brand
TEST_F(ProductListTest, BrandFilter) {
    std::vector<Product> filteredProducts = productList.BrandFilter("BrandA");
    EXPECT_EQ(filteredProducts.size(), 1) << "Expected 1 product of brand 'BrandA'.";
}

// Test for filtering products by size
TEST_F(ProductListTest, SizeFilter) {
    std::vector<Product> filteredProducts = productList.SizeFilter("large");
    EXPECT_EQ(filteredProducts.size(), 1) << "Expected 1 product of size 'large'.";
}


// Test adding products to the cart
TEST(ShoppingCartTest, AddProduct) {
    ShoppingCart cart;
    Product product1 = Product("Product1", "Category1","beer", "Medium", 10.0, 1);
    Product product2 = Product("Product2", "Category2", "wine", "Large", 20.0, 2);
    Product product3 = Product("Product3", "Category3", "vodka", "Small", 5.0, 3);

    EXPECT_TRUE(cart.addProduct(product1, 2)); // Add 2 of product1
    EXPECT_TRUE(cart.addProduct(product2, 3)); // Add 3 of product2
    std::map<int, std::pair<Product, int>> cartItems = cart.getCart();
    ASSERT_EQ(cartItems.size(), 2);
    EXPECT_EQ(cartItems[product1.getProductId()].second, 2);
    EXPECT_EQ(cartItems[product2.getProductId()].second, 3);
}

// Test removing products from the cart
TEST(ShoppingCartTest, RemoveProduct) {
    ShoppingCart cart;
    Product product1 = Product("Product1", "Category1","beer", "Medium", 10.0, 1);
    Product product2 = Product("Product2", "Category2", "wine", "Large", 20.0, 2);
    Product product3 = Product("Product3", "Category3", "vodka", "Small", 5.0, 3);

    cart.addProduct(product1, 2);
    cart.addProduct(product2, 3);

    // Remove 1 quantity of product1
    EXPECT_TRUE(cart.removeProduct(product1.getProductId(), 1));
    EXPECT_EQ(cart.getCart()[product1.getProductId()].second, 1);

    // Remove all of product2
    EXPECT_TRUE(cart.removeProduct(product2.getProductId(), 3));
    EXPECT_EQ(cart.getCart().size(), 1);

    // Try removing a product that doesn't exist
    EXPECT_FALSE(cart.removeProduct(product3.getProductId(), 1));
}

// Test calculating price summary
TEST(ShoppingCartTest, CalculatePriceSummary) {
    ShoppingCart cart;
    Product product1 = Product("Product1", "Category1","beer", "Medium", 10.0, 1);
    Product product2 = Product("Product2", "Category2", "wine", "Large", 20.0, 2);
    Product product3 = Product("Product3", "Category3", "vodka", "Small", 5.0, 3);

    cart.addProduct(product1, 2); // 2 * 10.0 = 20.0
    cart.addProduct(product2, 3); // 3 * 20.0 = 60.0
    cart.addProduct(product3, 1); // 1 * 5.0 = 5.0

    auto [subtotal, taxAmount, total] = cart.calculatePriceSummary();
    EXPECT_DOUBLE_EQ(subtotal, 85.0);
    EXPECT_DOUBLE_EQ(taxAmount, 11.05); // 85.0 * 0.13
    EXPECT_DOUBLE_EQ(total, 96.05);     // 85.0 + 11.05
}

