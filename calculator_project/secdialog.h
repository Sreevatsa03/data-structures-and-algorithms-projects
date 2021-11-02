#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QLineEdit>
#include <QDialog>
#include <QMessageBox>
#include <string>
#include <iostream>

using namespace std;

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    int n;
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();
    string qStringToString(QString qstr);

private slots:
    void on_pushButton_clicked();

    void on_Clear_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
