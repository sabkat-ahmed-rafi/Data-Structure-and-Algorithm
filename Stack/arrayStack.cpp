#include <iostream>
using namespace std;
#define MAX 5

// LIFO 

class ArrayStack {
    int top;
    int arr[MAX];

public:
    ArrayStack() {
        top = -1;
    }


    bool push(int x) {
        if(top >= MAX - 1) {
            return false;
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if(top < 0) {
            return 0;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        return arr[top];
    }

    void display() {
        for(int i = top; i >= 0; i--) {
            cout<< arr[i] << ", ";
        }
    }
};


int main() {
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.pop();

    cout<< "top element in stack: "<< stack.peek() << endl;
    stack.display();

    return 0;
}