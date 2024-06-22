//DS-MID-LT-2-03: Write a program that finds the highest value from an array using a pointer.

#include <iostream>
using namespace std;

int main() {
    int n = 5, maxVal;
    int arr[n] = {1, 2, 9, 4, 5};
    int *a = arr;

    maxVal = a[0];

    for(int i=0 ; i<n ; i++) {
        if(*a > maxVal) {
            maxVal = *a;
        }
        a++;
    }

    cout << endl << "Highest Value: " << maxVal << endl;
}