#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Database
{

private:

    // Private instance, database, and constructor for singleton design.
    static Database* instance;
    QSqlDatabase db;

    Database();
public:

    // Deconstructor
     ~Database();

    // Static method to get the single instance.
    static Database* getInstance();

    // Method to get the connection to the database.
    QSqlDatabase& getConnection();
};

#endif // DATABASE_H
