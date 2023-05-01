#include "lab.h"
#include "ui_lab.h"

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


lab::lab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lab)
{



    ui->setupUi(this);
   //   this->layout()->addWidget(statusbar);

   int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).


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
}

lab::~lab()
{
      A.getserial()->close();
      //A.getserial()->
    delete ui;
}

void lab::on_pushButton_clicked()
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

void lab::on_Supprimer_clicked()
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

void lab::on_comboBox_4_activated(int index)
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

void lab::on_modifier_clicked()
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

void lab::on_comboBox_5_activated(const QString &arg1)
{QSqlQuery query;

    query.prepare("select * from  LABORATOIRES  where ID_LABO=:ID_LABO ");

    query.bindValue(":ID_LABO",ui->comboBox_5->currentText().toInt());

    query.exec();

}

void lab::on_pushButton_2_clicked()
{
    ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_ntel->clear();

        ui->comboBox->setCurrentIndex(0);
        ui->lineEdit_ad->clear();



}

void lab::on_pushButton_3_clicked()
{
    labo Etmp;
     ui->tableView->setModel(Etmp.afficher5(ui->comboBox_tri->currentText()));
}

void lab::on_pushButton_4_clicked()
{
    ui->tableView->setModel(Etmp.afficher());
}

void lab::on_lineEdit_chercher_textChanged(const QString &arg1)
{
    labo Etmp;
        ui->tableView->setModel(Etmp.afficher4(ui->comboBox_chercher->currentText(),ui->lineEdit_chercher->text()));
}

/*void lab::on_pushButton_pdf_clicked()
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

void lab::on_pushButton_5_clicked()
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




void lab::on_pushButton_7_clicked()
{
    //s=new stat_combo();

 // s->setWindowTitle("statistique ComboBox");
  //s->choix_pie();
  //s->show();
}

void lab::on_pushButton_6_clicked()
{
   ui->lineEdit_chercher->clear();
}

void lab::on_pushButton_ovrir_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
        on_pushButtonStop_clicked();

        player->setMedia(QUrl::fromLocalFile(filename));

        on_pushButtonplay_clicked();
}

void lab::on_pushButtonStop_clicked()
{
    player->stop();
   statusbar->showMessage("Stopped");

}

void lab::on_pushButtonplay_clicked()
{
    player->play();
       statusbar->showMessage("Playing");
}

void lab::on_pushButton_9_clicked()
{
    player->pause();
        statusbar->showMessage("Paused...");
}

void lab::on_pushButton_8_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    ui->lien_video->setText(filename);
}

void lab::on_pushButton_10_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    ui->lien_video2->setText(filename);
}

void lab::on_tableView_pressed(const QModelIndex &index)
{
ui->WebBrowser1->dynamicCall("Navigate(const QString&)", index.data().toString());
    player->setMedia(QUrl::fromLocalFile(index.data().toString()));
    statusbar->showMessage("Playing");
    player->play();
}













void lab::update_label()
{




}

void lab::on_comboBox_2_activated(const QString &arg1)
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


           A.write_to_arduino(data);

       }
}





void lab::on_pushButton_12_clicked()
{

        A.write_to_arduino("1"); //envoyer 1 à arduino

}

void lab::on_pushButton_13_clicked()
{
  A.write_to_arduino("0");
}


void lab::on_pushButton_11_clicked()
{
  A.write_to_arduino("2");
}

void lab::on_pushButton_14_clicked()
{
    data=A.read_from_arduino();
       qDebug()<< "data"<< data;
       if(data.length()==5){

       ui->label_21->setText(data);
       ui->comboBox_6->setHidden(0);
       ui->cofirmer->setHidden(0);}
}

void lab::on_cofirmer_clicked()
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
