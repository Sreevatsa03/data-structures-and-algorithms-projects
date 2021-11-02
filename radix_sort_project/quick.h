#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <locale>
#include <vector>
#include <chrono>
#include <fstream>

#ifndef QUICK_H_
#define QUICK_H_

using namespace std;

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (vector<int> &arr, int low, int high) {  
    int pivot = arr[high];
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  {  
        if (arr[j] < pivot)  {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort2(vector<int> &arr, int low, int high) {  
    if (low < high) {  
        int pi = partition(arr, low, high);  

        quickSort2(arr, low, pi - 1);  
        quickSort2(arr, pi + 1, high);  
    }  
}

void quickSort(vector<int> &arr) {
    quickSort2(arr, 0, arr.size() - 1);
}

#endif
