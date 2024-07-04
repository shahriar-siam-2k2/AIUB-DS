#include <iostream>
using namespace std;

struct grocery {
    string name, id;
    int quantity;
    double price;
};
const int maxProduct = 1000;
grocery product[maxProduct];
int productC = 0, foundIndex;

bool DuplicateVerification(string id) {
    bool flag = false;
    for(int i=0 ; i<productC ; i++) {
        if(product[i].id == id) {
            flag = true;
            foundIndex = i;
            break;
        }
    }
    return flag;
}

void Add() {
    string name, id;
    int quantity;
    double price;

    cout << endl << "\tAdd Product" << endl;

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, name);
    cout << "Enter Product ID: ";
    getline(cin, id);
    cout << "Enter Product Quantity: ";
    cin >> quantity;
    cout << "Enter Product Price: ";
    cin >> price;
    
    if(DuplicateVerification(id) == false) {
        product[productC] = {name, id, quantity, price};
        productC++;
        cout << endl << "\tProduct Added!" << endl;
    }
    else {
        cout << endl << "Same ID found. Try Different." << endl;
    }
    
}

void Update() {
    int op;
    string id;

    cin.ignore();

    cout << endl << "\tProduct Update" << endl;

    cout << "Enter the product id to update: ";
    getline(cin, id);

    if(DuplicateVerification(id) == false) {
        while(true) {
            cin.ignore();

            cout << "1. Update Name" << endl;
            cout << "2. Update id" << endl;
            cout << "3. Update quantity" << endl;
            cout << "4. Update price" << endl;
            cout << "5. Cancel" << endl;

            cout << "Choose your operation: ";
            cin >> op;

            if(op == 1) {
                string txt;
                cout << "Enter new product name: ";
                getline(cin, txt);
                product[foundIndex].name = txt;
                break;
            }
            else if(op == 2) {
                string txt;
                cout << "Enter new product id: ";
                getline(cin, txt);
                product[foundIndex].id = txt;
                break;
            }
            else if(op == 3) {
                int q;
                cout << "Enter new product quantity: ";
                cin >> q;
                product[foundIndex].quantity = q;
                break;
            }
            else if(op == 4) {
                double price;
                cout << "Enter new product price: ";
                cin >> price;
                product[foundIndex].price = price;
                break;
            }
            else if(op == 5) {
                cout << endl << "Cancelled." << endl;
            }
            else {
                cout << endl << "Invalid operation" << endl;
            }
        }
    }
    else {
        cout << endl << "Same ID found. Try Different." << endl;
    }
}

void Search() {
    string id;

    cin.ignore();

    cout << endl << "\tProduct Search" << endl;

    cout << "Enter the product id to search: ";
    getline(cin, id);

    for(int i=0 ; i<productC ; i++) {
        if(product[i].id == id) {
            cout << "found";
            break;
        }
    }
}

int main() {
    int op;

    cout << endl << "\tXYZ Groceries LTD." << endl;

    while(true) {
        cout << endl << "1. Add Product" << endl;
        cout << "2. Update Product" << endl;
        cout << "3. Search Product" << endl;
        
        cout << "Enter your operation: ";
        cin >> op;

        if(op == 1) {
            Add();
        }
        else if(op == 2) {
            if(productC == 0) {
                cout << endl << "No Product added." << endl;
            }
            else {
                Update();
                break;
            }
        }
        else if(op == 3) {
            if(productC == 0) {
                cout << endl << "No Product added." << endl;
            }
            else {
                Search();
                break;
            }
        }
        else {
            cout << endl << "Wrong Operation." << endl;
        }
    }
}