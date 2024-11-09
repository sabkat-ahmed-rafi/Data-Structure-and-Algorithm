#include <iostream>
using namespace std;

// LIFO 

class Node {
public:
    int data;
    Node* next;
};


class LinkedListStack {
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        return top->data;
    }

    void display() {
        Node* temp = top;
        while(temp != nullptr) {
            cout<< temp->data << ", ";
            temp = temp->next;
        }
    }
};



int main() {

    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.pop();

    cout<< stack.peek() << endl;
    stack.display();



    return 0;
}