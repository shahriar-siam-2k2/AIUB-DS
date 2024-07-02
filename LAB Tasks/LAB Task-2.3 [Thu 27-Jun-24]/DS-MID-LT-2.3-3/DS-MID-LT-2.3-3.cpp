//DS-MID-LT-2.3-3: Using the structure above, develop a way for user login.

#include <iostream>
using namespace std;

struct bankUser {
    string name, id, dob, accOpenDate, pass;
    double balance;
};
bankUser user[3];

bool login(string refID, string refPass) {
    bool check = false;
    for(int i=0 ; i<3 ; i++) {
        if(user[i].id == refID && user[i].pass == refPass) {
            check = true;
            break;
        }
    }
    return check;
}

int main() {
    double balance;
    string name, id, dob, accOpenDate, pass, refID, refPass;

    user[0] = {"Siam", "1234", "04-Apr-24", "02-Jul-24", "seam", 2000};
    user[1] = {"Raj", "7410", "04-Apr-24", "02-Jul-24", "rj", 3000};
    user[2] = {"Erona", "9630", "04-Apr-24", "02-Jul-24", "ero", 4000};

    cout << endl << "Enter ID: ";
    cin >> refID;
    cout << "Enter Password: ";
    cin >> refPass;

    if(login(refID, refPass) == true) {
        cout << endl << "Login Successfull!" << endl;  
    }
    else {
        cout << endl << "Wrong User ID or Password!" << endl;
    }
}