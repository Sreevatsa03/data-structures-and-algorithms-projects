#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDialog>
#include <QMessageBox>
#include <string>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString math;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    string qStringToString(QString qstr);

private slots:
    void on_Enter_clicked();

    void on_Clear_clicked();

    void on_NextWindow_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
