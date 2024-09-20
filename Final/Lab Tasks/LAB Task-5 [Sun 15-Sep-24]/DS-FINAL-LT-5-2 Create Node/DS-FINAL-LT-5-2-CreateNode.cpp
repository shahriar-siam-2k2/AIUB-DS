//DS-FINAL-LT-5-2: Write a program to add a node to the BST in question no.1.

#include <iostream>
#include <conio.h>
using namespace std;

bool check = false;
int count = 0;

struct node {
    int data;
    node* Lchild;
    node* Rchild;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->Lchild = nullptr;
    newNode->Rchild = nullptr;
    check = true;

    cout << endl << "\t* New node with data " << data << " created!" << endl;

    return newNode;
}

node* createBST(node* &root, int data) {
    if(root == nullptr) {
        root = createNode(data);
    }
    else {
        if(data < root->data) {
            root->Lchild = createBST(root->Lchild, data);
        }
        else if(data > root->data) {
            root->Rchild = createBST(root->Rchild, data);
        }
        else {
            cout << endl << "\t* " << data << " already exists!" << endl;
        }
    }

    return root;
}

int main() {
    int* data = new int;
    char* op = new char;
    node* root = nullptr;

    while(true) {
        cout << endl << endl << "\tBinary Search Tree" << endl;

        cout << endl << "1. Add Data" << endl
                    << "2. Exit" << endl;
        cout << "Choose operation: ";
        cin >> *op;

        if(*op == '1') {
            cout << endl << "Enter data-" << (count+1) << ": ";
            cin >> *data;

            createBST(root, *data);

            if(check == true) {
                count++;
            }

            check = false;
        }
        else if(*op == '2') {
            break;
        }
        else {
            cout << endl << "\t* Invalid operation!" << endl;
        }
    }

    delete data;
    delete op;

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}