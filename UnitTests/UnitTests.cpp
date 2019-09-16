#include "pch.h"
#include "CppUnitTest.h"
#include "../PersonalAccount.h"
#include "../AccountId.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccountManagementUnitTests
{
	TEST_CLASS(AccountIdTests)
	{
	public:

		TEST_METHOD(OperatorEqual_TwoAccountIdsWithSameId_ShouldBeEqual)
		{
			AccountId id1(0);
			AccountId id2(0);
			Assert::IsTrue(id1 == id2);
		}
	};

	TEST_CLASS(AccountTests)
	{
		// Generate random integet between [low, high]. See http://www.stroustrup.com/C++11FAQ.html#std-random
		// for details.
		int rand_int(int low, int high)
		{
			static std::default_random_engine re{};
			using Dist = std::uniform_int_distribution<int>;
			static Dist uid{};
			return uid(re, Dist::param_type{ low,high });
		}

	public:
		
		TEST_METHOD(Deposit_DepositAmount_BalanceIsCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			double randomBalance = rand_int(1, 5000);
			test.Deposit(randomBalance);
			Assert::AreEqual(randomBalance, test.GetBalance());
		}

		TEST_METHOD(Deposit_DepositInvalidAmount_BalanceIsZero)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			double randomBalance = rand_int(1, 5000);
			test.Deposit(0 - randomBalance);
			Assert::AreEqual(0.0, test.GetBalance());
		}

		TEST_METHOD(Whitdraw_WithdrawAmount_BalanceCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			double randomBalance = rand_int(100, 5000);
			double randowWithdraw = rand_int(1, 50);
			test.Deposit(randomBalance);
			test.Withdraw(randowWithdraw);
			Assert::AreEqual(randomBalance - randowWithdraw, test.GetBalance());
		}

		TEST_METHOD(Whitdraw_WithdrawInvalidAmount_BalanceCorrect)
		{
			PersonalAccount test("Teppo", "Testaaja", 1);
			double randomBalance = rand_int(1, 500);
			double randomWithdraw = rand_int(600, 1000);
			test.Deposit(randomBalance);
			test.Withdraw(randomWithdraw);
			Assert::AreEqual(0.0, test.GetBalance());
		}
	};
}
