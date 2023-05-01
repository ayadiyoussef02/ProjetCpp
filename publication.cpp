#include "publication.h"

Publication::Publication()
{

}
Publication::Publication(int id, QDate date,  QString type,  QString desc)
{
    this->id_pub = id ;
    this->date_pub = date ;
    this->type_pub = type ;
    this->desc_pub = desc ;

}
Publication::Publication( QDate date,  QString type,  QString desc)
{
    this->date_pub = date ;
    this->type_pub = type ;
    this->desc_pub = desc ;
}
Publication::Publication(QString type,  QString desc)
{
    this->type_pub = type ;
    this->desc_pub = desc ;
    this->estFavoris = 0 ;
}
bool Publication::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO publication (date_pub,type_pub,desc_pub,estfavoris) "
                      "VALUES (:1,:2,:3,:4)");

        query.bindValue(":1",QDate::currentDate());
        query.bindValue(":2",this->type_pub);
        query.bindValue(":3",this->desc_pub);
        query.bindValue(":4",this->estFavoris);

        return query.exec();
}
bool Publication::supprimer(int id)
{
        QSqlQuery query;
        QString res= QString ::number(id);
        query.prepare("Delete from publication where id_pub = :id");
        query.bindValue(":id",res);
        return query.exec();
}
QSqlQueryModel* Publication::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();
    model->setQuery ("select * from publication where estfavoris = 0");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Publication"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));


    return model;
}
QSqlQueryModel* Publication::afficherFavoris()
{
    QSqlQueryModel* model =new QSqlQueryModel();
    model->setQuery ("select * from publication where estfavoris = 1 ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Publication"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));

    return model;
}
bool Publication::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE publication set type_pub = :1, desc_pub = :2 WHERE id_pub = :3") ;

    query.bindValue(":1",this->type_pub);
    query.bindValue(":2",this->desc_pub);
    query.bindValue(":3",this->id_pub);
    return query.exec();
}
bool Publication::ajouterfavoris(int id_pub)
{
    int a = 1 ;
    QSqlQuery query;
    query.prepare("UPDATE publication set estfavoris = :1 WHERE id_pub = :3") ;
    query.bindValue(":1",a);
    query.bindValue(":3",id_pub);
    return query.exec();
}
bool Publication::retirerfavoris(int id_pub)
{
    int a = 0 ;
    QSqlQuery query;
    query.prepare("UPDATE publication set estfavoris = :1 WHERE id_pub = :3") ;
    query.bindValue(":1",a);
    query.bindValue(":3",id_pub);
    return query.exec();
}
QSqlQueryModel* Publication::rechercher(QString rech)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery ("select * from publication WHERE( date_pub LIKE '%"+rech+"%' OR type_pub LIKE '%"+rech+"%' OR desc_pub LIKE '%"+rech+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Publication"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));

    return model;
}
QSqlQueryModel* Publication::trier(QString champ, QString ordre)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QString queryString = "SELECT * FROM publication ORDER BY " + champ + " " + ordre;
    QSqlQuery query ;
    query.prepare(queryString);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Publication"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));

    return model;
}

bool Publication::ajouterhistorique(QString action)
{
    QSqlQuery query;
    query.prepare("INSERT INTO historiquepublication (date_action,action) "
                  "VALUES (:1,:2)");

    query.bindValue(":1",QDateTime::currentDateTime());
    query.bindValue(":2",action);


    return query.exec();
}
QSqlQueryModel*  Publication::afficherhistorique()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM historiquepublication");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID action"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date action "));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    return model ;
}
QSqlQueryModel * Publication::setnom()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT desc_pub from publication");
     model->setHeaderData(0,Qt::Horizontal,"desc_pub");

     return model;
 }
