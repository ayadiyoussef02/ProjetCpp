#ifndef EMP_H
#define EMP_H

#include <QDialog>
#include"employee.h"

namespace Ui {
class emp;
}

class emp : public QDialog
{
    Q_OBJECT

public:
    explicit emp(QWidget *parent = nullptr);
    ~emp();

private slots:
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

private:
    Ui::emp *ui;
    Employee E;
};

#endif // EMP_H
