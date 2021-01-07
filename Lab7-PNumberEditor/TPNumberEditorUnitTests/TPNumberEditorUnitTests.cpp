#include "pch.h"
#include "CppUnitTest.h"
#include "../TPNumberEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPNumberEditorUnitTests
{
	TEST_CLASS(TPNumberEditorUnitTests)
	{
		public:
			TEST_METHOD(is_zero_test_0_true)
			{
				TPNumberEditor a("0", 10, 1);

				bool expected = true;
				bool actual = a.is_zero();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(is_zero_test_0_01__false)
			{
				TPNumberEditor a("0.01", 10, 1);

				bool expected = false;
				bool actual = a.is_zero();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_sign_test_5__5)
			{
				TPNumberEditor a("5", 10, 1);

				a.add_sign();

				string expected = "-5";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}

			TEST_METHOD(add_sign_test__5_5)
			{
				TPNumberEditor a("-5", 10, 1);

				a.add_sign();

				string expected = "5";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_p_number_test_0_5)
			{
				TPNumberEditor a("0", 10, 1);

				a.add_p_number(5);

				string expected = "5";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_p_number_test_0_0__0_5)
			{
				TPNumberEditor a("0.0", 10, 1);

				a.add_p_number(5);

				string expected = "0.5";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_p_number_test_0_0__0_00)
			{
				TPNumberEditor a("0.0", 10, 1);

				a.add_p_number(0);

				string expected = "0.00";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_p_number_test_115_5__115_54)
			{
				TPNumberEditor a("115.5", 10, 1);

				a.add_p_number(4);

				string expected = "115.54";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_zero_test_5_50)
			{
				TPNumberEditor a("5", 10, 1);

				a.add_zero();

				string expected = "50";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_zero_test_0_0)
			{
				TPNumberEditor a("0", 10, 1);

				a.add_zero();

				string expected = "0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(delete_symbol_test_50_5)
			{
				TPNumberEditor a("50", 10, 1);

				a.delete_symbol();

				string expected = "5";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(delete_symbol_test_50_4_50)
			{
				TPNumberEditor a("50.4", 10, 1);

				a.delete_symbol();

				string expected = "50";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(delete_symbol_test_0_0__0)
			{
				TPNumberEditor a("0.0", 10, 1);

				a.delete_symbol();

				string expected = "0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(delete_symbol_test_0_0)
			{
				TPNumberEditor a("0", 10, 1);

				a.delete_symbol();

				string expected = "0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(clear_test_0_00001_0)
			{
				TPNumberEditor a("0.00001", 10, 1);

				a.clear();

				string expected = "0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(add_delimiter_test_50_50_0)
			{
				TPNumberEditor a("50", 10, 1);

				a.add_delimiter();

				string expected = "50.0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(write_number_test_12345_12345)
			{
				TPNumberEditor a("0", 10, 1);

				a.write_number("12345");

				string expected = "12345";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(write_number_test_12345_0)
			{
				TPNumberEditor a("0", 4, 1);

				a.write_number("12345");

				string expected = "0";
				string actual = a.read_number();

				Assert::AreEqual(expected, actual);
			}
	};
}
