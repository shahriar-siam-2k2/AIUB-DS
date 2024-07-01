//DS-MID-LT-3-1: Implement Bubble Sort

#include <iostream>
using namespace std;

void swapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n) {
    for(int i=0 ; i < n-1 ; i++) {
        for(int j=0 ; j < n-1 ; j++) {
            if(arr[j] > arr[j+1]) {
                swapVal(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int size;

    cout << endl << "Enter array size: ";
    cin >> size;

    int array[size];

    cout << "Enter array values: ";
    for(int i=0 ; i<size ; i++) {
        cin >> array[i];
    }

    BubbleSort(array, size);

    cout << "Sorted array values: ";
    for(int i=0 ; i<size ; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}