#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "emp.h"
#include "cherch.h"
#include "pub.h"
#include "emp.h"
#include "lab.h"
#include "format.h"


namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr,const QString& str = "");
    ~menu();

private slots:
    void on_pushButton_emp_clicked();

    void on_pushButton_form_clicked();

    void on_pushButton_labo_clicked();

    void on_pushButton_pub_clicked();

    void on_pushButton_cherch_clicked();

private:
    Ui::menu *ui;
    emp *e;
    Format *f;
    lab *l;
cherch *ch;
Pub *p;
    QString type;
};

#endif // MENU_H
