#include "employe.h"

using namespace std;

employe::employe(int identifiant,QString nom,QString prenom,int telephone,QString mail,QString sexe)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->prenom=prenom;
    this->telephone=telephone;
    this->mail=mail;
    this->sexe=sexe;
}

bool employe::ajouterEmploye()
{

    QSqlQuery query;
    QString res= QString::number(identifiant);
    query.prepare("INSERT INTO CATEGORIE(IDENTIFIANT, NOM, PRENOM, TELEPHONE,MAIL,SEXE)"
                 "VALUES (:IDENTIFIANT, :NOM, :PRENOM, :TELEPHONE, :MAIL,:SEXE)");
    query.bindValue(":IDENTIFIANT", res);
    query.bindValue(":NOM",this->nom);
    query.bindValue(":PRENOM", this->prenom);
    query.bindValue(":TELEPHONE", this->telephone);
    query.bindValue(":MAIL", this->mail);
    query.bindValue(":SEXE", this->sexe);

    return    query.exec();
}

QSqlQueryModel * employe::afficherEmploye()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EMPLOYE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));


    return model;
}

bool employe::supprimerEmploye()
{
    QSqlQuery query;
    QString id=QString::number(identifiant);

    query.prepare("Delete from employe where IDENTIFIANT= :identifiant");
    query.bindValue(":IDENTIFIANT", id);

    return query.exec();
}


bool employe::modifierEmploye()
{
    QSqlQuery query;
    QString idm=QString::number(identifiant);

    query.prepare("Update EMPLOYE set nom=:nom,prenom=:prenom,telephone=:telephone,mail=:mail,sexe=:sexe where identifiant=:idEmploye");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":identifiant",idm);
    query.bindValue(":telephone",telephone);
    query.bindValue(":mail",mail);
    query.bindValue(":sexe",sexe);

    return query.exec();
}

bool employe::rechercherEmploye()//recherche modification
{
    QSqlQuery query;
    query.prepare("Select * from EMPLOYE where identifiant=:idEmploye");
    query.bindValue(":idEmploye",identifiant);
    query.exec();

    if (query.next())
    {
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        identifiant=(query.value(2).toInt());
        telephone=(query.value(3).toInt());
        mail=(query.value(4).toString());
        sexe=(query.value(5).toString());
    }
    return query.exec();
}

QSqlQueryModel * employe::trierEmployeParNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from EMPLOYÉ order by nom ASC ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * employe::trierEmployeParID()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from EMPLOYÉ order by identifiant ASC ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * employe::trierEmployeParCin()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from EMPLOYÉ order by identifiant ASC ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));


    return model;
}


bool employe::chercherParNom()
{

    QSqlQuery query;
    query.prepare("Select * from EMPLOYÉ where nom=:nom");
    query.bindValue(":nom",nom);
    query.exec();

    if (query.next())
    {
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        identifiant=(query.value(2).toInt());
        telephone=(query.value(3).toInt());
        mail=(query.value(4).toString());
        sexe=(query.value(5).toString());
    }
    return query.exec();
}


bool employe::chercherParCin()
{
    QSqlQuery query;
    query.prepare("Select * from EMPLOYÉ where identifiant=:identifiant");
    query.bindValue(":identifiant",identifiant);
    query.exec();

    if (query.next())
    {
        identifiant=(query.value(0).toInt());
       nom=(query.value(1).toString());
       prenom=(query.value(2).toString());
       telephone=(query.value(3).toInt());
       mail=(query.value(4).toString());
       sexe=(query.value(5).toString());
    }
    return query.exec();
}


int employe::verification_employe()
{
    QSqlQuery query;


    query.prepare("select * from machine where identifiant=:identifiant");
    query.bindValue(":identifiant",this->identifiant);
    query.exec();

    int count_user = 0;
    while (query.next())
    {
         identifiant=(query.value(0).toInt());
        nom=(query.value(1).toString());
        prenom=(query.value(2).toString());
        telephone=(query.value(3).toInt());
        mail=(query.value(4).toString());
        sexe=(query.value(5).toString());
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
