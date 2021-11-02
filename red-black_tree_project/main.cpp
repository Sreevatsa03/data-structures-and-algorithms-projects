#include "rbt.h"
#include "rbt.cpp"

using namespace std;

int main(int argc, char** argv) {
    rbt x; 
  
    x.insert(7); 
    x.insert(3); 
    x.insert(18); 
    x.insert(10); 
    x.insert(22); 
    x.insert(8); 
    x.insert(11); 
    x.insert(26); 
    x.insert(2); 
    x.insert(6); 
    x.insert(13); 
    
    x.printInOrder(); 
    x.print(); 
    
    cout << endl << "Deleting 18, 11, 3, 10, 22" << endl; 
    
    x.deleteByVal(18); 
    x.deleteByVal(11); 
    x.deleteByVal(3); 
    x.deleteByVal(10); 
    x.deleteByVal(22); 
    
    x.printInOrder(); 
    x.print();
}