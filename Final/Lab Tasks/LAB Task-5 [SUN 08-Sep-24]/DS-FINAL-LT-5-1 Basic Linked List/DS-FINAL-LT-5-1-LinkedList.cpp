#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    node* head;
    node* tail;
    node* temp;

    node* node1 = new node();
    node1 -> data = 1;
    head = node1;

    node* node2 = new node();
    node2 -> data = 2;
    node1 -> next = node2;

    node* node3 = new node();
    node3 -> data = 2;
    node2 -> next = node3;
    node3 -> next = nullptr;
    tail = node3;

    node* node0 = new node();
    node0 -> data = 0;
    node0 -> next = head;
    head = node0;

    temp = head;
    while(temp -> next != nullptr) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }

    //search
    int item = 1;
    while(item != 1 && tail != nullptr) {
        temp = temp -> next;
    }
}