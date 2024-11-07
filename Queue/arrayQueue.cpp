#include <iostream>
using namespace std;

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

    void inqueue(int value) {
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

    queue.inqueue(10);
    queue.inqueue(20);
    queue.inqueue(30);
    queue.inqueue(40);

    while(!queue.isEmpty()) {
        cout<< queue.getFront() << ", ";
        queue.dequeue();
    }
    

    return 0;
}