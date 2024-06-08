#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

class GraphList{
    int V;
    vector<vector<pair<int,int>>> List;
public:
    GraphList(int);
    void addEdge(int,int,int);
    void show();

    void fillRandomEdges(int,int);
    bool hasEdge(int,int);
    void addRandomEdge(int,int,int);

    void dijkstra(int=-1,bool=false);
    void dijkstra_two(int=-1, int=-1,bool=false);
};
