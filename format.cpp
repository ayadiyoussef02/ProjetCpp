#include "format.h"
#include "ui_format.h"
#include "formation.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QTextDocument>
#include <QSqlRecord>
#include <QPainter>
#include <fstream>
#include <iostream>
#include <QPrinter>
//#include <QtPrintSupport/QPrinter>
#include <QDate>
#include <QDebug>
#include <QTableView>
#include <QtCharts>
#include "stat_combo.h"
#include "exportexcel.h"



Format::Format(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Format)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 99999, this));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    //ui->la_description->setMaxLength(30);
     ui->tab_formation->setModel(F.afficher());
     ui->comboBox->setModel(F.setid());
}

Format::~Format()
{
    delete ui;
}

void Format::on_pb_ajouter_clicked()
{
    int id_forma=ui->le_id->text().toInt();
    QString nom_f=ui->le_nom->text();
    //QString date_d=ui->dateEdit_d->text();
    //QString date_f=ui->dateEdit_f->text();
     QDate date_d=ui->dateEdit_d->date();
      QDate date_f=ui->dateEdit_f->date();
    QString description=ui->des->currentText();
  bool test=true;

   Formation F(id_forma, nom_f, date_d, date_f, description);
             if((id_forma==0)&&(nom_f=="")&&(date_d==QDate::currentDate())&&(date_f==QDate::currentDate())&&(description==""))
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
                test=false;
             }
           else if(id_forma ==0)
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Veuillez remplir l'identifiant"), QMessageBox::Ok);
                test=false;

            }
            else if(nom_f =="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir le nom de la formation"), QMessageBox::Ok);
                   test=false;

               }
            else if(date_d ==QDate::currentDate())
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date debut"), QMessageBox::Ok);
                   test=false;

               }
            else if(date_f ==QDate::currentDate())
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date fin "), QMessageBox::Ok);
                   test=false;

               }


             else if(description =="")
             {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir la description"), QMessageBox::Ok);
                  test=false;

              }
   if(test){
   test=F.ajouter();

   // QMessageBox msgBox;
   if(test){
     // { msgBox.setText("Ajout avec succes.");
       ui->tab_formation->setModel(F.afficher());
       ui->comboBox->setModel(F.setid());
   QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("formation ajouté  \n""Click Cancel to exit."), QMessageBox::Cancel);
      ui->le_id->clear();
      ui->le_nom->clear();
      ui->des->clear();
      ui->dateEdit_d->clear();
      ui->dateEdit_f->clear();
   }
   else

         QMessageBox::critical(nullptr, QObject::tr("not ok"),
               QObject::tr("Identifiant deja exist\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->le_id->clear();
                  ui->le_nom->clear();
                  ui->des->clear();
                  ui->dateEdit_d->clear();
                  ui->dateEdit_f->clear();

}}

void Format::on_pb_supprimer_clicked()
{
    Formation F1; F1.setid_forma(ui->le_id_supp->text().toInt());
    //bool test=F1.supprimer(F1.getid_forma());
    QMessageBox msgBox;
    bool test=false;
     bool trouver=F1.verification(F1.getid_forma());
     if (trouver)
        test= F.supprimer(F1.getid_forma());
    QMessageBox msgbox;
  //  QItemSelectionModel *select = ui->tab_sponsor->selectionModel();
                //     int mat =select->selectedRows().value(0).data().toInt();
    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_formation->setModel(F.afficher());
    ui->le_id_supp->clear();
    }
    else
        msgBox.setText("Identifiant n'existe pas");
        ui->le_id_supp->clear();
    msgBox.exec();
}




void Format::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery query;

            query.prepare("select * from  FORMATIONS  where ID_FORMA=:id_forma ");

            query.bindValue(":id_forma",ui->comboBox->currentText().toInt());

            if(query.exec())

                while(query.next())

        {


            ui->le_nom_2->setText(query.value(1).toString()) ;
            //ui->dateEdit->setDate((query.value(2).toString()) ;
            //ui->dateEdit_2->setDate((query.value(3).toString()) ;
            //ui->des->setText(query.value(4).toString()) ;

            //ui->comboBox_3->setModel(query.value(3).toString());

        }
}

/*void Format::on_pushButton_2_clicked()
{


}*/



