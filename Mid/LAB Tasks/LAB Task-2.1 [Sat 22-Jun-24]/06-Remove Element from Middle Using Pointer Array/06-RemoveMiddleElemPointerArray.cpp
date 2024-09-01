//DS-MID-LT-2.1-06: Write a program where you can remove the value of the middle index of an array using pointer.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << endl << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integer numbers: ";
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }

    int *a = arr;
    int *midIndex = new int;

    *midIndex = n/2;

    for(int i = *midIndex ; i<n-1 ; i++) {
        a[i] = a[i+1];
    }

    n--;

    cout << endl << "Array elements after deleting the value of middle index: ";
    for(int i=0 ; i<n ; i++) {
        cout << a[i];
        if(i == n-1) {
            cout << "." << endl;
        }
        else {
            cout << ", ";
        }
    }

    delete midIndex;
    delete [] a;
}