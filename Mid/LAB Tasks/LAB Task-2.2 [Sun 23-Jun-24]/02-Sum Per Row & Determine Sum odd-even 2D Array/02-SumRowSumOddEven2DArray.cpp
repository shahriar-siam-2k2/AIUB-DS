//DS-MID-LT-2.2-02: Develop a program that will have a 3X4 2D array. Then find the sum of all the elements in each row and identify whether the sum is odd or even.

#include <iostream>
using namespace std;

int main() {
    int row=3, col=4;
    int *sum = new int;
    int arr[row][col];

    cout << endl << "Enter integer numbers in (" << row << "x" << col << ") size: " << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cin >> arr[i][j];
        }
    }

    *sum = 0;

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++) {
            *sum = *sum + arr[i][j];
        }
        
        cout << endl << "Sum of row-" << i+1 << ": " << *sum << endl;
        if(*sum % 2 == 0) {
            cout << "Sum of row-" << i+1 << " is an even number." << endl;
        }
        else {
            cout << "Sum of row-" << i+1 << " is an odd number." << endl;
        }

        *sum = 0;
    }

    delete sum;
}