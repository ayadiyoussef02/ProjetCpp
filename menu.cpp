#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent, const QString& str) :
    QDialog(parent),
    ui(new Ui::menu)
{

    ui->setupUi(this);

     if (str!="Chef")
         ui->pushButton_emp->hide();

     type = str;

}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_emp_clicked()
{

e=new emp(this,type);
    //this->hide();
    e->exec();
}


void menu::on_pushButton_form_clicked()
{
    f=new Format(this);

        f->exec();
}


void menu::on_pushButton_labo_clicked()
{
   l=new lab(this);

        l->exec();
}


void menu::on_pushButton_pub_clicked()
{
    p=new Pub(this);

        p->exec();
}


void menu::on_pushButton_cherch_clicked()
{
    ch=new cherch(this);

        ch->exec();
}

