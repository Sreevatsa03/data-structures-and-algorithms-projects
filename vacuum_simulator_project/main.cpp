#include "world.h"
#include "vacuum.h"
#include <iostream>

using namespace std;

int main() {
    World myWorld1("world.txt");
    // World myWorld2("world2.txt");
    // World myWorld3("world3.txt");
    Vacuum myVacuum1(myWorld1);
    // Vacuum myVacuum2(myWorld2);
    // Vacuum myVacuum3(myWorld3);
    myVacuum1.clean();
    cout << endl;
    // myVacuum1.mapDump();
    cout << myVacuum1.score() << endl;
    cout << endl;

}