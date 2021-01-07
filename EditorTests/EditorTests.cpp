#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7-PNumberEditor/TPNumberEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EditorTests
{
	TEST_CLASS(EditorTests)
	{
		public:	
			TEST_METHOD(ConstructorAndGetters)
			{
				TPNumberEditor test;
				string expected = "0";
				string actual = test.getNumber();
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(IsZero)
			{
				TPNumberEditor test;
				Assert::AreEqual(test.isZero(), true);
				test.addDigit(5);
				Assert::AreEqual(test.isZero(), false);
			}
			TEST_METHOD(AddSignAndAddDigit)
			{
				TPNumberEditor test;
				test.addDigit(5);
				string expected = "-5";
				string actual = test.changeSign();
				Assert::AreEqual(expected, actual);
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(AddZeroAndAddSplit)
			{
				TPNumberEditor test;
				test.addDigit(5);
				test.addZero();
				string expected = "50";
				string actual = test.getNumber();
				Assert::AreEqual(expected, actual);
				test.addSplit();
				test.addZero();
				test.addDigit(1);
				expected = "50.01";
				actual = test.getNumber();
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(BackSpace)
			{
				TPNumberEditor test;
				test.addDigit(5);
				test.changeSign();
				string expected = "0";
				string actual = test.backspace();
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(Clear)
			{
				TPNumberEditor test;
				test.addDigit(5);
				test.addDigit(6);
				test.changeSign();
				string expected = "0";
				string actual = test.clear();
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(WriteString)
			{
				TPNumberEditor test;
				string number = "42";
				test.setNumber(number);
				Assert::AreEqual(test.getNumber(), number);
			}
	};
}
