#pragma once
#include<string>
#include "Account.h"

class PersonalAccount :
	public Account
{
	std::string m_firstName;
	std::string m_lastName;

public:
	PersonalAccount(std::string firstName, std::string lastName);
	std::string GetDetails();
	double GetBalance();
};

