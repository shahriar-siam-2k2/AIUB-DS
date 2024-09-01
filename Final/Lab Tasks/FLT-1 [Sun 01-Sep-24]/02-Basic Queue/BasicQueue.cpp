#include <iostream>
using namespace std;

const int size = 5;
int front = -1, rear = -1;
int queue[size];

bool isEmpty() {
    if(front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull() {
    if(rear == size-1) {
        return true;
    }
    else {
        return false;
    }
}

void Enqueue(int a) {
    if(isFull()) {
        cout << endl << "Queue is full!" << endl;
    }
    else{
        rear++;
        queue[rear] = a;
        cout << endl << a << " is enqueued." << endl;
    }
}

void Dequeue() {
    if(isEmpty()) {
        cout << endl << "Queue is empty!" << endl;
    }
    else {
        front++;
    }
}

int main() {
    Dequeue();

    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);

    Dequeue();
    Dequeue();

    Enqueue(25);

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
}