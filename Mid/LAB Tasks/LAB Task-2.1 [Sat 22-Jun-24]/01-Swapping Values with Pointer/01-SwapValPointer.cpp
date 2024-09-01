//DS-MID-LT-2.1-01: Write a program that swaps the values of two integers using pointers.

#include <iostream>
using namespace std;

void swapVal(int *c, int *d) {
    int temp = *c;
    *c = *d;
    *d = temp;
}

int main() {
    int a, b;

    cout << endl << "Enter two integer numbers: ";
    cin >> a >> b;

    swapVal(&a, &b);

    cout << endl << "Swapped Values: " << a << " " << b << endl;

    return 0;
}