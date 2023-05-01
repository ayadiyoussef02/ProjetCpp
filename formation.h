#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>




#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QTextDocument>
#include <QTableWidget>
#include <QtCharts>
#include "stat_combo.h"

class Formation
{
public:
    Formation();
    Formation(int,QString,QDate,QDate,QString);// constructeur modifié
     //~Formation();
    int getid_forma();
    QString getnom_f();
    QDate getdate_d();
     QDate getdate_f();
    //QString getdate_d();
   // QString getdate_f();
    QString getdescription();
    void setid_forma(int);
    void setnom_f(QString);
    void setdate_d(QDate);
    void setdate_f(QDate);
    //void setdate_d(QString);
    //void setdate_f(QString);
    void setdescription(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    bool verification(int);
    QSqlQueryModel * setid();
    QSqlQueryModel *afficher_trie_id();
    QSqlQueryModel * afficher_trie_nom();
    QSqlQueryModel* recherche(QString a);
    //QSqlQueryModel * afficher_calendar(QString x);
    //QChart *stat();

      //QString  export_pdf();




private:
   int id_forma;
   QString nom_f,description;
    QDate date_d,date_f;

};

#endif // FORMATION_H
