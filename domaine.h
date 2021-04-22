#ifndef DOMAINE_H
#define DOMAINE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class domaine
{  QString NomD;
    int idD ;
public:
    domaine();
    domaine(int,QString);

    int getidD();
    QString getNomD();

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(const QString &arg1);
        QSqlQueryModel * trierid();
        QSqlQueryModel * triernom();

};

#endif // DOMAINE_H
