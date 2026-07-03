#pragma once
#include "Account.h"
class Savings :
    public Account
{
    float m_rate;
public:
    Savings(std::string name, float balance, float rate);
    ~Savings();
    float GetInterestRate()const override;
    void AccumulateInterest()override;
};

