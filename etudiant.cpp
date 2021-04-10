#include "etudiant.h"
#include <QDebug>
#include "connexion.h"
Etudiant::Etudiant()
{
id=0;
nom="";
prenom="";
}
Etudiant::Etudiant(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}
QString Etudiant::get_nom(){return  nom;}
QString Etudiant::get_prenom(){return prenom;}
int Etudiant::get_id(){return  id;}

bool Etudiant::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO etudiant (id, nom, prenom) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * Etudiant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool Etudiant::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

