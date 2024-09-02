#include <iostream>
using namespace std;

int front = -1, rear = -1, maxSize=10, queue[10];

bool IsEmpty() {
    if(front == -1 && rear == -1) {
        return true;
    }
}

bool IsFull() {
    if(rear == (maxSize - 1)) {
        return true;
    }
}

void EnQueue(int x) {
    if(IsFull()) {
        cout << endl << "Queue Full!" << endl;
    }
    else if(IsEmpty()) {
        front = 0, rear = 0;
        queue[rear] = x;
    }
    else {
        rear++;
        queue[rear] = x;
    }
}

void DeQueue() {
    if(IsEmpty()) {
        cout << endl << "Queue Empty! Dequeue is not possible!" << endl;
    }
    else if(front == rear) {
        front = -1, rear = -1;
    }
    else {
        front++;
    }
}

int FrontValue() {
    if(IsEmpty()) {
        cout << endl << "Queue Empty!" << endl;
    }
    else {
        return queue[front];
    }
}

void ShowQueue() {
    if(IsEmpty()) {
        cout << endl << "Queue Empty!" << endl;
    }
    else {
        for(int i=front ; i<rear ; i++) {
            cout << queue[i] << " ";
        }
    }
}

int main() {
    int op;

    while(true) {
        cout << endl << "1. En-queue";
        cout << endl << "2. De-queue";
        cout << endl << "3. Front Value";
        cout << endl << "4. Show Queue";
        cout << endl << "5. Exit" << endl;

        cout << endl << "Choose your operation: ";
        cin >> op;

        switch(op) {
            case 1:
                int x;
                cout << endl << "Enter a value to En-queue: ";
                cin >> x;
                EnQueue(x);
                continue;
            case 2:
                DeQueue();
                continue;
            case 3:
                FrontValue();
                continue;
            case 4:
                ShowQueue();
                continue;
            case 5:
                return 0;
            default:
                cout << endl << "Wrong Operation!" << endl;
                continue;
        }
    }
}