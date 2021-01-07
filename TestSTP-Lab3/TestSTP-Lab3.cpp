#include "pch.h"
#include "CppUnitTest.h"
#include "../STP-Lab3/MyClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSTPLab3
{
	TEST_CLASS(TestSTPLab3)
	{
	public:
		
		TEST_METHOD(max_of_three_numbers_3_5_7_expected_7)
		{
			int x = 3;
			int y = 5;
			int z = 7;
			int expected = 7;
			int actual = MyClass::max_of_three_numbers(x, y, z);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(max_of_three_numbers_5_7_3_expected_7)
		{
			int x = 5;
			int y = 7;
			int z = 3;
			int expected = 7;
			int actual = MyClass::max_of_three_numbers(x, y, z);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(max_of_three_numbers_7_3_5_expected_7)
		{
			int x = 7;
			int y = 3;
			int z = 5;
			int expected = 7;
			int actual = MyClass::max_of_three_numbers(x, y, z);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(max_index_12345_expected_42)
		{
			int expected = 42;
			int actual = MyClass::max_index(12345);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(max_index_0_expected_0)
		{
			int expected = 0;
			int actual = MyClass::max_index(0);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(min_index_62432_expected_2)
		{
			int expected = 2;
			int actual = MyClass::min_index(62432);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(min_index_1110101010_expected_0)
		{
			int expected = 0;
			int actual = MyClass::max_index(1110101010);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(min_index_0_expected_0)
		{
			int expected = 0;
			int actual = MyClass::max_index(0);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(diag_5_5_expected_24)
		{
			int n = 5;
			int m = 5;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = i + j;
				}
			}
			int expected = 24;
			int actual = MyClass::diag(a, n, m);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(diag_0_0_expected_0)
		{
			int n = 0;
			int m = 0;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = i + j;
				}
			}
			int expected = 0;
			int actual = MyClass::diag(a, n, m);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(diag_5_0_expected_0)
		{
			int n = 5;
			int m = 0;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = i + j;
				}
			}
			int expected = 0;
			int actual = MyClass::diag(a, n, m);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(diag_0_5_expected_0)
		{
			int n = 0;
			int m = 5;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = i + j;
				}
			}
			int expected = 0;
			int actual = MyClass::diag(a, n, m);
			Assert::AreEqual(expected, actual);
		}
	};
}
