#include <iostream>
#include <math.h>
using namespace std;

const int stkSize = 100;
int stack[stkSize], top = -1;

bool isFull() {
    if(top >= stkSize-1) {
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

void push(int opr) {
    if(isFull()) {
        cout << endl << "Stack Overflow!" << endl;
    }
    else {
        stack[++top] = opr;
    }
}

int pop() {
    if(isEmpty()) {
        cout << endl << "Stack Empty!" << endl;
        return -1;
    }
    else {
        return stack[top--];
    }
}

int operation(char op, int opr1, int opr2) {
    switch (op) {
        case '+':
            return opr1 + opr2;
        case '-':
            return opr1 - opr2;
        case '*':
            return opr1 * opr2;
        case '/':
            return opr1 / opr2;
        case '^':
            return pow(opr1, opr2);
        default:
            cout << endl << "Invalid Operator" << endl;
            return -1;
    }
}

int postfix(string ques) {
    char op;
    int opr1, opr2, result;
    for(int i=0; i<ques.length(); i++) {
        op = ques[i];

        if(op >= '0' && op <= '9') {
            push(op - '0');
        }
        else if(op == ' '|| op == '\t') {
            continue;
        }
        else {
            opr2 = pop();
            opr1 = pop();
            result = operation(op, opr1, opr2);
            push(result);
        }
    }
    return pop();
}

int main() {
    string ques;

    cout << endl << "Enter Question: ";
    cin >> ques;

    cout << endl << "Postfix Result: " << postfix(ques) << endl;

    return 0;
}