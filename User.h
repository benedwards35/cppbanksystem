#pragma once
#include "Account.h"
#include "BankDataBase.h"

class User : public Account {

private: 
    double balance;
public:
    User(string name, string pass);
    void menu(BankDataBase& db); 
    void deposit(BankDataBase& db);
    void withdraw(BankDataBase& db);
    void userSettings(BankDataBase& db);
    double getBalance();
    void setBalance(double amount);
};