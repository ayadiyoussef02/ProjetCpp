#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qrcodegen.h"
#include<QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include<QObject>
#include<QDebug>
#include <QPrintDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QtCharts>
#include <QRegularExpression>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_conncter_clicked()
{
    emp e;
        connection c;

        c.createconnect();
           QSqlQueryModel model;

           model.setQuery("SELECT * from INF_CONNEXION WHERE (NOM_UT  LIKE '"+ui->lineEdit_nomutilisateur->text()+"');");

           QString Nom=model.data(model.index(0, 0)).toString();
           QString mdp=model.data(model.index(0, 1)).toString();

           if ((mdp==ui->lineEdit_motpasse->text()) && (Nom!=""))
           {
               bool test=true;
               test=c.createconnect();
               if(test)
               {
                   QMessageBox::information(nullptr, QObject::tr("database is open"),
                                            QObject::tr("connection successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                   this->hide();


                   e.exec();

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                         QObject::tr("connection failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);



           }
           else {

               QMessageBox::critical(nullptr, QObject::tr("Password incorrect"),
                                     QObject::tr("Please check your password or try again later.\n"
                                                 ), QMessageBox::Cancel);
              // ui->mdp_2->setText("Please Scan RFID Card");


           }


}


void MainWindow::on_pushButton_inscrire_clicked()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("ayadi");//inserer nom de l'utilisateur
    db.setPassword("youssef");//inserer mot de passe de cet utilisateur

    QSqlQuery query(db);


    if (db.open())
    {
        if (ui->lineEdit_motpasse_2->text()=="")
        {QMessageBox::critical(nullptr, QObject::tr("ERROR"), QObject::tr("Don't leave password empty.\n""Click Cancel to retry ."), QMessageBox::Cancel);

        }else if  (ui->lineEdit_motpasse_2->text()!=ui->lineEdit_motpasse_3->text())
         {   QMessageBox::critical(nullptr, QObject::tr("ERROR"), QObject::tr("Passwords don't match.\n""Click Cancel to retry ."), QMessageBox::Cancel);
        }else if (ui->lineEdit_nomutilisateur_2->text()=="")
         {   QMessageBox::critical(nullptr, QObject::tr("ERROR"), QObject::tr("Don't leave Username Empty.\n""Click Cancel to retry ."), QMessageBox::Cancel);
   }else


        {


            query.prepare("insert into INF_CONNEXION(NOM_UT,MDP)" "values (:NOM_UT, :MDP);");

            query.bindValue(":NOM_UT",ui->lineEdit_nomutilisateur_2->text());
            query.bindValue(":MDP",ui->lineEdit_motpasse_2->text());



        if (query.exec())
                {
                QMessageBox::information(nullptr, QObject::tr("Done"), QObject::tr("Credentials added.\n""Click Cancel to Continue ."), QMessageBox::Cancel);
}
        }
    }//qInfo() << "RFID4= "<<at<<" "<<endl;

}

