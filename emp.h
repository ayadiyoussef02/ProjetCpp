#ifndef EMP_H
#define EMP_H

#include <QDialog>
#include"employee.h"
//Publications
#include <QDialog>
#include <QMessageBox>
#include "publication.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QtCharts>
#include "arduino.h"
//LAB
#include <QDialog>
#include "labo.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <QVector>
#include  <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>
#include <QDateTime>
#include <QDate>
#include <QSortFilterProxyModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QProgressBar>
#include <QSlider>

#include "arduino1.h"
#include "temp.h"
#include <QStatusBar>
#include <QLayout>
//CHERCH
#include "chercheur.h"
//FORMAT
#include "formation.h"

#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QTextDocument>
//

namespace Ui {
class emp;
}

class emp : public QDialog
{
    Q_OBJECT

public:
    explicit emp(QWidget *parent = nullptr,const QString& str = "");
    ~emp();

private slots:
    //EMP
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_charger_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_tri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_annuler_clicked();

    void on_pushButton_genererqr_clicked();



    void on_tableView_affiche_pressed(const QModelIndex &index);

    void on_pushButton_retour_clicked();
    //Pub

    void on_pushButtonAjouterPub_clicked();

    void on_pushButtonAnuulerPub_clicked();

    void on_pushButtonSupprimerPub_clicked();

    void on_pushButtonModifierPub_clicked();

    void on_tableViewPub_doubleClicked(const QModelIndex &index);

    void on_lineEditRecherchePub_textChanged(const QString &arg1);

    void on_pushButtonTrierPub_clicked();

    void on_pushButtonGenererPdfPub_clicked();

    void on_pushButtonStatistiquePub_clicked();

    void on_pushButtonAjouterfavoris_clicked();

    void on_pushButtonRetirerFavoris_clicked();

    void on_comboBox_activated(const QString &arg1);

    //LAB
    void on_pushButton_2_clicked();

       void on_Supprimer_clicked();

       void on_comboBox_4_activated(int index);

       void on_modifier_clicked();

       void on_comboBox_5_activated(const QString &arg1);

       void on_pushButton_3_clicked();//

       void on_pushButton_4_clicked();

       void on_pushButton_5_clicked();

      // void on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2);

       void on_lineEdit_chercher_textChanged(const QString &arg1);



       void on_pushButton_6_clicked();

       void on_pushButton_10_clicked();

       void on_pushButton_7_clicked();

       void on_pushButton_ovrir_clicked();

       void on_pushButtonStop_clicked();

       void on_pushButtonplay_clicked();

       void on_pushButton_9_clicked();

       void on_pushButton_8_clicked();//

       void on_pushButton_11_clicked();

       void on_tableView_pressed(const QModelIndex &index);



      // void on_pushButton_11_clicked();
       void on_pushButton_12_clicked();

     //  void on_on_clicked();
       void update_label();

     //  void on_off_clicked();

       void on_pushButton_13_clicked();

      // void on_pushButton_14_clicked();

       void on_comboBox_9_activated(const QString &arg1);



       void on_pushButton_14_clicked();

       void on_pushButton_15_clicked();

       void on_cofirmer_clicked();
    //CHERCH
       void on_pb_ajouter_2_clicked();


          void on_pushButton_annuler_4_clicked();

           void on_pushButton_mod_clicked();

           void on_pushButton_annuler_5_clicked();



           void on_pushButton_annuler_2_clicked();

           void on_pushButton_annuler_3_clicked();

           void on_pushButton_tri_2_clicked();

           void on_lineEdit_2_textChanged(const QString &arg1);

           void on_pushButton_stat_2_clicked();

           void on_pushButton_PDF_clicked();

           void on_pushButton_Historique_clicked();

           void on_pushButton_PDF_2_clicked();

           void on_pushButton_mod_2_clicked();
           //FORMAT
           void on_pb_ajouter_clicked();

           void on_pb_supprimer_clicked();




           void on_comboBox_2_activated(const QString &arg1);





           void on_pushButton_clicked();

           void on_pb_annuler_aj_clicked();

           void on_pb_annu_mod_clicked();



           void on_radioButton_clicked();

           void on_radioButton_2_clicked();



           void on_la_recherche_textChanged(const QString &arg1);



           void on_pb_pdf_clicked();

           void on_pb_stat_clicked();



           void on_pb_insert_clicked();

           void on_calendarWidget_clicked(const QDate &date);

           void on_pb_excel_clicked();
           //

private:
    Ui::emp *ui;
    Employee E;
    //PUB
    Publication ptmp;
          QByteArray data; // variable contenant les données reçues

          Arduino A;
          // LAB
          labo Etmp;
               TEMP etmp;
               //stat1 *s;
               QMediaPlayer* player;
               QVideoWidget* vw;
               QProgressBar* bar;
               QSlider* slider;
     //          QByteArray data;
               QByteArray data1;// variable contenant les données reçues

              // Arduino1 A;
                QStatusBar* statusbar= new QStatusBar();
                //CHERCH
                 chercheur ch;
                 //FORMAT
                  Formation F;
};

#endif // EMP_H
