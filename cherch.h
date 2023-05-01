#ifndef CHERCH_H
#define CHERCH_H

#include <QDialog>
#include "chercheur.h"
namespace Ui {
class cherch;
}

class cherch : public QDialog
{
    Q_OBJECT

public:
    explicit cherch(QWidget *parent = nullptr);
    ~cherch();

private slots:
    void on_pb_ajouter_clicked();


   void on_pushButton_annuler_4_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_annuler_5_clicked();



    void on_pushButton_annuler_clicked();

    void on_pushButton_annuler_3_clicked();

    void on_pushButton_tri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_stat_clicked();

    void on_pushButton_PDF_clicked();

    void on_pushButton_Historique_clicked();

    void on_pushButton_PDF_2_clicked();

    void on_pushButton_mod_2_clicked();

private:
    Ui::cherch *ui;
    chercheur ch;

};

#endif // CHERCH_H
