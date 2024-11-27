#include "mainwindow.h"

#include <QApplication>
#include "Database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database* dbManager = Database::getInstance();

    // Use the database connection
    QSqlDatabase& db = dbManager->getConnection();
    QSqlQuery query(db);
    return 0;
}
