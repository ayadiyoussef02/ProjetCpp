//EMPLOYEES
#include "emp.h"
#include "ui_emp.h"
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

// Publications

//LAB
#include "labo.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include "connection.h"
//#include "webaxwidget.h"
#include <QPainter>
#include <QPrinter>
//#include "salle.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
//CHERCH
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
//FORMAT
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
//
using namespace std;


emp::emp(QWidget *parent, const QString& str) :
    QDialog(parent),
    ui(new Ui::emp)
{
    ui->setupUi(this);
    //EMP
    //pour annuler des affichage des choses
   if (str!="Chef")
        ui->tabWidget->removeTab(0);
    //ui->pushButton_retour->setText(str);

   // ui->tableView_affiche->setModel(E.afficher());
    ui->lineEdit_cin_ajouter->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_nom_ajouter->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->lineEdit_prenom_ajouter->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->lineEdit_numtel_ajouter->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

    // PUB
    int ret=A.connectArduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< A.getArduinoPortName();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<A.getArduinoPortName();
              break;
           case(-1):qDebug() << "arduino is not available";
           }

           ui->tableViewPub->setModel(ptmp.afficher());
           ui->tableViewPubFAvoris->setModel(ptmp.afficherFavoris());
           ui->tableViewPub->hideColumn(4);
           ui->tableViewPubFAvoris->hideColumn(4);
           ui->tableViewPub->setColumnWidth(3,400);
           ui->tableViewPubFAvoris->setColumnWidth(3,400);
           ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
           ui->comboBox->setModel(ptmp.setnom());

    //LAB

           player = new QMediaPlayer(this);
              vw = new QVideoWidget(this);
              player->setVideoOutput(vw);

              vw->setGeometry(100,100,900,900);
              ui->tabWidget->addTab(vw,"VIDEO");
              slider = new QSlider(this);
              bar = new QProgressBar(this);

              slider->setOrientation(Qt::Horizontal);




            /* statusbar->addPermanentWidget(slider);
              statusbar->addPermanentWidget(bar);*/

              connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
              connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
              connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

              connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
              connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);
             // ui->WebBrowser1->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
              //actualiser
              ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
              ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
              ui->lineEdit_ntel->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
              ui->tableView->setModel(Etmp.afficher());
              ui->comboBox_4->setModel(Etmp.setid());
               ui->comboBox_5->setModel(Etmp.setid());
               ui->comboBox_2->setModel(Etmp.setnom());
               ui->comboBox_6->setModel(Etmp.sette());
               ui->comboBox_6->setHidden(1);
               ui->cofirmer->setHidden(1);
               //CHERCH
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
               //FORMAT
                  ui->le_id->setValidator(new QIntValidator(0, 99999, this));
                     ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
                     //ui->la_description->setMaxLength(30);
                      ui->tab_formation->setModel(F.afficher());
                      ui->comboBox->setModel(F.setid());
}

emp::~emp()
{
    delete ui;
}


