#include "DMatrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// dmatrix::dmatrix() {

// }

dmatrix::dmatrix(int r, int c) {
    rowsTotal = r;
    colsTotal = c;
    matrix = new float*[colsTotal]; 
    for (int i = 0; i < colsTotal; ++i) {
         matrix[i] = new float[rowsTotal];
    }
}

float dmatrix::get(int row, int col) {
    for (int i = 0; i < rowsTotal; i++) {  
        for (int j = 0; j < colsTotal; j++) { 
            if (i == row && j == col) {
                return matrix[i][j];
                break;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

void dmatrix::set(int row, int col, float value) {
    for (int i = 0; i < rowsTotal; i++) {  
        for (int j = 0; j < colsTotal; j++) { 
            if (i == row && j == col) {
                matrix[i][j] = value;
            }
        }
    }
}

int dmatrix::getTotalRows() {
    return rowsTotal;
}

int dmatrix::getTotalCols() {
    return colsTotal;
}

// float dmatrix::matrixMultiply(float matrix1[int rows1][int cols1], float matrix2[int rows2][int cols2]) {

// }

// float dmatrix::matrixMultiply(float dmatrix matrix1, float dmatrix matrix2) {
    
// }

dmatrix::~dmatrix() {
    for (int i = 0; i < rowsTotal; i++) {  
        for (int j = 0; j < colsTotal; j++) { 
            free (matrix);
        }
    }
}