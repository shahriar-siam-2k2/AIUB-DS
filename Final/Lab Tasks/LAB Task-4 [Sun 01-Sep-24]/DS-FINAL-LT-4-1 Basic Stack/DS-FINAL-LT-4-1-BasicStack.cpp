#include <iostream>
using namespace std;

const int stackSize = 5;
int top = -1, stack[stackSize];

bool isFull() {
    if(top >= stackSize-1) {
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
        stack[top] = a;
        cout << endl << a << " has been pushed." << endl;
    }
}

void Pop() {
    if(isEmpty()) {
        cout << endl << "Stack is empty!" << endl;
    }
    else {
        cout << endl << stack[top] << " has been popped." << endl;
        top--; 
    }
}

void Show() {
    if(isEmpty()) {
        cout << endl << "Stack is empty!" << endl;
    }
    else {
        cout << endl << "Showing stack values:" << endl;

        for(int i=top; i>=0; i--) {
            cout << stack[i] << endl;
        } 
    }
}

void TopElement() {
    if(isEmpty()) {
        cout << endl << "Stack is empty!" << endl;
    }
    else {
        cout << endl << "Top Element: " << stack[top] << endl; 
    }
}

int main() {
    TopElement();
    Show();
    Pop();
    Push(2);
    TopElement();
    Push(5);
    TopElement();
    Push(6);
    Show();
    Pop();
    Show();
    Pop();
    Show();
    Pop();
    Pop();
    Pop();
    Show();
}