#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionBiggerUnitTests
{
	TEST_CLASS(Lab4PrimeFractionBiggerUnitTests)
	{
	public:
		TEST_METHOD(TFrac_equals_2_5_2_5_expected_false)
		{
			bool expected = false;
			TFrac operand1("2/5");
			TFrac operand2("2/5");
			bool actual = operand1.bigger(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals__2_5_2__5_expected_false)
		{
			bool expected = false;
			TFrac operand1("-2/5");
			TFrac operand2("2/-5");
			bool actual = operand1.bigger(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_4_5_3_5_expected_true)
		{
			bool expected = true;
			TFrac operand1("4/5");
			TFrac operand2("3/5");
			bool actual = operand1.bigger(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_3_9_3_8_expected_false)
		{
			bool expected = false;
			TFrac operand1("3/9");
			TFrac operand2("3/8");
			bool actual = operand1.bigger(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_0_1_0_99_expected_false)
		{
			bool expected = false;
			TFrac operand1("0/1");
			TFrac operand2("0/99");
			bool actual = operand1.bigger(operand2);
			Assert::AreEqual(expected, actual);
		}
	};
}
