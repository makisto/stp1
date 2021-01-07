#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionDivUnitTests
{
	TEST_CLASS(Lab4PrimeFractionDivUnitTests)
	{
	public:
		TEST_METHOD(TFrac_div_2_5_4_5_expected_1_2)
		{
			TFrac expected(1, 2);
			TFrac operand1(2, 5);
			TFrac operand2(4, 5);
			TFrac actual = operand1.div(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_div_4_5__1_5_expected__4_1)
		{
			TFrac expected(-4, 1);
			TFrac operand1(4, 5);
			TFrac operand2(-1, 5);
			TFrac actual = operand1.div(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_div_15_5_5_5_expected_3_1)
		{
			TFrac expected(3, 1);
			TFrac operand1(15, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.div(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_div_5_5_5_5_expected_1_1)
		{
			TFrac expected(1, 1);
			TFrac operand1(5, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.div(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_div_47_15_94_15_expected_1_2)
		{
			TFrac expected(1, 2);
			TFrac operand1(47, 15);
			TFrac operand2(94, 15);
			TFrac actual = operand1.div(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
