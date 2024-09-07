#include <iostream>
using namespace std;

const int stackSize = 5;
int front = -1, rear = -1;
int queue[stackSize];

bool isEmpty() {
    if(front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull() {
    if(rear == stackSize-1) {
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
        if(isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear+1) % stackSize;
        }
        queue[rear] = a;
        cout << endl << a << " is enqueued." << endl;
    }
}

void Dequeue() {
    if(isEmpty()) {
        cout << endl << "Queue is empty!" << endl;
    }
    else if(front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front+1) % stackSize;;
    }
}

void FrontValue() {
    if(isEmpty()) {
        cout << endl << "Queue is empty!" << endl;
    }
    else {
        cout << endl << "Front Value: " << queue[front] << endl;
    }
}

void ShowQueue() {
    if(isEmpty()) {
        cout << endl << "Queue is empty!" << endl;
    }
    else {
        cout << endl << "Showing Queue:" << endl;
        for(int i=front; i<=rear; i++) {
            cout << queue[i] << endl;
        }
    }
}

int main() {
    Dequeue();

    Enqueue(2);
    Enqueue(3);
    Enqueue(4);

    FrontValue();

    Enqueue(5);
    Enqueue(6);

    FrontValue();

    ShowQueue();

    Dequeue();
    Dequeue();

    Enqueue(25);

    ShowQueue();

    FrontValue();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();

    FrontValue();

    Enqueue(3);

    FrontValue();

    ShowQueue();

    Dequeue();

    ShowQueue();
}