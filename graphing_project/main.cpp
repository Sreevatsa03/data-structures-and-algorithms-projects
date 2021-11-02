#include "graph.hpp"
#include <fstream>
#include <ctime>

using namespace std;

void dve(graph* g) {
    ofstream dve;
    dve.open("Distance vs. Edges.txt");

    for (int d = 1; d < 26; d++) {
        g = new graph(100/*#ofpoints*/, d/*distance*/);
        g -> addEdges(); 
        dve << d << " " << g -> getEdges() << endl;
    }
    dve.close();


    // g = new graph(10);
    // for (int i = 0; i < 10; i++) 
    //     g -> addPoint();

    // g -> dump();
    // g -> printMat();
    // g -> addEdges();
    // g -> printMat();
    // cout << g -> getEdges() << endl;
}

void dvc(graph* g) {
    int trials = 500;
    double c = 0;
    ofstream dvc;
    dvc.open("dvc50.txt");

    for (int d = 1; d < 26; d++) {
        c = 0;
        for (int t = 0; t < trials; t++) {
            graph g = graph(50/*#ofpoints*/, d/*distance*/);
            g.addEdges(); 
            if (g.isConnected())
                c++;
        }
        dvc << d << " " << (c / (double) trials) << endl;
    }
    dvc.close();


    // g = new graph(5);
    // for (int i = 0; i < 3; i++) 
    //     g -> addPoint();

    // // g -> addPoint(0, 1);
    // // g -> addPoint(1, 2);
    // // g -> addPoint(2, 3);
    // // g -> addPoint(3, 0);
    // // g -> addPoint(2, 4);
    // // g -> addPoint(4, 2);

    // g -> dump();
    // g -> addEdges();
    // g -> printMat();
    // if (g -> isConnected() == true)
    //     c = 1;
    // else
    //     c = 0;
    
    // cout << c << endl;
}

int main(int argc, const char* argv[]) {
    graph* g;
    dve(g);
    // dvc(g);
}