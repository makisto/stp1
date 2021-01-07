#include "pch.h"
#include "../TFrac.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4PrimeFractionCopyUnitTests
{
	TEST_CLASS(Lab4PrimeFractionCopyUnitTests)
	{
	public:
		TEST_METHOD(TFrac_copy_2_5_expected_2_5_)
		{
			TFrac expected("2/5");
			TFrac actual = expected.copy();
			Assert::AreEqual(expected.str_getprime(), actual.str_getprime());
		}
		TEST_METHOD(TFrac_copy__2_5_expected__2_5)
		{
			TFrac expected("-2/5");
			TFrac actual = expected.copy();
			Assert::AreEqual(expected.str_getprime(), actual.str_getprime());
		}
		TEST_METHOD(TFrac_copy_2__5_expected__2_5)
		{
			TFrac expected("2/-5");
			TFrac actual = expected.copy();
			Assert::AreEqual(expected.str_getprime(), actual.str_getprime());
		}
		TEST_METHOD(TFrac_copy__2__5_expected_2_5)
		{
			TFrac expected("-2/-5");
			TFrac actual = expected.copy();
			Assert::AreEqual(expected.str_getprime(), actual.str_getprime());
		}
		TEST_METHOD(TFrac_copy_56_56_expected_1_1)
		{
			TFrac expected("56/56");
			TFrac actual = expected.copy();
			Assert::AreEqual(expected.str_getprime(), actual.str_getprime());
		}
	};
}
