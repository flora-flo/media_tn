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
    int identifiant,telephone,salaire;

public:
    //constructeurs
    employe(){};
    employe(int,QString, QString,int,QString,QString);

    //getters

    int GetIdentifiant(){return identifiant;}
    void SetIdentifiant(int idE){identifiant=idE;}


    //fonctions
    bool ajouterEmploye();
    bool supprimerEmploye();
    bool rechercherEmploye();
    bool modifierEmploye();
    int verification_employe();


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
