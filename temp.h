#ifndef TEMP_H
#define TEMP_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class TEMP
{
public:
    TEMP();
    TEMP(QString );
    bool ajouter();
    bool modifier();
private:
    QString TT;


};

#endif // TEMP_H
