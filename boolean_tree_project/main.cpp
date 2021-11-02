#include "boolTree.h"
#include "boolTree.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    char input[256];
    cout << "This boolean logic evaluator takes in an input of: T,F,(),!,&,|,^,> (can be lowercase and have spaces)" << endl;
    cout << "Please enter a boolean logic expression to be evaluated:" << endl;
    cin.getline(input, sizeof(input));
    boolTree *x = new boolTree(input);
    cout << x -> logicEval() << endl;
    cout << endl;
    x -> print2D(); //Prints sideways
}
