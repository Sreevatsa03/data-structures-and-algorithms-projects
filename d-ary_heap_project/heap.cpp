#include "heap.h"

using namespace std;

heap::heap() {
    vecHeap = vector<int>();
}

heap::heap(vector<int> vec) {
    vecHeap = vector<int>();
    for (int i = 0; i < vec.size(); i++) {
        vecHeap.push_back(vec[i]);
    }
}

vector<int> heap::getHeap() {
    return vecHeap;
}

int heap::left(int i) {
    return 2 * i + 1;
}

int heap::right(int i) {
    return 2 * i + 2;
}

int heap::parent(int i) {
    return (i - 1) / 2;
}

int heap::getMax() {
    return vecHeap.at(0);
}

void heap::insert(int val) {
    vecHeap.push_back(val);
    siftUp(vecHeap.size() - 1, vecHeap.size());
}

// void heap::removeMax() {
//     for (int i = 0; i < vecHeap.size(); i++) {

//     }
// }

void heap::heapSort() { 
    for (int i = vecHeap.size() / 2 - 1; i >= 0; i--) 
        siftDown(i, vecHeap.size()); 
  
    for (int i = vecHeap.size() - 1; i >= 0; i--) { 
        swap(vecHeap[0], vecHeap[i]); 
        siftDown(0, i); 
    } 
} 

void heap::siftUp(int i, int n) {
    int p = parent(i);
  
    if (vecHeap[p] > 0) { 
        if (vecHeap[i] > vecHeap[p]) { 
            swap(vecHeap[i], vecHeap[p]); 
  
            siftUp(p, n); 
        } 
    }
}

void heap::siftDown(int i, int n) {
    int max = i; 
    int el = left(i); 
    int r = right(i); 
  
    if (el < n && vecHeap[el] > vecHeap[max]) 
        max = el; 
  
    if (r < n && vecHeap[r] > vecHeap[max]) 
        max = r; 
  
    if (max != i) { 
        swap(vecHeap[i], vecHeap[max]); 
  
        siftDown(max, n); 
    } 
}
void heap::printHeap() {
    // for (int i = 0; i < vecHeap.size(); i++) 
    //     cout << vecHeap[i] << " "; 
    // cout << "\n"; 
    int a = 0;
    int b = 0;
    for (int i = 0; i < vecHeap.size(); i++){
        int x = vecHeap.at(i);
        cout << x << " ";
        b++;
        if (b % (int) pow(2, a) == 0) {
            cout << endl;
            a++;
            b = 0;
        }
    }
    cout << endl;
}