//DS-MID-LT-2.3-1: Develop a structure that can store information about a user in a bank. The information will be – name, id, dob, account opening date, balance, and password.

#include <iostream>
using namespace std;

struct bankUser {
    string name, id, dob, accOpenDate, pass;
    double balance;
};

int main() {
    bankUser user1;
    string name, id, dob, accOpenDate, pass;
    double balance;

    cout << endl << "Enter Name: ";
    cin >> name;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Date of Birth: ";
    cin >> dob;

    cout << "Enter Account Opening Date: ";
    cin >> accOpenDate;

    cout << "Enter Password: ";
    cin >> pass;

    cout << "Enter Balance: ";
    cin >> balance;

    user1 = {name, id, dob, accOpenDate, pass, balance};

    cout << endl << "Name: " << user1.name << endl;
    cout << "ID: " << user1.id << endl;
    cout << "Date of Birth: " << user1.dob << endl;
    cout << "Account Opening Date: " << user1.accOpenDate << endl;
    cout << "Password: " << user1.pass << endl;
    cout << "Balance: " << user1.balance << endl;
}