#pragma once
#include <string>
using namespace std;

enum AccountType { USER, ADMIN };

class BankDataBase;

class Account {
protected:
    string username;
    string password;
    AccountType type;

public:
    Account(string name, string pass, AccountType t);
    bool login(string inputPassword);
    string getUsername();
    string getPassword();
    AccountType getType();
    virtual void menu(BankDataBase& db) {} 
    virtual ~Account() {}
};