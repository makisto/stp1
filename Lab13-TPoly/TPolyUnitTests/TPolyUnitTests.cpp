#include "pch.h"
#include "../TPoly.h"
#include "../TPoly.cpp"
#include "../TMember.h"
#include "../TMember.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPolyUnitTests
{
	TEST_CLASS(TPolyUnitTests)
	{
	public:
		TEST_METHOD(TPoly_constructor_tests)
		{
			TPoly actual(3, 4);
			string expected = "3*x^4";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = TPoly(-3, 4);
			expected = "-3*x^4";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = TPoly(-3, -4);
			expected = "-3*x^-4";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = TPoly(3, -4);
			expected = "3*x^-4";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = TPoly(5, 0);
			expected = "5";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = TPoly();
			expected = "";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_get_max_degree_tests)
		{
			TPoly actual(5, 3);

			int expected = 3;
			Assert::AreEqual(expected, actual.get_max_degree());

			actual = TPoly(5, 0);
			expected = 0;
			Assert::AreEqual(expected, actual.get_max_degree());

			actual = TPoly(5, -3);
			expected = -3;
			Assert::AreEqual(expected, actual.get_max_degree());
		}
		TEST_METHOD(TPoly_get_coeff_tests)
		{
			TPoly actual(5, 3);

			int expected = 5;
			Assert::AreEqual(expected, actual.get_coeff(3));

			actual = TPoly(5, 0);
			expected = 5;
			Assert::AreEqual(expected, actual.get_coeff(0));

			actual = TPoly(5, -3);
			expected = 5;
			Assert::AreEqual(expected, actual.get_coeff(-3));

			actual = TPoly(5, 4);
			expected = 0;
			Assert::AreEqual(expected, actual.get_coeff(2));
		}
		TEST_METHOD(TPoly_clear_test)
		{
			TPoly actual(5, 3);

			actual.clear();
			string expected = "";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_add_tests)
		{
			TPoly p(5, 3);
			TPoly p1(4, 2);
			TPoly p2(3, 3);
			TPoly p3(2, 1);
			TPoly p4(2, 0);

			TPoly actual = p + p1;
			string expected = "5*x^3+4*x^2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p + p2;
			expected = "8*x^3";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p + p3;
			expected = "5*x^3+2*x^1";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p + p4;
			expected = "5*x^3+2";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_sub_tests)
		{
			TPoly p(5, 3);
			TPoly p1(4, 2);
			TPoly p2(3, 3);
			TPoly p3(2, 1);
			TPoly p4(2, 0);

			TPoly actual = p - p1;
			string expected = "5*x^3-4*x^2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p - p2;
			expected = "2*x^3";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p - p3;
			expected = "5*x^3-2*x^1";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p - p4;
			expected = "5*x^3-2";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_miuns_tests)
		{
			TPoly p(5, 3);
			TPoly p1(4, 2);
			TPoly p2(3, 3);
			TPoly p3(2, 1);
			TPoly p4(2, 0);

			TPoly actual = -p;
			string expected = "-5*x^3";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = -p1;
			expected = "-4*x^2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = -p2;
			expected = "-3*x^3";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = -p3;
			expected = "-2*x^1";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = -p4;
			expected = "-2";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_mul_tests)
		{
			TPoly p(5, 3);
			TPoly p1(4, 2);
			TPoly p2(3, 3);
			TPoly p3(2, 1);
			TPoly p4(2, 0);

			TPoly actual = p * p1;
			string expected = "20*x^5";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p * p2;
			expected = "15*x^6";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p * p3;
			expected = "10*x^4";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p * p4;
			expected = "10*x^3";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_equals_tests)
		{
			TPoly p(5, 3);
			TPoly p2(5, 3);
			TPoly p3(1, 2);

			bool expected = true;
			bool actual = (p == p2);
			Assert::AreEqual(expected, actual);

			expected = false;
			actual = (p == p3);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TPoly_diff_tests)
		{
			TPoly p(5, 3);
			TPoly p1(4, 2);
			TPoly p2(3, 3);
			TPoly p3(2, 1);
			TPoly p4(2, 0);

			TPoly actual = p.diff();
			string expected = "15*x^2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p1.diff();
			expected = "8*x^1";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p2.diff();
			expected = "9*x^2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p3.diff();
			expected = "2";
			Assert::AreEqual(expected, actual.get_poly_as_string());

			actual = p4.diff();
			expected = "";
			Assert::AreEqual(expected, actual.get_poly_as_string());
		}
		TEST_METHOD(TPoly_count_tests)
		{
			TPoly actual(2, 3);

			double expected = 16;
			Assert::AreEqual(expected, actual.count_poly(2));

			expected = 54;
			Assert::AreEqual(expected, actual.count_poly(3));

			expected = 0;
			Assert::AreEqual(expected, actual.count_poly(0));

			expected = -16;
			Assert::AreEqual(expected, actual.count_poly(-2));
		}
		TEST_METHOD(TPoly_get_element_tests)
		{
			TPoly actual(2, 3);
			TPoly p2(3, 4);
			TPoly p3(4, 5);

			TMember expected = actual[0];
			Assert::AreEqual(expected.get_coeff(), actual.get_coeff(3));
			Assert::AreEqual(expected.get_degree(), actual.get_max_degree());

			actual = actual + p2;
			expected = actual[1];
			Assert::AreEqual(expected.get_coeff(), actual.get_coeff(4));
			Assert::AreEqual(expected.get_degree(), actual.get_max_degree());

			actual = actual + p3;
			expected = actual[2];
			Assert::AreEqual(expected.get_coeff(), actual.get_coeff(5));
			Assert::AreEqual(expected.get_degree(), actual.get_max_degree());
		}
	};
}
