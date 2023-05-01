#ifndef LAB_H
#define LAB_H

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

namespace Ui {
class lab;
}

class lab : public QDialog
{
    Q_OBJECT

public:
    explicit lab(QWidget *parent = nullptr);
    ~lab();

private slots:
    void on_pushButton_clicked();

    void on_Supprimer_clicked();

    void on_comboBox_4_activated(int index);

    void on_modifier_clicked();

    void on_comboBox_5_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

   // void on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_chercher_textChanged(const QString &arg1);



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_ovrir_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonplay_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_tableView_pressed(const QModelIndex &index);



   // void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();

  //  void on_on_clicked();
    void update_label();

  //  void on_off_clicked();

    void on_pushButton_13_clicked();

   // void on_pushButton_14_clicked();

    void on_comboBox_2_activated(const QString &arg1);



    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_cofirmer_clicked();

private:
    Ui::lab *ui;
    labo Etmp;
      TEMP etmp;
      //stat1 *s;
      QMediaPlayer* player;
      QVideoWidget* vw;
      QProgressBar* bar;
      QSlider* slider;
      QByteArray data;
      QByteArray data1;// variable contenant les données reçues

      Arduino1 A;
       QStatusBar* statusbar= new QStatusBar();



};

#endif // LAB_H
