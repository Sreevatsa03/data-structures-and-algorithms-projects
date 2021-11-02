#include "dHeap.h"

using namespace std; 

typedef pair<int, int> pairs; 

# define INF 0x3f3f3f3f 
  
class graph { 
    int d;
    int n;  
    list<pair<int, int>> *graphAdj; 
public: 
    graph(int, int); 
    void addEdge(int, int, int); 
    void shortestPath(int); 
    void printPath(int*, int);
    int printSolution(vector<int>, int, int*);
}; 

graph::graph(int n, int d1) { 
    d = d1;
    this -> n = n; 
    graphAdj = new list<pairs> [n]; 
} 
  
void graph::addEdge(int x, int y, int e) { 
    graphAdj[x].push_back(make_pair(y, e)); 
    // graphAdj[y].push_back(make_pair(x, e)); 
} 

// void graph::printPath(int parent[], int j) { 
//     if (parent[j] == - 1) 
//         return; 
  
//     printPath(parent, parent[j]); 
  
//     printf("%d ", j); 
// } 
  
// int graph::printSolution(vector<int> dist, int n, int parent[]) { 
//     int src = 0; 
//     printf("Vertex\t Distance\tPath"); 
//     for (int i = 1; i < n; i++) { 
//         printf("\n%d -> %d \t %d\t\t%d ", 
//                       src, i, dist[i], src); 
//         printPath(parent, i); 
//     } 
// } 
  
void graph::shortestPath(int src) { 
    dheap pq = dheap(d);
    vector<int> dist(n, INF); 

    // int parent[n];
    // parent[0] = -1; 
   
    pq.insert(make_pair(0, src)); 
    dist[src] = 0; 

    while (!pq.empty()) { 
        int x = pq.getMin().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (i = graphAdj[x].begin(); i != graphAdj[x].end(); ++i) { 
            int y = (i) -> first; 
            int weight = (i) -> second; 

            if (dist[y] > dist[x] + weight) { 
                // parent[y] = x;
                dist[y] = dist[x] + weight; 
                pq.insert(make_pair(dist[y], y)); 
            } 
        } 
    } 
  
    // printf("Vertex   Distance from Source\n"); 
    // for (int i = 0; i < n; ++i) 
    //     printf("%d \t\t %d\n", i, dist[i]); 

    // printSolution(dist, n, parent); 
}
 