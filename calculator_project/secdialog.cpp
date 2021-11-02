#include "secdialog.h"
#include "ui_secdialog.h"
#include "calc.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <QMessageBox>
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <sstream>
#include <vector>

using namespace std;

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    calc k = calc();
    QString qstrN = ui->lineEditPoint->text();
    n = qstrN.toInt();
    QString qstrX = ui->lineEditX->text();
    QString qstrY = ui->lineEditY->text();
    string strX = qStringToString(qstrX);
    string strY = qStringToString(qstrY);
    vector<double> x;
    vector<double> y;
    stringstream ssX(strX);
    stringstream ssY(strY);

    for (double i; ssX >> i;) {
        x.push_back(i);
        if (ssX.peek() == ',')
            ssX.ignore();
    }

    for (double i; ssY >> i;) {
        y.push_back(i);
        if (ssY.peek() == ',')
            ssY.ignore();
    }

    string rlAns = k.linearRegressionLine(x, y, n);
    QString qrlAns = QString::fromStdString(rlAns);
    ui->textBrowser->setText(qrlAns);
}

string SecDialog::qStringToString(QString qstr)
{
  string str = "";
  for(int i=0; i<qstr.length(); i++)
    str +=  qstr.at(i).toLatin1();
  return str;
}

//    double x[n],y[n];
//    cout << "\nEnter the x-axis values:\n";
//    for (int i = 0; i < n; i++)
//        cin >> x[i];
//    cout <<"\nEnter the y-axis values:\n";
//    for (int i = 0; i < n; i++)
//        cin >> y[i];
//    k.linearRegressionLine(x, y, n);

void SecDialog::on_Clear_clicked()
{
    ui->textBrowser->setText("");
}
