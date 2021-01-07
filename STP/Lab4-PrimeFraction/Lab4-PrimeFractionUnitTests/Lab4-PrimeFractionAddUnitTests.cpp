#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionAddUnitTests
{
	TEST_CLASS(Lab4PrimeFractionAddUnitTests)
	{
	public:		
		TEST_METHOD(TFrac_add_3_5__5_3__expected_34_15)
		{
			TFrac expected(34, 15);
			TFrac operand1(3, 5);
			TFrac operand2(5, 3);
			TFrac actual = operand1.add(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_add_3_5__7_5__expected_2_1)
		{
			TFrac expected(2, 1);
			TFrac operand1(3, 5);
			TFrac operand2(7, 5);
			TFrac actual = operand1.add(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_add_3_5__1_2__expected_11_10)
		{
			TFrac expected(11, 10);
			TFrac operand1(3, 5);
			TFrac operand2(1, 2);
			TFrac actual = operand1.add(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_add_244_562__95_93__expected_38041_26133)
		{
			TFrac expected(38041, 26133);
			TFrac operand1(244, 562);
			TFrac operand2(95, 93);
			TFrac actual = operand1.add(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_add__2_7__8_96__expected__17_84)
		{
			TFrac expected(-17, 84);
			TFrac operand1(-2, 7);
			TFrac operand2(8, 96);
			TFrac actual = operand1.add(operand2);
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
