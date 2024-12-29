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
    void heapify(int index) {
        int largest = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if(left < heap.size() && heap[left] > heap[largest]) largest = left;
        if(right < heap.size() && heap[right] > heap[largest]) largest = right;

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }
    void deleteRoot() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
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
    binaryHeap.deleteRoot();
    binaryHeap.printHeap();

    return 0;
}