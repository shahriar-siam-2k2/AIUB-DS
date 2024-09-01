//DS-MID-LT-2.1-07: Develop a program that will use a pointer to access all the elements of an array. Then use this pointer to swap the first two elements of the array and finally print the contents.

#include <iostream>
using namespace std;

void arrSwap(int arr[]) {
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

int main() {
    int n;
    cout << endl << "Enter array size (minimum 2): ";
    cin >> n;

    if(n < 2) {
        cout << endl << "Array size should be greater than or equal 2 according to this program!" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter " << n << " integer numbers: ";
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }

    int *a = arr;

    cout << endl << "Array Elements: ";
    for(int i = 0 ; i < n ; i++) {
        cout << a[i];
        if(i == n-1) {
            cout << "." << endl;
        }
        else {
            cout << ", ";
        }
    }

    arrSwap(a);

    cout << endl << "Array Elements after swapping first two elements: ";
    for(int i = 0 ; i < n ; i++) {
        cout << a[i];
        if(i == n-1) {
            cout << "." << endl;
        }
        else {
            cout << ", ";
        }
    }

    delete [] a;
}