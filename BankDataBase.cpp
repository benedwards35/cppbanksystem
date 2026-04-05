#include "BankDataBase.h"
#include <iostream>
#include "Account.h" 
#include "User.h"
#include "Admin.h"
#include <fstream>

using namespace std;


int BankDataBase::getValidInt(){
    int input;
    while(true){
        cin >> input;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number: ";
        } else {
            cin.ignore(1000, '\n');
            return input;
        }
    }
}

double BankDataBase::getValidDouble(){
    double input;
    while(true){
        cin >> input;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number: ";
        } else {
            cin.ignore(1000, '\n');
            return input;
        }
    }
}

void BankDataBase::addAccount(Account* account){
    accounts.push_back(account);
}
bool BankDataBase::removeAccount(Account* account){
    for (int i = 0; i < accounts.size(); i++){
        if (accounts[i] == account){
            accounts.erase(accounts.begin() + i);
            return true;
        }
    }
    return false;
}

Account* BankDataBase::findAccount(string username){
    for (Account* a : accounts){
        //cout << "Comparing: '" << a->getUsername() << "' with '" << username << "'" << endl;
        if (a->getUsername() == username)
            return a;
    }
    return nullptr;  // not found
}

void BankDataBase::listAllAccounts(){
    for (Account* a : accounts){
        string type = (a->getType() == USER) ? "User" : "Admin";
        cout << a->getUsername() << " (" << type << ")" << endl;
    }
}

void BankDataBase::saveToFile(string filename){
    ofstream file(filename);
    for (Account* a : accounts){
        if(a->getType() == USER){
            User* u = (User*)a;
            file << "USER " << a->getUsername() << " " << a->getPassword() << " " << u->getBalance() << "\n";
        } else {
            file << "ADMIN " << a->getUsername() << " " << a->getPassword() << "\n";
        }
    }
    file.close();
}

void BankDataBase::loadFromFile(string filename){
    ifstream file(filename);
    if(!file.is_open()) return;  // no file yet, skip
    string type, username, password;
    while(file >> type >> username >> password){
        if(type == "USER"){
            double balance;
            file >> balance;
            User* u = new User(username, password);
            u->setBalance(balance);
            addAccount(u);
        } else {
            addAccount(new Admin(username, password));
        }
    }
    file.close();
}

bool BankDataBase::fileExists(string filename){
    ifstream file(filename);
    return file.is_open();
}