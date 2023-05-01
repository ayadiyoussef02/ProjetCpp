#include "pub.h"
#include "ui_pub.h"

Pub::Pub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pub)
{
    ui->setupUi(this);
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
}

Pub::~Pub()
{
      A.getSerial()->close();
    delete ui;
}

void Pub::on_pushButtonAjouterPub_clicked()
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

void Pub::on_pushButtonAnuulerPub_clicked()
{
    ui->comboBoxTypePub->setCurrentIndex(0);
    ui->plainTextEditDescPub->clear();
}

void Pub::on_pushButtonSupprimerPub_clicked()
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

void Pub::on_pushButtonModifierPub_clicked()
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

void Pub::on_tableViewPub_doubleClicked(const QModelIndex &index)
{
   ptmp.setIdPub(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),0)).toInt());
   ui->comboBoxTypePub->setCurrentText(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),2)).toString());
   ui->plainTextEditDescPub->setPlainText(ui->tableViewPub->model()->data(ui->tableViewPub->model()->index(ui->tableViewPub->currentIndex().row(),3)).toString());
}

void Pub::on_lineEditRecherchePub_textChanged(const QString &arg1)
{
    ui->tableViewPub->setModel(ptmp.rechercher(arg1));
    ui->tableViewPub->hideColumn(4);
    ui->tableViewPubFAvoris->hideColumn(4);
    ui->tableViewPub->setColumnWidth(3,400);
    ui->tableViewPubFAvoris->setColumnWidth(3,400);
}

void Pub::on_pushButtonTrierPub_clicked()
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

void Pub::on_pushButtonGenererPdfPub_clicked()
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

void Pub::on_pushButtonStatistiquePub_clicked()
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

void Pub::on_pushButtonAjouterfavoris_clicked()
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

void Pub::on_pushButtonRetirerFavoris_clicked()
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

void Pub::on_comboBox_activated(const QString &arg1)
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

