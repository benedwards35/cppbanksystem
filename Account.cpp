#include "Account.h"
#include "BankDataBase.h"

Account::Account(string name, string pass, AccountType t){
    username = name;
    password = pass;
    type = t;
}

bool Account::login(string inputPassword){
    return inputPassword == password;
}

AccountType Account::getType(){
    return type;
}

string Account::getUsername(){
    return username;
}

string Account::getPassword(){
    return password;
}

