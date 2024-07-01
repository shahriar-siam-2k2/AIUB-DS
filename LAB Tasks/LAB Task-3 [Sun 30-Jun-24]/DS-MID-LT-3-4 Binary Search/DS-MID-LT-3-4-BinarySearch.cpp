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

void BinarySearch(int arr[], int n, int item) {
    bool flag = false;
    int midIndex, left = 0, right = n;
    
    while(left <= right) {
        midIndex = (left + right) / 2;
        if(arr[midIndex] == item) {
            flag = true;
            break;
        }
        else if(arr[midIndex] < item) {
            left = midIndex + 1;
        }
        else {
            right = midIndex - 1;
        }
    }

    if(flag == true) {
        cout << "Item Found!" << endl;
    }
    else {
        cout << "Item not found!" << endl;
    }
}

int main() {
    int size, item;

    cout << endl << "Enter array size: ";
    cin >> size;

    int array[size];

    cout << "Enter array values: ";
    for(int i=0 ; i<size ; i++) {
        cin >> array[i];
    }

    BubbleSort(array, size);

    cout << "Enter search value: ";
    cin >> item;

    BinarySearch(array, size, item);
}