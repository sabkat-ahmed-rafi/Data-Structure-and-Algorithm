#include <iostream>
using namespace std;



struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int value) {
    if(root == nullptr) return new Node(value);

    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


bool search(Node* root, int value) {
    if(root == nullptr) return false;
    if(root->data == value) return true;
    if(value < root->data) {
       return search(root->left, value);
    }
    return search(root->right, value);
}


void inOrder(Node* root) {
    if(root == nullptr) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


int main() {

    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);

    inOrder(root);

    cout << endl << search(root, 98) << endl;

    return 0;
}