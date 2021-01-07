#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionEqualsUnitTests
{
	TEST_CLASS(Lab4PrimeFractionEqualsUnitTests)
	{
	public:
		TEST_METHOD(TFrac_equals_2_5_2_5_expected_true)
		{
			bool expected = true;
			TFrac operand1("2/5");
			TFrac operand2("2/5");
			bool actual = operand1.equals(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals__2_5_2__5_expected_true)
		{
			bool expected = true;
			TFrac operand1("-2/5");
			TFrac operand2("2/-5");
			bool actual = operand1.equals(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_3_5_4_5_expected_false)
		{
			bool expected = false;
			TFrac operand1("3/5");
			TFrac operand2("4/5");
			bool actual = operand1.equals(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_1_3_3_9_expected_true)
		{
			bool expected = true;
			TFrac operand1("1/3");
			TFrac operand2("3/9");
			bool actual = operand1.equals(operand2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TFrac_equals_0__67_0_99_expected_true)
		{
			bool expected = true;
			TFrac operand1("0/-67");
			TFrac operand2("0/99");
			bool actual = operand1.equals(operand2);
			Assert::AreEqual(expected, actual);
		}
	};
}