void Format::on_pushButton_clicked()
{
    int id_forma=ui->comboBox->currentText().toInt();

        QString nom_f=ui->le_nom_2->text();
        //QString date_d=ui->lineEdit_d->text();
        //QString date_f=ui->lineEdit_f->text();
        QDate date_d=ui->dateEdit->date();
        QDate date_f=ui->dateEdit_2->date();
        QString description=ui->description->currentText();


          Formation Fm(id_forma,nom_f,date_d,date_f,description);

        bool test=Fm.modifier(id_forma);

              if(test)
            {
                  ui->comboBox->setModel(Fm.afficher());
                  ui->tab_formation->setModel(Fm.afficher());


            QMessageBox::information(nullptr, QObject::tr("modifier une formation"),
                              QObject::tr("formation modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
                 //ui->comboBox->setModel(Am.afficher());

            ui->comboBox->setModel(Fm.afficher());
           /* ui->le_nom_2->clear();
            ui->le_nom_3->clear();
            ui->le_nom_4->clear();
            ui->la_description_2->clear();*/


            }
              else  QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                                           QObject::tr("ERREUR.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void Format::on_pb_annuler_aj_clicked()
{
    ui->le_id->clear();
    ui->le_nom->clear();
    ui->des->clear();
    //ui->dateEdit_d->clear();
    //ui->dateEdit_f->clear();
    QDate date = QDate::currentDate();
    ui->dateEdit_d->setDate(date);
    ui->dateEdit_f->setDate(date);



}

void Format::on_pb_annu_mod_clicked()
{
     ui->le_nom_2->clear();
     ui->dateEdit->clear();
     ui->dateEdit_2->clear();
     ui->description->clear();
}





void Format::on_radioButton_clicked()
{
    Formation f;
    ui->tab_formation->setModel(f.afficher_trie_nom());
}


void Format::on_radioButton_2_clicked()
{
    Formation f;
    ui->tab_formation->setModel(f.afficher_trie_id());
}



void Format::on_la_recherche_textChanged(const QString &arg1)
{
    ui->tab_formation->setModel(F.recherche(arg1));
}


void Format::on_pb_pdf_clicked()
{

    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tab_formation->model()->rowCount();
                            const int columnCount = ui->tab_formation->model()->columnCount();

                            out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("strTitle")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"

                               //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H2>  Smart RDI Center \n \n\n\n</H2><H3> ~~Liste des Formations ~~ \n \n\n\n</H3><H4> \n \n\n\n</H4></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


                            // headers
                            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tab_formation->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tab_formation->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tab_formation->isColumnHidden(column)) {
                                        QString data = ui->tab_formation->model()->data(ui->tab_formation->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table> </center>\n"
                                "</body>\n"
                                "</html>\n";

                      QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}




void Format::on_pb_stat_clicked()
{

    stat_combo *s = new stat_combo();

   s->setWindowTitle("statistique ComboBox");
   s->choix_pie();
   s->show();
}



/*void Format::on_calendarWidget_selectionChanged()
{
    QString date = ui->calendarWidget->selectedDate().toString("dd-MM-yyyy"); // formater la date au format de la base de données
        ui->lineEdit_calendar->setText(date);
        QSqlQueryModel *model = F.afficher_calendar(date); // récupérer le modèle des formations pour cette date
        if(model->rowCount() > 0) { // vérifier si le modèle contient des données
            ui->tableView_calendar->setModel(model); // afficher le modèle dans le QTableView
        } else {
            ui->tableView_calendar->setModel(nullptr); // si le modèle est vide, désactiver le QTableView
            QMessageBox::information(this, "Aucune formation", "Il n'y a aucune formation pour cette date.");
        }
}
*/
void Format::on_pb_insert_clicked()
{
    QMessageBox msgbox;
    QString filename= QFileDialog::getOpenFileName(this,tr("Selectionnez"),"",tr("Images(*.png *.jpeg *.jpg)"));
    if(QString::compare(filename, QString())!=0)
    {
        QImage img;
        bool valid = img.load(filename);
        if (valid)
        {
            img=img.scaledToWidth(ui->label_img->width(), Qt::SmoothTransformation);
            ui->label_img->setPixmap(QPixmap::fromImage(img));
        }
        else
            msgbox.setText("failed");
    }
}


void Format::on_calendarWidget_clicked(const QDate &date)
{
    QString x=ui->calendarWidget->selectedDate().toString();
       ui->lineEdit_calendar->setText(x);

    QString d=date.toString("yyyy-MM-dd");
        QSqlQuery b;

        b.prepare("SELECT * from FORMATIONS where DATE_D = to_date(:date,'yyyy-MM-dd') OR DATE_F = to_date(:date,'yyyy-MM-dd') ");
        b.bindValue(":date",d);

    b.exec();

        QSqlQueryModel  * mod=new QSqlQueryModel();
      mod->setQuery(b);
        mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FORMA"));
        mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_F"));
        mod->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
        mod->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_F"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIPTION"));

        ui->tableView_calendar->setModel(mod);
}

void Format::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                      tr("Excel Files (*.xls)"));
                      if (fileName.isEmpty())
                          return;

                      ExportExcel obj(fileName, "Formation", ui->tab_formation);

        //colums to export
        obj.addField(0, "ID_FORMA", "char(20)");
        obj.addField(1, "NOM_F", "char(20)");
        obj.addField(2, "DATE_D", "char(20)");
        obj.addField(3, "DATE_F", "char(20)");
        obj.addField(4, "DESCRIPTION", "char(20)");




        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}
