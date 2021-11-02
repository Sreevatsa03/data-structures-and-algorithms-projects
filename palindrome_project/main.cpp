#include <cstdlib>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"
#include "LinkedList.cpp"


using namespace std;

int main(int argc, char* argv[]) {
    LinkedList el;
    string temp = argv[1];
    int size = temp.length();
    for (int i =  size - 1; i >= 0; i-- ) {
        el.push(argv[1][i]);
    }
    cout << el.lengthPalindrome() << endl;
}
