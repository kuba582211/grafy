#ifndef __heap__
#define __heap__
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    friend class GraphList;
    friend class GraphMatrix;
    vector<pair<int, int>> heap;
public:
    void push(int, int);
    pair<int, int> pop();
    bool empty();
};
#endif
