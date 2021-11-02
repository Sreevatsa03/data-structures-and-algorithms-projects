/*
 * calc.h
 *
 *  Created on: Oct 7, 2019
 *      Author: nvm
 */

#ifndef CALC_H_
#define CALC_H_


#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include "mathNode.h"


#ifndef CALC_H
#define CALC_H

using namespace std;

class calc {
private:
    float ans=0;
public:
    mathNode convert(string);
    float arithmetic(string);
    string linearRegressionLine(vector<double>, vector<double>, int n);
};

#endif


#endif /* CALC_H_ */
