#include "sMatrix.h"
#include "dMatrix.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    dmatrix matrix1 = dmatrix(3,3);
    dmatrix matrix2 = dmatrix(3,3);

    float a1[3][3] = {{0,5,5},{1,0,1},{5,0,7}};
    for (int i = 0; i < matrix1.getRows(); i++) {
        for (int j = 0; j < matrix1.getCols(); j++) {
            matrix1.set(i,j,a1[i][j]);
        }
    }

    matrix1.dump();
    cout << endl;

    float a2[3][3] = {{1,2,2},{5,6,1},{5,3,0}};
    for (int i = 0; i < matrix2.getRows(); i++) {
        for (int j = 0; j < matrix2.getCols(); j++) {
            matrix2.set(i,j,a2[i][j]);
        }
    }

    matrix2.dump();
    cout << endl;

    dmatrix resultMatrix = matrix1.multiply(matrix2);

    resultMatrix.dump();
    cout << endl;

    matrix1.~dmatrix();
    matrix2.~dmatrix();
    resultMatrix.~dmatrix();


    // smatrix d = smatrix(2,2);
    // d.set(0, 1, 8);
    // d.set(0, 0, 4);
    // d.set(1, 1, 1);
    // smatrix e = smatrix(2, 3);
    // e.set(0, 0, -6);
    // e.set(1, 0, 3);
    // e.set(1, 1, 11);
    // smatrix f = d.multiply(e);
    // d.dump();
    // cout << endl;
    // e.dump();
    // cout << endl;
    // f.dump();
    // cout << endl;
    // d.~smatrix();
    // e.~smatrix();
    // f.~smatrix();
}