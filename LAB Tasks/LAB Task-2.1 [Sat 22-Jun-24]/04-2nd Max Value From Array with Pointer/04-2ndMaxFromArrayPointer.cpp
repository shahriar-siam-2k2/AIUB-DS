//DS-MID-LT-2.1-04: Write a program that finds the second highest value from an array using a pointer.

#include <iostream>
using namespace std;

int main() {
    int n = 5, max2;
    int arr[n] = {0, 9, 9, 2, 5};
    int *a = arr;
    int *maxVal = new int;

    if(a[0] > a[1]) {
        *maxVal = a[0];
        max2 = a[1];
    }
    else {
        *maxVal = a[1];
        max2 = a[0];
    }

    for(int test=0 ; test<2 ; test++) {
        for(int i=0 ; i<n ; i++) {
            if(a[i] > *maxVal && a[i] != max2) {
                *maxVal = a[i];
            }
        }
        max2 = *maxVal;
        *maxVal = 0;
    }

    delete maxVal;

    cout << endl << "Second Highest Value: " << max2 << endl;
}