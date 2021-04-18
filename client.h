#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,QString,int,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_preference();
    int get_num();
    QString get_date();
    QString get_adresse();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(const QString &arg1);
        QSqlQueryModel * trierid();
        QSqlQueryModel * triernom();
private:
    QString nom,prenom,preference,date,adresse;
    int num;
};
#endif // CLIENT_H
