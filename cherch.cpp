#include "cherch.h"
#include "ui_cherch.h"

#include "chercheur.h"

#include <QMessageBox>
#include <QString>
#include <QDate>
#include <cstring>
#include <iostream>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QApplication>
#include <QFileDialog>
#include <QPrintDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QtCharts>

using namespace std;


cherch::cherch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cherch)
{
    ui->setupUi(this);

    ui->tab_chercheur->setModel(ch.afficher());
    //ui->tableView->setModel(ch.notification());
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_nom_mod_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_prenom_mod_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_id_mod_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->line_edit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->le_numtlf->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->le_num_mod_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

cherch::~cherch()
{
    delete ui;
      ui->tab_chercheur->setModel(ch.afficher());
}

void cherch::on_pb_ajouter_clicked()
{
   QString cin_chercheur=ui->line_edit_id->text();
   QString nom_ch=ui->le_nom->text();
   QString prenom_ch=ui->le_prenom->text();
   QString num_tel_ch=ui->le_numtlf->text();
   QDate date_i_ch=ui->le_datenaissance->date();
   QString type_ch=ui->comboBox->currentText();
   QString sexe_ch=ui->sexe->currentText();
   QDate dateUnAn = date_i_ch.addYears(1);
   QString datere;

   QDate date=QDate::currentDate();
   QString date_rr = date.toString("yyyyMMdd");
   QString date_c = dateUnAn.toString("yyyyMMdd");
   int dater=date_rr.toInt();
   int datec=date_c.toInt();
   int diff=dater-datec;
   if(diff>0)
       datere = date.toString("yyyy-MM-dd");
   else datere = dateUnAn.toString("yyyy-MM-dd");
   QString date_r=datere;



chercheur C(cin_chercheur, nom_ch, prenom_ch, num_tel_ch, date_i_ch, type_ch,sexe_ch,date_r);
int taillec=cin_chercheur.size();
int taillet=num_tel_ch.size();
bool test=true;



if((cin_chercheur=="")&&(nom_ch=="")&&(prenom_ch=="")&&(num_tel_ch=="")&&(date_i_ch==QDate::currentDate())&&(type_ch=="")&&(sexe_ch==""))
   {
       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                   QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
       test=false;
    }
  else if(cin_chercheur =="")
   {
       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                   QObject::tr("Veuillez remplir le cin"), QMessageBox::Ok);
       test=false;

   }
   else if(nom_ch =="")
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);
          test=false;

      }
   else if(prenom_ch =="")
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Veuillez remplir le prenom"), QMessageBox::Ok);
          test=false;

      }
   else if(num_tel_ch =="")
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Veuillez remplir le num de tel "), QMessageBox::Ok);
          test=false;

      }




    else if(date_i_ch ==QDate::currentDate())
     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                  QObject::tr("Veuillez remplir la date du naissance"), QMessageBox::Ok);
         test=false;

     }
    else if(type_ch =="")
    {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                  QObject::tr("Veuillez remplir le type"), QMessageBox::Ok);
         test=false;

     }
else if(sexe_ch =="")
{
     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
              QObject::tr("Veuillez remplir le sexe"), QMessageBox::Ok);
     test=false;

 }
else if(taillec!=8)
{QMessageBox::warning(this,"Attention","le cin est de 8 nombre ");
    test=false;}


 else if(taillet!=8)
    {QMessageBox::warning(this,"Attention","le num est de 8 nombres ");
        test=false;}





