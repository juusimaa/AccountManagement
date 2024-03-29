#include "Account.h"

Account::Account()
{
}

void Account::Deposit(double amount)
{
	if (amount > 0)
	{
		m_balance += amount;
	}
}

void Account::Withdraw(double amount)
{
	if (amount > 0 && amount <= m_balance)
	{
		m_balance -= amount;
	}

	if (amount > m_balance)
	{
		m_balance = 0.0;
	}
}
