#include "temp.h"

TEMP::TEMP()
{

}
TEMP::TEMP(QString a/* ,QDate b*/){

    TT=a;
   // DATE=b;


}

bool TEMP::ajouter(){
    QSqlQuery query;
    QString res = QString(TT);

    query.prepare("insert into TEMPP(TT)""values(:TT)");

    query.bindValue(":TT",TT);
   // query.bindValue(":DATE",DATE);




    return query.exec();


}
bool TEMP::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE TEMPP SET  TT=:TT  ");

    query.bindValue(":TT",TT);

    return    query.exec();
}
