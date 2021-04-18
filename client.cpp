#include "client.h"
#include <QDebug>
#include "connexion.h"

Client::Client()
{
nom="";
prenom="";
adresse="";
num=0;
preference="";
adresse="";
}
Client::Client(QString nom,QString prenom,QString preference,int num ,QString date,QString adresse)
{
    this->nom=nom;
    this->prenom=prenom;
    this->preference=preference;
    this->num=num;
    this->date=date;
    this->adresse=adresse;
}
QString Client::get_nom()
{
    return nom;
}
QString Client::get_prenom()
{
    return prenom;
}
QString Client::get_preference()
{
    return preference;
}
int Client::get_num()
{
    return num;
}
QString Client::get_date()
{
    return date;
}
QString Client::get_adresse()
{
    return adresse;
}

bool Client::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("INSERT INTO CLIENT (NOM,PRENOM,MAIL,NUM,DATEE,ADRESSE)" "VALUES(:nom, :prenom, :mail, :num, :date, :adresse)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",preference);
    query.bindValue(":num",res);
    query.bindValue(":date",date);
    query.bindValue(":adresse",adresse);
    return query.exec();
}
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Preference"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    return model;
}
bool Client::supprimer(int numm)
{
    QSqlQuery query;
    QString res =QString::number(numm);
    query.prepare("Delete from CLIENT where NUM = :numm");
    query.bindValue(":numm",res);
    return query.exec();
}
QSqlQueryModel * Client::rechercher(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.bindValue(":nombre",arg1);

    model->setQuery("select * from client where NUM='"+arg1+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Num de tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Mdp"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Departement"));


        return model;
}

QSqlQueryModel * Client::trierid()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from client ORDER BY NUM ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Num de tel"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("mdp"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("departement"));



    return model;
}

QSqlQueryModel * Client::triernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from client ORDER BY nom ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Num de tel"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("mdp"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("departement"));



    return model;
}




