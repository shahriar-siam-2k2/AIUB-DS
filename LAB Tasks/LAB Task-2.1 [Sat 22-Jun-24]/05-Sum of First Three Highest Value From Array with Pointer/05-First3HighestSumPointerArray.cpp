//DS-MID-LT-2.1-05: Write a program that finds the sum of the first three highest values from an array using pointer.

#include <iostream>
using namespace std;

int main() {
    int n, max1, max2, max3;
    int *maxVal = new int;
    int *index1 = new int;
    int *index2 = new int;
    int *index3 = new int;

    cout << endl << "Enter array size (minimum 3): ";
    cin >> n;

    if(n < 3) {
        cout << endl << "Array size should be greater than or equal 3 according to this program!" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter " << n << " integer numbers: ";
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }

    int *a = arr;
    *maxVal = 0;
    *index1 = -1;
    *index2 = -1;
    *index3 = -1;

    for(int test=0 ; test<3 ; test++) {
        for(int i=0 ; i<n ; i++) {
            if(a[i] > *maxVal && (i != *index1 && i != *index2 && i != *index3)) {
                *maxVal = a[i];
                
                if(test == 0) {
                    *index1 = i;
                }
                else if(test == 1) {
                    *index2 = i;
                }
                else if(test == 2) {
                    *index3 = i;
                }  
            }
        }

        if(test == 0) {
            max1 = *maxVal;
        }
        else if(test == 1) {
            max2 = *maxVal;
        }
        else if(test == 2) {
            max3 = *maxVal;
        }

        *maxVal = 0;
    }

    cout << endl << "Sum of the first three highest values: " << max1 + max2 + max3 << endl;

    delete maxVal, index1, index2, index3;
}