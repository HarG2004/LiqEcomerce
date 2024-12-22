#include "manwindow.h"
#include "ui_manwindow.h"
#include "producttable.h"
#include "database.h"

// Class for manager stuff, sorry for the confusion.

// COnstructor
CustomerWindow::CustomerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);
}

// deconstructor
CustomerWindow::~CustomerWindow()
{
    delete ui;
}

// button to edit a product
void CustomerWindow::on_eEnter_clicked()
{
    // get database
    Database* db;
    db = Database::getInstance();

    // Get the entered Product ID
    QString productID = ui->eID->text();
    if (productID.isEmpty()) {
        ui->eResult->setText("Product ID is required.");
        return;
    }

    // Validate the Product ID using the search method
    ProductTable productTable;
    QString searchQuery = QString("SELECT * FROM Products WHERE ProductID = %1").arg(productID);
    if (!productTable.search(searchQuery)) {
        ui->eResult->setText("Invalid Product ID. Product not found.");
        return;
    }

    // Get the selected component to change
    QString selectedComponent = ui->eComponents->currentText();

    // Get the new component value
    QString newValue = ui->eNew->text();
    if (newValue.isEmpty()) {
        ui->eResult->setText("New value is required.");
        return;
    }

    // Update the product based on the selected component
    bool success = false;
    if (selectedComponent == "Size") {
        if (newValue == "small" || newValue == "medium" || newValue == "large") {
            QString updateQuery = QString("UPDATE Products SET Size = '%1' WHERE ProductID = %2").arg(newValue).arg(productID);
            success = productTable.edit(updateQuery);
        } else {
            ui->eResult->setText("Invalid size. Choose small, medium, or large.");
            return;
        }

    }else if (selectedComponent == "Type") {
        if (newValue == "wine" || newValue == "beer" || newValue == "vodka") {
            QString updateQuery = QString("UPDATE Products SET Type = '%1' WHERE ProductID = %2").arg(newValue).arg(productID);
            success = productTable.edit(updateQuery);
        } else {
            ui->eResult->setText("Invalid Type. Choose wine, beer, or vodka.");
            return;
        }

    } else if (selectedComponent == "Price") {
        bool ok;
        double price = newValue.toDouble(&ok);
        if (ok && price > 0) {
            QString updateQuery = QString("UPDATE Products SET Price = %1 WHERE ProductID = %2").arg(price).arg(productID);
            success = productTable.edit(updateQuery);
        } else {
            ui->eResult->setText("Invalid price. Enter a positive number.");
            return;
        }

    } else if (selectedComponent == "Brand") {
        QString updateQuery = QString("UPDATE Products SET Brand = '%1' WHERE ProductID = %2").arg(newValue).arg(productID);
        success = productTable.edit(updateQuery);


    }else if (selectedComponent == "Name") {
        QString updateQuery = QString("UPDATE Products SET Name = '%1' WHERE ProductID = %2").arg(newValue).arg(productID);
        success = productTable.edit(updateQuery);
    } else {
        ui->eResult->setText("Invalid component selected.");
        return;
    }

    // Display the result of the update
    if (success) {
        ui->eResult->setText("Product updated successfully.");
    } else {
        ui->eResult->setText("Failed to update the product.");
    }

}

// Method to remove product when button is clicked.
void CustomerWindow::on_rButton_clicked()
{
    // Get database.
    Database* db;
    db = Database::getInstance();

    // Get productID
    QString productId = ui->rID->text();

    // Check if the product ID is not empty
    if (productId.isEmpty()) {
        ui->rResult->setText("Product ID cannot be empty!");
        return;
    }

    // Create an instance of ProductTable
    ProductTable productTable;

    // Check if product exists.
    QString query = QString("SELECT * FROM Products WHERE ProductID = %1").arg(productId);

    if (productTable.search(query) == false){
        ui->rResult->setText("Product doesn't exist!");
        return;
    }

    // Create a query to remove the product with the given ID
    query = QString("DELETE FROM Products WHERE productId = %1").arg(productId);

    // Use the remove method of ProductTable
    if (productTable.remove(query)) {
        // If successful, update the result label
        ui->rResult->setText("Product removed successfully!");
    } else {
        // If failed, update the result label
        ui->rResult->setText("Failed to remove the product!");
    }

}


// Method to add a product when clicked.
void CustomerWindow::on_aButton_clicked()
{
    // Get database.
    Database* db;
    db = Database::getInstance();

    // Get inputs from input widgets.
    QString name = ui->aName->text();
    QString brand = ui->aBrand->text();
    QString type = ui->aType->text();
    QString size = ui->aSize->text();
    QString priceText = ui->aPrice->text();

    // Validate that none of the fields are empty
    if (name.isEmpty() || brand.isEmpty() || type.isEmpty() || size.isEmpty() || priceText.isEmpty()) {
        ui->aResult->setText("All fields are required!");
        return;
    }

    // Convert price to a double
    bool isValidPrice;
    double price = priceText.toDouble(&isValidPrice);

    // Validate the price input
    if (!isValidPrice || price <= 0) {
        ui->aResult->setText("Invalid price. Please enter a positive number.");
        return;
    }

    // Create an instance of ProductTable
    ProductTable productTable;

    // Add the product to the database
    if (productTable.addProduct(brand, name, type, size, price)) {
        // If successful, update the result label.
        ui->aResult->setText("Success!");

        // Clear all input wdgets when product is added.
        ui->aName->clear();
        ui->aBrand->clear();
        ui->aType->clear();
        ui->aSize->clear();
        ui->aPrice->clear();

    } else {
        // If failed, update the result label
        ui->aResult->setText("Failure!");
    }

}

