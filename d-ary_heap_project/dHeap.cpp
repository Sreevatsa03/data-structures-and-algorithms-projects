#include "dHeap.h"

using namespace std;

typedef pair<int, int> pairs;

dheap::dheap(int n) {
    vecHeap = vector<pairs>();
    d = n;
}

bool dheap::empty() {
    if (vecHeap.size() == 0)
        return true;
    else 
        return false;
}

vector<pair<int, int>> dheap::getHeap() {
    return vecHeap;
}

int dheap::first(int i) {
    return d * i + 1;
}

int dheap::last(int i) {
    return d * i + d;
}

int dheap::parent(int i) {
    return (i - 1) / d;
}

pairs dheap::getMin() {
    return vecHeap.at(0);
}

void dheap::insert(pair<int, int> newP) {
    vecHeap.push_back(newP);
    siftUp(vecHeap.size() - 1);
}

void dheap::pop() {
    // vecHeap[0] = vecHeap.back();
    // vecHeap.pop_back();
    // siftDown(0);
    pairs temp = vecHeap.at(vecHeap.size() - 1);
    vecHeap.at(0);
    vecHeap.resize(vecHeap.size() - 1);
    siftDown(0, vecHeap.size() - 2);
} 

void dheap::siftUp(int i) {
    int p = parent(i);
  
    if (p > 0) { 
        if (vecHeap[p].first > vecHeap[i].first) { 
            swap(vecHeap[i], vecHeap[p]); 
  
            siftUp(p); 
        } 
    }
}

void dheap::siftDown(int index, int n) {
    int min = index; 
    int f = first(index); 
    int el = last(index); 

    for (int j = f; j <= el; j++) {
        if (j < n && vecHeap[j].first < vecHeap[min].first)
            min = j;

        if (min != index) {
            swap(vecHeap[index], vecHeap[min]);

            siftDown(min, n);
        }
    }
}

void dheap::printHeap() {
    int a = 0;
    int b = 0;
    for (int i = 0; i < vecHeap.size(); i++){
        int x = vecHeap.at(i).first;
        cout << x << " ";
        b++;
        if (b % (int) pow(d, a) == 0) {
            cout << endl;
            a++;
            b = 0;
        }
    }
    cout << endl;
}

void dheap::dump() {
    for (int i = 0; i < vecHeap.size(); i++) 
        cout << vecHeap[i].first << " "; 
    cout << "\n";
}