if(test){
test=C.ajouter();

if(test){
   ui->tab_chercheur->setModel(ch.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Ajout effectué\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->line_edit_id->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_numtlf->clear();
    QDate date = QDate::currentDate();
    ui->le_datenaissance->setDate(date);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("Ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}}







void cherch::on_pushButton_annuler_4_clicked()
{

    QModelIndex index=ui->tab_chercheur->currentIndex();
    QString cin_chercheur  =index.data(Qt::DisplayRole).toString();
    ui->le_id_mod_2->setText(cin_chercheur);
    QString nom_ch = ui->tab_chercheur->model()->index(index.row(), 1).data(Qt::DisplayRole).toString();
    ui->le_nom_mod_2->setText(nom_ch);
    QString prenom_ch = ui->tab_chercheur->model()->index(index.row(), 2).data(Qt::DisplayRole).toString();
    ui->le_prenom_mod_2->setText(prenom_ch);
    QString num_tel_ch = ui->tab_chercheur->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
    ui->le_num_mod_2->setText(num_tel_ch);
    QDate date_i_ch = ui->tab_chercheur->model()->index(index.row(), 4).data(Qt::DisplayRole).toDate();
    ui->le_date_mod_2->setDate(date_i_ch);
    QString type_ch = ui->tab_chercheur->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
    ui->comboBox_2->setCurrentIndex(0);
    QString sexe_ch = ui->tab_chercheur->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
    ui->sexe_mod->setCurrentIndex(0);



}
void cherch::on_pushButton_Historique_clicked()
{  /* QModelIndex index=ui->tab_chercheur->currentIndex();
    QString cin=index.data(Qt::DisplayRole).toString();;
    QString nom_ch=ui->tab_chercheur->model()->index(index.row(), 1).data(Qt::DisplayRole).toString();
    QString prenom_ch=ui->tab_chercheur->model()->index(index.row(), 2).data(Qt::DisplayRole).toString();
    int nombre_des_formation=0;
    QDate date_i=ui->tab_chercheur->model()->index(index.row(), 4).data(Qt::DisplayRole).toDate();
    historique h(cin,nom_ch,prenom_ch,nombre_des_formation,date_i);
  bool test=h.Ajouter();
  if(test){

      QMessageBox::information(nullptr, QObject::tr("OK"),
                  QObject::tr("Ajout effectué\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


  }

  else
  {QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                  QObject::tr("Ajout non effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}*/
  QModelIndex index=ui->tab_chercheur->currentIndex();
  QString cin_chercheur  =index.data(Qt::DisplayRole).toString();
  ui->tab_chercheur->setModel(ch.afficherh(cin_chercheur));
  QString strStream;
  QTextStream out(&strStream);
  const int rowCount = ui->tab_chercheur->model()->rowCount();
  const int columnCount = ui->tab_chercheur->model()->columnCount();

  out <<  "<html>\n"
      "<head>\n"
      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
      <<  QString("<title>%1</title>\n").arg("strTitle")
      <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

     //     "<align='right'> " << datefich << "</align>"
       "<center> <H1> smart RDI center \n \n\n\n</H1><H2>Liste des chercheur \n \n\n\n</H2><H3> \n \n\n\n</H3></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


  // headers
  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
  for (int column = 0; column < columnCount; column++)
      if (!ui->tab_chercheur->isColumnHidden(column))
          out << QString("<th>%1</th>").arg(ui->tab_chercheur->model()->headerData(column, Qt::Horizontal).toString());
  out << "</tr></thead>\n";

  // data table
  for (int row = 0; row < rowCount; row++) {
      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
      for (int column = 0; column < columnCount; column++) {
          if (!ui->tab_chercheur->isColumnHidden(column)) {
              QString data = ui->tab_chercheur->model()->data(ui->tab_chercheur->model()->index(row, column)).toString().simplified();
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


/*bool testt=h.supprimer(cin);

            if(testt){
                ui->tab_chercheur->setModel(ch.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("supprission effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("CIN does not exist.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
        }



void cherch::on_pushButton_PDF_2_clicked()
{


    QDate date = QDate::currentDate(); // Obtenir la date actuelle
    QString dateString = date.toString("yyyy-MM-dd");
    ui->tab_chercheur_2->setModel(ch.notification(dateString));


}







void cherch::on_pushButton_mod_clicked()
{
    { QString cin_chercheur=ui->le_id_mod_2->text();
      QString nom_ch=ui->le_nom_mod_2->text();
      QString prenom_ch=ui->le_prenom_mod_2->text();
      QString num_tel_ch=ui->le_num_mod_2->text();
      QDate date_i_ch=ui->le_date_mod_2->date();
      QString type_ch=ui->comboBox_2->currentText();
      QString sexe_ch=ui->sexe_mod->currentText();
      QDate dateUnAn = date_i_ch.addYears(1);
      //QString date_r = dateUnAn.toString("yyyy-MM-dd");
      QString datere;

      QDate date=QDate::currentDate();
      QString date_rr = date.toString("yyyyMMdd");
      QString date_c = dateUnAn.toString("yyyyMMdd");
      int dater=date_rr.toInt();
      int datec=date_c.toInt();
      int diff=dater-datec;
      if(diff>0)
          datere = date.toString("yyyy-MM-dd");
      else datere = dateUnAn.toString("yyyy-MM-dd");
      QString date_r=datere;
      chercheur c(cin_chercheur, nom_ch, prenom_ch, num_tel_ch, date_i_ch, type_ch, sexe_ch,date_r);
      bool test=c.modifier(cin_chercheur);
      int taillec=cin_chercheur.size();
      int taillet=num_tel_ch.size();




      if((cin_chercheur=="")&&(nom_ch=="")&&(prenom_ch=="")&&(num_tel_ch=="")&&(date_i_ch==QDate::currentDate())&&(type_ch=="")&&(sexe_ch==""))
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
             test=false;
          }
        else if(cin_chercheur =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le cin"), QMessageBox::Ok);
             test=false;

         }
         else if(nom_ch =="")
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);
                test=false;

            }
         else if(prenom_ch =="")
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Veuillez remplir le prenom"), QMessageBox::Ok);
                test=false;

            }
         else if(num_tel_ch =="")
            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Veuillez remplir le num de tel "), QMessageBox::Ok);
                test=false;

            }




          else if(date_i_ch ==QDate::currentDate())
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir la date du naissance"), QMessageBox::Ok);
               test=false;

           }
          else if(type_ch =="")
          {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir le type"), QMessageBox::Ok);
               test=false;

           }
      else if(sexe_ch =="")
      {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Veuillez remplir le sexe"), QMessageBox::Ok);
           test=false;

       }
      else if(taillec!=8)
      {QMessageBox::warning(this,"Attention","le cin est de 8 nombre ");
          test=false;}


      else if(taillet!=8)
          {QMessageBox::warning(this,"Attention","le num est de 8 nombres ");
              test=false;}



     if(test){

          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Modification effectué\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
            /*ui->le_id_mod_2->setText("");
            ui->le_nom_mod_2->setText("");
            ui->le_prenom_mod_2->setText("");
            ui->le_num_mod_2->setText("");
            QDate date = QDate::currentDate();
            ui->le_date_mod_2->setDate(date);
            ui->le_type_mod_2->setText("");*/

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                      QObject::tr("modification non effectue.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_chercheur->setModel(c.afficher());
    }

}

void cherch::on_pushButton_annuler_5_clicked()
{
    QModelIndex index=ui->tab_chercheur->currentIndex();
    QString cin_chercheur  =index.data(Qt::DisplayRole).toString();
    int reponse = QMessageBox::question(this, "Interrogatoire", "Vous ète sur du supprimer?", QMessageBox ::Yes | QMessageBox::No);


            if (reponse == QMessageBox::Yes)
            {
                bool test=ch.supprimer(cin_chercheur);

                if(test){
                    ui->tab_chercheur->setModel(ch.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("supprission effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                QObject::tr("CIN does not exist.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else if (reponse == QMessageBox::No)
            {
                QMessageBox::information(this, "ok", "supprission annulée");
            }

  }




void cherch::on_pushButton_annuler_clicked()
{
    ui->line_edit_id->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_numtlf->clear();
    QDate date = QDate::currentDate();
    ui->le_datenaissance->setDate(date);
   ui->comboBox->clear();
   ui->sexe->clear();
}

void cherch::on_pushButton_annuler_3_clicked()
{ui->le_id_mod_2->clear();
    ui->le_nom_mod_2->clear();
    ui->le_prenom_mod_2->clear();
    ui->le_num_mod_2->clear();
    QDate date = QDate::currentDate();
    ui->le_date_mod_2->setDate(date);
   ui->comboBox_2->clear();
   ui->sexe->clear();

}


void cherch::on_pushButton_tri_clicked()
{
    QString trie=ui->comboBox_tri->currentText();
    if(trie=="Nom"){
      ui->tab_chercheur->setModel(ch.Tri_nom());}
    else if(trie=="Date d'insecription"){
       ui->tab_chercheur->setModel(ch.Tri_dateI());
    }else if(trie=="sexe"){
        ui->tab_chercheur->setModel(ch.Tri_sexe());
    }
}

void cherch::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_chercheur->setModel(ch.rechercher_nom(arg1));
}

void cherch::on_pushButton_stat_clicked()
{
    QChart *chart = new QChart();
                 chart=ch.stat();
                QChartView *chartview = new QChartView(chart,ui->stat);
                chartview->resize(250,180);
                chartview->setRenderHint(QPainter::Antialiasing);
                chartview->setBackgroundBrush(Qt::transparent);
                chartview->show();

}

void cherch::on_pushButton_PDF_clicked()
{
                               QString strStream;
                               QTextStream out(&strStream);

                               const int rowCount = ui->tab_chercheur->model()->rowCount();
                               const int columnCount = ui->tab_chercheur->model()->columnCount();

                               out <<  "<html>\n"
                                   "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                   <<  QString("<title>%1</title>\n").arg("strTitle")
                                   <<  "</head>\n"
                                   "<body bgcolor=#ffffff link=#5000A0>\n"

                                  //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1> smart RDI center \n \n\n\n</H1><H2>Liste des chercheur \n \n\n\n</H2><H3> \n \n\n\n</H3></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


                               // headers
                               out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                               for (int column = 0; column < columnCount; column++)
                                   if (!ui->tab_chercheur->isColumnHidden(column))
                                       out << QString("<th>%1</th>").arg(ui->tab_chercheur->model()->headerData(column, Qt::Horizontal).toString());
                               out << "</tr></thead>\n";

                               // data table
                               for (int row = 0; row < rowCount; row++) {
                                   out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                   for (int column = 0; column < columnCount; column++) {
                                       if (!ui->tab_chercheur->isColumnHidden(column)) {
                                           QString data = ui->tab_chercheur->model()->data(ui->tab_chercheur->model()->index(row, column)).toString().simplified();
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



void cherch::on_pushButton_mod_2_clicked()
{   QModelIndex index=ui->tab_chercheur_2->currentIndex();
    QString cin_chercheur  =index.data(Qt::DisplayRole).toString();
          cin_chercheur=ui->le_id_mod_2->text();
          QString nom_ch=ui->le_nom_mod_2->text();
          QString prenom_ch=ui->le_prenom_mod_2->text();
          QString num_tel_ch=ui->le_num_mod_2->text();
          QDate date_i_ch=ui->le_date_mod_2->date();
          QString type_ch=ui->comboBox_2->currentText();
          QString sexe_ch=ui->sexe_mod->currentText();
          QDate date = QDate::currentDate();
          QDate dateUnAn = date.addYears(1);
          QString date_r = dateUnAn.toString("yyyy-MM-dd");
          QString date_c = date_i_ch.toString("yyyy-MM-dd");

          chercheur c(cin_chercheur, nom_ch, prenom_ch, num_tel_ch, date_i_ch, type_ch, sexe_ch,date_r);
           bool test=c.modifier(cin_chercheur);
            ui->tab_chercheur->setModel(c.afficher());
            ui->tab_chercheur_2->setModel(c.notification(date_r));

}

