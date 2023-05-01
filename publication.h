#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QDate>
#include <QDateTime>

class Publication
{
private :
    int id_pub ;
    QDate date_pub ;
    QString type_pub ;
    QString desc_pub ;
    int estFavoris ;

public:
    QSqlQueryModel * setnom();
    Publication();
    Publication(int id, QDate date,  QString type,  QString desc);
    Publication( QDate date,  QString type,  QString desc);
    Publication(QString type,  QString desc);
    int getIdPub() {
        return id_pub;
    }

    void setIdPub(int id) {
        id_pub = id;
    }

    QDate getDatePub() {
        return date_pub;
    }

    void setDatePub(QDate date) {
        date_pub = date;
    }

    QString getTypePub() {
        return type_pub;
    }

    void setTypePub( QString type) {
        type_pub = type;
    }

    QString getDescPub()  {
        return desc_pub;
    }

    void setDescPub( QString desc) {
        desc_pub = desc;
    }
    bool ajouter();
     bool ajouterhistorique(QString);
     QSqlQueryModel* afficherhistorique();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherFavoris();
    bool modifier();
    QSqlQueryModel* rechercher(QString rech);
    QSqlQueryModel* trier(QString champ, QString ordre);
    bool ajouterfavoris(int id_pub);
    bool retirerfavoris(int id_pub);
};

#endif // PUBLICATION_H
