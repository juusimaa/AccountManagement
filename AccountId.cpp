#include "AccountId.h"

AccountId::AccountId()
{
}

AccountId::AccountId(int id)
{
	m_id = id;
}

int AccountId::GetId()
{
	return m_id;
}

bool AccountId::operator==(const AccountId& other) const
{
	return this->m_id == other.m_id;
}
