#ifndef PRIME_H
#define PRIME_H
#include <QString>
#include <QSqlQueryModel>
class Prime
{
public:
    Prime();
    Prime(QString,int,int);
    QString getnom();
    int getnump();//les constructeur get et set
    int getvaleur();
    void setnom(QString);
    void setnump(int);
    void setvaleur(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(QString,int,int);
     QSqlQueryModel * recherche(int  , QString );
     QSqlQueryModel *  trierup(int);
     QSqlQueryModel *  trier_down(int);
private:
    QString nom;
     int nump, valeur;
};

#endif // PRIME_H
