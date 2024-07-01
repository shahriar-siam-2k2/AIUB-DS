//DS-MID-LT-3-4: Binary Search

#include <iostream>
using namespace std;

void swapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i=1 ; i<n ; i++) {
            if(arr[i-1] > arr[i]) {
                swapVal(&arr[i-1], &arr[i]);
                swapped = true;
            }
        }
        n = n-1;
    }
    while(swapped == true);
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