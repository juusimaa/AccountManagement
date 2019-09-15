#include "PersonalAccount.h"
#include <string>

PersonalAccount::PersonalAccount(std::string firstName, std::string lastName)
{
	m_firstName = firstName;
	m_lastName = lastName;
}

std::string PersonalAccount::GetDetails()
{
	return "Firstname: " + m_firstName + ", lastname: " + m_lastName + ", balance: " + std::to_string(m_balance);
}

double PersonalAccount::GetBalance()
{
	return m_balance;
}
