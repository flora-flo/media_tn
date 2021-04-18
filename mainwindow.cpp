#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "preference.h"
#include <QSqlQuery>
#include "QTextDocument "
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    ui->tabclient->setModel(tmpclient.afficher());//refresh
}

void MainWindow::on_pushButton_21_clicked()
{
    QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        QString mail=ui->lineEdit_email->text();
        int num=ui->lineEdit_numerocompte->text().toInt();
        QString date=ui->lineEdit_date->text();
        QString adresse=ui->lineEdit_adresse->text();
        Client c (nom,prenom,mail,num,date,adresse);

        int erreur=0;
        if(ui->lineEdit_nom->text().isEmpty())
        {
            ui->lineEdit_nom->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_prenom->setStyleSheet("");}
        if(ui->lineEdit_prenom->text().isEmpty())
        {
            ui->lineEdit_prenom->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_email->setStyleSheet("");}
        if(ui->lineEdit_email->text().isEmpty())
        {
            ui->lineEdit_email->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_numerocompte->setStyleSheet("");}
        if(ui->lineEdit_numerocompte->text().isEmpty())
        {
            ui->lineEdit_numerocompte->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_date->setStyleSheet("");}
        if(ui->lineEdit_date->text().isEmpty())
        {
            ui->lineEdit_date->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_date ->setStyleSheet("");}
        if(ui->lineEdit_adresse->text().isEmpty())
        {
            ui->lineEdit_adresse->setStyleSheet("border: 2px solid red;");
            erreur=1;
        }
        else {ui->lineEdit_adresse->setStyleSheet("");}
        if (erreur)
        {
            QMessageBox::warning(nullptr, QObject::tr("ERREUR d'ajout"),
                              QObject::tr("Vérifiez vos champs.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
       else if(!erreur)
        {
            bool test=c.ajouter();


   if((test) && (!erreur))
{

ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
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
  //  ui->CRUD_2->setCurrentIndex(1);
    ui->CRUD_2->setCurrentIndex(2);
    ui->tabpreference->setModel(tmppreference.afficher());//refresh
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->CRUD_2->setCurrentIndex(4);

}

void MainWindow::on_pushButton_17_clicked()
{
   // ui->CRUD_2->setCurrentIndex(2);
    //ui->tab_credit->setModel(tmpcredit.afficher());//refresh
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
    int reff = ui->lineEdit_2->text().toInt();
    bool test=tmpclient.supprimer(reff);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_5_clicked()
{
       QString nom=ui->lineEdit_montant_4->text();
       int id=ui->lineEditnom_5->text().toFloat();
       preference cr (id,nom);
       bool test=cr.ajouter();

  if(test)
{

ui->tabpreference->setModel(tmppreference.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une préference"),
                  QObject::tr("préference ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une préference"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
    bool test=tmppreference.supprimer(id);
    if(test)
    {ui->tabpreference->setModel(tmppreference.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une préference"),
                    QObject::tr("préference supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une préference"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_23_clicked()
{
    QSqlQuery query;


    QString nom=ui->lineEdit_nom5->text();
        QString prenom=ui->lineEdit_prenom5->text();
        QString mail=ui->lineEdit_mail5->text();
        int num=ui->lineEdit_numerocompte5->text().toInt();
        QString date=ui->lineEdit_date5->text();
        QString adresse=ui->lineEdit_adresse5->text();
        QString res= QString::number(num);

            query.prepare("update CLIENT set Nom=:nom ,PRENOM=:prenom ,MAIL=:mail , NUM=:num, DATEE=:date ,ADRESSE=:adresse WHERE NUM =:num");
            query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
            query.bindValue(":mail",mail);
            query.bindValue(":num",res);
            query.bindValue(":date",date);
            query.bindValue(":adresse",adresse);

            bool t=query.exec();
                   if(t)
                   {
                       ui->tabclient->setModel(tmpclient.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Promotion modifié.\n"
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
    QString nom=ui->lineEditnom_3->text();
    int id=ui->lineEditid_2->text().toInt();

    preference cr (id,nom);

            query.prepare("update preference set NOM=:nom WHERE ID =:id");
            query.bindValue(":id",id);
            query.bindValue(":nom",nom);


            bool t=query.exec();
                   if(t)
                   {
                       ui->tabpreference->setModel(tmppreference.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Credit modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}








void MainWindow::on_imprimer_clicked()
{
    /* QPrinter printer;
                      QString doc;

                      printer.setPrinterName("printer1");
                      QPrintDialog print_dialog(&printer,this);
                     if(print_dialog.exec()== QDialog::Rejected) return ;

                       ui->text_id-> */


                QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabclient->model()->rowCount();
                const int columnCount = ui->tabclient->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "  <h1>Gestion des clients PDF</h1>"
                          "<body bgcolor=#7ebbbd  link=#5000A0>\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

                // headers
                out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabclient->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabclient->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabclient->isColumnHidden(column)) {
                            QString data = ui->tabclient->model()->data(ui->tabclient->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                        "</body>\n"
                        "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
    }


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1=="Cin")
        {
            ui->tabclient->setModel(tmpclient.trierid());
        }
        else if(arg1=="Nom")
        {
            ui->tabclient->setModel(tmpclient.triernom());
        }
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
      ui->tabclient->setModel(tmpclient.rechercher(arg1));
}
