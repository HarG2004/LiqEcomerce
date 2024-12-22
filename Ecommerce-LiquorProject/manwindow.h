#ifndef MANWINDOW_H
#define MANWINDOW_H

#include <QMainWindow>

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerWindow(QWidget *parent = nullptr);
    ~CustomerWindow();

private slots:
    void on_eEnter_clicked();

    void on_rButton_clicked();

    void on_aButton_clicked();

private:
    Ui::CustomerWindow *ui;
};

#endif // MANWINDOW_H
