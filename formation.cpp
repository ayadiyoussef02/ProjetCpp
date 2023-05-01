#include "formation.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery >
#include <QtDebug>
#include <QObject>
#include <QtCharts/QtCharts>
#include <QListView>
#include <QStringListModel>
#include <QtCharts>
#include "stat_combo.h"

using namespace std;

QSqlQueryModel * Formation::setid(){
    QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select DISTINCT ID_FORMA from FORMATIONS");
        model->setHeaderData(0,Qt::Horizontal,"ID_FORMA");

        return model;
}
Formation::Formation()
{
      id_forma=0;
      nom_f="";
      date_d=QDate::currentDate();
      date_f=QDate::currentDate();
       description="";

}

Formation::Formation( int id_forma,QString nom_f,QDate date_d,QDate date_f,QString description)
    {
        this->id_forma=id_forma;
        this->nom_f=nom_f;
        this->date_d=date_d;
        this->date_f=date_f;
        this->description=description;

    }
int Formation::getid_forma() {return id_forma;}
QString Formation::getnom_f() {return nom_f;}
//QString Formation::getdate_d() {return date_d;}
//QString Formation::getdate_f() {return date_f ;}
QDate Formation::getdate_d(){return date_d;}
QDate Formation::getdate_f(){return date_f;}
QString Formation::getdescription() {return description;}
void Formation ::setid_forma(int id_forma) {this->id_forma=id_forma;}
void Formation ::setnom_f(QString nom_f){this->nom_f=nom_f;}
void Formation ::setdate_d(QDate date_d){this->date_d=date_d;}
void Formation ::setdate_f(QDate date_f){this->date_f=date_f;}
void Formation ::setdescription(QString description){this->description=description;}



bool Formation::ajouter()
    {
        //bool test=false;
        QSqlQuery query;
        QString id_string= QString::number(id_forma);
        query.prepare("INSERT INTO FORMATIONS(id_forma, nom_f, date_d,date_f,description) "
                        "VALUES (:id_forma, :nom_f, :date_d, :date_f, :description)");
        query.bindValue(":id_forma", id_string);
        query.bindValue(":nom_f", nom_f);
        query.bindValue( ":date_d",date_d);
        query.bindValue(":date_f",date_f);
        query.bindValue(":description",description);
        return  query.exec();
}

bool Formation::supprimer(int id_forma)
    {
         QSqlQuery query;
         query.prepare(" Delete from FORMATIONS where id_forma=:ID_FORMA") ;
         query.bindValue(":ID_FORMA", id_forma);
         return  query.exec();
    }


QSqlQueryModel* Formation::afficher()
    {
          QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM FORMATIONS");
          model->setHeaderData(0, Qt::Horizontal, QObject ::tr("ID_FORMA"));
          model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_F"));
          model->setHeaderData(2, Qt::Horizontal, QObject:: tr("DATE_D"));
          model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DATE_F"));
          model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DESCRIPTION"));

          return model;
      }

bool Formation::modifier(int id_forma)
    {
    QSqlQuery query;
     QString id_string= QString::number(id_forma);
        query.prepare("UPDATE FORMATIONS SET  nom_f=:NOM_F , date_d=:DATE_D , date_f=:DATE_F , description=:DESCRIPTION where id_forma=:ID_FORMA ");

        query.bindValue(":ID_FORMA",id_string);
        query.bindValue(":NOM_F",nom_f);
        query.bindValue(":DATE_D",date_d);
        query.bindValue(":DATE_F",date_f);
        query.bindValue(":DESCRIPTION",description);
        return    query.exec();
    }
bool Formation::verification(int id_forma)
{

    QSqlQuery query;
    QString n;
    QString  num = QString::number(id_forma);
            query.exec("SELECT ID_FORMA from FORMATIONS");
            while (query.next())
            {
                n=query.value("ID_FORMA").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }

QSqlQueryModel * Formation::afficher_trie_id(){

    QSqlQueryModel*model2=new QSqlQueryModel();

    QSqlQuery query;

    query.prepare("SELECT ID_FORMA, NOM_F, DATE_D, DATE_F, DESCRIPTION FROM FORMATIONS  ORDER BY ID_forma");

    query.exec();
    model2->setQuery(query);
return model2
        ;}


QSqlQueryModel * Formation::afficher_trie_nom(){
    QSqlQueryModel*model2=new QSqlQueryModel();

    QSqlQuery query;

    query.prepare("SELECT ID_FORMA, NOM_F, DATE_D, DATE_F,DESCRIPTION  FROM FORMATIONS  ORDER BY NOM_F");

    query.exec();
    model2->setQuery(query);
return model2
        ;}


QSqlQueryModel* Formation::recherche(QString a)
    {

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT * FROM FORMATIONS where NOM_F like '"+a+"%' ");
    q.addBindValue("%"+ a +"%");
    q.exec();
    model->setQuery(q);
    return (model);

    }

/*QSqlQueryModel * Formation::afficher_calendar(QString x)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FORMATIONS where DATE_D like '%"+x+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FORMA"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_F"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_D"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_F"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));

    return model;
}*/





