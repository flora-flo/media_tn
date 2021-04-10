#include "user.h"


#include <QString>
user::user()
{
    NomUtilisateur="flora";
    MotDePasse="1234";

}
/*
user::user(QString NomUtilisateur, long MotDePasse)
{
 NomUtilisateur="flora";
 MotDePasse=1234;

} */
QString user::getnom(){return NomUtilisateur;}
QString user::getpass(){return MotDePasse;}



