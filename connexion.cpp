#include "connexion.h"

// DATABSAE ::

QSqlDatabase connect_to_database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("Floflo");
    db.setPassword("merveille1");
    db.open();
    return db;
}

QSqlDatabase database = connect_to_database();
