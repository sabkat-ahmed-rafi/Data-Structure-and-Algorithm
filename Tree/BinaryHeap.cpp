#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;
private:
    void bubbleUp(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }
    void printHeap() {
        for(int val : heap) cout << val << " ";
    }
       
};    

int main() {
    MaxHeap binaryHeap;
    binaryHeap.insert(50);
    binaryHeap.insert(20);
    binaryHeap.insert(40);
    binaryHeap.insert(30);
    binaryHeap.insert(60);

    binaryHeap.printHeap();

    return 0;
}