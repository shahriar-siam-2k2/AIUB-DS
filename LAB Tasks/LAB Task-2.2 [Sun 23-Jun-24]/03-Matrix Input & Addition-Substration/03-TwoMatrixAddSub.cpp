//DS-MID-LT-2.2-03: Develop a program that can take matrix input from a user and perform addition or subtraction.

#include <iostream>
using namespace std;

void matAdd(int *arr1, int *arr2, int row, int col) {
    cout << endl << "Addition Matrix: " << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cout << *((arr1 + i * col) + j) + *((arr2 + i * col) + j);
            if(j < col-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void matSub(int *arr1, int *arr2, int row, int col) {
    cout << endl << "Subtraction Matrix: " << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cout << *((arr1 + i * col) + j) - *((arr2 + i * col) + j);
            if(j < col-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int row, col;
    int *op = new int;

    cout << endl << "Enter Matrix size (rowXcol): ";
    cin >> row >> col;

    int mat1[row][col], mat2[row][col];

    cout << endl << "Enter integer numbers in Matrix-1 (" << row << "x" << col << ") :" << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << endl << "Enter integer numbers in Matrix-2 (" << row << "x" << col << ") :" << endl;
    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            cin >> mat2[i][j];
        }
    }

    while(true) {
        cout << endl << "1. Addition." << endl;
        cout << "2. Substraction." << endl;
        cout << "Choose your operation: ";
        cin >> *op;

        if(*op == 1) {
            matAdd(*mat1, *mat2, row, col);
            break;
        }
        else if(*op == 2) {
            matSub(*mat1, *mat2, row, col);
            break;
        }
        else {
            cout << endl << "Wrong operation." << endl;
        }
    }

    delete op;
}