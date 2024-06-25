#include <iostream>
using namespace std;

int main() {
    int arr[10], sum = 0;

    cout << "Enter 10 integer numbers: ";
    for(int i=0 ; i<10 ; i++){
        cin >> arr[i];
    }
    
    cout << endl << "Even numbers: ";
    for(int i=0 ; i<10 ; i++){
        if(arr[i] % 2 == 0){
            sum += arr[i];

            if(i < 9) {
                cout << arr[i] << ", ";
            }
            else {  
                cout << arr[i] << "." << endl;
            }
        }
    }

    cout << "Sum of even numbers: " << sum << endl;
}