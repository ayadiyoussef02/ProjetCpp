#ifndef PUB_H
#define PUB_H

#include <QDialog>
#include <QMessageBox>
#include "publication.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QtCharts>
#include "arduino.h"

namespace Ui {
class Pub;
}

class Pub : public QDialog
{
    Q_OBJECT

public:
    explicit Pub(QWidget *parent = nullptr);
    ~Pub();
private slots:
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

private:
    Ui::Pub *ui;
    Publication ptmp;
       QByteArray data; // variable contenant les données reçues

       Arduino A;
};

#endif // PUB_H
