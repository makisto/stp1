#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionReverseUnitTests
{
	TEST_CLASS(Lab4PrimeFractionReverseUnitTests)
	{
	public:
		TEST_METHOD(TFrac_reverse_2_5_expected_5_2)
		{
			TFrac expected(5, 2);
			TFrac operand(2, 5);
			TFrac actual = operand.reverse();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_reverse__2_5_expected_5_2)
		{
			TFrac expected(-5, 2);
			TFrac operand(-2, 5);
			TFrac actual = operand.reverse();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_reverse_2__5_expected_4_25)
		{
			TFrac expected(-5, 2);
			TFrac operand(2, -5);
			TFrac actual = operand.reverse();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_reverse__2__5_expected_4_25)
		{
			TFrac expected(5, 2);
			TFrac operand(-2, -5);
			TFrac actual = operand.reverse();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
		TEST_METHOD(TFrac_reverse_string__2__5_expected_5_2)
		{
			TFrac expected(5, 2);
			TFrac operand("-2/-5");
			TFrac actual = operand.reverse();
			Assert::AreEqual(expected.getchisl(), actual.getchisl());
			Assert::AreEqual(expected.getznam(), actual.getznam());
		}
	};
}
