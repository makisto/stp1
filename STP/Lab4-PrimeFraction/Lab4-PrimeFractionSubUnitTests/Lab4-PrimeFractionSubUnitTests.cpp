#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionSubUnitTests
{
	TEST_CLASS(Lab4PrimeFractionSubUnitTests)
	{
	public:
		
		TEST_METHOD(TFrac_sub_2_5_4_5_expected__2_5)
		{
			TFrac expected(-2, 5);
			TFrac operand1(2, 5);
			TFrac operand2(4, 5);
			TFrac actual = operand1.sub(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_4_5__1_5_expected_1_1)
		{
			TFrac expected(1, 1);
			TFrac operand1(4, 5);
			TFrac operand2(-1, 5);
			TFrac actual = operand1.sub(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_15_5_5_5_expected_2_1)
		{
			TFrac expected(2, 1);
			TFrac operand1(15, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.sub(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_5_5_5_5_expected_0_5)
		{
			TFrac expected(0, 1);
			TFrac operand1(5, 5);
			TFrac operand2(5, 5);
			TFrac actual = operand1.sub(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_sub_47_15_94_15_expected__47_15)
		{
			TFrac expected(-47, 15);
			TFrac operand1(47, 15);
			TFrac operand2(94, 15);
			TFrac actual = operand1.sub(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
