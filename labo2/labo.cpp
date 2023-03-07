#include "labo.h"

labo::labo()
{

}

labo::labo(int a, QString b, int c, QString d , QString e){

    ID_LABO=a;
    NOM_LABO=b;
     NTEL_LABO=c;
     SPECIALITE=d ;
     ADRESSE=e ;


}

bool labo::ajouter(){
    QSqlQuery query;
    QString res = QString::number(ID_LABO);

    query.prepare("insert into LABO(ID_LABO,NOM_LABO,NTEL_LABO,SPECIALITE,ADRESSE)""values(:ID_LABO,:NOM_LABO,:NTEL_LABO,:SPECIALITE,:ADRESSE)");

    query.bindValue(":ID_LABO",ID_LABO);
    query.bindValue(":NOM_LABO",NOM_LABO);
    query.bindValue(":NTEL_LABO",NTEL_LABO);
    query.bindValue(":SPECIALITE",SPECIALITE);
    query.bindValue(":ADRESSE",ADRESSE);


    return query.exec();


}

QSqlQueryModel * labo::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from LABO ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_LABO"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_LABO"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NTEL_LABO"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("SPECIALITE"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));


     return  model;

}


bool labo::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("delete from LABO where ID_LABO= :ID_LABO");
    query.bindValue(":ID_LABO",res);

    return query.exec();

}


QSqlQueryModel * labo::setid()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT ID_LABO from LABO");
     model->setHeaderData(0,Qt::Horizontal,"ID_LABO");

     return model;
 }
bool labo::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE LABO SET  NOM_LABO=:NOM_LABO , NTEL_LABO=:NTEL_LABO , SPECIALITE=:SPECIALITE , ADRESSE=:ADRESSE where ID_LABO=:ID_LABO ");

    query.bindValue(":ID_LABO",ID_LABO);
    query.bindValue(":NOM_LABO",NOM_LABO);
    query.bindValue(":NTEL_LABO",NTEL_LABO);
    query.bindValue(":SPECIALITE",SPECIALITE);
    query.bindValue(":ADRESSE",ADRESSE);
    return    query.exec();
}
