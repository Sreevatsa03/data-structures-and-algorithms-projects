/*
 * main.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: nvm
 */

#include <string>
#include <string.h>
#include <stdio.h>
#include "calc.h"
#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
