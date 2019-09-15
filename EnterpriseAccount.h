#pragma once
#include <string>
#include "Account.h"
#include "AccountId.h"

class EnterpriseAccount :
	public Account
{
	std::string m_yTunnus;
	std::string m_name;

public:
	EnterpriseAccount(std::string yTunnus, std::string name, int id);
	std::string GetDetails();
	AccountId GetId();
	double GetBalance();
};

