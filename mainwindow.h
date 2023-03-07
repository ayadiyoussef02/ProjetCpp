#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employee.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_charger_clicked();

    void on_pushButton_supprimer_clicked();

    //void on_pushButton_stat_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_tri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Employee E;
};
#endif // MAINWINDOW_H
