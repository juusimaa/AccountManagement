#include "EnterpriseAccount.h"

EnterpriseAccount::EnterpriseAccount(std::string yTunnus, std::string name, int id)
{
	m_yTunnus = yTunnus;
	m_name = name;
	m_id = id;
}

std::string EnterpriseAccount::GetDetails()
{
	return std::to_string(m_id.GetId()) + "\t" + m_yTunnus + ", " + m_name + 
		"\t\t" + std::to_string(m_balance);
}

AccountId EnterpriseAccount::GetId()
{
	return m_id;
}

double EnterpriseAccount::GetBalance()
{
	return m_balance;
}