void emp::on_pushButton_ajouter_clicked()
{
    QString cin_e=ui->lineEdit_cin_ajouter->text();
    QString nom_e=ui->lineEdit_nom_ajouter->text();
    QString prenom_e=ui->lineEdit_prenom_ajouter->text();
    QString num_tel_e=ui->lineEdit_numtel_ajouter->text();
    QString sexe_e=ui->comboBox_sexe->currentText();
    QString email_e=ui->lineEdit_email_ajouter->text();
    QString mtp_e=ui->lineEdit_mdp_ajouter->text();
    QDate date_n_e=ui->dateEdit->date();
    QString adresse_e=ui->lineEdit_adr_ajouter->text();
    QString type_e=ui->comboBox_type_ajouter->currentText();


    QRegExp regex_email("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,}");
        if (!regex_email.exactMatch(email_e)) {
            QMessageBox::warning(this, "Erreur", "L'email n'est pas valide.");
            return;
        }

    int taillec=cin_e.size();
    int taillet=num_tel_e.size();
     bool test=true;
     bool bd;
     //int cin=cin_e.toInt(&bd);
     bool bt;
     //int tel=num_tel_e.toInt(&bt);
    Employee E(cin_e,nom_e,prenom_e,num_tel_e,sexe_e,email_e,mtp_e,date_n_e,adresse_e,type_e);
    if((cin_e=="")&&(nom_e=="")&&(prenom_e=="")&&(num_tel_e=="")&&(sexe_e==0)&&(email_e=="")&&(mtp_e=="")&&(date_n_e==QDate::currentDate())&&(adresse_e=="")&&(type_e==""))
       {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
        }
      else if(cin_e =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Veuillez remplir le cin"), QMessageBox::Ok);

       }
       else if(nom_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

          }
       else if(prenom_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le prenom"), QMessageBox::Ok);

          }
       else if(num_tel_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le num de tel "), QMessageBox::Ok);

          }

       else if(sexe_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le sexe"), QMessageBox::Ok);

          }
        else if(email_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Veuillez remplir l email"), QMessageBox::Ok);

          }
        else if(mtp_e =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Veuillez remplir le mot de passe"), QMessageBox::Ok);

          }
        else if(adresse_e =="")
          {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Veuillez remplir l adresse"), QMessageBox::Ok);

          }
        else if(date_n_e ==QDate::currentDate())
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Veuillez remplir la date du naissance"), QMessageBox::Ok);

         }
        else if(type_e =="")
        {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Veuillez remplir le type"), QMessageBox::Ok);

         }
    else if(taillec!=8)
    {QMessageBox::warning(this,"Attention","le cin est de 8 nombre ");
        test=false;}

        else if(!cin_e.toInt(&bd)){
          QMessageBox::warning(this,"Attention","le cin est de 8 nombres ");
            test=false;}

       else if(taillet!=8)
        {QMessageBox::warning(this,"Attention","le num tel est de 8 nombre ");
            test=false;}

          else  if(!num_tel_e.toInt(&bt)){
              QMessageBox::warning(this,"Attention","le num tel est de 8 nombres ");
                test=false;}


   if(test) {
   test = E.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("ajout effectué.\n",
                                             "click Cancel to exist."), QMessageBox::Cancel);
        ui->lineEdit_cin_ajouter->clear();
        ui->lineEdit_nom_ajouter->clear();
        ui->lineEdit_prenom_ajouter->clear();
        ui->lineEdit_numtel_ajouter->clear();
        ui->comboBox_sexe->setCurrentIndex(0);
        ui->lineEdit_email_ajouter->clear();
        ui->lineEdit_mdp_ajouter->clear();
        QDate date = QDate::currentDate();
        ui->dateEdit->setDate(date);
        ui->lineEdit_adr_ajouter->clear();
        ui->comboBox_type_ajouter->setCurrentIndex(0);


    }else{
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                                 QObject::tr("ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }}
         ui->tableView_affiche->setModel(E.afficher());
}

void emp::on_pushButton_modifier_clicked()
{ //emp e;
    //oublier o;
    QString cin_e=ui->lineEdit_cin_ajouter->text();
    QString nom_e=ui->lineEdit_nom_ajouter->text();
    QString prenom_e=ui->lineEdit_prenom_ajouter->text();
    QString num_tel_e=ui->lineEdit_numtel_ajouter->text();
    QString sexe_e=ui->comboBox_sexe->currentText();
    QString email_e=ui->lineEdit_email_ajouter->text();
    QString mtp_e=ui->lineEdit_mdp_ajouter->text();
    QDate date_n_e=ui->dateEdit->date();
    QString adresse_e=ui->lineEdit_adr_ajouter->text();
    QString type_e=ui->comboBox_type_ajouter->currentText();







         Employee E(cin_e,nom_e,prenom_e,num_tel_e,sexe_e,email_e,mtp_e,date_n_e,adresse_e,type_e);
        if((cin_e=="")&&(nom_e=="")&&(prenom_e=="")&&(num_tel_e=="")&&(sexe_e==0)&&(email_e=="")&&(mtp_e=="")&&(date_n_e==QDate::currentDate())&&(adresse_e=="")&&(type_e==""))
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
            }
          else if(cin_e =="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le cin"), QMessageBox::Ok);

           }
           else if(nom_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

              }
           else if(prenom_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Veuillez remplir le prenom"), QMessageBox::Ok);

              }
           else if(num_tel_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Veuillez remplir le num de tel "), QMessageBox::Ok);

              }

           else if(sexe_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Veuillez remplir le sexe"), QMessageBox::Ok);

              }
            else if(email_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir l email"), QMessageBox::Ok);

              }
            else if(mtp_e =="")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le mot de passe"), QMessageBox::Ok);

              }
            else if(adresse_e =="")
              {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir l adresse"), QMessageBox::Ok);

              }
            else if(date_n_e ==QDate::currentDate())
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir la date du naissance"), QMessageBox::Ok);

             }
            else if(type_e =="")
            {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le type"), QMessageBox::Ok);

             }

        else {

            if(E.modifier(cin_e))
            {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un employee"),
                                 QObject::tr("employee modifié.\n"), QMessageBox::Cancel);

                     ui->lineEdit_cin_ajouter->setText("");
                     ui->lineEdit_nom_ajouter->setText("");
                     ui->lineEdit_prenom_ajouter->setText("");
                     ui->lineEdit_numtel_ajouter->setText("");
                     ui->comboBox_sexe->currentText();
                     ui->lineEdit_email_ajouter->setText("");
                     ui->lineEdit_mdp_ajouter->setText("");
                     QDate date = QDate::currentDate();
                     ui->dateEdit->setDate(date);
                     ui->lineEdit_adr_ajouter->setText("");
                     ui->comboBox_type_ajouter->currentText();


            }
            else
            {
               QMessageBox::critical(nullptr, QObject::tr("Modifier un emloyee"),

                                     QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
               //e.exec();
               //o.exec();
            }
        }
        ui->tableView_affiche->setModel(E.afficher());
}

