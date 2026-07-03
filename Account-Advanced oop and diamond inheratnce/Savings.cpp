#include "Savings.h"
#include <iostream>
Savings::Savings(std::string name, float balance, float rate):Account(name,balance),m_rate(rate)
{
	std::cout << "Savings()\n";
}

Savings::~Savings()
{
	std::cout << "~Savings()\n";
}

float Savings::GetInterestRate()const
{
	return m_rate;
}

void Savings::AccumulateInterest(){
	m_balance += (m_balance * 0.01*m_rate);
}
