#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "categorie.h"
#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    employe em;
    categorie ca;

};

#endif // MAINWINDOW_H
