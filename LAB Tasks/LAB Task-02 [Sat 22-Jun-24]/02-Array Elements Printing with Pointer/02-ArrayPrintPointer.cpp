//DS-MID-LT-2-02: Write a program to print all elements of an array using a pointer to traverse the array.

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int *a = arr;

    cout << endl << "Erray elements: ";

    for(int i=0 ; i<n ; i++) {
        cout << *a;

        if(i == n-1) {
            cout << "." << endl;
        }
        else {
            cout << ", ";
        }

        a++;
    }
}