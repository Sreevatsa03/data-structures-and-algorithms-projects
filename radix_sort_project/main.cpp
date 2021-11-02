/*
1. Implement quick sort
2. Implement radix sort
3. Sort a bunch of data
4. Compare runtimes
    a) 4 datasets min
        I. 2 quick sort faster
        II. 2 radix sort faster
5. Conclude when to use radix sort
*/

#include "quick.h"
#include "radix.h"
#include <fstream>
#include <limits.h>

using namespace std;

void print(vector<int> &arr) {   
    for (int i = 0; i < arr.size(); i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}

void quick(vector <int> a) {
    // print(a);
    quickSort(a);
    // print(a);
}

void radix(vector<int> a, int d) {
    // print(a);
    radixSort(a, d);
    // print(a);
}

int main() {
    using namespace std::chrono;
    vector<int> v;

    // ifstream infile("Birthdays.csv");
    // int a;
    // while (infile >> a) {
    //     v.push_back(a);
    // }

    for (int i = 0; i < 1000000; i++) {
        unsigned long int x = rand() % ULONG_MAX;
        v.push_back(x);
    }
    
    for (int b = 2; b <= 15; b++) {
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++)
            quick(v);
        auto t2 = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>( t2 - t1 ).count();

        cout << "Quick Sort duration: " << duration  << " milliseconds" << endl;
        cout << endl;
    }   
    for (int b = 2; b <= 15; b++) {
        auto t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++)
            radix(v, b);
        auto t4 = chrono::high_resolution_clock::now();

        auto duration2 = chrono::duration_cast<chrono::milliseconds>( t4 - t3 ).count();

        cout << "Radix Sort duration with " << b  << " bins: " << duration2 << " milliseconds"  << endl;
    }
    
}