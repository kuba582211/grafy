#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<pair<int, int>> heap;
public:
    void push(int, int);
    pair<int, int> pop();
    bool empty();
