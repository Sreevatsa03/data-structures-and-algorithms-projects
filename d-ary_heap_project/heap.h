#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <locale>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class heap {
private:
    vector<int> vecHeap;
    void siftUp(int, int);
    void siftDown(int, int);
    int left(int);
    int right(int);
    int parent(int);
public:
    heap(vector<int>);
    heap();
    vector<int> getHeap();
    int getMax();
    void insert(int);
    void heapSort();
    void removeMax();
    // void heapify(int);
    void printHeap();
};

#endif /* HEAP_H_ */
