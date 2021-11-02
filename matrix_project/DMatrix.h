#include <cstdlib>
#include <iostream>

#ifndef DMATRIX_H
#define DMATRIX_H

using namespace std;

class dmatrix {
private:
    int rowsTotal;
    int colsTotal;
    float **matrix;
public:
    // dmatrix(int rows, int cols);
    // dmatrix();
    // virtual ~dmatrix();
    // float** getArr() const;
    // // dmatrix(const dmatrix &);
    // int getSize() const;
    // float get(int row, int col) const;
    // void set(int row, int col, float val);
    // int getRows() const;
    // int getCols() const;
    // void dump() const;
    // dmatrix multiply(const dmatrix &);
    dmatrix();
    dmatrix(int, int);
    // dmatrix(const dmatrix &);
    float get(int, int) const;
    int getSize() const;
    int getRows() const;
    int getCols() const;
    void set(int, int, float);
    dmatrix multiply(const dmatrix &);
    void dump() const;
    virtual ~dmatrix();
    float** getArr() const;
};


#endif 