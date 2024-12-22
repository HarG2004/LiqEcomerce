#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
#include "Database.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();  // Displays the main window
    return a.exec();
}
