#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prime.h"
#include "salaire.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Desktop/boris/Atelier_Connexion/markus-spiske-1yyKF6NK4PQ-unsplash.jpg");
        ui->label_10->setPixmap(pix.scaled(1100,15000,Qt::KeepAspectRatio));
        QPixmap pix2("C:/Users/HP/Desktop/boris/Atelier_Connexion/press.jpg");
            ui->label_14->setPixmap(pix2.scaled(1100,15000,Qt::KeepAspectRatio));
ui->lineEdit_14->setValidator(new QIntValidator(1000, 9999, this));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Prime P1; P1.setnump(ui->lineEdit->text().toInt());
    bool test=P1.supprimer(P1.getnump());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tableView->setModel(P.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
            msgBox.exec();
}


void MainWindow::on_pushButton_clicked()
{

    int nump=ui->lineEdit_14->text().toInt();
    int valeur=ui->la_description->text().toInt();
    QString nom=ui->le_id->text();
 Prime P(nom,nump,valeur);
 bool test=P.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView->setModel(P.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    int nump = ui->lineEdit_3->text().toInt();
    QString nom= ui->lineEdit_2->text();
    int valeur = ui->lineEdit_4->text().toInt();

    Prime P(nom,nump,valeur);
    bool test=P.modifier(nom,nump,valeur);
    QMessageBox msgBox;
        if(test)
           {
         ui->tableView->setModel(P.afficher());
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("success"))
                                 );
        }
        else
            QMessageBox::information(this, tr("Done"),
                                                  QString(tr("echec"))
                                                  );                msgBox.exec();
}



void MainWindow::on_pushButton_5_clicked()
{
    int choix ;
    choix=ui->comboBox_2->currentIndex();
    QSqlQueryModel * model =new QSqlQueryModel();


  if(ui->radioButton_2->isChecked())
  model =   P.trierup(choix);


 else if(ui->radioButton->isChecked())
    model=P.trier_down(choix);

  else
      model=P.afficher();

   ui->tableView->setModel(model);
}

//Salaire
void MainWindow::on_pushButton_8_clicked()
{
    int nums=ui->lineEdit_6->text().toInt();
    int montant=ui->lineEdit_7->text().toInt();

 Salaire S(nums, montant);
 bool test=S.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajouté avec succes.");
     ui->tableView_2->setModel(S.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    Salaire S1; S1.setnums(ui->lineEdit_9->text().toInt());
    bool test=S1.supprimer(S1.getnums());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimé avec succes.");
    ui->tableView_2->setModel(S1.afficher());

    }
    else
        msgBox.setText("Echec de la suppression");
         msgBox.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    int nums = ui->lineEdit_10->text().toInt();
    int montant = ui->lineEdit_11->text().toInt();

    Salaire S(nums, montant);
    bool test=S.modifier(nums, montant);
    QMessageBox msgBox;
        if(test)
           {
         ui->tableView_2->setModel(S.afficher());
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("Salaire modifié !"))
                                 );
        }
        else
            QMessageBox::information(this, tr("Done"),
                                                  QString(tr("echec"))
                                                  );                msgBox.exec();
}
