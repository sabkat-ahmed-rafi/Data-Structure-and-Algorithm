#include <iostream>
using namespace std;

// FIFO

class Queue {
    int *arr;
    int front, rear, capacity;

public: 
    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = -1;
        capacity = size;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity -1;
    }

    void enqueue(int value) {
        if(isFull()) {
            return;
        }
        arr[++rear] = value;
    }

    void dequeue() {
        if(isEmpty()) {
            return;
        }
        front++;
    }

    int getFront() {
        return arr[front];
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    while(!queue.isEmpty()) {
        cout<< queue.getFront() << ", ";
        queue.dequeue();
    }
    

    return 0;
}