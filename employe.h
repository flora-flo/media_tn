#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QDebug>
#include <QBuffer>
#include <QSqlQuery>
#include <QRegExp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <QStringListModel>
#include <QList>
#include <QListView>
using namespace std;

class employe
{
    QString nom, prenom,mail,sexe;
    int identifiant,telephone;

public:
    //constructeurs
    employe(){};
    employe(int,QString, QString,int,QString,QString);

    //getters

    int GetIdentifiant(){return identifiant;}
    QString GetNom(){return nom;}
    QString GetPrenom(){return prenom;}
    int GetTelephone(){return telephone;}
    QString GetMail(){return mail;}
    QString GetSexe(){return sexe;}

    //setters
    void SetIdentifiant(int idE){identifiant=idE;}
    void SetNom(QString n){nom=n;}
    void SetPrenom(QString pr){prenom=pr;}
    void SetTelephone(int tel){telephone=tel;}
    void SetMail(QString m){mail=m;}
    void SetSexe(QString s){sexe=s;}


    //fonctions
    bool ajouterEmploye();
    bool supprimerEmploye();
    bool maillingEmploye();
    bool modifierEmploye();
    int verification_employe();
    int verifEmploye();
    int verifEmployeParNom();
    int verifEmployeParCin();


    QSqlQueryModel * afficherEmploye();
    QSqlQueryModel * trierEmployeParNom();
    QSqlQueryModel * trierEmployeParID();
    QSqlQueryModel * trierEmployeParCin();

    QSqlQueryModel * chercherParId(int );
    bool chercherParNom();
    bool chercherParCin();
    QSqlQueryModel * afficher_email();


};

#endif // EMPLOYE_H
