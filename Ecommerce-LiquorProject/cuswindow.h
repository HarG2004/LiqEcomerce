#ifndef CUSWINDOW_H
#define CUSWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "shoppingcart.h"

namespace Ui {
class managerWindow;
}

class managerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit managerWindow(int customerId, QWidget *parent = nullptr);
    ~managerWindow();

    void populateTable();
    void updateCart();
    void refreshTable();
    void oTable();

private slots:
    void on_eEnter_clicked();

    void on_update_clicked();

    void on_refreshButton_clicked();

    void on_oButton_clicked();


private:
    int cusID;
    ShoppingCart cart;
    std::vector<Product> list;
    Ui::managerWindow *ui;
};

#endif // CUSWINDOW_H
