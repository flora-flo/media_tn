#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMainWindow>

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->tabetudiant_5->setModel(Categorie.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouterem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_modifierem_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_afficherem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_mailem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_supprimerem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouterca_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_modifierca_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_supprimerca_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_afficherca_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_rechercherca_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_46_clicked()
{
  //  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb_ajouter_6_clicked()
{

    int identifiant = ui->identifiant1_2->text().toInt();
    QString nom= ui->nom_9->text();
     QString poste= ui->poste->text();
     int salaire= ui->salaire_2->text().toInt();

    categorie c(identifiant, nom, poste, salaire);
    bool test=c.ajouter();
    if(test)
    {

        ui->tabetudiant_5->setModel(Categorie.afficher());//refresh


               QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                    QObject::tr("Categorie ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->identifiant1_2->clear();
               ui->nom_9->clear();
               ui->poste->clear();
               ui->salaire_2->clear();

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->identifiant1_2->clear();
        ui->nom_9->clear();
        ui->poste->clear();
        ui->salaire_2->clear();



    }



}


void MainWindow::on_pushButton_31_clicked()
{


    int identifiant = ui->lineEdit_24->text().toInt();
    QString nom= ui->lineEdit_25->text();
     QString poste= ui->lineEdit_26->text();
     int salaire= ui->lineEdit_27->text().toInt();

    categorie c(identifiant, nom, poste, salaire);
    bool test=c.modifier(identifiant);
    if(test)
    {

        ui->tabetudiant_5->setModel(Categorie.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEdit_24->clear();
               ui->lineEdit_25->clear();
               ui->lineEdit_26->clear();
               ui->lineEdit_27->clear();
  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_24->clear();
        ui->lineEdit_25->clear();
        ui->lineEdit_26->clear();
        ui->lineEdit_27->clear();



    }
}

void MainWindow::on_pushButton_32_clicked()
{
    int id=ui->lineEdit_24->text().toInt();
    Categorie.setID(id);
    if(Categorie.verificationCategorie()==0)
    {
        ui->lineEdit_24->show();
        ui->lineEdit_25->show();
        ui->lineEdit_26->show();
        ui->lineEdit_27->show();

        QString id=QString::number(Categorie.get_identifiant());
        QString pr=QString::number(Categorie.get_salaire());

        ui->lineEdit_24->setText(id);
        ui->lineEdit_25->setText(Categorie.get_nom());;
        ui->lineEdit_26->setText(Categorie.get_poste());
        ui->lineEdit_27->setText(pr);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("l'identifiant n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pb_supprimer_5_clicked()
{

    int ident= ui->lineEdit_id_12->text().toInt();
     Categorie.setID(ident);

         if(Categorie.verificationCategorie()==0)
         {
             bool test=Categorie.supprimer(Categorie.get_identifiant());
             if(test)
             {
                 ui->tabetudiant_5->setModel(Categorie.afficher());
                 qDebug()<<"Suppression effectue"<<endl;
                 QMessageBox::information(this, "Reussite", "Supression effectué !");
                 ui->lineEdit_id_12->clear();

             }
             else
             {
                 qDebug()<<"Suppression non effectue"<<endl;
                 QMessageBox::warning(this, "Echec", "Supression non effectué !");
                 ui->lineEdit_id_12->clear();
             }

         }
         else
         {
              QMessageBox::warning(this, "Echec", "identifiant non existant !");
         }


}

void MainWindow::on_rechercheNom_clicked()
{

    QString nom= ui->nomcher_2->text();
    Categorie.setNom(nom);
    if(Categorie.verificationCategorieN()==0)
    {
      ui->tabcategorie_2->setModel(Categorie.chercher(Categorie.get_nom()));
       ui->nomcher_2->clear();
    }

    else
    {
             QMessageBox::warning(this, "Echec", "non existant !");
             ui->nomcher_2->clear();
    }

}

void MainWindow::on_rechercheSalaire_clicked()
{

    int salaire= ui->lineEdit_32->text().toInt();
    Categorie.setsalaire(salaire);

    if(Categorie.verificationCategorieS()==0)
    {
    ui->tabcategorie_2->setModel(Categorie.chercherSalaire(Categorie.get_salaire()));
    ui->lineEdit_32->clear();
    }
    else
     {

        QMessageBox::warning(this, "Echec", "non existant !");
        ui->lineEdit_32->clear(); //efface le qline edit
    }

}

void MainWindow::on_rechercheId_clicked()
{
    int id= ui->lineEdit_28->text().toInt();
    Categorie.setID(id);
    if(Categorie.verificationCategorie()==0)
    {
    ui->tabcategorie_2->setModel(Categorie.chercherID(Categorie.get_identifiant()));
    ui->lineEdit_28->clear();
    }
    else
    {
    QMessageBox::warning(this, "Echec", "non existant !");
    ui->lineEdit_28->clear();
    }


}

void MainWindow::on_pushButton_33_clicked()
{
    ui->tabetudiant_5->setModel(Categorie.trier_nom());
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->tabetudiant_5->setModel(Categorie.trier_salaire());
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->tabetudiant_5->setModel(Categorie.trier_ID());
}
