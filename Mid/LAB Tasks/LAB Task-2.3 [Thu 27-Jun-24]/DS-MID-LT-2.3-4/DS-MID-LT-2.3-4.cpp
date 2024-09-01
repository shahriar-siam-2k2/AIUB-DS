//DS-MID-LT-2.3-4: Using the structure above, develop a way to create, and delete a user.

#include <iostream>
using namespace std;

struct bankUser {
    string name, id, dob, accOpenDate, pass;
    double balance;
};
const int maxUser = 1000;
int userC = 0, foundIndex;
bankUser user[maxUser];

bool duplicateCheck(string id) {
    bool flag = false;
    for(int i=0 ; i<userC ; i++) {
        if(user[i].id == id) {
            flag = true;
            break;
        }
    }
    return flag;
}

bool credentialCheck(string id, string pass) {
    bool flag = false;
    for(int i=0 ; i<userC ; i++) {
        if(user[i].id == id && user[i].pass == pass) {
            flag = true;
            foundIndex = i;
            break;
        }
    }
    return flag;
}

void create() {
    double balance;
    string name, id, dob, accOpenDate, pass;

    cout << endl << "\tCreate Account" << endl;

    while(true) {
        cout << endl << "Enter Name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Date of Birth: ";
        getline(cin, dob);
        cout << "Enter Account Opening Date: ";
        getline(cin, accOpenDate);
        cout << "Enter Password: ";
        getline(cin, pass);
        cout << "Enter Balance: ";
        cin >> balance;
        
        if(duplicateCheck(id) == false) {
            user[userC] = {name, id, dob, accOpenDate, pass, balance};
            cout << endl << "\t* Account Created Successfully!" << endl;
            userC++;
            break;
        }
        else {
            cout << endl << "\t* This user id is already exists! Try different." << endl << endl;
        }
    }
}

void deleteID() {
    string id, pass;

    cout << endl << "\tUser Delete" << endl;

    cout << "Enter User ID: ";
    getline(cin, id);
    cout << "Enter Password: ";
    getline(cin, pass);

    if(credentialCheck(id, pass) == true) {
        userC--;
        for(int i=foundIndex ; i<userC ; i++) {
            user[i] = user[i+1];
        }
        cout << endl << "\t* User (" << id << ") and corresponding Password Deleted Successfully!" << endl;
    }
    else {
        cout << endl << "\t* Wrong user ID or password!" << endl;
    }
}

int main() {
    int op;

    while (true) {
        cout << endl << "1. Create Account." << endl;
        cout << "2. Delete Account." << endl;
        cout << "3. Exit." << endl;

        cout << "Choose your operation: ";
        cin >> op;

        if(op == 1) {
            create();
        }
        else if(op == 2) {
            if(userC == 0) {
                cout << endl << "No Account Created!" << endl;
            }
            else {
                deleteID();
            }
        }
        else if(op == 3) {
            cout << endl << "Successfully exited." << endl;
            break;
        }
        else {
            cout << endl << "INVALID OPERATION!" << endl;
        }
    }

    return 0;
}