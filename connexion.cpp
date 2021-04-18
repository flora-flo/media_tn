#include "connexion.h"
#include <QDebug>


Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("omar");//inserer nom de l'utilisateur
db.setPassword("omar");//inserer mot de passe de cet utilisateur


if (db.open()) test = true;


return test;

}
void Connexion::fermerConnexion()
{db.close();}
