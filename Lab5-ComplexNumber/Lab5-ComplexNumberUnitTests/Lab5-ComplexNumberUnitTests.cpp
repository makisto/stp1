#include "pch.h"
#include <cmath>
#include "../TComplex.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5ComplexNumberUnitTests
{
	TEST_CLASS(Lab5ComplexNumberUnitTests)
	{
	public:
		
		TEST_METHOD(TComplex_add_2_1_2_1_expected_4_2)
		{
			const TComplex expected(4, 2);
			const TComplex operand1(2, 1);
			const TComplex operand2(2, 1);
			const TComplex actual = operand1.add(operand2);

			Assert::AreEqual(expected.get_re(), actual.get_re());
			Assert::AreEqual(expected.get_im(), actual.get_im());
		}
		TEST_METHOD(TComplex_add_20__30_34_15_4_84_expected_54_15_25_16)
		{
			const TComplex expected(54.15, -25.16);
			const TComplex operand1(20, -30);
			const TComplex operand2(34.15, 4.84);
			const TComplex actual = operand1.add(operand2);

			Assert::AreEqual(expected.get_re_as_string(), actual.get_re_as_string());
			Assert::AreEqual(expected.get_im_as_string(), actual.get_im_as_string());
		}
		TEST_METHOD(TComplex_sub_2_1_2_1_expected_0_0)
		{
			const TComplex expected(0, 0);
			const TComplex operand1(2, 1);
			const TComplex operand2(2, 1);
			const TComplex actual = operand1.sub(operand2);

			Assert::AreEqual(expected.get_re(), actual.get_re());
			Assert::AreEqual(expected.get_im(), actual.get_im());
		}
		TEST_METHOD(TComplex_sub_20__30_34_15_4_84_expected__14_15__34_84)
		{
			const TComplex expected(-14.15, -34.84);
			const TComplex operand1(20, -30);
			const TComplex operand2(34.15, 4.84);
			const TComplex actual = operand1.sub(operand2);

			Assert::AreEqual(expected.get_re_as_string(), actual.get_re_as_string());
			Assert::AreEqual(expected.get_im_as_string(), actual.get_im_as_string());
		}
		TEST_METHOD(TComplex_mul_2_1_2_1_expected_3_4)
		{
			const TComplex expected(3, 4);
			const TComplex operand1(2, 1);
			const TComplex operand2(2, 1);
			const TComplex actual = operand1.mul(operand2);

			Assert::AreEqual(expected.get_re(), actual.get_re());
			Assert::AreEqual(expected.get_im(), actual.get_im());
		}
		TEST_METHOD(TComplex_mul_20__30_34_15_4_84_expected_54_15_25_16)
		{
			const TComplex expected(828.2, -927.7);
			const TComplex operand1(20, -30);
			const TComplex operand2(34.15, 4.84);
			const TComplex actual = operand1.mul(operand2);

			Assert::AreEqual(expected.get_re_as_string(), actual.get_re_as_string());
			Assert::AreEqual(expected.get_im_as_string(), actual.get_im_as_string());
		}
		TEST_METHOD(TComplex_div_2_1_2_1_expected_1_0)
		{
			const TComplex expected(1, 0);
			const TComplex operand1(2, 1);
			const TComplex operand2(2, 1);
			const TComplex actual = operand1.div(operand2);

			Assert::AreEqual(expected.get_re(), actual.get_re());
			Assert::AreEqual(expected.get_im(), actual.get_im());
		}
		TEST_METHOD(TComplex_div_20__30_34_15_4_84_expected_54_15_25_16)
		{
			const TComplex expected(0.452066, -0.942548);
			const TComplex operand1(20, -30);
			const TComplex operand2(34.15, 4.84);
			const TComplex actual = operand1.div(operand2);

			Assert::AreEqual(expected.get_re_as_string(), actual.get_re_as_string());
			Assert::AreEqual(expected.get_im_as_string(), actual.get_im_as_string());
		}
		TEST_METHOD(TComplex_square_2_1_expected_3_4)
		{
			const TComplex expected(3, 4);
			const TComplex operand(2, 1);
			const TComplex actual = operand.square();

			Assert::IsTrue(expected.equals(actual));
		}
		TEST_METHOD(TComplex_square_20__30_34_15_4_84_expected_54_15_25_16)
		{
			const TComplex expected("-500-i*1200");
			const TComplex operand(20, -30);
			const TComplex actual = operand.square();

			Assert::AreEqual(expected.get_complex_as_string(), actual.get_complex_as_string());
		}
		TEST_METHOD(TComplex_inverse_2_1_expected_3_4)
		{
			const TComplex expected(0.4, -0.2);
			const TComplex operand(2, 1);
			const TComplex actual = operand.inverse();

			Assert::IsTrue(expected.equals(actual));
		}
		TEST_METHOD(TComplex_inverse_20__30_34_15_4_84_expected_54_15_25_16)
		{
			const TComplex expected("0.015385+i*0.023077");
			const TComplex operand(20, -30);
			const TComplex actual = operand.inverse();

			Assert::AreEqual(expected.get_complex_as_string(), actual.get_complex_as_string());
		}
		TEST_METHOD(TComplex_minus_2_1_expected__2__1)
		{
			const TComplex expected(-2, -1);
			const TComplex operand(2, 1);
			const TComplex actual = operand.minus();

			Assert::IsTrue(expected.equals(actual));
		}
		TEST_METHOD(TComplex_minus_20__30expected__20_30)
		{
			const TComplex expected("-20+i*30");
			const TComplex operand(20, -30);
			const TComplex actual = operand.minus();

			Assert::AreEqual(expected.get_complex_as_string(), actual.get_complex_as_string());
		}
		TEST_METHOD(TComplex_module_2_0_expected_2)
		{
			double expected = 2;
			const TComplex operand(2, 0);
			double actual = operand.module();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_module_20__30_expected_36_0555127)
		{
			double expected = 36.05551275463989;
			const TComplex operand(20, -30);
			double actual = operand.module();

			Assert::AreEqual(expected, actual); 
		}
		TEST_METHOD(TComplex_angle_rad_2_1_expected_0_463647)
		{
			double expected = 0.4636476090008061;
			const TComplex operand(2, 1);
			double actual = operand.angle_rad();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_angle_rad__20__30_expected_0_982793723247329_COMPL_PI)
		{
			double expected = 0.982793723247329 + COMPL_PI;
			const TComplex operand(-20, -30);
			double actual = operand.angle_rad();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_angle_rad_0_5_expected_COMPL_PI_2)
		{
			double expected = COMPL_PI / 2;
			const TComplex operand(0, 5);
			double actual = operand.angle_rad();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_angle_rad_0_5_expected__COMPL_PI_2)
		{
			double expected = -COMPL_PI / 2;
			const TComplex operand(0, -5);
			double actual = operand.angle_rad();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_angle_deg_2_1_expected_26_5651)
		{
			double expected = 45;
			const TComplex operand(1, 1);
			double actual = operand.angle_deg();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TComplex_pow_2_1_3_expected_2_11)
		{
			const TComplex expected(2, 11);
			const TComplex operand(2, 1);
			const TComplex actual = operand.pow(3);

			Assert::IsTrue(expected.equals(actual));
		}
		TEST_METHOD(TComplex_pow_20__30_23_expected_2)
		{
			const TComplex expected(-500, -1200);
			const TComplex operand(20, -30);
			const TComplex actual = operand.pow(23);

			Assert::IsTrue(expected.non_equals(actual));
		}
		TEST_METHOD(TComplex_root_test)
		{
			double value = sqrt(2) / 2;

			Assert::IsTrue(TComplex(-1, 0).root(4, 0).equals(TComplex(value, value)));
			Assert::IsTrue(TComplex(-1, 0).root(4, 1).equals(TComplex(-value, value)));
			Assert::IsTrue(TComplex(-1, 0).root(4, 2).equals(TComplex(-value, -value)));
			Assert::IsTrue(TComplex(-1, 0).root(4, 3).equals(TComplex(value, -value)));
		}
		TEST_METHOD(TComplex_inverse_exception)
		{
			auto expected = [this] 
			{
				TComplex(0, 0).inverse();
			};
			Assert::ExpectException<TComplex::Zero>(expected);
		}
		TEST_METHOD(TComplex_angle_rad_exception)
		{
			auto expected = [this]
			{
				TComplex(0, 0).angle_rad();
			};
			Assert::ExpectException<TComplex::Zero>(expected);
		}
		TEST_METHOD(TComplex_root_n_exception)
		{
			auto expected = [this]
			{
				TComplex(0, 0).root(0, 1);
			};
			Assert::ExpectException<TComplex::Zero>(expected);
		}
		TEST_METHOD(TComplex_root_i_exception)
		{
			auto expected = [this]
			{
				TComplex(0, 0).root(2, 5);
			};
			Assert::ExpectException<TComplex::Zero>(expected);
		}
	};
}
