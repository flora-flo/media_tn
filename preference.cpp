#include "preference.h"
#include <QDebug>
#include "connexion.h"

preference::preference()
{

}
preference::preference(int id,QString nom)
{
    this->id=id;
    this->nom=nom;

}
int preference::get_id()
{
    return id;
}
QString preference::getnom()
{
    return nom;
}


bool preference::ajouter()
{
    QSqlQuery query;

    QString res1= QString::number(id);

    query.prepare("INSERT INTO PREFERENCE (ID,NOM)" "VALUES( :id, :nom)");
    query.bindValue(":id",res1);
    query.bindValue(":nom",nom);

    return query.exec();
}

QSqlQueryModel * preference::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from preference");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));

    return model;
}


bool preference::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from PREFERENCE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


