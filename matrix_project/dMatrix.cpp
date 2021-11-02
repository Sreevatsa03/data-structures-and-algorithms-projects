#include "dMatrix.h"
#include <iostream>

using namespace std;

dmatrix::dmatrix() {
    rowsTotal = 0;
    colsTotal = 0;
}

dmatrix::dmatrix(int row, int col) {
    matrix = new float*[row];
    for(int row = 0; row < row; row++) {
        matrix[row] = new float[col];
    }
    rowsTotal = row;
    colsTotal = col;
}

int dmatrix::getRows() const{
    return rowsTotal;
}

float** dmatrix::getArr() const {
    return matrix;
}

int dmatrix::getCols() const {
    return colsTotal;
}

int dmatrix::getSize() const {
    return rowsTotal * colsTotal;
}

float dmatrix::get(int row, int col) const {
    if(row >= 0 && row < rowsTotal && col >= 0 && col < colsTotal) {
        return  matrix[row][col];
    } else {
        cout << "Get() method was out of bounds" << endl;
        return 0;
    }
}

void dmatrix::set(int row, int col, float value) {
    if(row  >= 0 && row < rowsTotal && col >= 0 && col < colsTotal) {
        matrix[row][col] = value;
    } else {
        cout << "Out of bounds error." << endl; 
    }
}

dmatrix dmatrix::multiply(const dmatrix &right) {
    if(getCols() != right.getRows()) {
        cout << "Not possible multiplication." << endl;
        dmatrix left = dmatrix(getRows(), getCols());
        return left;
    }
    dmatrix* result = new dmatrix(getRows(), right.getCols());
    for(int i = 0; i < getRows(); i++) {
        for(int j = 0; j < right.getCols(); j++) {
            float value = 0;
            for(int k = 0; k < right.getRows(); k++) {
                value += get(i, k) * right.get(k, j);
            }
            result -> set(i, j, value);
        }
    }
    return *result;
}

// dmatrix::dmatrix(const dmatrix &original) {
//     rowsTotal= original.getRows();
//     colsTotal = original.getCols();
//     matrix = new float*[rowsTotal];
//     for(int row = 0; row < rowsTotal; row++) {
//         matrix[row] = new float[colsTotal];
//     }
//     float** ptr = original.getArr();
//     for(int row = 0; row < rowsTotal; row++) {
//         for(int col = 0; col < colsTotal; col++) {
//             matrix[row][col] = ptr[row][col];
//         }
//     }
// }

void dmatrix::dump() const {
    for(int x = 0; x < rowsTotal; x++) {
        for(int y = 0; y < colsTotal; y++) {
            cout << get(x, y) << " ";
        }
        cout << endl;
    }
}

dmatrix::~dmatrix() {
    delete[] matrix;
}
