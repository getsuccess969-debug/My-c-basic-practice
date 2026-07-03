#pragma once
#include "Account.h"
class Checking :
    public Account
{
    int min_balance;
public:
    Checking(const  std::string& name, float balance, int min);
    ~Checking();
     int GetMinBalance();
    void Withdraw(int amount);
};

