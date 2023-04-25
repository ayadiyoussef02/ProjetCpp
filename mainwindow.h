#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emp.h"
#include "connection.h"
#include "arduino.h"

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


    void on_pushButton_conncter_clicked();
    void returnEmloyee();

private:
    Ui::MainWindow *ui;
    Arduino A;
    QByteArray data;

  //  emp *e;
};
#endif // MAINWINDOW_H
