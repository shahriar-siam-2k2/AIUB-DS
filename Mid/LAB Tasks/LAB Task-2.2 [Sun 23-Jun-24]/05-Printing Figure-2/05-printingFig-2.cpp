/* 
    DS-MID-LT-2.2-05: Develop a program using a 2D array to show the following-

    1 0 1 0
    0 1 0 1
    1 0 1 0
    0 1 0 1

*/

#include <iostream>
using namespace std;

int main() {
    int arr[4][4];
    int *n = new int;

    for(int i=0 ; i<4 ; i++){
        if(i % 2 == 0) {
            *n = 0;
        }
        else {
            *n = 1;
        }
        for(int j=0 ; j<4 ; j++) {
            if(*n % 2 == 0) {
                *n = *n + 1;
            }
            else {
                *n = *n - 1;
            }
            arr[i][j] = *n;
        }
    }

    delete n;

    cout << endl;
    for(int i=0 ; i<4 ; i++) {
        for(int j=0 ; j<4 ; j++) {
            cout << arr[i][j];
            if(j < 3) {
                cout << " ";
            }
        }
        cout << endl;
    }
}