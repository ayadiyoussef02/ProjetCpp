#ifndef LABO_H
#define LABO_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class labo
{
public:


    QSqlQueryModel * setid();
    QSqlQueryModel * setnom();
    QSqlQueryModel *sette();
    bool ajouter();
    bool supprimer(int );
    bool modifier();
    bool modifiert();
    QSqlQueryModel * afficher() ;
    QSqlQueryModel * afficher5(QString a);
    QSqlQueryModel * afficher4(QString a,QString b);
    labo();
    labo(int , QString , QString, QString, QString,QString);

private:
    int ID_LABO;
    QString NOM_LABO ;
    QString NTEL_LABO;
    QString SPECIALITE ;
    QString ADRESSE ;
    QString VIDEO;
    QString TEMP ;
};

#endif // LABO_H
