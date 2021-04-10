#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QBuffer>
#include <QSqlQuery>
#include <cstdlib>
#include <iostream>

class categorie
{
public:
    categorie();

    categorie(int, QString, QString, int);


           int get_identifiant(){return identifiant;}
            QString get_nom(){return nom;}
            QString get_poste(){return poste;}
            int get_salaire(){return salaire;}


            void setID(int n){identifiant=n;}
            void setNom(QString n){nom=n;};
            void setposte(QString n){poste=n;}
            void setsalaire(int n){salaire=n;}


            bool ajouter();
            bool modifier();
            QSqlQueryModel * afficher();
            bool supprimer(int);
            QSqlQueryModel * trier_nom();
            QSqlQueryModel * trier_ID();
            QSqlQueryModel * trier_salaire();
            QSqlQueryModel * chercher(QString);
            QSqlQueryModel * chercherID(int);
            QSqlQueryModel * chercherSalaire(int);
            int verificationCategorie();
            int verificationCategorieN();
            int verificationCategorieS();

    private:
        int identifiant, salaire;
        QString nom,poste;
};

#endif // CATEGORIE_H
