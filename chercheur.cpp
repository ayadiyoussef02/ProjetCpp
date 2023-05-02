#include "chercheur.h"
#include <QtDebug>
#include <QDate>
#include <QListView>
#include <QStringListModel>
#include <QObject>
#include <QtCharts/QtCharts>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
chercheur::chercheur(QString cin_chercheur,QString nom_ch,QString prenom_ch,QString num_tel_ch,QDate date_i_ch,QString type_ch,QString sexe_ch,QString date_r)
{
 this->cin_chercheur=cin_chercheur;
 this->nom_ch=nom_ch;
 this->prenom_ch=prenom_ch;
 this->num_tel_ch=num_tel_ch;

 this->date_i_ch=date_i_ch;
 this->type_ch=type_ch;
 this->sexe_ch=sexe_ch;
 this->date_r=date_r;
}

bool chercheur::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO GESTIONCHERCHEUR (CIN_CHERCHEUR, NOM_CH, PRENOM_CH, NUM_TEL_CH, DATE_I_CH, TYPE_CH, SEXE_CH, DATE_R)""VALUES (:CIN_CHERCHEUR, :NOM_CH, :PRENOM_CH , :NUM_TEL_CH, :DATE_I_CH, :TYPE_CH ,:SEXE_CH ,:DATE_R)");
         query.bindValue(":CIN_CHERCHEUR", cin_chercheur);
         query.bindValue(":NOM_CH", nom_ch);
         query.bindValue(":PRENOM_CH", prenom_ch);
         query.bindValue(":NUM_TEL_CH", num_tel_ch);
         query.bindValue(":DATE_I_CH", date_i_ch);
         query.bindValue(":TYPE_CH", type_ch);
         query.bindValue(":SEXE_CH", sexe_ch);
         query.bindValue(":DATE_R", date_r);



    return query.exec();

   //to do
}
QSqlQueryModel * chercheur:: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM GESTIONCHERCHEUR");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'insecription"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("date de renouvellement"));




            return model;
}
QSqlQueryModel * chercheur:: afficherh(QString cin_chercheur)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT cin_chercheur , nom_ch , date_i_ch , date_r FROM GESTIONCHERCHEUR where cin_chercheur like '"+cin_chercheur+"%' ");
    q.addBindValue("%"+ cin_chercheur +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
bool chercheur::supprimer(QString cin_chercheur)
{

   QSqlQuery query;



         query.prepare("Delete from GESTIONCHERCHEUR WHERE cin_chercheur=:cin_chercheur");
           query.bindValue(0,cin_chercheur);
           return query.exec();




}
bool chercheur::modifier(QString cin_chercheur)
{

QSqlQuery query;



query.prepare("UPDATE GESTIONCHERCHEUR SET cin_chercheur=:cin_chercheur, nom_ch=:nom_ch, prenom_ch=:prenom_ch, num_tel_ch=:num_tel_ch, date_i_ch=date_i_ch, type_ch=:type_ch, sexe_ch=:sexe_ch, date_r=:date_r WHERE cin_chercheur=:cin_chercheur");

query.bindValue(":cin_chercheur", cin_chercheur);
query.bindValue(":nom_ch", nom_ch);
query.bindValue(":prenom_ch", prenom_ch);
query.bindValue(":num_tel_ch", num_tel_ch);
query.bindValue(":date_i_ch", date_i_ch);
query.bindValue(":type_ch", type_ch);
query.bindValue(":sexe_ch", sexe_ch);
query.bindValue(":date_r", date_r);
return query.exec();

}
QSqlQueryModel * chercheur:: notification(QString datee)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT cin_chercheur FROM GESTIONCHERCHEUR where date_r like '"+datee+"%' ");
    q.addBindValue("%"+ datee +"%");
    q.exec();
    model->setQuery(q);
    return (model);










}
QSqlQueryModel * chercheur ::Tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM GESTIONCHERCHEUR ORDER BY nom_ch");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'insecription"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));


            return model;
}
QSqlQueryModel * chercheur ::Tri_dateI()
{
    QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM GESTIONCHERCHEUR ORDER BY date_i_ch");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'insecription"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));


            return model;
}
QSqlQueryModel * chercheur ::Tri_sexe()
{
    QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM GESTIONCHERCHEUR ORDER BY sexe_ch");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'insecription"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));


            return model;
}
QSqlQueryModel * chercheur::rechercher_nom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT * FROM GESTIONCHERCHEUR where nom_ch like '"+nom+"%' ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QChart * chercheur ::stat(){
QSqlQuery q,q1,q2;
   q.exec("Select * from GESTIONCHERCHEUR");
   int tot=0;
   while (q.next())
       tot++;
  qDebug() << "total =" << tot;
   q1.prepare("Select * from GESTIONCHERCHEUR where sexe_ch = :sexe_ch ");
   q1.bindValue(":sexe_ch","Homme");
   q1.exec();

   int tot_don=0;
   while (q1.next())
       tot_don++;
qDebug() << "pourcentage don =" << tot_don;
   qreal pour_1=(tot_don*100)/tot;

   q2.prepare("Select * from GESTIONCHERCHEUR where sexe_ch = :sexe_ch  ");
   q2.bindValue(":sexe_ch","Femme");
   q2.exec();
   int tot_event=0;
   while (q2.next())
       tot_event++;

   qreal pour_2=(tot_event*100)/tot;



   QPieSeries *series = new QPieSeries();
    series->append("Homme",pour_1);
    series->append("Femme",pour_2);

    QPieSlice *slice0= series->slices().at(0);
    slice0->setBrush(Qt::blue);
    //slice0->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setBrush(Qt::green);
/*
    QPieSlice *slice2= series->slices().at(2);
    slice2->setLabelVisible();
     slice2->setBrush(Qt::red);*/

    QChart *chart = new QChart();

    chart->addSeries(series);

    chart->setTitle("Statistisue Homme & Femme");
    chart->legend()->hide();
    series->setLabelsVisible();
   for(auto slice : series->slices())
    slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));
 //chart->setBackgroundBrush(Qt::transparent);

   return chart;
   return chart;
}