void emp::on_pushButton_charger_clicked()
{


             QModelIndex index = ui->tableView_affiche->currentIndex();
             QString cin_e = index.data(Qt::DisplayRole).toString();
             ui->lineEdit_cin_ajouter->setText(cin_e);
             QString nom_e = ui->tableView_affiche->model()->index(index.row(), 1).data(Qt::DisplayRole).toString();
             ui->lineEdit_nom_ajouter->setText(nom_e);
             QString prenom_e = ui->tableView_affiche->model()->index(index.row(), 2).data(Qt::DisplayRole).toString();
             ui->lineEdit_prenom_ajouter->setText(prenom_e);
             QString num_tel_e = ui->tableView_affiche->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
             ui->lineEdit_numtel_ajouter->setText(num_tel_e);
             QString sexe_e = ui->tableView_affiche->model()->index(index.row(), 4).data(Qt::DisplayRole).toString();
             ui->comboBox_sexe->setCurrentIndex(0);
             QString mtp_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
             ui->lineEdit_mdp_ajouter->setText(mtp_e);
             QString email_e = ui->tableView_affiche->model()->index(index.row(), 6).data(Qt::DisplayRole).toString();
             ui->lineEdit_email_ajouter->setText(email_e);
             QDate date_n_e = ui->tableView_affiche->model()->index(index.row(), 7).data(Qt::DisplayRole).toDate();
             ui->dateEdit->setDate(date_n_e);
             QString adresse_e = ui->tableView_affiche->model()->index(index.row(), 8).data(Qt::DisplayRole).toString();
             ui->lineEdit_adr_ajouter->setText(adresse_e);
             QString type_e = ui->tableView_affiche->model()->index(index.row(), 9).data(Qt::DisplayRole).toString();
             ui->comboBox_type_ajouter->setCurrentIndex(0);
}

