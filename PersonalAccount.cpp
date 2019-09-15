#include "PersonalAccount.h"
#include <string>

PersonalAccount::PersonalAccount(std::string firstName, std::string lastName, int id)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_id = AccountId(id);
}

std::string PersonalAccount::GetDetails()
{
	return std::to_string(m_id.GetId()) + "\t" + m_firstName + ", " +
		m_lastName + "\t\t" + std::to_string(m_balance);
}

AccountId PersonalAccount::GetId()
{
	return m_id;
}

double PersonalAccount::GetBalance()
{
	return m_balance;
}
