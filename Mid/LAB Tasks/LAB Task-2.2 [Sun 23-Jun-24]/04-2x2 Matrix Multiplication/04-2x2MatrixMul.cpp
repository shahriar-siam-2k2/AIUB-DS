//DS-MID-LT-2.2-04: Develop a program to show matrix multiplication. Keep it simple by using a 2X2 matrix.

#include <iostream>
using namespace std;

int main() {
    int size = 2, mul;
    int mat1[size][size], mat2[size][size];

    cout << endl << "Enter integer numbers in Matrix-1 (" << size << "x" << size << ") :" << endl;
    for(int i=0 ; i<size ; i++) {
        for(int j=0 ; j<size ; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << endl << "Enter integer numbers in Matrix-2 (" << size << "x" << size << ") :" << endl;
    for(int i=0 ; i<size ; i++) {
        for(int j=0 ; j<size ; j++) {
            cin >> mat2[i][j];
        }
    }
    
    cout << endl << "Multiplication Matrix: " << endl;
    for(int i=0 ; i<size ; i++) {
        for(int j=0 ; j<size ; j++) {
            mul = 0;
            for(int k=0 ; k<size ; k++) {
                mul = mul + (mat1[i][k] * mat2[k][j]);
            }
            cout << mul;
            if(j < size-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}