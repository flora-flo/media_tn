#include "domaine.h"
#include <QDebug>
#include "connexion.h"

domaine::domaine(){
    idD=0;
    NomD="";
}

domaine::domaine(int idD,QString NomD)
{
    this->idD=idD;
    this->NomD=NomD;

}
int domaine::getidD()
{
    return idD;
}
QString domaine::getNomD()
{
    return NomD;
}

bool domaine::ajouter()
{
    QSqlQuery query;



    query.prepare("INSERT INTO domaine (IDD,NOMD)" "VALUES( :idD, :NomD)");
    query.bindValue(":idD",idD);
    query.bindValue(":NomD",NomD);


    return query.exec();
}

QSqlQueryModel * domaine::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from domaine");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idD"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NomD"));

    return model;
}

QSqlQueryModel * domaine::rechercher(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.bindValue(":nombre",arg1);

    model->setQuery("select * from domaine where IDD='"+arg1+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));



        return model;
}

QSqlQueryModel * domaine::trierid()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from domaine ORDER BY IDD ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));




    return model;
}

QSqlQueryModel * domaine::triernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from domaine ORDER BY NOMD ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));




    return model;
}


bool domaine::supprimer(int idD)
{
QSqlQuery query;
QString res= QString::number(idD);
query.prepare("Delete from DOMAINE where IDD = :idD ");
query.bindValue(":idD", res);
return    query.exec();
}
