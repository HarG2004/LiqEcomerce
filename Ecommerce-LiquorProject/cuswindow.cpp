#include "cuswindow.h"
#include "ui_cuswindow.h"
#include "customertable.h"
#include "register.h"
#include "database.h"
#include "product.h"
#include "productlist.h"
#include <tuple>
#include "ordertable.h"

// This is the class for the customer section of the UI. It says manager because of a mistake.
// I don't know how to fix this.

// Initialize private variables and database when opening this window.
managerWindow::managerWindow(int customerId, QWidget *parent)
    : QMainWindow(parent), cusID(customerId)
    , ui(new Ui::managerWindow)
{
    ui->setupUi(this);
    Database* db;
    db = Database::getInstance();
    ProductList ls;
    list = ls.getProducts();
    populateTable();

}

// deconstructor
managerWindow::~managerWindow()
{
    delete ui;
}

// Button that edits a customer component.
void managerWindow::on_eEnter_clicked()
{

    // get database register and customertable
    Database* db;
    db = Database::getInstance();
    Register reg;
    CustomerTable customerTable;

    // Get selected component and new value from UI
    QString component = ui->eComponent->currentText();
    QString newValue = ui->eNew->text();


    // Validate the selected component
    if (component == "Username") {
        QString query = QString("SELECT * FROM Customers WHERE Username = '%1'").arg(newValue);

        if (customerTable.search(query) == true){
            ui->eResult->setText("Username already exists!");
            return;
        }
        if (!reg.isUsernameValid(newValue)) {
            ui->eResult->setText("Invalid username. Must be 6 or more characters.");
            return;
        }
    } else if (component == "Password") {
        if (!reg.isPasswordValid(newValue)) {
            ui->eResult->setText("Invalid password. Must be 6 or more characters.");
            return;
        }

    } else if (component == "CreditCardInfo") {
        if (!reg.isCreditCardValid(newValue)) {
            ui->eResult->setText("Invalid credit card. Must be 16 digits.");
            return;
        }
    } else if (component == "LiquorLicenseNum") {
        int liquorLicense = newValue.toInt();
        if (!reg.isLiquorLicenseValid(liquorLicense)) {
            ui->eResult->setText("Invalid liquor license. Must be 10-12 digits.");
            return;
        }
    } else if (component == "LLExpDate") {
        int expiryDate = newValue.toInt();
        if (!reg.isExpiryDateValid(expiryDate)) {
            ui->eResult->setText("Invalid expiry date. Must be between 2024 and 2100.");
            return;
        }
    }

    // Prepare the SQL query to update the customer
    QString query = QString("UPDATE Customers SET %1 = '%2' WHERE CustomerID = %3")
                        .arg(component, newValue, QString::number(cusID));

    // Execute the update query
    if (customerTable.edit(query)) {
        ui->eResult->setText("Customer details updated successfully.");
    } else {
        ui->eResult->setText("Failed to update customer details.");
    }
}

// Method to populate the product table, sadly I couldn't figure out how to filter the table effeciently.
void managerWindow::populateTable() {

    ui->productTable->setRowCount(list.size());
    for (int i = 0; i < list.size(); ++i) {
        Product product = list[i];
        ui->productTable->setItem(i, 0, new QTableWidgetItem(product.getProductName()));
        ui->productTable->setItem(i, 1, new QTableWidgetItem(product.getBrand()));
        ui->productTable->setItem(i, 2, new QTableWidgetItem(product.getType()));
        ui->productTable->setItem(i, 3, new QTableWidgetItem(product.getSize()));
        ui->productTable->setItem(i, 4, new QTableWidgetItem(QString::number(product.getPrice())));
    }
}

// Create order table of all of customer's orders.
void managerWindow::oTable() {
    // get order table
    OrderTable orderTable;
    auto ord = orderTable.getCustomerOrders(cusID);

    std::vector<Order> ord2;

    // check if customer has any orders.
    if (ord.has_value()){
        ord2 = ord.value();
    }
    else{
        return;
    }

    // create the table.
    ui->oTable->setRowCount(ord2.size());
    for (int i = 0; i < ord2.size(); ++i) {

        Order order = ord2[i];
        ui->oTable->setItem(i, 0, new QTableWidgetItem(QString::number(order.getOrderID())));
        ui->oTable->setItem(i, 1, new QTableWidgetItem(QString::number(order.getSubtotal())));
        ui->oTable->setItem(i, 2, new QTableWidgetItem(QString::number(order.getTax())));
        ui->oTable->setItem(i, 3, new QTableWidgetItem(QString::number(order.getTotal())));
        ui->oTable->setItem(i, 4, new QTableWidgetItem(order.getArrivalDate()));
    }
}

// Method to populate the shopping cart table for checkout.
void managerWindow::refreshTable() {
    int i = 0;

    ui->cartTable->setRowCount(cart.getCart().size());

    for (auto const& [key, val] : cart.getCart()) {
        Product product = val.first;

        ui->cartTable->setItem(i, 0, new QTableWidgetItem(product.getProductName()));
        ui->cartTable->setItem(i, 1, new QTableWidgetItem(QString::number(val.second)));
        ui->cartTable->setItem(i, 2, new QTableWidgetItem(QString::number(product.getPrice())));

        i++;
    }
}


// Method to update the customer's shopping cart in the ui.
void managerWindow::updateCart() {
    // Get the selected row
    int currentRow = ui->productTable->currentRow();
    if (currentRow < 0) {
        ui->statusLabel->setText("No product selected!");
        return;
    }

    // Get the product ID from the row
    int productId = list[currentRow].getProductId();

    // Get the quantity from the spin box
    int quantity = ui->quantity->value();

    // Update the shopping cart
    if (quantity > 0) {

        if (cart.addProduct(list[currentRow], quantity)) {
            ui->statusLabel->setText("Product added to cart!");
        } else {
            ui->statusLabel->setText("Failed to add product.");
        }
    } else if (quantity < 0) {

        if (cart.removeProduct(productId, -quantity)) {
            ui->statusLabel->setText("Product removed from cart!");
        } else {
            ui->statusLabel->setText("Failed to remove product.");
        }

    } else {
        ui->statusLabel->setText("Quantity cannot be zero.");
    }
}

// Method to update the shopping cart when this button is clicked.
void managerWindow::on_update_clicked()
{
    updateCart();
}


// Method to refresh the shopping cart table when the button is clicked.
void managerWindow::on_refreshButton_clicked()
{
    refreshTable();
    auto val = cart.calculatePriceSummary();
    ui->sub->setText(QString::number(std::get<0>(val)));
    ui->tax->setText(QString::number(std::get<1>(val)));
    ui->total->setText(QString::number(std::get<2>(val)));


}


// Method to order products when this button is clicked
void managerWindow::on_oButton_clicked()
{
    OrderTable table;

    // Get prices.
    auto val = cart.calculatePriceSummary();

    // Check if the order went through.
    if (table.addOrder(cusID,std::get<0>(val), std::get<1>(val), std::get<2>(val), QString("2025"))){
        ui->checkResult->setText("Order Taken!");
    }
    else{
        ui->checkResult->setText("Order Failed!");

    }
}

