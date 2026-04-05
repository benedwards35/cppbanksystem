#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "BankDataBase.h"
using namespace std;

int main(){
    BankDataBase db;
    if(!db.fileExists("database.txt")){
        db.addAccount(new User("user", "1234"));
        db.addAccount(new Admin("admin", "abcd"));
        db.saveToFile("database.txt");
    }

    db.loadFromFile("database.txt");

    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    Account* account = db.findAccount(username);

    if (account == nullptr){
        cout << "Username not found." << endl;
        return 1;
    } else if (!account->login(password)){
        cout << "Incorrect password." << endl;
        return 1;
    } else {
        cout << "Login successful!" << endl;
        account->menu(db);
    }
    db.saveToFile("database.txt");
    return 0;
}