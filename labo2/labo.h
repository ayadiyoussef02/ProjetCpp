#ifndef LABO_H
#define LABO_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class labo
{
public:


    QSqlQueryModel * setid();
    bool ajouter();
    bool supprimer(int );
    bool modifier();
    QSqlQueryModel * afficher() ;
    labo();
    labo(int , QString , int, QString, QString);

private:
    int ID_LABO;
    QString NOM_LABO ;
    int NTEL_LABO;
    QString SPECIALITE ;
    QString ADRESSE ;
};

#endif // LABO_H
