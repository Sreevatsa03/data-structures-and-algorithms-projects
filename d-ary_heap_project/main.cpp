#include "dHeap.h"
#include "graph.h"
#include "heap.h"
#include <fstream>

using namespace std;

void test(int d) {
    int n = 2394386;
    graph g(n, d);

    ifstream infile("WikiTalk.txt");
    int a, b;
    while (infile >> a >> b) {
        // cout << a  << "   " << b << endl;
        // g.addEdge(a - 1, b - 1, 1); // data not zero-indexed
        g.addEdge(a, b, 1); // data not zero-indexed
        // g.addEdge(b, a, 0); 
    }

    g.shortestPath(0);
}

void graphTest() {
    int n = 9;
    graph g(n, 2);

    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7);  

    g.shortestPath(0);
}

int main(int argc, const char* argv[]) {
    // auto start = chrono::steady_clock::now();

	// auto end = chrono::steady_clock::now();

	// cout << "Elapsed time in nanoseconds : " 
	// 	<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
	// 	<< " ns" << endl;

    //     cout << endl;

	// cout << "Elapsed time in microseconds : " 
	// 	<< chrono::duration_cast<chrono::microseconds>(end - start).count()
	// 	<< " µs" << endl;

    //     cout << endl;

	// cout << "Elapsed time in milliseconds : " 
	// 	<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
	// 	<< " ms" << endl;

    //     cout << endl;

	// cout << "Elapsed time in seconds : " 
	// 	<< chrono::duration_cast<chrono::seconds>(end - start).count()
	// 	<< " sec";

    //     cout << endl;

    using namespace std::chrono;

    auto t1 = chrono::high_resolution_clock::now();
    // graphTest();
    test(15);
    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();

    cout << duration << endl;

    return 0;
}