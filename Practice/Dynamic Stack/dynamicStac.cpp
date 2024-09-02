#include <iostream>
using namespace std;

int maxSize = 10, stack[10], top=0;

void resize(int size = 100) {
    int *tempStk = new int [maxSize + size];

    for(int i=0 ; i<maxSize ; i++) {
        tempStk[i] = stack[i];
    }

    maxSize += size;
    delete [] stack;
    stack = tempStk;
}

void push(int element) {
    if(isFull()) {
        resize();
    }
    stack[top++] = element;
}

int main() {

}