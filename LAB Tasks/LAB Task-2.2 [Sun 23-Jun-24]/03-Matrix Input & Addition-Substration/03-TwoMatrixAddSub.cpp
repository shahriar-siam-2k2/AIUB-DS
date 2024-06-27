//DS-MID-LT-2.2-02: Develop a program that can take matrix input from a user and perform addition or subtraction.

#include <iostream>
using namespace std;

int matAdd(int arr[][], int row, int col) {

}
int matSub(int arr[], int row, int col) {
    
}

int main() {
    int row1, col1, row2, col2;
    int *sum = new int;

    cout << endl << "Enter Matrix-1 size (rowXcol): ";
    cin >> row1 >> col1;

    int mat1[row1][col1];

    cout << endl << "Enter integer numbers in Matrix-1 (" << row1 << "x" << col1 << ") :" << endl;
    for(int i=0 ; i<row1 ; i++) {
        for(int j=0 ; j<col1 ; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << endl << "Enter Matrix-2 size (rowXcol): ";
    cin >> row2 >> col2;

    int mat2[row2][col2];

    cout << endl << "Enter integer numbers in Matrix-2 (" << row2 << "x" << col2 << ") :" << endl;
    for(int i=0 ; i<row2 ; i++) {
        for(int j=0 ; j<col2 ; j++) {
            cin >> mat2[i][j];
        }
    }

    int *op = new int;

    while(true) {
        cout << endl << "1. Addition." << endl;
        cout << "2. Substraction." << endl;
        cout << "Choose your operation: ";
        cin >> *op;

        if(*op == 1) {
            matAdd(mat1, row1, col1);
        }
    }
}