#include "pch.h"
#include "CppUnitTest.h"
#include "..\12_Kovaleva_AA\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsgeneratePrototip
{
	TEST_CLASS(TestsgeneratePrototip)
	{
	public:

		TEST_METHOD(no_prototip)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 12;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(have_prototip)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa (int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int summa (int, int);",
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa (int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(prototip_with_comment_without_spaces)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa (int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int summa (int, int);//прототип",
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(prototip_with_comment_with_spaces)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa (int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int summa (int, int);   //прототип",
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(header_with_comment_without_spaces)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)//заголовок",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 12;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(header_with_comment_with_spaces)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int one_number, int two_number);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)   //заголовок",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 12;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(no_function)
		{
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summaAB (a, b);",
				"return 0;",
				"}",
				"int summaAB(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}"
			};
			int numberSymbols = 12;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(0, exemple);
		}

		TEST_METHOD(prototip_located_in_end)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}",
				"int summa(int, int);"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(spaces_before_prototip)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}",
				"            int summa(int, int);"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(tab_before_prototip)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}",
				"\t\tint summa(int, int);"
			};
			int numberSymbols = 13;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(max_size_rows)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int main()",
				"{",
				"int a = 1;",
				"int b = 2;",
				"int c = 3;",
				"int d = 4;",
				"int e = 5;",
				"int j = 6;",
				"int z = 7;",
				"int i = 8;",
				"int k = 9;",
				"int sum = summa (a, b);",
				"return 0;",
				"}",
				"int summa(int one_number, int two_number)",
				"{",
				"int sum = one_number + two_number;",
				"return sum;",
				"}",
				"int summa(int, int);"
			};
			int numberSymbols = 20;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}

		TEST_METHOD(min_size_rows)
		{
			char prototipForTest[MAX_NUMBER_SYMBOLS] = "int summa(int, int);";
			char nameFunction[10] = "summa";
			char textFunction[MAX_NUMBER_ROWS][MAX_NUMBER_SYMBOLS] =
			{
				"int summa(int, int);"
			};
			int numberSymbols = 1;
			char strPrototip[MAX_NUMBER_SYMBOLS];
			int exemple = generatePrototip(textFunction, numberSymbols, nameFunction, strPrototip);
			Assert::AreEqual(prototipForTest, strPrototip);
		}
	};
}
