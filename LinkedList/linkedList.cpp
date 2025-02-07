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
    Node* newNode = new Node(newData); // Create a new node
    newNode->next = head; // Point new node to the current head
    head = newNode; // Update head to the new node
}

void insertAtEnd(Node* &head, int newData) {
    Node* newNode = new Node(newData);

    // Checking if the list is empty or not 
    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
 
    while(temp->next != nullptr) { // traverse to the list to go to the end Node
        temp = temp->next;
    } 

    temp->next = newNode;

}


int main() {

    Node* firstElement = new Node(10);
    Node* secondElement = new Node(20);
    Node* thirdElement = new Node(30);

    firstElement->next = secondElement;
    secondElement->next = thirdElement;
    
    insertAtBeginning(firstElement, 40);
    insertAtEnd(firstElement, 50);

    Node* current = firstElement;


    while (current != nullptr) {
        cout<< current->data << " -> ";
        current = current->next;
    }
    


    return 0;
}