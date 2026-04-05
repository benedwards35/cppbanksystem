#pragma once
#include <vector>
#include <string>
using namespace std;

class Account;

class BankDataBase {
private:
    vector<Account*> accounts;  // list of all accounts

public:
    int getValidInt();
    double getValidDouble();
    void addAccount(Account* account);
    bool removeAccount(Account* account);
    Account* findAccount(string username); 
    void listAllAccounts(); // returns nullptr if not found
    void saveToFile(string filename);
    void loadFromFile(string filename);
    bool fileExists(string filename);
};