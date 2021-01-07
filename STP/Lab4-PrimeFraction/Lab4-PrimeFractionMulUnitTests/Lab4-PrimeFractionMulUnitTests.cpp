#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionMulUnitTests
{
	TEST_CLASS(Lab4PrimeFractionMulUnitTests)
	{
	public:
		
	public:
		TEST_METHOD(TFrac_mul_2_5_4__5_expected__8_25)
		{
			TFrac expected(8, 25);
			TFrac operand1(2, 5);
			TFrac operand2(-4, -5);
			TFrac actual = operand1.mul(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_4_5__1_5_expected__4_25)
		{
			TFrac expected(-4, 25);
			TFrac operand1(4, 5);
			TFrac operand2(-1, 5);
			TFrac actual = operand1.mul(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_15_5_5_5_expected_3_1)
		{
			TFrac expected(3, 1);
			TFrac operand1(15, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.mul(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_5_5_5_5_expected_1_1)
		{
			TFrac expected(1, 1);
			TFrac operand1(5, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.mul(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_47_15_94_15_expected_4418_225)
		{
			TFrac expected(4418, 225);
			TFrac operand1(47, 15);
			TFrac operand2(94, 15);
			TFrac actual = operand1.mul(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
