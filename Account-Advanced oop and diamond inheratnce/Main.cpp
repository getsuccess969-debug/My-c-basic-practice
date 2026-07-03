#include <iostream>
#include "Stream.h"
/*#include "Account.h"
#include "savings.h";
#include "Transaction.h"
#include "Checking.h"*/
int main() {
	/*Account acc("bob", 1000);
	{
		using namespace std;
		cout << "Account name:" << acc.GetName() << "\n";
		cout << "Initial balance:" << acc.GetBalance()<<"\n";
		cout << "Enter withdrawal money:";
		int m;
		cin >> m;
		acc.Withdraw(m);
		cout << "Final balance:" << acc.GetBalance() << "\n";
	}
	Savings s("Aarush", 100000, 10);
	std::cout << "Enter no of years:";
	int y;
	std::cin >> y;
	std::cout << "Account name:" << s.GetName() << "\nAccno:"<<s.GetAccno()<<"\n";
	std::cout << "Intial Balance:" << s.GetBalance()<<"\n";
	std::cout << "Interest rate:" << s.GetInterestRate()<<"%\n";
	for (int i = 1;i <= y;i++) {
		s.AccumulateInterest();
	}
	std::cout << "Amount after " << y << " years is:" << s.GetBalance() << "\n";
	*/
	/*Savings s("aarush", 1000, 2);
	Transact(&s);*/
	/*Savings ch("Arus", 1000, 100);
	Account* a = &ch;
	
	std::cout << "Min balance:" << (static_cast<Checking*>(a))->GetMinBalance()<< "\n";//downcasted account pointer
	*/
	ioStream io("Bobbby", 10, 11);
	io.Getfilename();
}
