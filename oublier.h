#ifndef OUBLIER_H
#define OUBLIER_H

#include <QDialog>
#include "emp.h"

namespace Ui {
class oublier;
}

class oublier : public QDialog
{
    Q_OBJECT

public:
    explicit oublier(QWidget *parent = nullptr);
    ~oublier();
private slots:
    void on_Submit_clicked();


    void on_pushButton_retour_clicked();

private:
    Ui::oublier *ui;
    emp e;
};

#endif // OUBLIER_H
