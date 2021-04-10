#include "categorie.h"

categorie::categorie()
{

}

categorie::categorie(int identifiant, QString nom, QString poste, int salaire)
{

    this->identifiant=identifiant;
        this->nom=nom;
        this->poste=poste;
        this->salaire=salaire;
}
bool categorie::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO CATEGORIE(ID, NOM, POSTE, SALAIRE)"
             "VALUES (:ID, :NOM, :POSTE, :SALAIRE)");
query.bindValue(":ID", res);
query.bindValue(":NOM", nom);
query.bindValue(":POSTE", poste);
query.bindValue(":SALAIRE", salaire);

return    query.exec();
}


QSqlQueryModel * categorie::afficher()
{
   QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CATEGORIE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));

   return model;
}

bool categorie::supprimer(int identifiant)
{

QSqlQuery query;
query.prepare("Delete from CATEGORIE where ID = :identifiant");
query.bindValue(":identifiant", identifiant);
return    query.exec();



}

bool categorie::modifier()
{
       QSqlQuery query;



          //QString res= QString::number(identifiant);
          query.prepare("UPDATE CATEGORIE SET NOM=:nom,POSTE=:poste,SALAIRE=:salaire WHERE ID=:identifiant");
          query.bindValue(":identifiant", identifiant);
          query.bindValue(":NOM", nom);
          query.bindValue(":POSTE", poste);
          query.bindValue(":SALAIRE", salaire);

             return    query.exec();

}



int categorie::verificationCategorie()
{
    QSqlQuery query;

    query.prepare("select * from CATEGORIE where ID=:identifiant");
    query.bindValue(":identifiant",this->identifiant);
    query.exec();

    int count_user = 0;
    while (query.next())
    {
        identifiant=(query.value(0).toInt());
        nom=(query.value(1).toString());
        poste=(query.value(2).toString());
        salaire=(query.value(3).toInt());
        count_user++;
    }
    if (count_user==1)
    {
        return 0;
    }
    else if(count_user > 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


int categorie::verificationCategorieN()
{
    QSqlQuery query;

    query.prepare("select * from CATEGORIE where NOM=:nom");
    query.bindValue(":nom",this->nom);
    query.exec();

    int count_user = 0;
    while (query.next())
    {
        identifiant=(query.value(0).toInt());
        nom=(query.value(1).toString());
        poste=(query.value(2).toString());
        salaire=(query.value(3).toInt());
        count_user++;
    }
    if (count_user==1)
    {
        return 0;
    }
    else if(count_user > 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int categorie::verificationCategorieS()
{
    QSqlQuery query;

    query.prepare("select * from CATEGORIE where SALAIRE=:salaire");
    query.bindValue(":salaire",this->salaire);
    query.exec();

    int count_user = 0;
    while (query.next())
    {
        identifiant=(query.value(0).toInt());
        nom=(query.value(1).toString());
        poste=(query.value(2).toString());
        salaire=(query.value(3).toInt());
        count_user++;
    }
    if (count_user==1)
    {
        return 0;
    }
    else if(count_user > 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}



QSqlQueryModel * categorie::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from CATEGORIE order by nom ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));

   return model;
}

QSqlQueryModel * categorie::trier_ID()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from CATEGORIE order by id ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));

   return model;
}

QSqlQueryModel * categorie::trier_salaire()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from CATEGORIE order by salaire ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));

   return model;
}



QSqlQueryModel * categorie::chercher(QString id)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;

query.prepare("select * from CATEGORIE where NOM=:nom");
query.bindValue(":nom", nom);

query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));


return model;

}


QSqlQueryModel * categorie::chercherID(int id)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;

query.prepare("select * from CATEGORIE where ID=:identifiant");
query.bindValue(":identifiant", id);

query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));


return model;

}

QSqlQueryModel * categorie::chercherSalaire(int salaire)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;

query.prepare("select * from CATEGORIE where SALAIRE=:salaire");
query.bindValue(":salaire", salaire);

query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));


return model;

}
