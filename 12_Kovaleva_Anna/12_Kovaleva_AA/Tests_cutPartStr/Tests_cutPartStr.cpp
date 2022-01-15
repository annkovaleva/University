#include "pch.h"
#include "CppUnitTest.h"
#include "..\12_Kovaleva_AA\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestscutPartStr
{
	TEST_CLASS(TestscutPartStr)
	{
	public:
		
		TEST_METHOD(spaces_before_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "   int summa(int a, int b);";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = " ";

		    char truePartStr[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);";
			cutPartStr(str, partStr,finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(spaces_after_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);   ";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = " ";

			char truePartStr[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(spaces_after_and_before_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "   int summa(int a, int b);   ";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = " ";

			char truePartStr[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(random_chars_before_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "..//,,  int summa(int a, int b);";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = " ,./";

			char truePartStr[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(random_chars_after_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);//,,..  ";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = " ";

			char truePartStr[MAX_NUMBER_SYMBOLS] = "int summa(int a, int b);";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(one_char)
		{
			char str[MAX_NUMBER_SYMBOLS] = "a;";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = ';';
			char startStr[MAX_NUMBER_SYMBOLS] = "a";

			char truePartStr[MAX_NUMBER_SYMBOLS] = ";";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}

		TEST_METHOD(finish_empty_str)
		{
			char str[MAX_NUMBER_SYMBOLS] = "a;";
			char partStr[MAX_NUMBER_SYMBOLS];
			char finishSymbol = 'a';
			char startStr[MAX_NUMBER_SYMBOLS] = "a";

			char truePartStr[MAX_NUMBER_SYMBOLS] = "";
			cutPartStr(str, partStr, finishSymbol, startStr);

			Assert::AreEqual(partStr, truePartStr);
		}
	};
}
