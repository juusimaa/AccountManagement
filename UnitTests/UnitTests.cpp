#include "pch.h"
#include "CppUnitTest.h"
#include "../PersonalAccount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccountManagementUnitTests
{
	TEST_CLASS(AccountTests)
	{
	public:
		
		TEST_METHOD(Deposit_DepositAmount_BalanceIsCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			test.Deposit(100);
			Assert::AreEqual(100.0, test.GetBalance());
		}

		TEST_METHOD(Deposit_DepositInvalidAmount_BalanceIsZero)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			test.Deposit(-100);
			Assert::AreEqual(0.0, test.GetBalance());
		}

		TEST_METHOD(Whitdraw_WithdrawAmount_BalanceCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			test.Deposit(100);
			test.Withdraw(50);
			Assert::AreEqual(50.0, test.GetBalance());
		}

		TEST_METHOD(Whitdraw_WithdrawInvalidAmount_BalanceCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			test.Deposit(100);
			test.Withdraw(500);
			Assert::AreEqual(0.0, test.GetBalance());
		}
	};
}
