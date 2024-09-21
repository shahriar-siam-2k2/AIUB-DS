//DS-FINAL-LT-5-1: Write a program to create a BST with 10 nodes.

#include <iostream>
#include <conio.h>
using namespace std;

int c = 0;

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

    c++;

    cout << endl << "\t* New Node (node-" << c << ") Created!" << endl;
    cout << endl << "\t* " << data << " Added to Node-" << c << "!" << endl;

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
    node* root = nullptr;

    createBST(root, 1);
    createBST(root, 2);
    createBST(root, 3);
    createBST(root, 3);
    createBST(root, 4);
    createBST(root, 5);
    createBST(root, 6);
    createBST(root, 7);
    createBST(root, 8);
    createBST(root, 9);
    createBST(root, 10);
    
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}