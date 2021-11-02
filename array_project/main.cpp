#include<cstdlib>
#include<iostream>
#include"Array.h"
#include<string>

using namespace std;

int main(int argc, char *argv[]) {
    // long *arr = (long*)malloc(10*sizeof(long));
    // for (int i =0; i<10; i++) {
    //     cout << *(arr + sizeof(long)*i) <<endl;
    // }
    // *(arr + sizeof(long)*5) = 7;
    // for (int i =0; i<10; i++) {
    //     cout << *(arr + sizeof(long)*i) <<endl;
    // }

    array<int> arr1 = array<int> (5);

    // string x = "Hello";
    // arr1.set(0,x);
    // cout << arr1.get(0) << endl;


    arr1.set(0,5);
    arr1.set(1,2);
    arr1.set(2,6);
    arr1.set(3,3);
    arr1.set(4,7);
    // for (int i=0; i < 5; i++) {
    //     cout << arr1.get(i) << endl;
    // }
     for (int i=0; i < 5; i++) {
        cout << arr1.get(i) << endl;
    }

    // int *arr = new int[argc-1];
    // for (int i = 1; i < argc; i++) {
    //     arr[i - 1] = atoi(argv[i]);
    // }
    // for ( int i = 0; i<argc-1; i++) {
    //     cout << arr[i] << endl;
    // }
 }