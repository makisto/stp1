#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionSquareUnitTests
{
	TEST_CLASS(Lab4PrimeFractionSquareUnitTests)
	{
	public:
		
		TEST_METHOD(TFrac_square_2_5_expected_4_25)
		{
			TFrac expected(4, 25);
			TFrac operand(2, 5);
			TFrac actual = operand.square();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_square__2_5_expected_4_25)
		{
			TFrac expected(4, 25);
			TFrac operand(-2, 5);
			TFrac actual = operand.square();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_square_2__5_expected_4_25)
		{
			TFrac expected(4, 25);
			TFrac operand(2, -5);
			TFrac actual = operand.square();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_square__2__5_expected_4_25)
		{
			TFrac expected(4, 25);
			TFrac operand(-2, -5);
			TFrac actual = operand.square();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_square_0_5_expected_0_1)
		{
			TFrac expected(0, 1);
			TFrac operand(0, 5);
			TFrac actual = operand.square();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
