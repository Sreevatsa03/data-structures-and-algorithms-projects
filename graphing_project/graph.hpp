#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include "point.hpp"

using namespace std;

class graph { 
private:
    int d, e, n;
    vector<vector<int>> *graphAdj;
    vector<point> *points;
public:
    graph(int); 
    graph(int, int);
    void addPoint();
    void addPoint(double, double);
    void addPoint(point);
    void dump();
    int getEdges();
    void addEdges(); 
    void printMat();
    void traverse(int, bool[]);
    bool isConnected();
};

graph::graph(int d1) { 
    d = d1;
    e = 0;
    n = 0;
    graphAdj = new vector<vector<int>>(); 
    points = new vector<point>();
}

graph::graph(int n1, int d1) {
    d = d1;
    e = 0;
    n = 0;
    graphAdj = new vector<vector<int>>(); 
    points = new vector<point>();
    for (int i = 0; i < n1; i++) 
        addPoint();
}

void graph::addPoint() {
    points -> push_back(point());
    n++;
    vector<int> col;
    for (int i = 0; i < n; i++) 
        col.push_back(0);
    
    graphAdj = new vector<vector<int>>;
    for (int i = 0; i < n; i++) 
        graphAdj -> push_back(col);
}

void graph::addPoint(double x, double y) {
    points -> push_back(point(x, y));
    n++;
    vector<int> col;
    for (int i = 0; i < n; i++) 
        col.push_back(0);
    
    graphAdj = new vector<vector<int>>;
    for (int i = 0; i < n; i++) 
        graphAdj -> push_back(col);
}

void graph::addEdges() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            } else if (points -> at(i).distance(points -> at(j)) <= d) {
                graphAdj -> at(i).at(j) = 1;
                e++;
            }
        }
    }
}

int graph::getEdges() {
    return e;
}

void graph::dump() {
    for (int i = 0; i < points -> size(); i++)
        cout << "(" << points -> at(i).x << "," << points -> at(i).y << ")" << endl;
}

void graph::printMat() {
    for (auto i = graphAdj -> begin(); i != graphAdj -> end(); i++) {
        cout << endl;
        for (auto j = i -> begin(); j != i -> end(); j++)  
            cout << *j << ' ';
    }
    cout << endl;
}

void graph::traverse(int x, bool vis[]) {
    vis[x] = true;
    for (int y = 0; y < n; y++) {
        if (graphAdj -> at(x).at(y) == 1) { 
            if (!vis[y])
                traverse(y, vis);
        }
    }
}

bool graph::isConnected() {
    bool *vis = new bool[n];
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) 
            vis[i] = false;
        traverse(s, vis);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) 
                return false;
        }
    }

    return true;
}

#endif /* GRAPH_HPP_ */
