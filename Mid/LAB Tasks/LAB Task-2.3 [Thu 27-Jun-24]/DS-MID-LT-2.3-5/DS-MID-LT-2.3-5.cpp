//DS-MID-LT-2.3-5: Using the structure above, develop a way to update specific information of a user. 

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

void createUser() {
    double balance;
    string name, id, dob, accOpenDate, pass;

    cout << endl << "\tCreate Account" << endl;

    while(true) {
        cin.ignore();

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

void login() {
    string id, pass;

    cin.ignore();
    
    cout << endl << "\tUser Login" << endl;

    cout << "Enter User ID: ";
    getline(cin, id);
    cout << "Enter Password: ";
    getline(cin, pass);
    
    if(credentialCheck(id, pass) == true) {
        cout << endl << "\t* Login Successfull!" << endl;
        cout << endl << "User Information- " << endl;
        cout << "Name: " << user[foundIndex].name << endl;
        cout << "ID: " << user[foundIndex].id << endl;
        cout << "Date of Birth: " << user[foundIndex].dob << endl;
        cout << "Account Opening Date: " << user[foundIndex].accOpenDate << endl;
        cout << "Password: " << user[foundIndex].pass << endl;
        cout << "Balance: " << user[foundIndex].balance << endl;
    }
    else {
        cout << endl << "\t* Wrong user ID or password." << endl;
    }
}

void updateUser() {
    string id, pass;

    cin.ignore();

    cout << endl << "\tUpdate Information" << endl;

    cout << endl << "Enter User ID: ";
    getline(cin, id);
    cout << "Enter Password: ";
    getline(cin, pass);

    if(credentialCheck(id, pass) == true) {
        int op;
        double updateBlnc;
        string updateTxt;
        bool update = false;
        
        while(true) {
            cout << endl << "1. Update Name" << endl;
            cout << "2. Update ID" << endl;
            cout << "3. Update Date of Birth" << endl;
            cout << "4. Update Password" << endl;
            cout << "5. Update Balance" << endl;
            cout << "6. Cancel" << endl;

            cout << "Choose your operation: ";
            cin >> op;

            cin.ignore();

            if(op == 1) {
                cout << endl << "Enter New Name: ";
                getline(cin, updateTxt);
                user[foundIndex].name = updateTxt;
                update = true;
                break;
            }
            else if(op == 2) {
                cout << endl << "Enter New ID: ";
                getline(cin, updateTxt);

                if(duplicateCheck(updateTxt) == false) {
                    user[foundIndex].id = updateTxt;
                    update = true;
                    break;
                }
                else {
                    cout << endl << "\t* This user id is already exists! Try different." << endl;
                }
            }
            else if(op == 3) {
                cout << endl << "Enter New Date of Birth: ";
                getline(cin, updateTxt);
                user[foundIndex].dob = updateTxt;
                update = true;
                break;
            }
            else if(op == 4) {
                cout << endl << "Enter New Password: ";
                getline(cin, updateTxt);
                user[foundIndex].pass = updateTxt;
                update = true;
                break;
            }
            else if(op == 5) {
                cout << endl << "Enter New Balance: ";
                cin >> updateBlnc;
                user[foundIndex].balance = updateBlnc;
                update = true;
                break;
            }
            else if(op == 6) {
                cout << endl << "\t* Cancelled Update Information" << endl;
                break;
            }
            else {
                cout << endl << "\t* INVALID OPERATION!" << endl;
            }
        }

        if(update == true) {
            cout << endl << "\t* Information Updated Successfully!" << endl;
        }
    }
    else {
        cout << endl << "\t* Wrong user ID or password." << endl;
        cout << "\t* Enter correct ID and Password to update information of user." << endl;
    }
}

void deleteUser() {
    string id, pass;

    cin.ignore();

    cout << endl << "\tUser Delete" << endl << endl;

    cout << "Enter User ID: ";
    getline(cin, id);
    cout << "Enter Password: ";
    getline(cin, pass);

    if(credentialCheck(id, pass) == true) {
        userC--;
        for(int i=foundIndex ; i<userC ; i++) {
            user[i] = user[i+1];
        }
        cout << endl << "\t* User (" << id << ") and corresponding Data Deleted Successfully!" << endl;
    }
    else {
        cout << endl << "\t* Wrong user ID or password!" << endl;
    }
}

int main() {
    int op;

    while (true) {
        cout << endl << "1. Create Account." << endl;
        cout << "2. Login." << endl;
        cout << "3. Update Information." << endl;
        cout << "4. Delete Account." << endl;
        cout << "5. Exit." << endl;

        cout << "Choose your operation: ";
        cin >> op;

        if(op == 1) {
            createUser();
        }
        else if(op == 2) {
            if(userC == 0) {
                cout << endl << "\t* No Account Created!" << endl;
            }
            else {
                login();
            }
        }
        else if(op == 3) {
            if(userC == 0) {
                cout << endl << "\t* No Account Created!" << endl;
            }
            else {
                updateUser();
            }
        }
        else if(op == 4) {
            if(userC == 0) {
                cout << endl << "\t* No Account Created!" << endl;
            }
            else {
                deleteUser();
            }
        }
        else if(op == 5) {
            cout << endl << "\t* Successfully exited." << endl;
            break;
        }
        else {
            cout << endl << "\t* INVALID OPERATION!" << endl;
        }
    }

    return 0;
}