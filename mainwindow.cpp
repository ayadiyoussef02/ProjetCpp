#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QPrintDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_affiche->setModel(E.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    QString cin_e=ui->lineEdit_cin_ajouter->text();
    QString nom_e=ui->lineEdit_nom_ajouter->text();
    QString prenom_e=ui->lineEdit_prenom_ajouter->text();
    QString num_tel_e=ui->lineEdit_numtel_ajouter->text();
    QString sexe_e=ui->lineEdit_sexe_ajouter->text();
    QString email_e=ui->lineEdit_email_ajouter->text();
    QString mtp_e=ui->lineEdit_mdp_ajouter->text();
    QDate date_n_e=ui->dateEdit->date();
    QString adresse_e=ui->lineEdit_adr_ajouter->text();
    QString type_e=ui->comboBox_type_ajouter->currentText();


    Employee E(cin_e,nom_e,prenom_e,num_tel_e,sexe_e,mtp_e,email_e,adresse_e,date_n_e,type_e);

    bool test = E.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("ajout effectué.\n",
                                             "click Cancel to exist."), QMessageBox::Cancel);
    }else{
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                                 QObject::tr("ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
         ui->tableView_affiche->setModel(E.afficher());
}

void MainWindow::on_pushButton_modifier_clicked()
{
    QString cin_e=ui->lineEdit_cin_ajouter->text();
    QString nom_e=ui->lineEdit_nom_ajouter->text();
    QString prenom_e=ui->lineEdit_prenom_ajouter->text();
    QString num_tel_e=ui->lineEdit_numtel_ajouter->text();
    QString sexe_e=ui->lineEdit_sexe_ajouter->text();
    QString email_e=ui->lineEdit_email_ajouter->text();
    QString mtp_e=ui->lineEdit_mdp_ajouter->text();
    QDate date_n_e=ui->dateEdit->date();
    QString adresse_e=ui->lineEdit_adr_ajouter->text();
    QString type_e=ui->comboBox_type_ajouter->currentText();



         Employee E(cin_e,nom_e,prenom_e,num_tel_e,sexe_e,mtp_e,email_e,adresse_e,date_n_e,type_e);
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
                     ui->lineEdit_sexe_ajouter->setText("");
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
            }
        }
        ui->tableView_affiche->setModel(E.afficher());
}

void MainWindow::on_pushButton_charger_clicked()
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
             ui->lineEdit_sexe_ajouter->setText(sexe_e);
             QString email_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
             ui->lineEdit_email_ajouter->setText(email_e);
             QString mtp_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
             ui->lineEdit_mdp_ajouter->setText(mtp_e);
             QDate date_n_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toDate();
             ui->dateEdit->setDate(date_n_e);
             QString adresse_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
             ui->lineEdit_adr_ajouter->setText(adresse_e);
             QString type_e = ui->tableView_affiche->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
             ui->comboBox_type_ajouter->currentText();
}

void MainWindow::on_pushButton_supprimer_clicked()
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

void MainWindow::on_pushButton_tri_clicked()
{
    QString trie=ui->comboBox_tri->currentText();
    if(trie=="nom"){
      ui->tableView_affiche->setModel(E.Tri_nom());}
    else if(trie=="Date de naissance"){
       ui->tableView_affiche->setModel(E.Tri_dateN());
    }
}
/*
void MainWindow::on_pushButton_stat_clicked()
{
    s = new stats();

  s->setWindowTitle("Stats");
  s->Stats_bar();
  s->show();
}*/

void MainWindow::on_pushButton_pdf_clicked()
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



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView_affiche->setModel(E.rechercher(arg1));
}
