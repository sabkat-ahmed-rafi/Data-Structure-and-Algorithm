#include <iostream>
using namespace std;

struct Stack {
    int* arr;       
    int top;        
    int capacity;   

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
};