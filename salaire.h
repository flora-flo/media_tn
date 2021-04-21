#ifndef SALAIRE_H
#define SALAIRE_H
#include <QSqlQueryModel>

class Salaire
{
public:
    Salaire();
    Salaire(int,int);
    int getnums();
    int getmontant();//les constructeur get et set
    void setnums(int);
    void setmontant(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int);
     QSqlQueryModel * recherche(int  , int );
     QSqlQueryModel *  trierup(int);
     QSqlQueryModel *  trier_down(int);
private:

     int nums, montant;
};
#endif // SALAIRE_H
