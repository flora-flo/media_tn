#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

  ui->tabetudiant->setModel(em.afficherEmploye());
  ui->tabetudiant_2->setModel(ca.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();

    int telephone = ui->tel->text().toInt();

    QString mail= ui->lineEdit_5->text();
   QString sexe= ui->lineEdit_6->text();
    employe E(id,nom,prenom,telephone,mail,sexe);

  bool test=E.ajouterEmploye();
  if(test)
{

      ui->tabetudiant->setModel(em.afficherEmploye());//refresh

             QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                  QObject::tr("Employé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajout non effectyué"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();

bool test=em.supprimerEmploye();
if(test)
{//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Suppression effectué"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Suppression non effectué"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int identifiant = ui->identifiant1->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
     QString poste= ui->lineEdit_prenom_2->text();
     int salaire= ui->salaire->text().toInt();

    categorie c(identifiant, nom, poste, salaire);
    bool test=c.ajouter();
    if(test)
    {

        ui->tabetudiant_2->setModel(ca.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                    QObject::tr("Categorie ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
}


void MainWindow::on_pushButton_14_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ca.setID(id);
    if(ca.verificationCategorie()==0)
    {
        ui->lineEdit->show();
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->lineEdit_16->show();

        QString id=QString::number(ca.get_identifiant());
        QString pr=QString::number(ca.get_salaire());

        ui->lineEdit->setText(id);
        ui->lineEdit_2->setText(ca.get_nom());;
        ui->lineEdit_3->setText(ca.get_poste());
        ui->lineEdit_16->setText(pr);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("l'identifiant n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}







void MainWindow::on_pushButton_11_clicked()
{
     int identifiant = ui->lineEdit->text().toInt();
     ca.setID(identifiant);
     QString nom= ui->lineEdit_2->text();
     ca.setNom(nom);
     QString poste= ui->lineEdit_3->text();
     ca.setposte(poste);
     int salaire= ui->lineEdit_16->text().toInt();
     ca.setsalaire(salaire);
     categorie c(ca.get_identifiant(), ca.get_nom(), ca.get_poste(), ca.get_salaire());
     bool test=c.modifier();
     if(test)
     {

         ui->tabetudiant_2->setModel(ca.afficher());//refresh

                QMessageBox::information(nullptr, QObject::tr("effectué"),
                     QObject::tr(" Modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("non effectyué"),
                     QObject::tr("non modifié !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



     }
}







void MainWindow::on_pb_supprimer_2_clicked()
{
   int ident= ui->lineEdit_id_4->text().toInt();
    ca.setID(ident);

        if(ca.verificationCategorie()==0)
        {
            bool test=ca.supprimer(ca.get_identifiant());
            if(test)
            {
                ui->tabetudiant_2->setModel(ca.afficher());
                qDebug()<<"Suppression effectue"<<endl;
                QMessageBox::information(this, "Reussite", "Supression effectué !");
                ui->lineEdit_id_4->clear();

            }
            else
            {
                qDebug()<<"Suppression non effectue"<<endl;
                QMessageBox::warning(this, "Echec", "Supression non effectué !");
                ui->lineEdit_id_4->clear();
            }

        }
        else
        {
             QMessageBox::warning(this, "Echec", "identifiant non existant !");
        }


}

void MainWindow::on_pushButton_clicked()
{
    ui->tabetudiant_2->setModel(ca.trier_nom());
}


void MainWindow::on_pushButton_12_clicked()
{

        ui->tabetudiant_2->setModel(ca.trier_salaire());

}

void MainWindow::on_pushButton_13_clicked()
{
     ui->tabetudiant_2->setModel(ca.trier_ID());
}

void MainWindow::on_pushButton_15_clicked()
{
    QString nom= ui->nomcher->text();
    ca.setNom(nom);
    if(ca.verificationCategorieN()==0)
    {
      ui->tabcategorie->setModel(ca.chercher(ca.get_nom()));
       ui->nomcher->clear();
    }

    else
    {
             QMessageBox::warning(this, "Echec", "non existant !");
             ui->nomcher->clear();
        }

}

void MainWindow::on_pushButton_16_clicked()
{
    int id= ui->lineEdit_18->text().toInt();
    ca.setID(id);
    if(ca.verificationCategorie()==0)
    {
    ui->tabcategorie->setModel(ca.chercherID(ca.get_identifiant()));
    ui->lineEdit_18->clear();
    }
    else
    {
    QMessageBox::warning(this, "Echec", "non existant !");
    ui->lineEdit_18->clear();
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    int salaire= ui->lineEdit_17->text().toInt();
    ca.setsalaire(salaire);

    if(ca.verificationCategorieS()==0)
    {
    ui->tabcategorie->setModel(ca.chercherSalaire(ca.get_salaire()));
    ui->lineEdit_17->clear();
    }
    else
     {

        QMessageBox::warning(this, "Echec", "non existant !");
        ui->lineEdit_17->clear(); //efface le qline edit
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    Smtp* smtp = new Smtp("douamerveille92@gmail.com","RC02072000","smtp.gmail.com",465);
    connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
    smtp->sendMail("douamerveille92@gmail.com", ui->lineEdit_4->text(), ui->sujet->text(), ui->plainTextEdit->toPlainText());
}

