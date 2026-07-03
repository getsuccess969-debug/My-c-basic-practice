#pragma once
#include <string>
class Account
{
	std::string name;
	
	int m_Accno;
	static int AccnoGenerator;
protected:
	float m_balance;
public:
	Account(const  std::string &name,float balance);
	virtual ~Account();
	const std::string GetName()const;
	float GetBalance()const;
	int GetAccno();
	virtual void AccumulateInterest();
	virtual void Withdraw(int amount);
	void Deposit(int amount);
	virtual float GetInterestRate()const;

};

