#include "pch.h"
#include "../TMemory.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TMemoryUnitTests
{
	TEST_CLASS(TMemoryUnitTests)
	{
	public:
		TEST_METHOD(TMemory_int_constructor_int_OFF)
		{
			TMemory<int> test = TMemory<int>();

			int expected = int();
			int actual = test.get_FNumber();

			string expected_state = "OFF";
			string actual_state = test.get_FState();

			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
		TEST_METHOD(TMemory_float_constructor_float_OFF)
		{
			TMemory<float> test = TMemory<float>();

			float expected = float();
			float actual = test.get_FNumber();

			string expected_state = "OFF";
			string actual_state = test.get_FState();

			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
		TEST_METHOD(TMemory_int_write_to_memory_12_ON)
		{
			TMemory<int> test = TMemory<int>();

			test.write_to_memory(12);

			int expected = 12;
			int actual = test.get_FNumber();

			string expected_state = "ON";
			string actual_state = test.get_FState();
			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
		TEST_METHOD(TMemory_float_write_to_memory_12_55_ON)
		{
			TMemory<float> test = TMemory<float>();

			test.write_to_memory(12.55);

			float expected = 12.55;
			float actual = test.get_FNumber();

			string expected_state = "ON";
			string actual_state = test.get_FState();
			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
		TEST_METHOD(TMemory_int_get_from_memory_12)
		{
			TMemory<int> test = TMemory<int>();

			test.write_to_memory(12);

			int expected = 12;
			int actual = test.get_from_memory();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TMemory_float_get_from_memory_12_55)
		{
			TMemory<float> test = TMemory<float>();

			test.write_to_memory(12.55);

			float expected = 12.55;
			float actual = test.get_from_memory();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TMemory_int_add_in_memory_12_12_24)
		{
			TMemory<int> test = TMemory<int>();

			test.write_to_memory(12);
			test.add_in_memory(12);

			int expected = 24;
			int actual = test.get_from_memory();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TMemory_float_add_in_memory_12_55_12_55_25_1)
		{
			TMemory<float> test = TMemory<float>();

			test.write_to_memory(12.55);
			test.add_in_memory(12.55);

			float expected = 25.1;
			float actual = test.get_from_memory();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TMemory_int_clear_memory)
		{
			TMemory<int> test = TMemory<int>();

			test.write_to_memory(12);
			test.clear_memory();

			int expected = 0;
			int actual = test.get_from_memory();

			string expected_state = "OFF";
			string actual_state = test.get_FState();

			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
		TEST_METHOD(TMemory_float_clear_memory)
		{
			TMemory<float> test = TMemory<float>();

			test.write_to_memory(12.55);
			test.clear_memory();

			float expected = 0;
			float actual = test.get_from_memory();

			string expected_state = "OFF";
			string actual_state = test.get_FState();

			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expected_state, actual_state);
		}
	};
}
