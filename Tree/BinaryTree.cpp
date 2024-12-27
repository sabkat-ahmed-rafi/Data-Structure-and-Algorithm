#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


void inOrder(Node* root) {
    if(root == nullptr) 
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// maxDepth and height is similar
int maxDepth(Node* root) {
    if(root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if(root == nullptr) return 0;
    if(root->left == nullptr) return 1 + minDepth(root->right);
    if(root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}


bool isBalanced(Node* root) {
    if(root == nullptr) return true;

    int lh =  maxDepth(root->left);
    int rh = maxDepth(root->right);

    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    inOrder(root);
    cout << endl;
    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
    cout << isBalanced(root);

    return 0;
}