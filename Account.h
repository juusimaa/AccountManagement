#pragma once
#include<string>
#include "AccountId.h"

// Account class
class Account
{
protected:
	double m_balance = 0.0;
	AccountId m_id;

public:
	Account();

	// Get account balance
	virtual double GetBalance() = 0;

	virtual AccountId GetId() = 0;
	
	// Get account details
	virtual std::string GetDetails() = 0;

	// Deposit amount to account
	void Deposit(double amount);

	// Withdraw amount from account
	void Withdraw(double amount);	
};

