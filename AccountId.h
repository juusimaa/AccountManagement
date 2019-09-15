#pragma once
#include <string>

class AccountId
{
	int m_id;

public:
	std::string Date;

	AccountId();

	AccountId(int id);

	int GetId();

	bool operator==(const AccountId& other) const;
};

