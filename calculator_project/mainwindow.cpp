#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calc.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <QMessageBox>
#include <QDialog>
#include <QString>
#include "secdialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Enter_clicked()
{
    calc k =  calc();
    math = ui->lineEdit->text();
    string m = qStringToString(math);
    float x = k.arithmetic(m);
    string xs = to_string(x);
    QString qstr = QString::fromStdString(xs);
    ui->lineEdit->setText(qstr);
}

string MainWindow::qStringToString(QString qstr)
{
  string str = "";
  for(int i=0; i<qstr.length(); i++)
    str +=  qstr.at(i).toLatin1();
  return str;
}

void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_NextWindow_clicked()
{
    SecDialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();
}
