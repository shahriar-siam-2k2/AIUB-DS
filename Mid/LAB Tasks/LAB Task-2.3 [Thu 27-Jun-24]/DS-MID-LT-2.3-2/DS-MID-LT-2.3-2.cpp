//DS-MID-LT-2.3-2: Using the structure above, develop a way to store information of multiple users in one place.

#include <iostream>
using namespace std;

struct bankUser {
    string name, id, dob, accOpenDate, pass;
    double balance;
};

int main() {
    int n;
    double balance;
    string name, id, dob, accOpenDate, pass;

    cout << endl << "Enter the number of users: ";
    cin >> n;

    bankUser user[n];

    for(int i=0 ; i<n ; i++) {
        cout << endl << "Set User-" << i+1 <<  " Informations-";

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

        user[i] = {name, id, dob, accOpenDate, pass, balance};
    }

    for(int i=0 ; i<n ; i++) {
        cout << endl << "Information of User-" << i+1 << "-" << endl;

        cout << "Name: " << user[i].name << endl;
        cout << "ID: " << user[i].id << endl;
        cout << "Date of Birth: " << user[i].dob << endl;
        cout << "Account Opening Date: " << user[i].accOpenDate << endl;
        cout << "Password: " << user[i].pass << endl;
        cout << "Balance: " << user[i].balance << endl;
    }
}