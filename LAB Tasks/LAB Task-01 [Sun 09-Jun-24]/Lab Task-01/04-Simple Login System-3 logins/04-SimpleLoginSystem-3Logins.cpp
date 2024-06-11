#include <iostream>
using namespace std;

const int maxUser = 1000;
int users = 0, retry = 3;
string idPass[maxUser][2];

bool duplicateCheck(string id) {
    bool flag = false;
    for(int i=0 ; i<users ; i++) {
        if(idPass[i][0] == id) {
            flag = true;
            break;
        }
    }
    return flag;
}

bool credentialCheck(string id, string pass) {
    bool flag = false;
    for(int i=0 ; i<users ; i++) {
        if(idPass[i][0] == id && idPass[i][1] == pass) {
            flag = true;
            break;
        }
    }
    return flag;
}

void create() {
    string id, pass;

    cout << endl << "\tCreate Account" << endl;

    while(true) {
        cout << "Enter New User ID: ";
        cin >> id;
        cout << "Enter New Password: ";
        cin >> pass;
        
        if(duplicateCheck(id) == false) {
            idPass[users][0] = id;
            idPass[users][1] = pass;
            cout << endl << "\t* Account Created Successfully!" << endl;
            users++;
            break;
        }
        else {
            cout << endl << "\t* This user id is already exists! Try different" << endl << endl;
        }
    }
}

void login() {
    string id, pass;

    cout << endl << "\tUser Login" << endl;

    cout << "Enter User ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> pass;
    
    if(credentialCheck(id, pass) == true) {
        cout << endl << "\t* Login Successfull!" << endl;
        retry = 3;
    }
    else {
        retry--;
        cout << endl << "\t* Wrong user ID or password." << endl;
        if(retry == 0) {
            cout << "\t* System locked LOGIN OPERATION due to 3 continuous wrong login attempts!" << endl << endl;
        }
        else {
            cout << "\t* You have only " << retry << " attempts left!" << endl << endl;
        }
    }
}

int main() {
    int op;

    cout << endl << "\t*** Simple Login System ***" << endl;

    while (true) {
        cout << endl << "1. Create Account." << endl;
        cout << "2. Login." << endl;
        cout << "3. Exit." << endl;

        cout << "Choose your operation: ";
        cin >> op;

        if(op == 1) {
            create();
        }
        else if(op == 2) {
            if(retry == 0) {
                cout << endl << "\t* System locked LOGIN OPERATION due to 3 continuous wrong login attempts!" << endl << endl;
            }
            else {
                login();
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