void emp::on_pushButton_supprimer_clicked()
{
    QModelIndex index = ui->tableView_affiche->currentIndex();
          QString cin_e = index.data(Qt::DisplayRole).toString();
        bool test=E.supprimer(cin_e);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("delete effectué.\n",
                                                 "click Cancel to exist."), QMessageBox::Cancel);

        }else{
            QMessageBox::information(nullptr, QObject::tr("not ok"),
                                     QObject::tr("delete non effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
        ui->tableView_affiche->setModel(E.afficher());
}

void emp::on_pushButton_tri_clicked()
{
    QString trie=ui->comboBox_tri->currentText();
    if(trie=="nom"){
      ui->tableView_affiche->setModel(E.Tri_nom());}
    else if(trie=="Date de naissance"){
       ui->tableView_affiche->setModel(E.Tri_dateN());
    }else if(trie=="sexe"){
        ui->tableView_affiche->setModel(E.Tri_sexe());
    }else if(trie=="trier par défaut"){
        ui->tableView_affiche->setModel(E.Tri_pardefaut());
    }
}

void emp::on_pushButton_stat_clicked()
{
    QChart *chart = new QChart();
                 chart=E.stat();
                QChartView *chartview = new QChartView(chart,ui->graphicsView_statistique);
                chartview->resize(521,192);
                chartview->setRenderHint(QPainter::Antialiasing);
                chartview->setBackgroundBrush(Qt::transparent);
            chartview->show();
}

void emp::on_pushButton_pdf_clicked()
{

    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView_affiche->model()->rowCount();
                            const int columnCount = ui->tableView_affiche->model()->columnCount();

                            out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("strTitle")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"

                               //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H1> smart RDI center \n \n\n\n</H1><H2>Liste des employee \n \n\n\n</H2><H3> \n \n\n\n</H3></br></br><table border=1 cellspacing=3 cellpadding=2>\n";


                            // headers
                            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_affiche->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_affiche->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView_affiche->isColumnHidden(column)) {
                                        QString data = ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(row, column)).toString().simplified();
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



void emp::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView_affiche->setModel(E.rechercher_nom(arg1));
    //ui->tableView_affiche->setModel(E.rechercher_sexe_h(arg1));
    //ui->tableView_affiche->setModel(E.rechercher_sexe_f(arg1));
}

void emp::on_pushButton_annuler_clicked()
{
    ui->lineEdit_cin_ajouter->clear();
    ui->lineEdit_nom_ajouter->clear();
    ui->lineEdit_prenom_ajouter->clear();
    ui->lineEdit_numtel_ajouter->clear();
    ui->comboBox_sexe->setCurrentIndex(0);
    ui->lineEdit_email_ajouter->clear();
    ui->lineEdit_mdp_ajouter->clear();
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
    ui->lineEdit_adr_ajouter->clear();
    ui->comboBox_type_ajouter->setCurrentIndex(0);
}

void emp::on_pushButton_genererqr_clicked()
{
    QString text ="detail d un Employee  :"+ ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),0)).toString()
                    +" /"+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),1)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),2)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),3)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),4)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),5)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),6)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),7)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),8)).toString()
                    +"/ "+ui->tableView_affiche->model()->data(ui->tableView_affiche->model()->index(ui->tableView_affiche->currentIndex().row(),9)).toString();


           using namespace qrcodegen;
             QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
             qint32 sz = qr.getSize();
             QImage im(sz,sz, QImage::Format_RGB32);
               QRgb black = qRgb(0, 0, 0);
               QRgb white = qRgb(255,255,255);
             for (int y = 0; y < sz; y++)
               for (int x = 0; x < sz; x++)
                 im.setPixel(x,y,qr.getModule(x, y) ? black : white );
             ui->label_11->setPixmap( QPixmap::fromImage(im.scaled(131,111,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
}


void emp::on_tableView_affiche_pressed(const QModelIndex &index)
{
    // This function is called when a cell is pressed, but we don't need to do anything here
        // because the model has already been set

        Q_UNUSED(index); // To avoid warnings about unused parameter

        // In the constructor or elsewhere, load the data once and set the model to the table view
        QAbstractItemModel *model = E.afficher();
        ui->tableView_affiche->setModel(model);

    //ui->tableView_affiche->setModel(E.afficher());
}


void emp::on_pushButton_retour_clicked()
{
        this->close();
        emp e;
        e.show();
        e.exec();
}

//PUB


void emp::on_pushButtonAjouterPub_clicked()
{
    Publication p(ui->comboBoxTypePub->currentText() , ui->plainTextEditDescPub->toPlainText()) ;
    if (ui->plainTextEditDescPub->toPlainText().isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Controle de saisie"),
                            QObject::tr("Remplir description\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (ui->plainTextEditDescPub->toPlainText().size() < 20 )
    {
        QMessageBox::warning(nullptr, QObject::tr("Controle de saisie"),
                            QObject::tr("description trop courte !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        {
    bool test = p.ajouter();
    if (test)
    {
        ptmp.ajouterhistorique("Ajout");
        ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->tableViewPub->hideColumn(4);
        ui->tableViewPubFAvoris->hideColumn(4);
        ui->tableViewPub->setColumnWidth(3,400);
        ui->tableViewPubFAvoris->setColumnWidth(3,400);
        QMessageBox::information(nullptr, QObject::tr("Information"),
                           QObject::tr("Succes\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Critical"),
                            QObject::tr("Echec \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void emp::on_pushButtonAnuulerPub_clicked()
{
    ui->comboBoxTypePub->setCurrentIndex(0);
    ui->plainTextEditDescPub->clear();
}

void emp::on_pushButtonSupprimerPub_clicked()
{
    int id = ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),0)).toInt();
    if (! ui->tableViewPub->currentIndex().isValid())
    {
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                         QObject::tr("Selectionnez une publication pour la supprimer\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    bool test = ptmp.supprimer(id);
    if (test)
    {ptmp.ajouterhistorique("Suppression");
        ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->tableViewPub->hideColumn(4);
        ui->tableViewPubFAvoris->hideColumn(4);
        ui->tableViewPub->setColumnWidth(3,400);
        ui->tableViewPubFAvoris->setColumnWidth(3,400);
        QMessageBox::information(nullptr, QObject::tr("Information"),
                           QObject::tr("Succes\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Critical"),
                            QObject::tr("Echec \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void emp::on_pushButtonModifierPub_clicked()
{
    ptmp.setTypePub(ui->comboBoxTypePub->currentText());
    ptmp.setDescPub(ui->plainTextEditDescPub->toPlainText());

    if (! ui->tableViewPub->currentIndex().isValid())
    {
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                         QObject::tr("Selectionnez une publication pour la modifier\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
    if (ui->plainTextEditDescPub->toPlainText().isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Controle de saisie"),
                            QObject::tr("Remplir description\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (ui->plainTextEditDescPub->toPlainText().size() < 20 )
    {
        QMessageBox::warning(nullptr, QObject::tr("Controle de saisie"),
                            QObject::tr("description trop courte !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        {
    bool test = ptmp.modifier();
    if (test)
    {
        ptmp.ajouterhistorique("Modification");
        ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->tableViewPub->hideColumn(4);
        ui->tableViewPubFAvoris->hideColumn(4);
        ui->tableViewPub->setColumnWidth(3,400);
        ui->tableViewPubFAvoris->setColumnWidth(3,400);
        QMessageBox::information(nullptr, QObject::tr("Information"),
                           QObject::tr("Succes\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Critical"),
                            QObject::tr("Echec \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    }

}

void emp::on_tableViewPub_doubleClicked(const QModelIndex &index)
{
   ptmp.setIdPub(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),0)).toInt());
   ui->comboBoxTypePub->setCurrentText(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),2)).toString());
   ui->plainTextEditDescPub->setPlainText(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),3)).toString());
}

void emp::on_lineEditRecherchePub_textChanged(const QString &arg1)
{
    ui->tableViewPub->setModel(ptmp.rechercher(arg1));
    ui->tableViewPub->hideColumn(4);
    ui->tableViewPubFAvoris->hideColumn(4);
    ui->tableViewPub->setColumnWidth(3,400);
    ui->tableViewPubFAvoris->setColumnWidth(3,400);
}

void emp::on_pushButtonTrierPub_clicked()
{
    QString champ = "date_pub" ;
    QString order = "asc";

   if (ui->comboBoxChampPub->currentText().compare("Type") == 0)
    {
        champ = "type_pub";
    }
    else if (ui->comboBoxChampPub->currentText().compare("Description") == 0)
    {
        champ = "desc_pub";
    }
    if (ui->comboBoxOrderPub->currentText().compare("Descendant") == 0 )
    {
        order = "desc";
    }
    ui->tableViewPub->setModel(ptmp.trier(champ,order));
    ui->tableViewPub->hideColumn(4);
    ui->tableViewPubFAvoris->hideColumn(4);
    ui->tableViewPub->setColumnWidth(3,400);
    ui->tableViewPubFAvoris->setColumnWidth(3,400);
}

void emp::on_pushButtonGenererPdfPub_clicked()
{

    QPdfWriter pdf("test.pdf");
               QPainter painter(&pdf);
               int i = 4000;
               painter.setPen(Qt::red);
               painter.setFont(QFont("Arial", 30));
               painter.drawText(3300,1200,"Liste des publications");
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial", 50));
               painter.drawRect(1500,200,7300,2600);
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("Arial", 9));
               painter.drawText(1300,3300,"Publication");
               painter.drawText(2600,3300,"Date");
               painter.drawText(3900,3300,"Type");
               painter.drawText(5200,3300,"Description");

               QSqlQuery query;
               query.prepare("select * from publication");
               query.exec();
               while (query.next())
               {
                   painter.drawText(1300,i,query.value(0).toString());
                   painter.drawText(2600,i,query.value(1).toDate().toString("dd-MM-yy"));
                   painter.drawText(3900,i,query.value(2).toString());
                   painter.drawText(5200,i,query.value(3).toString());
                   i = i +500;
               }

               int reponse = QMessageBox::question(this, "Génerer PDF", "Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
               if (reponse == QMessageBox::Yes)
               {
                   QDesktopServices::openUrl(QUrl::fromLocalFile("test.pdf"));

                   painter.end();
               }
               if (reponse == QMessageBox::No)
               {
                   painter.end();
               }

               ptmp.ajouterhistorique("Generation PDF");
               ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
   }

void emp::on_pushButtonStatistiquePub_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT type_pub FROM publication WHERE  type_pub='Article' ");
        float counta=model->rowCount();
        model->setQuery("SELECT type_pub FROM publication WHERE  type_pub='Conference' ");
        float countc=model->rowCount();
        model->setQuery("SELECT type_pub FROM publication WHERE  type_pub='Projet' ");
        float countp=model->rowCount();

        float total=counta+countp+countc;

                QPieSeries *series = new QPieSeries();
                series->append("Article",counta);
                series->append("Conference",countc);
                series->append("Projet",countp);

                if (counta!=0)
                {QPieSlice *slice = series->slices().at(0);
                    slice->setLabel("Article "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                    slice->setLabelVisible();
                    slice->setPen(QPen(Qt::black));}
                if ( countc!=0)
                {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabel("Conference "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                    slice1->setLabelVisible();
                    slice1->setBrush(QColor(Qt::cyan));
                }
                if ( countp!=0)
                {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(2);
                    //slice1->setExploded();
                    slice1->setLabel("Projet "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                    slice1->setLabelVisible();
                    slice1->setBrush(QColor(Qt::red));
                }


                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("Totale "+ QString::number(total));

                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);


                chart->legend()->hide();
                chartView->show();
                ptmp.ajouterhistorique("Voir Statistique");
                ui->tableViewHistoriquePub->setModel(ptmp.afficherhistorique());
}

void emp::on_pushButtonAjouterfavoris_clicked()
{

    int id = ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),0)).toInt();
    if (! ui->tableViewPub->currentIndex().isValid())
    {
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                         QObject::tr("Selectionnez une publication pour l'ajouter aux favoris\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    bool test = ptmp.ajouterfavoris(id);
    if (test)
    {
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->tableViewPubFAvoris->setModel(ptmp.afficherFavoris());
        ui->tableViewPub->hideColumn(4);
        ui->tableViewPubFAvoris->hideColumn(4);
        ui->tableViewPub->setColumnWidth(3,400);
        ui->tableViewPubFAvoris->setColumnWidth(3,400);
        QMessageBox::information(nullptr, QObject::tr("Information"),
                           QObject::tr("Succes\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Critical"),
                            QObject::tr("Echec \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void emp::on_pushButtonRetirerFavoris_clicked()
{
    int id = ui->tableViewPubFAvoris->model()->data(ui->tableViewPubFAvoris->model()->index(ui->tableViewPubFAvoris->currentIndex().row(),0)).toInt();
    if (! ui->tableViewPubFAvoris->currentIndex().isValid())
    {
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                         QObject::tr("Selectionnez une publication pour la retirer des favoris\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    bool test = ptmp.retirerfavoris(id);
    if (test)
    {
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->tableViewPubFAvoris->setModel(ptmp.afficherFavoris());
        ui->tableViewPub->hideColumn(4);
        ui->tableViewPubFAvoris->hideColumn(4);
        ui->tableViewPub->setColumnWidth(3,400);
        ui->tableViewPubFAvoris->setColumnWidth(3,400);
        QMessageBox::information(nullptr, QObject::tr("Information"),
                           QObject::tr("Succes\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Critical"),
                            QObject::tr("Echec \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void emp::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery query;

           query.prepare("select * from  publication  where desc_pub=:desc_pub ");

           query.bindValue(":desc_pub",ui->comboBox->currentText());

           if(query.exec())

               while(query.next())

       {
        QString nom;
       // QString sp;

          // ui->lineEdit->setText(query.value(1).toString()) ;
           nom = query.value(1).toString();
          // sp = query.value(3).toString();


           data.append(QString("%1.").arg(nom));
               A.writeToArduino(data);

       }
}

//LAB
void emp::on_pushButton_2_clicked()
{
int x=0;
        int id_labo=ui->lineEdit_id->text().toInt();
        QRegularExpression regex2("^[a-zA-Z]+$");
        QString nom_labo=ui->lineEdit_nom->text();
        QRegularExpression regex("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement

        QString ntel_labo=ui->lineEdit_ntel->text();
        QRegularExpression regex1("^[0-9]{8}$"); // Expression régulière pour 8 chiffres consécutifs

        QString specialite=ui->comboBox->currentText();
        QString adresse=ui->lineEdit_ad->text();
        QString videoo=ui->lien_video->text();
        if (regex.match(nom_labo).hasMatch() && regex1.match(ntel_labo).hasMatch()&& x==0) {
            // Le nom est valide, on peut l'utiliser
            // ... (code pour traiter le nom valide)


            x=1;





        } else {
            // Le nom est invalide
          QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );
           QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres.");
            QMessageBox::warning(this, "Erreur", "Le NTEL_LABO ne doit contenir que 8 chiffres.");
        }
        labo l(id_labo , nom_labo , ntel_labo, specialite, adresse,videoo);
         bool test=l.ajouter();
        if(test && x==1){
            //actualiser
             ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
        ui->tableView->setModel(Etmp.afficher());
        ui->comboBox_4->setModel(Etmp.setid());
         ui->comboBox_5->setModel(Etmp.setid());
           QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("Ajout effectué\n" "click cancel to exit."), QMessageBox::Cancel);

        }//else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );



}

void emp::on_Supprimer_clicked()
{// int NUMERO=ui->lineEdit_supp->text().toInt();
    int NUMERO=ui->comboBox_5->currentText().toInt();
    bool test=Etmp.supprimer(NUMERO);

    if(test){
        //actualiser
ui->tableView->setModel(Etmp.afficher());
ui->comboBox_5->setModel(Etmp.setid());
ui->comboBox_2->setModel(Etmp.setnom());
ui->comboBox_6->setModel(Etmp.sette());
        QMessageBox::information(nullptr, QObject::tr("supp"),QObject::tr("suppression effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("not supp"),QObject::tr("suppression non effectué. \n" " click cancel to exit") );

}

void emp::on_comboBox_4_activated(int index)
{
    QSqlQuery query;

        query.prepare("select * from  LABORATOIRES  where ID_LABO=:ID_LABO ");

        query.bindValue(":ID_LABO",ui->comboBox_4->currentText().toInt());

        if(query.exec())

            while(query.next())

    {


        ui->lineEdit_nom_3->setText(query.value(1).toString()) ;
        ui->lineEdit_ntel_3->setText(query.value(2).toString()) ;
        ui->lineEdit_sp_4->setText(query.value(3).toString()) ;
        ui->lineEdit_ad_3->setText(query.value(4).toString()) ;
        ui->lien_video2->setText(query.value(5).toString()) ;



    }
}

void emp::on_modifier_clicked()
{
    labo l(ui->comboBox_4->currentText().toInt(),ui->lineEdit_nom_3->text(),ui->lineEdit_ntel_3->text(),ui->comboBox_3->currentText(),ui->lineEdit_ad_3->text(),ui->lien_video2->text());
    bool test=l.modifier();




    if(test){
        //actualiser
    ui->tableView->setModel(Etmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("modification effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("modification non effectué. \n" " click cancel to exit") );
}

void emp::on_comboBox_5_activated(const QString &arg1)
{QSqlQuery query;

    query.prepare("select * from  LABORATOIRES  where ID_LABO=:ID_LABO ");

    query.bindValue(":ID_LABO",ui->comboBox_5->currentText().toInt());

    query.exec();

}

void emp::on_pushButton_3_clicked()
{
    ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_ntel->clear();

        ui->comboBox->setCurrentIndex(0);
        ui->lineEdit_ad->clear();



}

void emp::on_pushButton_4_clicked()
{
    labo Etmp;
     ui->tableView->setModel(Etmp.afficher5(ui->comboBox_tri->currentText()));
}

void emp::on_pushButton_5_clicked()
{
    ui->tableView->setModel(Etmp.afficher());
}

void emp::on_lineEdit_chercher_textChanged(const QString &arg1)
{
    labo Etmp;
        ui->tableView->setModel(Etmp.afficher4(ui->comboBox_chercher->currentText(),ui->lineEdit_chercher->text()));
}

/*void emp::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/MFELHI/Desktop/Web/projetcpp/labo2/PDF/LABO.pdf");
        QPainter painter(&pdf);

        // set background color
        painter.setBackground(QBrush(QColor("#dcdcdc")));
        painter.eraseRect(0, 0, pdf.width(), pdf.height());

        int v = 4000;
        painter.setPen(QPen(QColor("#6a1615")));
        painter.setFont(QFont("Arial", 30, QFont::Bold));
        painter.drawText(2000, 1400, "LISTE DES LABORATOIRES");

        painter.setPen(QPen(QColor("#6a1615")));
        painter.setFont(QFont("Arial", 15));
        painter.drawRect(100, 100, 9400, 2500);
        painter.drawRect(100, 3000, 9400, 500);


        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.drawText(500, 3300, "ID_LABO");
        painter.drawText(2000, 3300, "NOM_LABO");
        painter.drawText(3000, 3300, "SPECIALITE");
        painter.drawText(4000, 3300, "ADRESSE");

        QSqlQuery query;
        query.prepare("select * from LABORATOIRES");
        query.exec();
        while (query.next())
        {
            painter.setFont(QFont("Arial", 10));
            painter.setPen(QPen(QColor("#6a1615")));
            painter.drawText(500, v, query.value(0).toString());
            painter.drawText(2000, v, query.value(1).toString());
            painter.drawText(3000, v, query.value(2).toString());
            painter.drawText(4000, v, query.value(3).toString());
            painter.drawText(6000, v, query.value(4).toString());
            painter.drawText(8500, v, query.value(5).toString());

            // Draw horizontal line after writing text for each row
            painter.setPen(QPen(QColor("#6a1615")));
            painter.drawLine(100, v+50, 9500, v+50);

            v = v + 350;
        }

        // Move this line to the end of the while loop
        painter.drawRect(100, 3000, 9400, 9000);

        QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
            QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}*/

void emp::on_pushButton_6_clicked()
{
    QPdfWriter pdf("C:/Users/MFELHI/Desktop/integration/PDF/LABO.pdf");
    QPainter painter(&pdf);

    // set background color
    painter.setBackground(QBrush(QColor("#464646")));
    painter.eraseRect(0, 0, pdf.width(), pdf.height());

    int v = 4000;
    painter.setPen(QPen(QColor("#ffc34a")));
    painter.setFont(QFont("Arial", 30, QFont::Bold));
    painter.drawText(2000, 1400, "LISTE DES LABORATOIRES");

    painter.setPen(QPen(QColor("#ffc34a")));
    painter.setFont(QFont("Arial", 15));
    painter.drawRect(100, 100, 9400, 2500);
    painter.drawRect(100, 3000, 9400, 500);


    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setPen(QPen(QColor("#ffc34a")));
    painter.drawText(500, 3300, "ID ");
    painter.drawText(1000, 3300, "NOM ");
    painter.drawText(2000, 3300, "NUMERO TELEPHONE");
    painter.drawText(5000, 3300, "SPECIALITE");
    painter.drawText(6000, 3300, "ADRESSE");
    painter.drawText(8000, 3300, "Temperature");

    QSqlQuery query;
    query.prepare("select * from LABORATOIRES");
    query.exec();
    while (query.next())
    {
        painter.setFont(QFont("Arial", 10));
        painter.setPen(QPen(QColor("#ffc34a")));
        painter.drawText(500, v, query.value(0).toString());
        painter.drawText(1000, v, query.value(1).toString());
        painter.drawText(2000, v, query.value(2).toString());
        painter.drawText(5000, v, query.value(3).toString());
        painter.drawText(6000, v, query.value(4).toString());
        painter.drawText(8000, v, query.value(6).toString());

        // Draw horizontal line after writing text for each row
        painter.setPen(QPen(QColor("#ffc34a")));
        painter.drawLine(100, v+50, 9500, v+50);

        v = v + 350;
    }

    // Move this line to the end of the while loop
    painter.setPen(QPen(QColor("#ffc34a")));
    painter.drawRect(100, 3000, 9400, 9000);

    QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
        QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}




void emp::on_pushButton_7_clicked()
{
    //s=new stat_combo();

 // s->setWindowTitle("statistique ComboBox");
  //s->choix_pie();
  //s->show();
}

void emp::on_pushButton_10_clicked()
{
   ui->lineEdit_chercher->clear();
}

void emp::on_pushButton_ovrir_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
        on_pushButtonStop_clicked();

        player->setMedia(QUrl::fromLocalFile(filename));

        on_pushButtonplay_clicked();
}

void emp::on_pushButtonStop_clicked()
{
    player->stop();
   statusbar->showMessage("Stopped");

}

void emp::on_pushButtonplay_clicked()
{
    player->play();
       statusbar->showMessage("Playing");
}

void emp::on_pushButton_9_clicked()
{
    player->pause();
        statusbar->showMessage("Paused...");
}

void emp::on_pushButton_8_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    ui->lien_video->setText(filename);
}

void emp::on_pushButton_11_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    ui->lien_video2->setText(filename);
}

void emp::on_tableView_pressed(const QModelIndex &index)
{
ui->WebBrowser1->dynamicCall("Navigate(const QString&)", index.data().toString());
    player->setMedia(QUrl::fromLocalFile(index.data().toString()));
    statusbar->showMessage("Playing");
    player->play();
}













void emp::update_label()
{




}

void emp::on_comboBox_9_activated(const QString &arg1)
{
    QSqlQuery query;

           query.prepare("select * from  LABORATOIRES  where NOM_LABO=:NOM_LABO ");

           query.bindValue(":NOM_LABO",ui->comboBox_2->currentText());

           if(query.exec())

               while(query.next())

       {
        QString nom;
        QString sp;

           nom = query.value(1).toString();
           sp = query.value(6).toString();


           data.append(QString("%1,%2,!").arg(nom).arg(sp));


           A.writeToArduino(data);

       }
}





void emp::on_pushButton_12_clicked()
{

        A.writeToArduino("1"); //envoyer 1 à arduino

}

void emp::on_pushButton_13_clicked()
{
  A.writeToArduino("0");
}


void emp::on_pushButton_14_clicked()
{
  A.writeToArduino("2");
}

void emp::on_pushButton_15_clicked()
{
    data=A.readFromArduino();
       qDebug()<< "data"<< data;
       if(data.length()==5){

       ui->label_21->setText(data);
       ui->comboBox_6->setHidden(0);
       ui->cofirmer->setHidden(0);}
}

void emp::on_cofirmer_clicked()
{
    QString nom=ui->comboBox_6->currentText();
    QString  TEMP=data;
            QSqlQuery query;
            query.prepare(" UPDATE LABORATOIRES SET TEMP=:TEMP where NOM_LABO= :NOM_LABO");
            query.bindValue(":TEMP",TEMP);
            query.bindValue(":NOM_LABO",nom);

               query.exec();
               ui->tableView->setModel(Etmp.afficher());
               ui->comboBox_6->setHidden(1);
               ui->cofirmer->setHidden(1);
}


//CHERCH
void emp::on_pb_ajouter_2_clicked()
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







void emp::on_pushButton_annuler_4_clicked()
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
void emp::on_pushButton_Historique_clicked()
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



void emp::on_pushButton_PDF_2_clicked()
{


    QDate date = QDate::currentDate(); // Obtenir la date actuelle
    QString dateString = date.toString("yyyy-MM-dd");
    ui->tab_chercheur_2->setModel(ch.notification(dateString));


}







void emp::on_pushButton_mod_clicked()
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

void emp::on_pushButton_annuler_5_clicked()
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




void emp::on_pushButton_annuler_2_clicked()
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

void emp::on_pushButton_annuler_3_clicked()
{ui->le_id_mod_2->clear();
    ui->le_nom_mod_2->clear();
    ui->le_prenom_mod_2->clear();
    ui->le_num_mod_2->clear();
    QDate date = QDate::currentDate();
    ui->le_date_mod_2->setDate(date);
   ui->comboBox_2->clear();
   ui->sexe->clear();

}


void emp::on_pushButton_tri_2_clicked()
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

void emp::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tab_chercheur->setModel(ch.rechercher_nom(arg1));
}

void emp::on_pushButton_stat_2_clicked()
{
    QChart *chart = new QChart();
                 chart=ch.stat();
                QChartView *chartview = new QChartView(chart,ui->stat);
                chartview->resize(250,180);
                chartview->setRenderHint(QPainter::Antialiasing);
                chartview->setBackgroundBrush(Qt::transparent);
                chartview->show();

}

void emp::on_pushButton_PDF_clicked()
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



void emp::on_pushButton_mod_2_clicked()
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



//FORMATIONS

void emp::on_pb_ajouter_clicked()
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

void emp::on_pb_supprimer_clicked()
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




void emp::on_comboBox_2_activated(const QString &arg1)
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

/*void emp::on_pushButton_2_clicked()
{


}*/



void emp::on_pushButton_clicked()
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

void emp::on_pb_annuler_aj_clicked()
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

void emp::on_pb_annu_mod_clicked()
{
     ui->le_nom_2->clear();
     ui->dateEdit->clear();
     ui->dateEdit_2->clear();
     ui->description->clear();
}





void emp::on_radioButton_clicked()
{
    Formation f;
    ui->tab_formation->setModel(f.afficher_trie_nom());
}


void emp::on_radioButton_2_clicked()
{
    Formation f;
    ui->tab_formation->setModel(f.afficher_trie_id());
}



void emp::on_la_recherche_textChanged(const QString &arg1)
{
    ui->tab_formation->setModel(F.recherche(arg1));
}


void emp::on_pb_pdf_clicked()
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




void emp::on_pb_stat_clicked()
{

    stat_combo *s = new stat_combo();

   s->setWindowTitle("statistique ComboBox");
   s->choix_pie();
   s->show();
}



/*void emp::on_calendarWidget_selectionChanged()
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
void emp::on_pb_insert_clicked()
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


void emp::on_calendarWidget_clicked(const QDate &date)
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

void emp::on_pb_excel_clicked()
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

//


