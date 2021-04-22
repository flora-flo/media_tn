#include "connexion.h"
#include <QDebug>


Connexion::Connexion(){}

bool Connexion::ouvrirConnexion()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");
db.setUserName("system");//inserer nom de l'utilisateur mela aandek mochkla fel connexion déja ena hasit khater bizarre hedhom lkol
db.setPassword("a");//inserer mot de passe de cet utilisateur

if (db.open()) test = true;


return test;

}
void Connexion::fermerConnexion()
{db.close();}
