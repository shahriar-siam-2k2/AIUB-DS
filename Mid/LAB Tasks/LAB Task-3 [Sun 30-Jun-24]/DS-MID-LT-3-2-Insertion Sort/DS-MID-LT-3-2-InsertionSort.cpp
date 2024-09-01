//DS-MID-LT-3-2: Insertion Sort

#include <iostream>
using namespace std;

void swapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    int i_min;
    for(int i=0 ; i < n-1 ; i++) {
        i_min = i;
        for(int j = i+1 ; j < n ; j++) {
            if(arr[j] > arr[i_min]) {
                i_min = j;
            }
            swapVal(&arr[j], &arr[i_min]);
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

    SelectionSort(array, size);

    cout << "Sorted array values: ";
    for(int i=0 ; i<size ; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}