#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QDate>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtCharts>


class Employee
{
private:
    QString cin_e , nom_e , prenom_e,num_tel_e,sexe_e,email_e,mtp_e,adresse_e,type_e;
    QDate date_n_e;
public:
    //Constructeur-destructeur
    Employee();
    Employee(QString,QString,QString,QString,QString,QString,QString,QDate,QString,QString);
    ~Employee(){};

    //Getters
        QString getcin_e(){return cin_e;}
        QString getnom_e(){return nom_e;}
        QString getprenom_e(){return prenom_e;}
        QString getnum_tel_e(){return num_tel_e;}
        QString getsexe_e(){return sexe_e;}
        QString getemail_e(){return email_e;}
        QString getmtp_e(){return mtp_e;}
        QDate getdate_n_e(){return date_n_e;}
        QString getadresse_e(){return adresse_e;}
        QString gettype_e(){return type_e;}

     //Setters
         void setcin_e(QString c){cin_e=c;}
         void setnom_e(QString n){nom_e=n;}
         void setprenom_e(QString p){prenom_e=p;}
         void setnum_tel_e(QString nu){num_tel_e=nu;}
         void setsexe_e(QString s){sexe_e=s;}
         void setemail_e(QString e){email_e=e;}
         void setmtp_e(QString m){mtp_e=m;}
         void setdate_n_e(QDate d){date_n_e=d;}
         void setadresse_e(QString a){adresse_e=a;}
         void settype_e(QString t){type_e=t;}

         //fct
             bool ajouter();
             QSqlQueryModel * afficher();
             bool supprimer(QString);
             bool modifier(QString);


             QSqlQueryModel * Tri_pardefaut();
             QSqlQueryModel * Tri_nom();
             QSqlQueryModel * Tri_dateN();
             QSqlQueryModel * Tri_sexe();

             QSqlQueryModel *rechercher_nom(QString nom);

             QString  export_pdf();

             QChart *stat();




};

#endif // EMPLOYEE_H
