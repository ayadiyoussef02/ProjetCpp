#include "connection.h"


connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Project2A");
db.setUserName("ayadi");//inserer nom de l'utilisateur
db.setPassword("youssef");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}

void connection::closeconnect(){db.close();}
