#include "pch.h"
#include "../TPNumber.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab6PNumberUnitTests
{
	TEST_CLASS(Lab6PNumberUnitTests)
	{
	public:
		TEST_METHOD(TPNumber_add_test)
		{
			TPNumber expected(57, 8, 4);
			TPNumber operand1("25", "8", "4");
			TPNumber operand2(32, 8, 4);
			TPNumber actual = operand1.add(operand2);

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_sub_test)
		{
			TPNumber expected(-7, 8, 4);
			TPNumber operand1("25", "8", "4");
			TPNumber operand2(32, 8, 4);
			TPNumber actual = operand1.sub(operand2);

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_mul_test)
		{
			TPNumber expected(800, 8, 4);
			TPNumber operand1("25", "8", "4");
			TPNumber operand2(32, 8, 4);
			TPNumber actual = operand1.mul(operand2);

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_div_test)
		{
			TPNumber expected(0.78125, 8, 4);
			TPNumber operand1("25", "8", "4");
			TPNumber operand2(32, 8, 4);
			TPNumber actual = operand1.div(operand2);

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_reverse_test)
		{
			TPNumber expected(0.04, 8, 4);
			TPNumber operand("25", "8", "4");
			TPNumber actual = operand.reverse();

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_square_test)
		{
			TPNumber expected(625, 8, 4);
			TPNumber operand("25", "8", "4");
			TPNumber actual = operand.square();

			Assert::AreEqual(expected.get_n(), actual.get_n());
		}
		TEST_METHOD(TPNumber_get_b_test)
		{
			int expected = 8;
			TPNumber operand(25, 8, 4);
			int actual = operand.get_b();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TPNumber_get_b_as_string_test)
		{
			string expected = "8";
			TPNumber operand(25, 8, 4);
			string actual = operand.get_b_as_string();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TPNumber_get_c_test)
		{
			int expected = 4;
			TPNumber operand(25, 8, 4);
			int actual = operand.get_c();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TPNumber_get_c_string_test)
		{
			string expected = "4";
			TPNumber operand(25, 8, 4);
			string actual = operand.get_c_as_string();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TPNumber_set_b_test)
		{
			int expected = 14;
			TPNumber actual(25, 8, 4);
			actual.set_b(14);

			Assert::AreEqual(expected, actual.get_b());
		}
		TEST_METHOD(TPNumber_set_b_by_string_test)
		{
			string expected = "14";
			TPNumber actual(25, 8, 4);
			actual.set_b_by_string("14");

			Assert::AreEqual(expected, actual.get_b_as_string());
		}
		TEST_METHOD(TPNumber_set_c_test)
		{
			int expected = 14;
			TPNumber actual(25, 8, 4);
			actual.set_c(14);

			Assert::AreEqual(expected, actual.get_c());
		}
		TEST_METHOD(TPNumber_set_c_by_string_test)
		{
			string expected = "14";
			TPNumber actual(25, 8, 4);
			actual.set_c_by_string("14");

			Assert::AreEqual(expected, actual.get_c_as_string());
		}
		TEST_METHOD(TPNumber_get_n_as_string_tests)
		{
			Assert::AreEqual((string)"35.11463146", TPNumber(29.15, 8, 8).get_n_as_string());
			Assert::AreEqual((string)"1D.26666666", TPNumber(29.15, 16, 8).get_n_as_string());
			Assert::AreEqual((string)"11101.00100110", TPNumber(29.15, 2, 8).get_n_as_string());
			Assert::AreEqual((string)"29.14", TPNumber(29.15, 10, 2).get_n_as_string());
			Assert::AreEqual((string)"104.03333333", TPNumber(29.15, 5, 8).get_n_as_string());
		}
		TEST_METHOD(TPNumber_constructor_base_exception)
		{
			auto f = [this]
			{
				TPNumber(25, -5, 6);
			};
			Assert::ExpectException<TPNumber::constructor_exception>(f);

			auto f1 = [this]
			{
				TPNumber(25, 25, 6);
			};
			Assert::ExpectException<TPNumber::constructor_exception>(f1);
		}
		TEST_METHOD(TPNumber_constructor_precision_exception)
		{
			auto f = [this]
			{
				TPNumber(25, 5, -6);
			};
			Assert::ExpectException<TPNumber::constructor_exception>(f);
		}
		TEST_METHOD(TPNumber_string_constructor_base_exception)
		{
			auto f = [this]
			{
				TPNumber a("25", "-5", "6");
			};
			Assert::ExpectException<TPNumber::string_constructor_exception>(f);

			auto f1 = [this]
			{
				TPNumber a("25", "25", "6");
			};
			Assert::ExpectException<TPNumber::string_constructor_exception>(f1);
		}
		TEST_METHOD(TPNumber_string_constructor_precision_exception)
		{
			auto f = [this]
			{
				TPNumber a("25", "5", "-6");
			};
			Assert::ExpectException<TPNumber::string_constructor_exception>(f);
		}
		TEST_METHOD(TPNumber_add_base_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").add(TPNumber("25", "6", "6"));
			};
			Assert::ExpectException<TPNumber::add_exception>(f);
		}
		TEST_METHOD(TPNumber_add_precision_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").add(TPNumber("25", "5", "5"));
			};
			Assert::ExpectException<TPNumber::add_exception>(f);
		}
		TEST_METHOD(TPNumber_sub_base_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").sub(TPNumber("25", "6", "6"));
			};
			Assert::ExpectException<TPNumber::sub_exception>(f);
		}
		TEST_METHOD(TPNumber_sub_precision_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").sub(TPNumber("25", "5", "5"));
			};
			Assert::ExpectException<TPNumber::sub_exception>(f);
		}
		TEST_METHOD(TPNumber_mul_base_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").mul(TPNumber("25", "6", "6"));
			};
			Assert::ExpectException<TPNumber::mul_exception>(f);
		}
		TEST_METHOD(TPNumber_mul_precision_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").mul(TPNumber("25", "5", "5"));
			};
			Assert::ExpectException<TPNumber::mul_exception>(f);
		}
		TEST_METHOD(TPNumber_div_base_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").div(TPNumber("25", "6", "6"));
			};
			Assert::ExpectException<TPNumber::div_exception>(f);
		}
		TEST_METHOD(TPNumber_div_precision_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").div(TPNumber("25", "5", "5"));
			};
			Assert::ExpectException<TPNumber::div_exception>(f);
		}
		TEST_METHOD(TPNumber_div_division_zero_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").div(TPNumber("0", "5", "5"));
			};
			Assert::ExpectException<TPNumber::div_exception>(f);
		}
		TEST_METHOD(TPNumber_reverse_exception)
		{
			auto f = [this]
			{
				TPNumber("0", "5", "6").reverse();
			};
			Assert::ExpectException<TPNumber::reverse_exception>(f);
		}
		TEST_METHOD(TPNumber_set_b_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").set_b(766);
			};
			Assert::ExpectException<TPNumber::set_b_exception>(f);

			auto f1 = [this]
			{
				TPNumber("25", "5", "6").set_b(-9);
			};
			Assert::ExpectException<TPNumber::set_b_exception>(f1);
		}
		TEST_METHOD(TPNumber_set_b_by_string_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").set_b_by_string("766");
			};
			Assert::ExpectException<TPNumber::set_string_b_exception>(f);

			auto f1 = [this]
			{
				TPNumber("25", "5", "6").set_b_by_string("-9");
			};
			Assert::ExpectException<TPNumber::set_string_b_exception>(f1);
		}
		TEST_METHOD(TPNumber_set_c_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").set_c(-9);
			};
			Assert::ExpectException<TPNumber::set_c_exception>(f);
		}
		TEST_METHOD(TPNumber_set_c_by_string_exception)
		{
			auto f = [this]
			{
				TPNumber("25", "5", "6").set_c_by_string("-9");
			};
			Assert::ExpectException<TPNumber::set_string_c_exception>(f);
		}
	};
}
