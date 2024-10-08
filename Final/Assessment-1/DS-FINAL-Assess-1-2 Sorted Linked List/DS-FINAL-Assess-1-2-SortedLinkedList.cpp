//DS-FINAL-Assess-1-2: Develop a program to sort the linked list that you created for the previous question.

#include <iostream>
#include <conio.h>
using namespace std;

int posLimit = 0;

struct node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;
    cout << endl << "\t* New Node Created!" << endl;
    return newNode;
}

void addHead(node* &head, int data) {
    node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    posLimit++;

    cout << endl << "\t* " << data << " Added!" << endl;

    return;
}
void addMid(node* &head, int data, int pos) {
    if(head == nullptr || pos == 0) {
        addHead(head, data);
    }
    else {
        node* newNode = createNode(data);
        node* temp = head;

        for(int i=1; i<pos; i++) {
            if(temp != nullptr) {
                temp = temp->next;
            }
        }

        if(temp == nullptr) {
            cout << endl << "\t* An Error Occurred!" << endl;
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
            posLimit++;

            cout << endl << "\t* " << data << " Added!" << endl;
        }
    }
}
void addTail(node* &head, int data) {
    node* newNode = createNode(data);

    if(head == nullptr) {
        head = newNode;
    }
    else {
        node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    posLimit++;

    cout << endl << "\t* " << data << " Added!" << endl;
}

void traverseNodes(node* head) {
    if(head == nullptr) {
        cout << endl << "\t* Empty Node!" << endl;
    }
    else {
        node* temp = head;

        cout << endl << "Traversing All Nodes: " << endl;
        while(temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

void deleteNode(node* &head, int data) {
    if(head == nullptr) {
        cout << endl << "\t* Empty Nodes!" << endl;
        return;
    }

    node* curr = head;
    node* prev = head;

    if(head->data == data) {
        head = curr->next;
        delete curr;
        posLimit--;

        cout << endl << "\t* Node containing " << data << " is deleted!" << endl;

        return;
    }
    else {
        prev = curr;
        curr = curr->next;
    }

    while(curr != nullptr) {
        if(curr->data == data) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(curr == nullptr) {
        cout << endl << "\t* Node containing " << data << " is not found!" << endl;
    }
    else {
        prev->next = curr->next;
        delete curr;
        posLimit--;

        cout << endl << "\t* Node containing " << data << " is deleted!" << endl;
        return;
    }
}

void sort(node* &head) {
    if(head == nullptr) {
        cout << endl << "\t* Empty Node!" << endl;
    }
    else {
        node* curr = head;
        node* min = head;
        node* check = nullptr;
        int temp;
        
        while(curr != nullptr) {
            min = curr;
            check = curr->next;

            while(check != nullptr) {
                if(check->data < min->data) {
                    min = check;
                }
                check = check->next;
            }

            if(curr != min) {
                temp = curr->data;
                curr->data = min->data;
                min->data = temp;
            }

            curr = curr->next;
        }

        cout << endl << "\t* List Sorted!" << endl;
    }
}

int main() {
    char* op = new char;
    int* data = new int;
    node* head = nullptr;

    while(true) {
        cout << endl << "\tLinked List" << endl;
        cout << endl << "1. Add Node." << endl
                    << "2. Traverse List." << endl
                    << "3. Sort List." << endl
                    << "4. Delete Node." << endl
                    << "5. Exit."
        << endl;
        cout << "Choose operation: ";
        cin >> *op;

        if(*op == '1') {
            while(true) {
                cout << endl << "\tAdd Node" << endl;
                cout << endl << "1. Add at Head." << endl
                            << "2. Add at Middle." << endl
                            << "3. Add at Tail." << endl
                            << "4. Back"
                << endl;
                cout << "Choose operation: ";
                cin >> *op;

                if(*op != '4') {
                    cout << endl << "Enter Data: ";
                    cin >> *data;

                    if(*op == '1') {
                        addHead(head, *data);
                        break;
                    }
                    else if(*op == '2') {
                        int* pos = new int;

                        cout << "Enter Position (0 to " << posLimit << "): ";
                        cin >> *pos;

                        if(*pos >= 0 && *pos <= posLimit) {
                            addMid(head, *data, *pos);
                        }
                        else {
                            cout << endl << "\t* Invalid position!" << endl;
                        }

                        delete pos;
                        break;
                    }
                    else if(*op == '3') {
                        addTail(head, *data);
                        break;
                    }
                }
                else if(*op == '4') {
                    break;
                }
                else {
                    cout << endl << "\t* Invalid operation!" << endl;
                }
            }
        }
        else if(*op == '2') {
            traverseNodes(head);
        }
        else if(*op == '3') {
            sort(head);
        }
        else if(*op == '4') {
            cout << endl << "Enter data for delete: ";
            cin >> *data;
            deleteNode(head, *data);
        }
        else if(*op == '5') {
            break;
        }
        else {
            cout << endl << "\t* Invalid operation!" << endl;
        }
    }

    delete op;
    delete data;

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "\t* Press any key to close...";

    getch();

    return 0;
}