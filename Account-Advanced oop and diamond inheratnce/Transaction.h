#pragma once
#include <iostream>
#include "Account.h"
void Transact(Account* p) {
	std::cout << "inital_balance:" << p->GetBalance() << "\n";
	p->Withdraw(100);
	p->Deposit(200);
	p->AccumulateInterest();
	std::cout << "Interest rate:" << p->GetInterestRate() << "%\n";
	std::cout << "final amount:" << p->GetBalance() << "\n";
}