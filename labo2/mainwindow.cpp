#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "labo.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    ui->comboBox_4->setModel(Etmp.setid());
     ui->comboBox_5->setModel(Etmp.setid());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

        int id_labo=ui->lineEdit_id->text().toInt();
        QString nom_labo=ui->lineEdit_nom->text();
        int ntel_labo=ui->lineEdit_ntel->text().toInt();
        QString specialite=ui->comboBox->currentText();
        QString adresse=ui->lineEdit_ad->text();

        labo l(id_labo , nom_labo , ntel_labo, specialite, adresse);



        bool test=l.ajouter();

        if(test){
        ui->tableView->setModel(Etmp.afficher());
        ui->comboBox_4->setModel(Etmp.setid());
         ui->comboBox_5->setModel(Etmp.setid());
           QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("Ajout effectué\n" "click cancel to exit."), QMessageBox::Cancel);

        }

            else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );

}

void MainWindow::on_Supprimer_clicked()
{// int NUMERO=ui->lineEdit_supp->text().toInt();
    int NUMERO=ui->comboBox_5->currentText().toInt();
    bool test=Etmp.supprimer(NUMERO);

    if(test){
ui->tableView->setModel(Etmp.afficher());
ui->comboBox_5->setModel(Etmp.setid());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("suppression effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("not ok"),QObject::tr("suppression non effectué. \n" " click cancel to exit") );

}

void MainWindow::on_comboBox_4_activated(int index)
{
    QSqlQuery query;

        query.prepare("select * from  LABO  where ID_LABO=:ID_LABO ");

        query.bindValue(":ID_LABO",ui->comboBox_4->currentText().toInt());

        if(query.exec())

            while(query.next())

    {


        ui->lineEdit_nom_3->setText(query.value(1).toString()) ;
        ui->lineEdit_ntel_3->setText(query.value(2).toString()) ;
        ui->lineEdit_sp_4->setText(query.value(3).toString()) ;
        ui->lineEdit_ad_3->setText(query.value(4).toString()) ;

        //ui->comboBox_3->setModel(query.value(3).toString());

    }
}

void MainWindow::on_modifier_clicked()
{
    labo l(ui->comboBox_4->currentText().toInt(),ui->lineEdit_nom_3->text(),ui->lineEdit_ntel_3->text().toInt(),ui->comboBox_3->currentText(),ui->lineEdit_ad_3->text());
    bool test=l.modifier();




    if(test){
    ui->tableView->setModel(Etmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("modification effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("modification non effectué. \n" " click cancel to exit") );
}

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{QSqlQuery query;

    query.prepare("select * from  LABO  where ID_LABO=:ID_LABO ");

    query.bindValue(":ID_LABO",ui->comboBox_5->currentText().toInt());

    query.exec();

}
