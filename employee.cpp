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

Employee::Employee(QString cin_e,QString nom_e,QString prenom_e,QString num_tel_e,QString sexe_e,QString email_e,QString mtp_e,QDate date_n_e,QString adresse_e,QString type_e)
{
        this->cin_e=cin_e;
        this->nom_e=nom_e;
        this->prenom_e=prenom_e;
        this->num_tel_e=num_tel_e;
        this->sexe_e=sexe_e;
        this->email_e=email_e;
        this->mtp_e=mtp_e;
        this->date_n_e=date_n_e;
        this->adresse_e=adresse_e;
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
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("date_n_e"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("adresse_e"));
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

QSqlQueryModel * Employee::Tri_sexe()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYER ORDER BY sexe_e");
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

QSqlQueryModel * Employee::rechercher_nom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("SELECT * FROM EMPLOYER where nom_e like '"+nom+"%' ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QChart * Employee ::stat(){
QSqlQuery q,q1,q2;
   q.exec("Select * from EMPLOYER");
   int tot=0;
   while (q.next())
       tot++;
  qDebug() << "total =" << tot;
   q1.prepare("Select * from EMPLOYER where sexe_e = :sexe_e ");
   q1.bindValue(":sexe_e","Homme");
   q1.exec();

   int tot_don=0;
   while (q1.next())
       tot_don++;
qDebug() << "pourcentage don =" << tot_don;
   qreal pour_1=(tot_don*100)/tot;

   q2.prepare("Select * from EMPLOYER where sexe_e = :sexe_e  ");
   q2.bindValue(":sexe_e","Femme");
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
}



