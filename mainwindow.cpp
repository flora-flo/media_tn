#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domaine.h"
#include "offre.h"
#include <QSqlQuery>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)

 {

     ui->setupUi(this);
 }

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->CRUD->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->CRUD->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->CRUD->setCurrentIndex(3);
    ui->taboffre->setModel(o.afficher());

}

void MainWindow::on_pushButton_21_clicked()
{
    int idO=ui->lineEdit_nom->text().toInt();
        QString nom=ui->lineEdit_prenom->text();
        QString dateD=ui->lineEdit_5->text();
        QString dateF=ui->lineEdit_6->text();
        QString adresse=ui->lineEdit_adresse_2->text();
        QString NomD=ui->lineEdit_adresse->text();
        QString NomS=ui->lineEdit->text();
       offre c (idO,dateD,dateF,adresse,NomD,nom,NomS);
        int erreur=0;
        if(ui->lineEdit_nom->text().isEmpty())
        {
            ui->lineEdit_nom->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_nom->setStyleSheet("");}
        if(ui->lineEdit_prenom->text().isEmpty())
        {
            ui->lineEdit_prenom->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_prenom->setStyleSheet("");}
        if(ui->lineEdit_5->text().isEmpty())
        {
            ui->lineEdit_5->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_5->setStyleSheet("");}
        if(ui->lineEdit_6->text().isEmpty())
        {
            ui->lineEdit_6->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_6->setStyleSheet("");}
        if(ui->lineEdit_adresse_2->text().isEmpty())
        {
            ui->lineEdit_adresse_2->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_adresse_2->setStyleSheet("");}
        if(ui->lineEdit_adresse->text().isEmpty())
        {
            ui->lineEdit_adresse->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_adresse->setStyleSheet("");}
        if(ui->lineEdit->text().isEmpty())
        {
            ui->lineEdit->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit->setStyleSheet("");}

if(erreur)
{
    QMessageBox::information(nullptr, QObject::tr("Ajouter un offre"),
                QObject::tr("Vérifiez vos champs !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
if(!erreur)
{
    bool test=c.ajouter();

  if(test)
{

 ui->taboffre->setModel(o.afficher());//refresh
 QMessageBox::information(nullptr, QObject::tr("Ajouter un offre"),
                  QObject::tr("offre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un offre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pushButton_14_clicked()
{
    ui->CRUD->setCurrentIndex(1);

}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_18_clicked()
{
    ui->CRUD_2->setCurrentIndex(1);
    ui->CRUD_2->setCurrentIndex(2);
    ui->tabdomaine->setModel(d.afficher());//refresh
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->CRUD_2->setCurrentIndex(4);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->CRUD_2->setCurrentIndex(2);
    ui->tabdomaine->setModel(d.afficher());//refresh
    ui->CRUD_2->setCurrentIndex(3);


}

void MainWindow::on_pushButton_15_clicked()
{
    ui->CRUD_2->setCurrentIndex(0);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(1);

}
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{

    int ido = ui->lineEdit_2->text().toInt();
     bool test=o.supprimer(ido);
     if(test)
     {ui->tabdomaine->setModel(d.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer offre"),
                  QObject::tr("Offre supprimée.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

}
}


 void MainWindow::on_pushButton_5_clicked()
 {
        int idD=ui->lineEdit_8->text().toInt();
           QString NomD=ui->lineEdit_7->text();
           domaine d (idD,NomD);
            bool test=d.ajouter();
  if(test)
{
  ui->tabdomaine->setModel(o.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un domaine"),
                  QObject::tr("domaine ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter un domaine"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_7_clicked()
{
   int idD = ui->lineEdit_3->text().toInt();
    bool test=d.supprimer(idD);
    if(test)
    {ui->tabdomaine->setModel(d.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Supprimer un domaine"),
                 QObject::tr("Carte supprimée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Supprimer un domaine"),
                QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pushButton_23_clicked()
{
    QSqlQuery query;

  //  int idO = ui->lineEdit_nom5->text().toInt();
        QString nom=ui->lineEdit_prenom5->text();
        QString dateD=ui->lineEdit_11->text();
        QString dateF=ui->lineEdit_12->text();
        QString adresse=ui->lineEdit_date5->text();
        QString NomD=ui->lineEdit_adresse5->text();
        QString NomS=ui->lineEdit_5->text();


            query.prepare("update offre set DATED=:dateD ,DATEF=:dateF , ADRESSE=:adresse ,NOM_DOMAINE=:NomD,NOM_OFFRE=:Nom, NOM_SOCIETE=:NomS WHERE ID_OFFRE =:idO");
            query.bindValue(":nom",nom);
            query.bindValue(":dateD",dateD);
            query.bindValue(":dateF",dateF);
            query.bindValue(":adresse",adresse);
            query.bindValue(":NomD",NomD);
            query.bindValue(":NomS",NomS);

            bool t=query.exec();
                   if(t)
                   {
                      ui->tabdomaine->setModel(d.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("OFFRE modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_28_clicked()
{
    QSqlQuery query;
    int idD=ui->lineEditnom_2->text().toInt();
    QString NomD=ui->lineEdit_9->text();


            query.prepare("update domaine set IDD=:idD ,NOMD=:NomD  WHERE IDD =:idD");
            query.bindValue(":idD",idD);
            query.bindValue(":NomD",NomD);


            bool t=query.exec();
                   if(t)
                   {
                      ui->tabdomaine->setModel(d.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("domaine modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{

    ui->tabdomaine->setModel(d.rechercher(arg1));
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="Id")
        {
            ui->tabdomaine->setModel(d.trierid());
        }
        else if (arg1=="Nom")
        {
            ui->tabdomaine->setModel(d.triernom());
        }

}
