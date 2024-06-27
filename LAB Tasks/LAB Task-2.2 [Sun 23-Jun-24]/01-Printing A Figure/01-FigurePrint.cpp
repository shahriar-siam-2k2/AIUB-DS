/*
    DS-MID-LT-2.2-01: Develop a program to print the following structure-
    + 
    + +
    + + +
    + + + +
*/

#include <iostream>
using namespace std;

int main() {
    cout << endl;

    for(int line = 0 ; line < 4 ; line++) {
        for(int i = 0 ; i < line+1 ; i++) {
            cout << "+";
            if(i < line) {
                cout << " ";
            }
        }
        cout << endl;
    }
}