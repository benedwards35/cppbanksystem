#include "Admin.h"
#include "User.h"
#include <iostream>
#include "BankDataBase.h"

Admin::Admin(string name, string pass) : Account(name, pass, ADMIN) {}

void Admin::menu(BankDataBase& db){
    int adminChoice = 0;
    bool quit = false;
    cout << "Admin Menu: Select an Option:" << endl;
    while(!quit) {
        cout << "1. View All Accounts\n2. Add an account\n3. Remove an account\n4. Exit" << endl;
        adminChoice = db.getValidInt();
        switch(adminChoice){
            case 1:
                cout << "All Accounts:" << endl;
                db.listAllAccounts();
                break;
            case 2:
                addAccount(db);
                break;
            case 3:
                removeAccount(db);
                break;
            case 4:
                quit = true;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}

bool Admin::addAccount(BankDataBase& db){
    string username;
    string password;
    string type;
    bool validUser = false;
    cout << "Input Username (or 'cancel' to exit): ";
    while(!validUser){
        cin >> username;
        if (username == "cancel") return false;
        Account* a = db.findAccount(username);
        if(a == nullptr){
            validUser = true;
        } else {
            cout << "Username already taken. Try again: ";
        }
    }

    cout << "Input Password (or 'cancel' to exit): ";
    cin >> password;
    if (password == "cancel") return false;

    cout << "Input Type (USER or ADMIN, or 'cancel' to exit): ";
    cin >> type;
    while(type != "USER" && type != "ADMIN"){
        if (type == "cancel") return false;
        cout << "Invalid Type. Try again" << endl;
        cout << "Input Type (USER or ADMIN, or 'cancel' to exit): ";
        cin >> type;
    }

    if (type == "USER")
        db.addAccount(new User(username, password));
    else
        db.addAccount(new Admin(username, password));

    return true;
}

bool Admin::removeAccount(BankDataBase& db){
    string username;

    while(true){
        cout << "Enter the username of the account to delete ('cancel' to exit): ";
        cin >> username;
        if(username == "cancel") return false;
        Account* a = db.findAccount(username);
        if (a == nullptr){
            cout << "Unknown username. Try again." << endl;
        } else {
            return db.removeAccount(a);
        }
    }
}
