#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButto_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_regButton_clicked();

    void on_mLoginButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
