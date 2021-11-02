#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> &arr) { 
    int max = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
 
void countSort(vector<int> &arr, int exp, int bins) { 
    int result[arr.size()];
    int count[bins];

    for (int i = 0; i < bins; i++) 
        count[i] = 0; 

    for (int i = 0; i < arr.size(); i++) 
        count[(arr[i] / exp) % bins]++;

    count[0] = count[0] - 1;
    for (int i = 1; i < bins; i++) 
        count[i] = count[i - 1] + count[i];

    for (int i = arr.size() - 1; i >= 0; i--) {
        result[count[(arr[i] / exp) % bins]] = arr[i];
        count[(arr[i] / exp) % bins] = count[(arr[i] / exp) % bins] - 1;
    }

    for (int i = 0; i < arr.size(); i++) 
        arr[i] = result[i]; 
} 

void radixSort(vector<int> &arr, int bins) {
    int exp, max = getMax(arr);
  
    for (int i = 0, exp = 1; max/exp > 0; i++, exp *= bins) 
        countSort(arr, exp, bins);
}