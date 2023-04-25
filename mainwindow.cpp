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
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret = A.connectArduino();
        qDebug() << ret;
        switch(ret){
            case 0:
                qDebug() << ret;
                qDebug() << "arduino is abailable and connected to: " << A.getArduinoPortName();
            break;
            case 1 :
                qDebug() << ret;
                qDebug() << "arduino is available but not connected to :  " << A.getArduinoPortName();
            break;
            case -1:
                qDebug() << ret;
                qDebug() << "arduino is not available";
            break;
        }
        QObject::connect(A.getSerial(), SIGNAL(readyRead()), this, SLOT(returnEmloyee()));


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
                   if (type!="Chef")
                       QMessageBox::information(nullptr, QObject::tr("database is open"),
                                                QObject::tr("opennnnn vous etes un agent.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
                   else
                       QMessageBox::information(nullptr, QObject::tr("database is open"),
                                                QObject::tr("opennnnn vous etes un chef.\n"
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
//ardouino
void MainWindow::returnEmloyee(){
    emp* e;
    connection c;
    QString nomPrenom,message,type;
        data =  A.readFromArduino();
        QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(data);
        qDebug() << data;
        //qDebug() << DataAsString;
        if(data == "0"){
            QMessageBox::critical(nullptr, QObject::tr("NOOOOOO"),
                                  QObject::tr("carte n'existe pas.\n"
                                              ), QMessageBox::Cancel);        }
        else{
            QSqlQuery query;
            query.prepare("select * from EMPLOYER where IDCARTE= :IDCARTE");
            query.bindValue(":IDCARTE",DataAsString);
            query.exec();
            while(query.next()){
                nomPrenom = query.value(1).toString();

                type = query.value(9).toString();


                bool test=true;
                test=c.createconnect();
                if(test)
                {
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                             QObject::tr("connection successful.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);
                    if (type!="Chef"){
                        message = nomPrenom + " "+ type;
                        qDebug() << message;
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                                 QObject::tr("opennnnn vous etes un agent.\n"
                                                             "Click Cancel to exit."), QMessageBox::Cancel);
                        A.writeToArduino(message.toUtf8());
                    }
                    else{
                        message = nomPrenom + " "+ type;
                        qDebug() << message;
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                                 QObject::tr("opennnnn vous etes un chef.\n"
                                                             "Click Cancel to exit."), QMessageBox::Cancel);
                        A.writeToArduino(message.toUtf8());
                       }

                    this->hide();

     e = new emp(nullptr,type);
                    e->exec();


                }

                }
            //A.writeToArduino(message.toUtf8());
    }
}
