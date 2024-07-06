#include <iostream>
#include <conio.h>
using namespace std;

struct grocery {
    string name, id;
    int quantity;
    double price;
};
const int maxProduct = 1000;
grocery product[maxProduct];
int productC = 0, tracer, foundIndex;

void showDetails() {
    cout << "Product ID: " << product[foundIndex].id << endl;
    cout << "Product Name: " << product[foundIndex].name << endl;
    cout << "Product Quantity: " << product[foundIndex].quantity << endl;
    cout << "Product Price: " << product[foundIndex].price << endl;
}

bool Search(string id) {
    bool flag = false;

    for(int i=0 ; i<productC ; i++) {
        if(product[i].id == id) {
            flag = true;
            foundIndex = i;
            break;
        }
    }

    if(flag == true) {
        if(tracer == 2) {
            cout << endl << "Product Details-" << endl;
            showDetails();
        }
        else if(tracer == 4) {
            cout << endl << "Searched Product Details-" << endl;
            showDetails();
        }
    }

    return flag;
}

void Add() {
    string name, id;
    int quantity;
    double price;

    cout << endl << "\tProduct Add" << endl;

    cin.ignore(10000, '\n');

    cout << "Enter Product ID: ";
    getline(cin, id);

    if(Search(id) == false) {
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Product Quantity: ";
        cin >> quantity;
        cout << "Enter Product Price: ";
        cin >> price;

        product[productC] = {name, id, quantity, price};
        productC++;
        cout << endl << "\t* Product Added!" << endl;
    }
    else {
        cout << endl << "\t* Same ID found. Try Different." << endl;
    }
    
}

void Delete() {
    string id;

    cout << endl << "\tProduct Delete" << endl;

    cin.ignore(10000, '\n');

    cout << "Enter Product ID: ";
    getline(cin, id);

    if(Search(id) == true) {
        productC--;
        for(int i=foundIndex ; i<productC ; i++) {
            product[i] = product[i+1];
        }
        cout << endl << "\t* Product (" << id << ") and corresponding Data Deleted Successfully!" << endl;
    }
    else {
        cout << endl << "\t* Product Not Found!" << endl;
    }
}

void Update() {
    int op;
    tracer = 2;
    string id;
    bool update = false;

    cin.ignore(10000, '\n');

    cout << endl << "Enter the product ID to update: ";
    getline(cin, id);

    if(Search(id) == true) {
        int index = foundIndex;
        while(true) {
            cout << endl << "\tProduct Update of Product (" << product[index].id << ")" << endl;
            cout << "1. Update ID" << endl;
            cout << "2. Update Name" << endl;
            cout << "3. Update quantity" << endl;
            cout << "4. Update price" << endl;
            cout << "5. Back To Menu" << endl;

            cout << "Choose your operation: ";
            cin >> op;

            cin.ignore(10000, '\n');

            if(op == 1 && productC >= 1) {
                string txt;
                cout << endl << "Enter new product id: ";
                getline(cin, txt);
                if(Search(txt) == false) {
                    product[index].id = txt;
                    update = true;
                    cout << endl << "\t* Product ID Updated!" << endl;
                }
                else {
                    cout << endl << "\t* Same ID found! Try Different." << endl;
                }
            }
            else if(op == 2) {
                string txt;
                cout << endl << "Enter new product name: ";
                getline(cin, txt);
                product[index].name = txt;
                update = true;
                cout << endl << "\t* Product Name Updated!" << endl;
            }
            else if(op == 3) {
                int q;
                cout << endl << "Enter new product quantity: ";
                cin >> q;
                product[index].quantity = q;
                update = true;
                cout << endl << "\t* Product Quantity Updated!" << endl;
            }
            else if(op == 4) {
                double price;
                cout << endl << "Enter new product price: ";
                cin >> price;
                product[index].price = price;
                update = true;
                cout << endl << "\t* Product Price Updated!" << endl;
            }
            else if(op == 5) {
                break;
            }
            else {
                cout << endl << "\t* Invalid operation" << endl;
            }
        }
    }
    else {
        cout << endl << "\t* Product Not Found." << endl;
    }

    if(update == true) {
        cout << endl << "Updated Product Information-" << endl;
        showDetails();
    }
}

int main() {
    int op;

    while(true) {
        cout << endl << endl << "\tXYZ Groceries LTD." << endl;
        cout << endl << "\tMenu" << endl;

        cout << "1. Add Product" << endl;
        cout << "2. Update Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Search Product" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your operation: ";
        cin >> op;

        if(op == 1) {
            Add();
        }
        else if(op == 2) {
            if(productC == 0) {
                cout << endl << "\t* No Product added!" << endl;
            }
            else {
                Update();
            }
        }
        else if(op == 3) {
            if(productC == 0) {
                cout << endl << "\t* No Product added!" << endl;
            }
            else {
                Delete();
            }
        }
        else if(op == 4) {
            if(productC == 0) {
                cout << endl << "\t* No Product added!" << endl;
            }
            else {
                string id;
                tracer = 4;
                cin.ignore(10000, '\n');
                cout << endl << "\tProduct Search" << endl;
                cout << "Enter Product ID: ";
                getline(cin, id);
                if(Search(id) == false) {
                    cout << endl << "\t* Product Not Found!" << endl;
                }
            }
        }
        else if(op == 5) {
            cout << endl << "\t* Successfully Exited" << endl;
            break;
        }
        else {
            cout << endl << "\t* Wrong Operation." << endl;
        }
    }
    cout << endl << "\t* Enter any key to close console.";

    getch();

    cout << endl;

    return 0;
}