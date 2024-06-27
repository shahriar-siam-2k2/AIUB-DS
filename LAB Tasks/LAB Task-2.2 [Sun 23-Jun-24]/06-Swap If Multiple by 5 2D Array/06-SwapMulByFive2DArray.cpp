//DS-MID-LT-2.2-06: Develop a program where the contents that are multiple of 5 in a particular row of a 2D array will be swapped with the immediate next element below it.

#include <iostream>
using namespace std;

int main() {
    int row, col;
    int *temp = new int;

    cout << endl << "Enter Array Size (Row X Col): ";
    cin >> row >> col;

    if(row < 2) {
        cout << endl << "Row size should be greater than or equal 2 according to this program." << endl;
        return 0;
    }

    int arr[row][col];
    cout << endl << "Enter Array Elements:" << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<row-1 ; i++) {
        for(int j=0 ; j<col ; j++) {
            if(arr[i][j] % 5 == 0) {
                *temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = *temp;
            }
        }
    }

    delete temp;

    cout << endl << "After Swapping:" << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cout << arr[i][j];
            if(j < col-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}