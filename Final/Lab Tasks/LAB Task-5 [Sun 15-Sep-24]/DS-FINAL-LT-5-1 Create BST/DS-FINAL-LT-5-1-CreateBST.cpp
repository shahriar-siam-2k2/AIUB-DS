//DS-FINAL-LT-5-1: Write a program to create a BST with 10 nodes.

#include <iostream>
#include <conio.h>
using namespace std;

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
    int data;
    node* root = nullptr;

    cout << endl << "\tBinary Search Tree" << endl;
    cout << "      Create Node & Add Data" << endl;

    for(int i=0 ; i<10; i++) {
        cout << endl << "Enter data-" << (i+1) << ": ";
        cin >> data;
        createBST(root, data);
    }

    cout << endl << "\t* 10 nodes created!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}