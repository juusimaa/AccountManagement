#pragma once
#include<string>

class Account
{
protected:
	double m_balance = 0.0;

public:
	virtual double GetBalance() = 0;
	virtual std::string GetDetails() = 0;
	void Deposit(double amount);
	void Withdraw(double amount);
};

