//DS-MID-LT-3-3: Linear Search

#include <iostream>
using namespace std;

void LinearSearch(int arr[], int n, int item) {
    bool flag = false;
    int index = -1;
    for(int i=0 ; i<n ; i++) {
        if(arr[i] == item) {
            flag = true;
            index = i;
            break;
        }
    }

    if(index != -1) {
        cout << item << " Found at index " << index << endl;
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

    cout << "Enter search value: ";
    cin >> item;

    LinearSearch(array, size, item);
}