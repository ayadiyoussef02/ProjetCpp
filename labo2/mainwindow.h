#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "labo.h"

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
    void on_pushButton_clicked();

    void on_Supprimer_clicked();

    void on_comboBox_4_activated(int index);

    void on_modifier_clicked();

    void on_comboBox_5_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    labo Etmp;
};
#endif // MAINWINDOW_H
