//DS-MID-LT-2.1-08: Write a program to print all elements of an array using a pointer to traverse the array.

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

    delete [] a;
}