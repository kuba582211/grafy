#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

void PriorityQueue::push(int priority, int value){
    heap.push_back(make_pair(priority, value));
    int index = heap.size() - 1;
    while (index > 0){
        int parent = (index - 1) / 2;
        if (heap[parent].first > heap[index].first){
            swap(heap[parent], heap[index]);
            index = parent;
        } else{
            break;
        }
    }
}

pair<int, int> PriorityQueue::pop(){
    pair<int, int> top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild].first < heap[smallest].first) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].first < heap[smallest].first) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
    return top;
}

bool PriorityQueue::empty() {
    return heap.empty();
}
