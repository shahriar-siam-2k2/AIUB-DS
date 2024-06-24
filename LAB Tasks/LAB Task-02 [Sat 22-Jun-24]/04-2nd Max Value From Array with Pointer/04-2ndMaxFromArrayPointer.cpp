//DS-MID-LT-2-04: Write a program that finds the second highest value from an array using a pointer.

#include <iostream>
using namespace std;

int main() {
    int n = 5, secMax=0, maxVal=0;
    int arr[n] = {0, 9, 9, 2, 5};
    int *a = arr;

    if(a[0] > a[1]) {
        maxVal = a[0];
        secMax = a[1];
    }
    else {
        maxVal = a[1];
        secMax = a[0];
    }

    for(int test=0 ; test<2 ; test++) {
        for(int i=0 ; i<n ; i++) {
            if(a[i] > maxVal && a[i] != secMax) {
                maxVal = a[i];
            }
        }
        secMax = maxVal;
        maxVal = 0;
    }

    cout << endl << "Second Highest Value: " << secMax << endl;
}