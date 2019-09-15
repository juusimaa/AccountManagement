#include "Account.h"

void Account::Deposit(double amount)
{
	if (amount > 0)
	{
		m_balance += amount;
	}
}

void Account::Withdraw(double amount)
{
	if (amount > 0)
	{
		m_balance -= amount;
	}
}
