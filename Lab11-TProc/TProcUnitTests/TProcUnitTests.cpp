#include "pch.h"
#include "../TFrac.h"
#include "../TProc.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TProcUnitTests
{
	TEST_CLASS(TProcUnitTests)
	{
		public:
			TEST_METHOD(TProc_tfrac_constructor_0_1_None)
			{
				TProc<TFrac> test = TProc<TFrac>();

				int expected_rop = 1;
				int expected_lop_res = 0;
				TOprtn expected_operation = None;

				int actual_rop = test.get_rop().getznam();
				int actual_lop_res = test.get_rop().getchisl();
				TOprtn actual_operation = test.get_operation();

				Assert::AreEqual(expected_rop, actual_rop);
				Assert::AreEqual(expected_lop_res, actual_lop_res);
				Assert::AreEqual(expected_operation, actual_operation);
			}
			TEST_METHOD(TProc_tfrac_set_rop_lop_res_and_operation_1_2_Add)
			{
				TProc<TFrac> test = TProc<TFrac>();

				TFrac d(2, 1);

				test.set_rop(d);
				test.set_lop_res(d);
				test.set_operation(Add);

				int expected_rop = 1;
				int expected_lop_res = 2;
				TOprtn expected_operation = Add;

				int actual_rop = test.get_rop().getznam();
				int actual_lop_res = test.get_rop().getchisl();
				TOprtn actual_operation = test.get_operation();

				Assert::AreEqual(expected_rop, actual_rop);
				Assert::AreEqual(expected_lop_res, actual_lop_res);
				Assert::AreEqual(expected_operation, actual_operation);
			}
			TEST_METHOD(TProc_tfrac_execute_operation_add_2_1_2_1_4_1)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(4, 1);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Add);

				actual.execute_operation();

				Assert::AreEqual(expected.getchisl(), actual.get_lop_res().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_lop_res().getznam());
			}
			TEST_METHOD(TProc_tfrac_execute_operation_sub_2_1_2_1_0_1)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(0, 1);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Sub);

				actual.execute_operation();

				Assert::AreEqual(expected.getchisl(), actual.get_lop_res().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_lop_res().getznam());
			}
			TEST_METHOD(TProc_tfrac_execute_operation_mul_2_1_2_1_4_1)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(4, 1);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Mul);

				actual.execute_operation();

				Assert::AreEqual(expected.getchisl(), actual.get_lop_res().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_lop_res().getznam());
			}
			TEST_METHOD(TProc_tfrac_execute_operation_div_2_1_2_1_1_1)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(1, 1);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Div);

				actual.execute_operation();

				Assert::AreEqual(expected.getchisl(), actual.get_lop_res().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_lop_res().getznam());
			}
			TEST_METHOD(TProc_tfrac_execute_function_reverse_2_1_1_2)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(1, 2);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Mul);

				actual.execute_function(Rev);

				Assert::AreEqual(expected.getchisl(), actual.get_rop().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_rop().getznam());
			}
			TEST_METHOD(TProc_tfrac_execute_operation_square_2_1_4_1)
			{
				TProc<TFrac> actual = TProc<TFrac>();

				TFrac d(2, 1);
				TFrac expected(4, 1);

				actual.set_rop(d);
				actual.set_lop_res(d);
				actual.set_operation(Div);

				actual.execute_function(Sqr);

				Assert::AreEqual(expected.getchisl(), actual.get_rop().getchisl());
				Assert::AreEqual(expected.getznam(), actual.get_rop().getznam());
			}
	};
}

