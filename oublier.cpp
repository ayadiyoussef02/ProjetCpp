#include "oublier.h"
#include "ui_oublier.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include "connection.h"

oublier::oublier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oublier)
{
    ui->setupUi(this);
}

oublier::~oublier()
{
    delete ui;
}
void oublier::on_Submit_clicked()
{
    oublier o;
connection c;
//c.createconnection();
    QSqlQuery query;

    QSqlQueryModel model;


     model.setQuery("SELECT ADRESSE_E from EMPLOYER WHERE NOM_E || PRENOM_E = '"+ui->nomutilisateur_oublier->text()+"');");

    QString Adresse=model.data(model.index(0, 0)).toString();

if (ui->nomutilisateur_oublier->text()!=ui->nomutilisateur_oublier2->text())
{
    QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("nom utilisateur don't match.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else if ((Adresse!="") && (ui->mdp_in->text()!=""))
{

    query.prepare("UPDATE EMPLOYER SET MTP_E= :MDP2   where NOM_E || PRENOM_E = :NOM_UT2 ;");
    query.bindValue(":MDP2",ui->mdp_in->text() );
    query.bindValue(":NOM_UT2",ui->nomutilisateur_oublier->text() );

    if (query.exec()) {QMessageBox::information(nullptr, QObject::tr("Done"),
                                            QObject::tr("Password changed.\n"
                                                        "Click OK to Continue."), QMessageBox::Ok);


 o.exec();}
    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                               QObject::tr("Contact your administrator.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}
else    QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                QObject::tr("Some fields are empty!.\n"
                            "Click to to retry."), QMessageBox::Retry);





}

void oublier::on_pushButton_retour_clicked()
{
    this->close();
    //oublier e;
   // e.show();
    //e.exec();
}
