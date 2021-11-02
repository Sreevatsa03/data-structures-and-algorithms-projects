#include <cstdlib>
#include <iostream>
#include "sNode.h"
#include "dMatrix.h"


#ifndef SMATRIX_H
#define SMATRIX_H

using namespace std;

class smatrix {
private:
    int nrows;
    int ncols;
    snode **rows;
public:
    smatrix(int row, int col);
    smatrix(const dmatrix &);
    virtual ~smatrix();
    float get(int row, int col) const;
    void set(int row, int col, float val);
    int getCols() const;
    int getRows() const;
    smatrix transpose() const;
    snode **getRowPtr();
    void dump() const;
    smatrix add(const smatrix &);
    smatrix multiply(const smatrix &) const;
};


#endif 

