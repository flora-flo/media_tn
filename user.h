#ifndef USER_H
#define USER_H
#include <QString>

class user
{
    QString NomUtilisateur;
     QString MotDePasse;
public :

     user();
     user(QString, long);

     QString getnom();
     QString getpass();
};

#endif // USER_H
