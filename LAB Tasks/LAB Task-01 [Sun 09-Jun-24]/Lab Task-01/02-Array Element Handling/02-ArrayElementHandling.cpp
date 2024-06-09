#include <iostream>
using namespace std;

int main() {
    int arr[10], sum = 0;

    cout << "Enter 10 integer numbers: ";
    for(int i=0 ; i<10 ; i++){
        cin >> arr[i];
    }

    cout << endl << "Array values except first and last values: ";
    for(int i=0 ; i<10 ; i++) {
        if(i == 0 || i==9) {
            continue;
        }
        else {
            sum += arr[i];

            if(i < 8) {
                cout << arr[i] << ", ";
            }
            else {  
                cout << arr[i] << "." << endl;
            }
        }
    }

    arr[0] = sum;
    arr[9] = sum;

    cout << "Array values with overwritten with sum: ";

    for(int i=0 ; i<10 ; i++) {
        if(i < 9) {
            cout << arr[i] << ", ";
        }
        else {  
            cout << arr[i] << "." << endl;
        }
    }
}