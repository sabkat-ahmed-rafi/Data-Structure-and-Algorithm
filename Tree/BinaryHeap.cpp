#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> heap;
private:
    void bubbleUpMax(int index) {
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
    void bubbleUpMin(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapifyMax(int index) {
        int largest = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if(left < heap.size() && heap[left] > heap[largest]) largest = left;
        if(right < heap.size() && heap[right] > heap[largest]) largest = right;

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyMax(largest);
        }
    }
    void heapifyMin(int index) {
        int smallest = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if(left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if(right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if(smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyMin(smallest);
        }
    }

public:
    void insertMax(int value) {
        heap.push_back(value);
        bubbleUpMax(heap.size() - 1);
    }
    void insertMin(int value) {
        heap.push_back(value);
        bubbleUpMin(heap.size() - 1);
    }
    void deleteRootMax() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyMax(0);
    }
    void deleteRootMin() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyMin(0);
    }
    void printHeap() {
        for(int val : heap) cout << val << " ";
        cout << endl;
    }
       
};    

int main() {
    Heap binaryMaxHeap;
    binaryMaxHeap.insertMax(50);
    binaryMaxHeap.insertMax(20);
    binaryMaxHeap.insertMax(40);
    binaryMaxHeap.insertMax(30);
    binaryMaxHeap.insertMax(60);
    binaryMaxHeap.deleteRootMax();
    binaryMaxHeap.printHeap();

    Heap binaryMinHeap;
    binaryMinHeap.insertMin(50);
    binaryMinHeap.insertMin(60);
    binaryMinHeap.insertMin(30);
    binaryMinHeap.insertMin(40);
    binaryMinHeap.insertMin(20);
    binaryMinHeap.insertMin(10);
    binaryMinHeap.deleteRootMin();
    binaryMinHeap.printHeap();

    return 0;
}