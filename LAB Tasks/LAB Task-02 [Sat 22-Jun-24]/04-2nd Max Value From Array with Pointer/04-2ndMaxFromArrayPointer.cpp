//DS-MID-LT-2-04: Write a program that finds the second highest value from an array using a pointer.

#include <iostream>
using namespace std;

int main() {
    int n = 5, secMax, maxVal;
    int arr[n] = {1, 5, 9, 4, 2};
    int *a = arr;

    maxVal = a[0];
    secMax = maxVal;

    for(int test=0 ; test<1 ; test++) {
        for(int i=0 ; i<n ; i++) {
            if(*a > secMax) {
                maxVal = *a;
            }
            a++;
        }
        secMax = maxVal;
    }

    cout << endl << "Second Highest Value: " << secMax << endl;
}