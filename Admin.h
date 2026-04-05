#pragma once
#include "Account.h"
#include "BankDataBase.h"

class Admin : public Account {
public:
    Admin(string name, string pass);
    void menu(BankDataBase& db); 
    bool addAccount(BankDataBase& db);
    bool removeAccount(BankDataBase& db);
};