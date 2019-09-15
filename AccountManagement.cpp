// AccountManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Account.h"
#include "PersonalAccount.h"
#include "EnterpriseAccount.h"

using namespace std;

PersonalAccount* m_personalAccount = nullptr;
EnterpriseAccount* m_enterpriseAccount = nullptr;

void ManagePersonalMenu()
{
	while (true)
	{
		int selection;

		cout << endl << "      Personel Account Menu   " << endl;
		cout << endl << "----------------------------" << endl;
		cout << "1. Create new account" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Whitdraw" << endl;
		cout << "4. Get account details" << endl;
		cout << "0. Back" << endl;

		cin >> selection;

		string firstName = "", lastName = "";

		switch (selection)
		{
		case 1:
			
			cout << "Firstname: ";
			cin >> firstName;
			cout << endl << "Lastname: ";
			cin >> lastName;

			m_personalAccount = new PersonalAccount(firstName, lastName);
			break;

		case 4:
			cout << m_personalAccount->GetDetails() << endl;
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
		cout << "0. Exit" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
			ManagePersonalMenu();
			break;
		case 0:
			delete m_personalAccount;
			delete m_enterpriseAccount;
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



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
