#include "User.h"
#include <iostream>
#include "BankDataBase.h"

User::User(string name, string pass) : Account(name, pass, USER) {
    balance = 0.0; 
}


void User::menu(BankDataBase& db){
    int userChoice = 0;
    bool quit = false;
    cout << "User Menu: Select an Option:" << endl;
    while(!quit) {
        cout << "Balance: $" << balance << endl;
        cout << "1. Deposit\n2. Withdraw\n3. User Settings\n4. Exit" << endl;
        userChoice = db.getValidInt();
        switch(userChoice){
            case 1:
                deposit(db);
                break;
            case 2:
                withdraw(db);
                break;
            case 3:
                userSettings(db);
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

void User::deposit(BankDataBase& db){
    cout << "Enter amount to deposit: ";
    double amount = db.getValidDouble();
    if(amount <= 0){
        cout << "Invalid amount." << endl;
        return;
    }
    balance += amount;
    cout << "New balance: " << balance << endl;
}

void User::withdraw(BankDataBase& db){
    cout << "Enter amount to withdraw: ";
    double amount = db.getValidDouble();
    if(amount <= 0){
        cout << "Invalid amount." << endl;
        return;
    }
    if(amount > balance){
        cout << "Insufficient funds." << endl;
        return;
    }
    balance -= amount;
    cout << "New balance: " << balance << endl;
}

void User::userSettings(BankDataBase& db){
    int choice = 0;
    bool quit = false;
    while(!quit){
        cout << "1. Change Username\n2. Change Password\n3. Back" << endl;
        choice = db.getValidInt();
        switch(choice){
            case 1: {
                string newUsername;
                while(true){
                    cout << "Enter new username ('cancel' to exit): ";
                    cin >> newUsername;
                    if(newUsername == "cancel") break;
                    if(db.findAccount(newUsername) != nullptr){
                        cout << "Username already taken. Try again." << endl;
                    } else {
                        username = newUsername;
                        cout << "Username changed successfully." << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                string newPassword;
                string confirmPassword;
                cout << "Enter new password ('cancel' to exit): ";
                cin >> newPassword;
                if(newPassword == "cancel") break;
                cout << "Confirm new password: ";
                cin >> confirmPassword;
                if(newPassword != confirmPassword){
                    cout << "Passwords do not match." << endl;
                } else {
                    password = newPassword;
                    cout << "Password changed successfully." << endl;
                }
                break;
            }
            case 3:
                quit = true;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}

double User::getBalance(){
    return balance;
}

void User::setBalance(double amount){
    balance = amount;
}
