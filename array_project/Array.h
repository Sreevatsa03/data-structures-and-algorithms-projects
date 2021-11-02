#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

#ifndef ARRAY_H_
#define ARRAY_H_

template <typename T> class array {
// Using a template class so that array when initialized in client code can be of any data type
private:
// Initializes the pointer to the array and size of the array as private fields
    int size;
    T *arr;
public:
// Initializes constructor, blank constructor, get, set, and destructor as public functions
    array();
    array(int s);
    T get(int ind);
    void set(int ind, T val);
    // void sort();
    virtual ~array();
};

template <typename T> array<T>::array () {
    size = 0;
}
// Empty constructor that takes no parameter and initializes an array of size 0

template <typename T> array<T>::array(int s){
    size = s;
    arr = (T*)malloc(size*sizeof(T));
}
// Constructor that takes parameter for size of the array and initializes the array

template <typename T> T array<T>::get(int ind) {
    return *(arr + ind);
}
// Method that when called in client code, takes a parameter of index and returns the value at that index

template <typename T> void array<T>::set(int ind, T val) {
    *(arr + ind) = val;
}
// Method that when called in client code, takes a parameter of index and a perameter of value that should be put in the index given

template <typename T> array<T>::~array() {
    free(arr);
}
// Destructor to automatically free memory array

// template <typename T> void array<T>::sort() {
//     int temp;
//     for(int i=0; i<size; i++) {
//         for(int j=size-1; j>i; j--) {
//             if(get(i)<get(j-1)) {
//                 temp=get(j-1);
//                 set(j-1, get(j));
//                 set(j, temp);
//             }
//         }
//     }
// }

#endif /* ARRAY_H */