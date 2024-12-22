#ifndef TABLE_H
#define TABLE_H

#include "Database.h"
#include <optional>

class Table
{
public:

    // Methods to edit, remove, or confirm entries in the database.
    virtual bool edit(QString query);
    virtual bool remove(QString query);
    virtual bool search(QString query);

protected:

    // Method meant to be passed onto child classes for them to make unique tables..
    virtual void createTable() = 0; // Falcilitates the template pattern.
};

#endif // TABLE_H
