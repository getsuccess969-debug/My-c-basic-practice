#include "Checking.h"
#include <iostream>


Checking::Checking(const std::string& name, float balance, int min):Account(name,balance),min_balance(min)
{
	std::cout << "Checking(...)\n";
}

Checking::~Checking()
{
	std::cout << "~Checking()\n";
}

int Checking::GetMinBalance()
{
	return min_balance;
}

void Checking::Withdraw(int amount)
{
	if ((m_balance - amount) > 50) {
		Account::Withdraw(amount);
	}
	else {
		std::cout << "Invalid amount!!\n";
	}
}
