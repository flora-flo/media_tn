#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("module_finance");
db.setUserName("Boris");//inserer nom de l'utilisateur
db.setPassword("motdepasse");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

qDebug()<<db.lastError().text();



    return  test;
}
