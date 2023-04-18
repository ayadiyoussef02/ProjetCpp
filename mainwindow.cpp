#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qrcodegen.h"
#include "oublier.h"
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
#include <QDebug>


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
    emp* e;
        connection c;
QString Nom_utilisateur,mdp,type;
        c.createconnect();
           QSqlQuery query("SELECT MTP_E, CONCAT(NOM_E,PRENOM_E) as Nom_ut ,TYPE_E from EMPLOYER WHERE NOM_E || PRENOM_E ='" + ui->lineEdit_nomutilisateur->text() + "';");

           while (query.next()) {
               mdp = query.value(0).toString();
                Nom_utilisateur = query.value(1).toString();
               type = query.value(2).toString();

           }

qDebug()<<"Nom= "<< ui->lineEdit_nomutilisateur->text()<<" mdp= "<< ui->lineEdit_motpasse->text() <<endl;

           if ((mdp==ui->lineEdit_motpasse->text()) && (Nom_utilisateur!=""))
           {
               bool test=true;
               test=c.createconnect();
               if(test)
               {
                   QMessageBox::information(nullptr, QObject::tr("database is open"),
                                            QObject::tr("connection successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                   this->hide();

    e = new emp(nullptr,type);
                   e->exec();


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



void MainWindow::on_commandLinkButton_clicked()
{


    o.show();
}
