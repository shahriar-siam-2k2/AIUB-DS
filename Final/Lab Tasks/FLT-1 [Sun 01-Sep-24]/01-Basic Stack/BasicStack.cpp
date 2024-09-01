#include <iostream>
using namespace std;

int top = -1, size = 5;
int arr[5];

bool isFull() {
    if(top >= size) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty() {
    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void Push(int a) {
    if(isFull()) {
        cout << endl << "Stack Overflow!" << endl;
    }
    else {
        top++;
        arr[top] = a;
        cout << endl << a << " has been pushed." << endl;
    }
}

void Pop() {
    if(isEmpty()) {
        cout << endl << "Stack is empty!" << endl;
    }
    else {
        cout << endl << arr[top] << " has been popped." << endl;
        top--; 
    }
}

// void Show() {
//     if(isEmpty()) {
//         cout << endl << "Stack is empty!" << endl;
//     }
//     else {
//         cout << endl << "Showing stack values:" << endl;

//         for(int i=0; i<size; i++) {
//             cout << arr[i] << endl;
//         } 
//     }
// }

int main() {
    Pop();
    Push(2);
    Push(5);
    Push(6);
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
}