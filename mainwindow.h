#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMessageBox>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMainWindow>
#include "categorie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_commandLinkButton_4_clicked();

    void on_pushButton_clicked();

    void on_ajouterem_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_3_clicked();

    void on_modifierem_clicked();

    void on_afficherem_clicked();

    void on_mailem_clicked();


    void on_pushButton_2_clicked();



    void on_supprimerem_clicked();

    void on_pushButton_30_clicked();

    void on_ajouterca_clicked();

    void on_modifierca_clicked();

    void on_supprimerca_clicked();

    void on_afficherca_clicked();

    void on_rechercherca_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pb_ajouter_6_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pb_supprimer_5_clicked();

    void on_rechercheNom_clicked();

    void on_rechercheSalaire_clicked();

    void on_rechercheId_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_41_clicked();

private:
    Ui::Menu *ui;
    categorie Categorie;

};
#endif // MAINWINDOW_H
