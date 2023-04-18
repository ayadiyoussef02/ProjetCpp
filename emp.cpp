#include "emp.h"
#include "oublier.h"
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

emp::emp(QWidget *parent, const QString& str) :
    QDialog(parent),
    ui(new Ui::emp)
{
    ui->setupUi(this);
    //pour annuler des affichage des choses
    //if (str!="Chef")
        //ui->groupBox->hide();
    //ui->pushButton_retour->setText(str);

   // ui->tableView_affiche->setModel(E.afficher());
    ui->lineEdit_cin_ajouter->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_nom_ajouter->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->lineEdit_prenom_ajouter->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->lineEdit_numtel_ajouter->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
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
