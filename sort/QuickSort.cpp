#include <iostream>
using namespace std;

int partision(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partision(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<", ";
    }

    return 0;
}
