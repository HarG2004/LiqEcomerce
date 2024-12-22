#include "table.h"

// Class to manage tables.

// Method to edit an entry in the database.
bool Table::edit(QString query){

    // Get database connection.
    QSqlQuery sqlQuery(Database::getInstance()->getConnection());

    // Execute query, return true for success and false for failure.
    if (!sqlQuery.exec(query)) {
        return false;
    } else {
        return true;
    }
}

// Method to remove an entry from the database.
bool Table::remove(QString query){

    // Get database connection.
    QSqlQuery sqlQuery(Database::getInstance()->getConnection());

    // Execute query, return true for success and false for failure.
    if (!sqlQuery.exec(query)) {
        return false;
    } else {
        return true;
    }
}

/* Method to see if there is an entry that matches the query in the table
 */
bool Table::search(QString query){

    // Get database connection.
    QSqlQuery sqlQuery(Database::getInstance()->getConnection());

    // Execute query, return true if something is found and false for failure.
    if (sqlQuery.exec(query)) {
        if (sqlQuery.next()) {
            return true;
        }
    }
    return false;

}

