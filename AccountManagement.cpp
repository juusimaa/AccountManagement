// AccountManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

#include "Account.h"
#include "PersonalAccount.h"
#include "EnterpriseAccount.h"
#include "AccountId.h"

using namespace std;

std::list<Account*> m_accountList;
int m_id = 0;

std::string GetAccountDetails(AccountId id)
{
	for (std::list<Account*>::iterator it = m_accountList.begin(); it != m_accountList.end(); ++it)
	{
		AccountId currentId = (*it)->GetId();
		if (currentId == id)
		{
			return (*it)->GetDetails();
		}
	}

	return "Account not found!";
}

void ManagePersonalMenu()
{
	while (true)
	{
		int selection;

		cout << endl << "      Personel Account Menu   " << endl;
		cout << endl << "----------------------------" << endl;
		cout << "1. Create new account" << endl;
		cout << "0. Back" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			string firstName = "", lastName = "";
			cout << "Firstname: ";
			cin >> firstName;
			cout << endl << "Lastname: ";
			cin >> lastName;
			m_accountList.push_back(new PersonalAccount(firstName, lastName, m_id++));
		}
		break;

		case 0:
			return;

		default:
			break;
		}
	}
}

void ManageEnterpriseMenu()
{
	while (true)
	{
		int selection;

		cout << endl << "      Enterprise Account Menu   " << endl;
		cout << endl << "----------------------------" << endl;
		cout << "1. Create new account" << endl;
		cout << "0. Back" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			string yTunnus = "", name = "";
			cout << "y-tunnus: ";
			cin >> yTunnus;
			cout << endl << "Company name: ";
			cin >> name;
			m_accountList.push_back(new EnterpriseAccount(yTunnus, name, m_id++));
		}
		break;

		case 0:
			return;

		default:
			break;
		}
	}
}

void MainMenu()
{
	while (true)
	{
		int selection;

		cout << endl << "      Main Menu   " << endl;
		cout << endl << "----------------------------" << endl;
		cout << "1. Manage personal account" << endl;
		cout << "2. Manage enterprise account" << endl;
		cout << "3. List accounts" << endl;
		cout << "4. Find account" << endl;
		cout << "0. Exit" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
			ManagePersonalMenu();
			break;

		case 2:
			ManageEnterpriseMenu();
			break;

		case 3:
			cout << "\nAccounts" << endl;
			cout << "------------------------------------------------" << endl;
			std::for_each(m_accountList.begin(), m_accountList.end(), [](Account* account)
				{
					cout << account->GetDetails() << endl;
				});
			break;

		case 4:
			{
			int id;
			cout << "Give account id: ";
			cin >> id;
			cout << GetAccountDetails(AccountId(id)) << endl;
			}
			break;

		case 0:
			while (!m_accountList.empty())
			{
				delete m_accountList.front();
				m_accountList.pop_front();
			}
			exit(0);

		default:
			break;
		}
	}
}

int main()
{
	MainMenu();
}
