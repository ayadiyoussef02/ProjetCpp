#include "employee.h"
#include <QtDebug>
#include <QObject>


Employee::Employee()
{
    cin_e="";
    nom_e="";
    prenom_e="";
    num_tel_e="";
    sexe_e="";
    email_e="";
    mtp_e="";
    adresse_e="";
    date_n_e=QDate::currentDate();
    type_e="";

}

Employee::Employee(QString cin_e,QString nom_e,QString prenom_e,QString num_tel_e,QString sexe_e,QString email_e,QString mtp_e,QString adresse_e,QDate date_n_e,QString type_e)
{
        this->cin_e=cin_e;
        this->nom_e=nom_e;
        this->prenom_e=prenom_e;
        this->num_tel_e=num_tel_e;
        this->sexe_e=sexe_e;
        this->email_e=email_e;
        this->mtp_e=mtp_e;
        this->adresse_e=adresse_e;
        this->date_n_e=date_n_e;
        this->type_e=type_e;
}

bool Employee::ajouter()
{
   QSqlQuery Q1;
   Q1.prepare("insert into EMPLOYER(cin_e,nom_e,prenom_e,num_tel_e,sexe_e,email_e,mtp_e,date_n_e,adresse_e,type_e)" "values(:cin_e,:nom_e,:prenom_e,:num_tel_e,:sexe_e,:email_e,:mtp_e,:date_n_e,:adresse_e,:type_e)");
   Q1.bindValue(":cin_e",cin_e);
   Q1.bindValue(":nom_e",nom_e);
   Q1.bindValue(":prenom_e",prenom_e);
   Q1.bindValue(":num_tel_e",num_tel_e);
   Q1.bindValue(":sexe_e",sexe_e);
   Q1.bindValue(":email_e",email_e);
   Q1.bindValue(":mtp_e",mtp_e);
   Q1.bindValue(":date_n_e",date_n_e);
   Q1.bindValue(":adresse_e",adresse_e);
   Q1.bindValue(":type_e",type_e);
   return Q1.exec();
}


bool Employee::supprimer(QString cin_e)
{
    QSqlQuery Q1;
        Q1.prepare("Delete from EMPLOYER where cin_e=:cin_e");
        Q1.bindValue(":cin_e",cin_e);

    return Q1.exec();


}



bool Employee::modifier(QString cin_e)
{
    QSqlQuery Q1;
    Q1.prepare("UPDATE EMPLOYER set nom_e=:nom_e,prenom_e=:prenom_e,num_tel_e=:num_tel_e,sexe_e=:sexe_e,email_e=:email_e,mtp_e=:mtp_e,date_n_e=:date_n_e,adresse_e=:adresse_e,type_e=:type_e where cin_e=:cin_e");

    Q1.bindValue(":cin_e",cin_e);
    Q1.bindValue(":nom_e",nom_e);
    Q1.bindValue(":prenom_e",prenom_e);
    Q1.bindValue(":num_tel_e",num_tel_e);
    Q1.bindValue(":sexe_e",sexe_e);
    Q1.bindValue(":email_e",email_e);
    Q1.bindValue(":mtp_e",mtp_e);
    Q1.bindValue(":date_n_e",date_n_e);
    Q1.bindValue(":adresse_e",adresse_e);
    Q1.bindValue(":type_e",type_e);


    return Q1.exec();

}





QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYER");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin_e"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom_e"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom_e"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("num_tel_e"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("sexe_e"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("email_e"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("mtp_e"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("date_n_e"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("adresse_e"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("type_e"));
    return model;
}


QSqlQueryModel * Employee::Tri_nom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYER ORDER BY nom_e");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin_e"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom_e"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom_e"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("num_tel_e"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("sexe_e"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("email_e"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("mtp_e"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("date_n_e"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("adresse_e"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("type_e"));
    return model;
}


QSqlQueryModel * Employee::Tri_dateN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYER ORDER BY date_n_e");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin_e"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom_e"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom_e"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("num_tel_e"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("sexe_e"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("email_e"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("mtp_e"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("date_n_e"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("adresse_e"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("type_e"));
    return model;
}

QSqlQueryModel * Employee::rechercher(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT * FROM EMPLOYER where nom_e like '"+nom+"%' ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}



