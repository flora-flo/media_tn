#include "prime.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Prime::Prime()
{
nump=0; nom=" "; valeur=0;
}

Prime::Prime(QString nom,int nump,int valeur)
{this->nom=nom; this->nump=nump; this->valeur=valeur;}
QString Prime::getnom(){return  nom;}
int Prime::getnump(){return nump;}
int Prime::getvaleur(){return valeur;}
void Prime::setnom(QString nom){this->nom=nom;}
void Prime::setnump(int nump){this->nump=nump;}
void Prime::setvaleur(int valeur){this->valeur=valeur;}
bool Prime::ajouter()
{

    QSqlQuery query;
  QString nump_string= QString::number(nump);
  QString valeur_string= QString::number(valeur);
         query.prepare("INSERT INTO prime (nom, nump, valeur) "
                       "VALUES (:forename, :nump, :valeur)");
         query.bindValue(":forename", nom);
         query.bindValue(":nump",nump_string);
         query.bindValue(":valeur", valeur_string);
        return query.exec();

}
bool Prime::supprimer(int nump)
{
    QSqlQuery query;
         query.prepare(" Delete from prime where nump=:nump");
         query.bindValue(0, nump);

        return query.exec();


}
QSqlQueryModel* Prime::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM prime");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMP"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("VALEUR"));


  return  model;
}
bool Prime::modifier(QString nom,int nump,int valeur)
{
    QSqlQuery query;
    query.prepare("UPDATE prime SET nom=:nom,valeur=:valeur WHERE nump=:nump");
    QString res= QString::number(nump);
     QString ress= QString::number(valeur);
      query.bindValue(":nom",nom);
    query.bindValue(":nump",res);
    query.bindValue(":valeur",ress);
    return query.exec();

}


QSqlQueryModel *Prime::trierup(int test)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (test == 0) {
      query.prepare(" SELECT * FROM prime ORDER BY nump asc; ");
      query.exec();
      model->setQuery(query);
    }

    if (test == 1) {
      query.prepare(" SELECT * FROM prime ORDER BY valeur asc; ");
      query.exec();
      model->setQuery(query);
    }


    return model;
}

QSqlQueryModel *Prime::trier_down(int test) {
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (test == 0) {
      query.prepare(" SELECT * FROM prime ORDER BY nump desc; ");
      query.exec();
      model->setQuery(query);
    }

    if (test == 1) {
      query.prepare(" SELECT * FROM prime ORDER BY valeur desc; ");
      query.exec();
      model->setQuery(query);
    }


    return model;
  }

