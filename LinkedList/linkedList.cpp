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


void insertAtBeginning(Node* &head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}


int main() {

    Node* firstElement = new Node(10);
    Node* secondElement = new Node(20);
    Node* thirdElement = new Node(30);

    firstElement->next = secondElement;
    secondElement->next = thirdElement;
    
    insertAtBeginning(firstElement, 40);

    Node* current = firstElement;


    while (current != nullptr) {
        cout<< current->data << " -> ";
        current = current->next;
    }
    


    return 0;
}