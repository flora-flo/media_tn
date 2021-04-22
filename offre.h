#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class offre
{    QString nom,adresse,nomD,nomS,dateD,dateF ;
    int idO ;

public:
     offre();
      offre(int,QString,QString,QString,QString,QString,QString);
      QString getNom(){return nom;}
       QString getadresse(){return adresse;}
        QString getnomD(){return nomD;}
         QString getnomS(){return nomS;}
          int getidO(){return idO;}
           QString getdateD(){return dateD;}
            QString getdateF(){return dateF;}
             void setNom(QString n){nom=n;}
              bool ajouter();
               QSqlQueryModel * afficher();
                bool supprimer(int);

};

#endif
