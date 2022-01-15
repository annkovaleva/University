#include "pch.h"
#include "CppUnitTest.h"
#include "..\12_Kovaleva_AA\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsfindEntryName
{
	TEST_CLASS(TestsfindEntryName)
	{
	public:
		
		TEST_METHOD(no_name)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number);";
			char nameFunction[10] = "add";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = -1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(prototip)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number);";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = 1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(header)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number)";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = 0;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(no_true_name)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summator(int one_number, int two_number);";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = -1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(use_function)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int a = summa(one_number, two_number);";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = -1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(advert_variable)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa = 0;";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = -1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(longest_prototip)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "long long int summa(int one_number, int two_number);";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = 1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(mini_prototip)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa();";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = 1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(prototip_with_modifiers)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "long summa();";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = 1;

			Assert::AreEqual(exemple, trueExemple);
		}

		TEST_METHOD(function_name_same_variable_name)
		{
			char strForTest[MAX_NUMBER_SYMBOLS] = "int summa = summa();";
			char nameFunction[10] = "summa";

			int exemple = findEntryName(strForTest, nameFunction);
			int trueExemple = -1;

			Assert::AreEqual(exemple, trueExemple);
		}
	};
}
