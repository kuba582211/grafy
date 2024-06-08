#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

class GraphMatrix{
    int V;
    vector<vector<int>> Matrix;
public:
    GraphMatrix(int);
    void addEdge(int,int,int);
    void show();

    void fillRandomEdges(int,int);

    void dijkstra(int=-1,bool=false);
    void dijkstra_two(int=-1,int=-1,bool=false);
};
