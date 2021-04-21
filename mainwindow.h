#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "prime.h"
#include "salaire.h"
#include <QMainWindow>
#include "QMessageBox"
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();










    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Prime P;


};

#endif // MAINWINDOW_H
