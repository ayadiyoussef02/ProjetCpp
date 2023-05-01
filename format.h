#ifndef FORMAT_H
#define FORMAT_H




#include <QDialog>

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

namespace Ui {
class Format;
}

class Format : public QDialog
{
    Q_OBJECT

public:
    explicit Format(QWidget *parent = nullptr);
    ~Format();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();




    void on_comboBox_activated(const QString &arg1);





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

private:

    Ui::Format *ui;

    Formation F;
};

#endif // FORMAT_H
