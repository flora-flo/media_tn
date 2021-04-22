#include "offre.h"
#include <QDebug>
#include "connexion.h"
offre::offre()
{
idO=0;
nom="";
dateD="";
dateF="";
adresse="";
nomD="";nomS="";
}
 offre::offre(int idO,QString nom,QString dateD,QString dateF,QString adresse,QString nomD,QString nomS )
{
 this->idO=idO;
    this->nom=nom;
    this->dateD=dateD;
    this->dateF=dateF;
    this->adresse=adresse;
    this->nomD=nomD;
    this->nomS=nomS;
}

bool offre::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idO);
    query.prepare("INSERT INTO offree (ID_OFFRE,DATED,DATEF,ADRESSE,NOM_DOMAINE,NOM_OFFRE,NOM_SOCIETE)" "VALUES(:ido, :dated, :datef, :adresse, :nom_domaine, :nom_offre, :nom_societe)");
    query.bindValue(":ido",res);
    query.bindValue(":dated",dateD);
    query.bindValue(":datef",dateF);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nom_domaine",nomD);
    query.bindValue(":nom_offre",nom);
    query.bindValue(":nom_societe",nomS);

    return query.exec();
}
QSqlQueryModel * offre::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from offree");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date debut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date fin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Domaine"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Offre"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Societe"));

    return model;
}
bool offre::supprimer(int ido)
{
    QSqlQuery query;
    QString res =QString::number(ido);
    query.prepare("Delete from OFFREE where ID_OFFRE = :ido");
    query.bindValue(":ido",res);
    return query.exec();
}



