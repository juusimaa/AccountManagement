#pragma once
#include "Account.h"

class EnterpriseAccount :
	public Account
{
public:
	EnterpriseAccount();
	double GetBalance();
};

