#include <iostream>
using namespace std;

int main() {
    int arr[10] = {12,20,30,40,50,60,70,80,90,100};
    int *p = arr;

    cout << endl << "*p + *p: " << *p + *p << endl;
    cout << "*(p+*p): " << *(p+*p) << endl;
    cout << "*p+1: " << *p+1 << endl;
    cout << "*p+1: " << *p+1 << endl;
    cout << "*p++: " << *p++ << endl;
    cout << "*p++: " << *p++ << endl;
    cout << "++*p: " << ++*p << endl;
    cout << "++*p: " << ++*p << endl;
    cout << "*++p: " << *++p << endl;
    cout << "*p: " << *p << endl;
    cout << "*(p+1): " << *(p+1) << endl;
    cout << "*(p+2): " << *(p+2) << endl;
    cout << "*p+2: " << *p+2 << endl;
    cout << "(*p)+3: " << (*p)+3 << endl;
    cout << "(*p+3)+3: " << (*p+3)+3 << endl;
    cout << "(*p+3+1): " << (*p+3+1) << endl;
    cout << "*(p+4): " << *(p+4) << endl;
    cout << "*(p+4+1): " << *(p+4+1) << endl;   
}