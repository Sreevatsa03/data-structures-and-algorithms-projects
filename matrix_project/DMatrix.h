#include <iostream>
#include <cstdlib>
// #include "DMatrix.cpp"

#ifndef DMATRIX_H_
#define DMATRIX_H_

using namespace std;

class dmatrix {
    private:
        int rowsTotal;
        int colsTotal;
        float **matrix;
    public:
        dmatrix();
        dmatrix(int rows, int cols);
        ~dmatrix();
        float get(int row, int col);
        void set(int row, int col, float value);
        int getTotalRows();
        int getTotalCols();
        // float matrixMultiply(float matrix1[int rows1][int cols1], float matrix2[int rows2][int cols2]);
        // float matrixMultiply(float dmatrix matrix1, float dmatrix matrix2);
};




#endif