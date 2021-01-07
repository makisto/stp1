#include "pch.h"
#include "../TPoly.h"
#include "../TPoly.cpp"
#include "../TMember.h"
#include "../TMember.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TMemberUnitTests
{
	TEST_CLASS(TMemberUnitTests)
	{
		public:
		
			TEST_METHOD(TMember_constructor_tests)
			{
				TMember actual(0, 2);
				string expected = "0";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = TMember(-3, 2);
				expected = "-3*x^2";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = TMember(-3, -2);
				expected = "-3*x^-2";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = TMember(3, -2);
				expected = "3*x^-2";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = TMember();
				expected = "0";
				Assert::AreEqual(expected, actual.get_tmember_as_string());
			}
			TEST_METHOD(TMember_get_coeff_tests)
			{
				TMember actual(0, 2);
				int expected = 0;
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(-3, 2);
				expected = -3;
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(-3, -2);
				expected = -3;
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(3, -2);
				expected = 3;
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember();
				expected = 0;
				Assert::AreEqual(expected, actual.get_coeff());
			}
			TEST_METHOD(TMember_get_degree_tests)
			{
				TMember actual(0, 2);
				int expected = 2;
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(-3, 2);
				expected = 2;
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(-3, -2);
				expected = -2;
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(3, -2);
				expected = -2;
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember();
				expected = 0;
				Assert::AreEqual(expected, actual.get_degree());
			}
			TEST_METHOD(TMember_set_coeff_tests)
			{
				TMember actual(0, 2);
				int expected = 2;
				actual.set_coeff(expected);
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(-3, 2);
				expected = -2;
				actual.set_coeff(expected);
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(-3, -2);
				expected = -3;
				actual.set_coeff(expected);
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember(3, -2);
				expected = 0;
				actual.set_coeff(expected);
				Assert::AreEqual(expected, actual.get_coeff());

				actual = TMember();
				expected = -5;
				actual.set_coeff(expected);
				Assert::AreEqual(expected, actual.get_coeff());
			}
			TEST_METHOD(TMember_set_degree_tests)
			{
				TMember actual(0, 2);
				int expected = 5;
				actual.set_degree(expected);
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(-3, 2);
				expected = -2;
				actual.set_degree(expected);
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(-3, -2);
				expected = 2;
				actual.set_degree(expected);
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember(3, -2);
				expected = 0;
				actual.set_degree(expected);
				Assert::AreEqual(expected, actual.get_degree());

				actual = TMember();
				expected = -5;
				actual.set_degree(expected);
				Assert::AreEqual(expected, actual.get_degree());
			}
			TEST_METHOD(TMember_equals_tests)
			{
				TMember m(5, 3);
				TMember m2(5, 3);
				TMember m3(1, 2);

				bool expected = true;
				bool actual = (m == m2);
				Assert::AreEqual(expected, actual);

				expected = false;
				actual = (m == m3);
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(TMember_diff_tests)
			{
				TMember m(0, 2);
				TMember m1(-3, 2);
				TMember m2(-3, -2);
				TMember m3(3, -2);
				TMember m4(2, 0);

				TMember actual = m.diff();
				string expected = "0";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = m1.diff();
				expected = "-6*x^1";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = m2.diff();
				expected = "6*x^-3";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = m3.diff();
				expected = "-6*x^-3";
				Assert::AreEqual(expected, actual.get_tmember_as_string());

				actual = m4.diff();
				expected = "0";
				Assert::AreEqual(expected, actual.get_tmember_as_string());
			}
			TEST_METHOD(TMember_count_tests)
			{
				TMember actual(5, 5);

				double expected = 5;
				Assert::AreEqual(expected, actual.count_poly(1));

				expected = 160;
				Assert::AreEqual(expected, actual.count_poly(2));

				expected = 0;
				Assert::AreEqual(expected, actual.count_poly(0));

				expected = -5;
				Assert::AreEqual(expected, actual.count_poly(-1));

				expected = -15625;
				Assert::AreEqual(expected, actual.count_poly(-5));
			}
	};
}
