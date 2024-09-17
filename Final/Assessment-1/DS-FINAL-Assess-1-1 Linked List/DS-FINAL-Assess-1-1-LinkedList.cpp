#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode -> data = data;
    newNode -> next = nullptr;
    cout << endl << "\t* New Node Created!" << endl;
    return newNode;
}

void addHead(node* &head, int data) {
    node* newNode = createNode(data);
    newNode -> next = head;
    head = newNode;
    cout << endl << "\t* Data Added!" << endl;
    return;
}
void addMid(node* &head, int data, int pos) {
    if(head == nullptr) {
        addHead(head, data);
    }
    else {
        node* newNode = createNode(data);
        node* temp = head;

        for(int i=1; i< (pos && temp -> next != nullptr); i++) {
            temp = temp -> next;
        }

        if(temp == nullptr) {
            cout << endl << "\t* Invalid Position!" << endl;
        }
        else {
            newNode -> next = temp -> next;
            temp -> next = temp;
        }

        cout << endl << "\t* Data Added!" << endl;
    }
}
void addTail(node* &head, int data) {
    node* newNode = createNode(data);

    if(head == nullptr) {
        head = newNode;
    }
    else {
        node* temp = head;
        while(temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    cout << endl << "\t* Data Added!" << endl; 
}

void traverseNodes(node* head) {
    if(head == nullptr) {
        cout << endl << "\t* Empty Node!" << endl;
    }
    else {
        node* temp = head;

        cout << endl << "Traversing All Nodes: " << endl;
        while(temp != nullptr) {
            cout << temp -> data << endl;
            temp = temp -> next;
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

    if(head -> data == data) {
        head = curr -> next;
        delete curr;
        cout << endl << "\t* " << data << " deleted!" << endl;
        return;
    }
    else {
        while(curr != nullptr) {
            prev = curr;
            if(curr -> data == data) {
                prev -> next = curr -> next;
                delete curr;
                cout << endl << "\t* " << data << " deleted!" << endl;
                return;
            }
            curr = curr -> next;
        }
    }
    
    cout << endl << "\t* Node not found!" << endl;
}

int main() {
    char* op = new char;
    int* data = new int;
    node* head = nullptr;

    while(true) {
        cout << endl << "\tLinked List" << endl;
        cout << endl << "1. Add Node." << endl
                    << "2. Traverse List." << endl
                    << "3. Delete Node." << endl
                    << "4. Exit."
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
                        int* pos;

                        cout << "Enter Position: ";
                        cin >> *pos;

                        addMid(head, *data, *pos);
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
            cout << endl << "Enter data for delete: ";
            cin >> *data;
            deleteNode(head, *data);
        }
        else if(*op == '4') {
            break;
        }
        else {
            cout << endl << "\t* Invalid operation!" << endl;
        }
    }

    delete op;
    delete data;

    cout << endl << "\t* Program returned!" << endl;

    return 0;
}