#ifndef CHERCHEUR_H
#define CHERCHEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QtCharts>


class chercheur
{ QString cin_chercheur, nom_ch, prenom_ch, num_tel_ch;
    QDate date_i_ch;
    QString type_ch,sexe_ch,date_r ;
public:
    //constructeur
    chercheur(){}
    chercheur(QString,QString,QString,QString,QDate,QString,QString,QString);

    //Getters
    QString getcin_chercheur(){return cin_chercheur;}
    QString getnom_ch(){return nom_ch;}
    QString getprenom_ch(){return prenom_ch;}
    QString getnum_tel_ch(){return num_tel_ch;}

    QDate getdate_i_ch(){return date_i_ch;}
    QString gettype_ch(){return type_ch;}
    QString getsexe_ch(){return sexe_ch;}
     QString getdate_r(){return date_r;}

    //setters
    void setcin_chercheur(QString c){cin_chercheur=c;}
    void setnom_ch(QString n){nom_ch=n;}
    void setprenom_ch(QString p){prenom_ch=p;}
    void setnum_tel_ch(QString t){num_tel_ch=t;}

    void setdate_i_ch(QDate d){date_i_ch=d;}
    void settype_ch(QString y){type_ch=y;}
    void setsexe_ch(QString s){sexe_ch=s;}
    void setdate_r(QString r){date_r=r;}


    //fonctionnalités de base relatives a l'entité etudiant
    bool ajouter();
    QSqlQueryModel * afficher() ;
     QSqlQueryModel * afficherh(QString) ;
    bool supprimer(QString);
    bool modifier(QString );
    QSqlQueryModel * notification(QString datee) ;
    QSqlQueryModel * Tri_nom();
    QSqlQueryModel * Tri_dateI();
    QSqlQueryModel * Tri_sexe();
    QSqlQueryModel *rechercher_nom(QString nom);

    QChart *stat();



};

#endif // CHERCHEUR_H
