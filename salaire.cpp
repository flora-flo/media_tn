#include "salaire.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Salaire::Salaire()
{
 montant=0; nums=0;
}

    Salaire::Salaire(int nums,int montant)
    {this->nums=nums; this->montant=montant;}
    int Salaire::getnums(){return nums;}
    int Salaire::getmontant(){return  montant;}
    void Salaire::setnums(int nums){this->nums=nums;}
    void Salaire::setmontant(int montant){this->montant=montant;}

    bool Salaire::ajouter()
    {

        QSqlQuery query;
      QString nums_string= QString::number(nums);
      QString montant_string= QString::number(montant);
             query.prepare("INSERT INTO salaire (nums,montant) "
                           "VALUES (:nums, :montant)");
             query.bindValue(":nums",nums_string);
             query.bindValue(":montant", montant_string);
            return query.exec();

    }
    bool Salaire::supprimer(int nums)
    {
        QSqlQuery query;
             query.prepare(" Delete from salaire where nums=:nums");
             query.bindValue(0, nums);

            return query.exec();


    }

    QSqlQueryModel* Salaire::afficher()
    {
      QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT* FROM salaire");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMS"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT"));


      return  model;
    }
    bool Salaire::modifier(int nums,int montant)
    {
        QSqlQuery query;
        query.prepare("UPDATE salaire SET montant=:montant WHERE nums=:nums");
        QString res= QString::number(nums);
        QString ress= QString::number(montant);
        query.bindValue(":nums",res);
        query.bindValue(":montant",ress);
        return query.exec();

    }


    QSqlQueryModel *Salaire::trierup(int test)
    {
        QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel();

        if (test == 0) {
          query.prepare(" SELECT * FROM salaire ORDER BY nums asc; ");
          query.exec();
          model->setQuery(query);
        }

        if (test == 1) {
          query.prepare(" SELECT * FROM salaire ORDER BY montant asc; ");
          query.exec();
          model->setQuery(query);
        }


        return model;
    }

    QSqlQueryModel *Salaire::trier_down(int test) {
        QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel();

        if (test == 0) {
          query.prepare(" SELECT * FROM salaire ORDER BY nums desc; ");
          query.exec();
          model->setQuery(query);
        }

        if (test == 1) {
          query.prepare(" SELECT * FROM salaire ORDER BY montant desc; ");
          query.exec();
          model->setQuery(query);
        }


        return model;
      }
