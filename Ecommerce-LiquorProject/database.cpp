#include "database.h"

// Class to create a database and insure only one connection to the database exists.

// Initialize database pointer to null.
Database* Database::instance = nullptr;


// Constructor to create database or open if dtabase already created.
Database::Database() {

    // Create database.
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Harjap/LiqEcomWebsite.db");

    // Open databse.
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connection established.";
    }
}


// Deconstructor to close database.
Database::~Database() {
    if (db.isOpen()) {
        db.close();
    }
}

// Method to get the instance of the database.
Database* Database::getInstance() {
    if (instance == nullptr) {
        instance = new Database();
    }
    return instance;
}

// Method to get the database connection.
QSqlDatabase& Database::getConnection() {
    return db;
}
