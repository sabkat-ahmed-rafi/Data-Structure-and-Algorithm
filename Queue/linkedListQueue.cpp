#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


class Queue {
    Node* head;
    Node* tail;

public:

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if(isEmpty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return head->data;
    }
};


int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    while(!queue.isEmpty()) {
        cout<< queue.getFront() << " ,";
        queue.dequeue();
    }

    return 0;
}