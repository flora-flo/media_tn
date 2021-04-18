#ifndef PREFERENCE_H
#define PREFERENCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class preference
{
public:
    preference();
    preference(int,QString);
     int get_id();
    QString getnom();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
private:
    QString nom;
    int id;
};

#endif // PREFERENCE_H
