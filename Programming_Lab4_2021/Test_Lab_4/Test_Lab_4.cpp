#include "pch.h"
#include "CppUnitTest.h"
#include "..\KovalevaAnnaLab4\Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLab4
{
	TEST_CLASS(TestLab4)
	{
	public:

		//Тесты к функции OrderArrInAscending

		TEST_METHOD(type_test)
		{
			int vector[10] = { 7, 23, 1, 8, 4 };
			int lengtn = 5;
			int trueVector[10] = { 1, 4, 7, 8, 23 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++) 
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		TEST_METHOD(one_element)
		{
			int vector [10] = { 1 };
			int lengtn = 1;
			int trueVector [10] = { 1 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		TEST_METHOD(even_number_of_numbers)
		{
			int vector[10] = { 7, 23, 1, 8 };
			int lengtn = 4;
			int trueVector[10] = { 1, 7, 8, 23 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}
		TEST_METHOD(has_negative_numbers)
		{
			int vector[10] = { 7, -4, 1, 23, -23 };
			int lengtn = 5;
			int trueVector[10] = { -23, -4, 1, 7, 23 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		TEST_METHOD(has_zero)
		{
			int vector[10] = { 7, 23, 0, 8, 4 };
			int lengtn = 5;
			int trueVector[10] = { 0, 4, 7, 8, 23 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		TEST_METHOD(has_the_same_numbers)
		{
			int vector[10] = { 7, 23, 1, 1, 1 };
			int lengtn = 5;
			int trueVector[10] = { 1, 1, 1, 7, 23 };
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		TEST_METHOD(zero_vector)
		{
			int vector[10] = {};
			int lengtn = 0;
			int trueVector[10] = {};
			OrderArrInAscending(vector, lengtn);
			for (int i = 0; i < lengtn; i++)
			{
				Assert::AreEqual(vector[i], trueVector[i]);
			}
		}

		//Тесты к функции CombineOrderedVectors

		TEST_METHOD(typeTest)
		{
			int vectorA[10] = { 3, 4, 6 };
			int vectorB[10] = { 1, 7 };
			int lengthA = 3;
			int lengthB = 2;
			int mergedVector[10];
			int trueVector[10] = { 1, 3, 4, 6, 7 };
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}

		TEST_METHOD(vectorsWithOneNumber)
		{
			int vectorA [10] = { 1 };
			int vectorB [10] = { 2 };
			int lengthA = 1;
			int lengthB = 1;
			int mergedVector[10];
			int trueVector[10] = { 1, 2 };
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}

		TEST_METHOD(hasNegativeNumbers)
		{
			int vectorA[10] = { 1, 4, 6 };
			int vectorB[10] = { -1, 7 };
			int lengthA = 3;
			int lengthB = 2;
			int mergedVector[10];
			int trueVector[10] = { -1, 1, 4, 6, 7 };
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}

		TEST_METHOD(hasTheSameNumbers)
		{
			int vectorA[10] = { 1, 4, 6 };
			int vectorB[10] = { 1, 4 };
			int lengthA = 3;
			int lengthB = 2;
			int mergedVector[10];
			int trueVector[10] = { 1, 1, 4, 4, 6 };
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}

		TEST_METHOD(hasZero)
		{
			int vectorA[10] = { 0, 4, 6 };
			int vectorB[10] = { 1, 7 };
			int lengthA = 3;
			int lengthB = 2;
			int mergedVector[10];
			int trueVector[10] = { 0, 1, 4, 6, 7 };
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}

		TEST_METHOD(zeroVectors)
		{
			int vectorA[10] = {};
			int vectorB[10] = {};
			int lengthA = 0;
			int lengthB = 0;
			int mergedVector[10];
			int trueVector[10] = {};
			int length = CombineOrderedVectors(vectorA, lengthA, vectorB, lengthB, mergedVector);
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(mergedVector[i], trueVector[i]);
			}
		}
	};
}
