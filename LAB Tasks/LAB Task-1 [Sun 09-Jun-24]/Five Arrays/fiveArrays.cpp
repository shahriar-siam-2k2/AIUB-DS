#include <iostream>

using namespace std;

int main() {
    int arr[5] = {5, 3, 9, 0, 4};
    int maximum = arr[0];

    for(int i=0 ; i<5 ; i++) {
        if(maximum < arr[i]) {
            maximum = arr[i];
        }
    }

    cout << "Maximum Element = " << maximum << endl;
}