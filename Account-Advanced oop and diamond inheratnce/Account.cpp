#include "Account.h"
#include <iostream>
int Account::AccnoGenerator=100;
Account::Account(const std::string& name, float balance):name(name),m_balance(balance)
{
	m_Accno = ++AccnoGenerator;
	std::cout << "Account(...)\n";
}

Account::~Account()
{
	std::cout << "~Account()\n";

}

const std::string Account::GetName() const
{
	return name;
}

float Account::GetBalance() const
{
	return m_balance;
}

int Account::GetAccno()
{
	return AccnoGenerator;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(int amount)
{
	if (amount < m_balance) {
		m_balance -= amount;
	}
	else {
		std::cout << "Insufficient balance!!\n";
	}
}

void Account::Deposit(int amount)
{
	m_balance += amount;
}

float Account::GetInterestRate() const
{
	return 0.0f;
}
