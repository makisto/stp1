#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionMinusUnitTests
{
	TEST_CLASS(Lab4PrimeFractionMinusUnitTests)
	{
	public:		
		TEST_METHOD(TFrac_minus_2_5_expected__2_5)
		{
			TFrac expected(-2, 5);
			TFrac operand(2, 5);
			TFrac actual = operand.minus();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_minus__2_5_expected_2_5)
		{
			TFrac expected(2, 5);
			TFrac operand(-2, 5);
			TFrac actual = operand.minus();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_minus_2__5_expected_2_5)
		{
			TFrac expected(2, 5);
			TFrac operand(2, -5);
			TFrac actual = operand.minus();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_minus__2__5_expected__2_5)
		{
			TFrac expected(-2, 5);
			TFrac operand(-2, -5);
			TFrac actual = operand.minus();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_minus_string__2__5_expected__2_5)
		{
			TFrac expected(-2, 5);
			TFrac operand("-2/-5");
			TFrac actual = operand.minus();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
