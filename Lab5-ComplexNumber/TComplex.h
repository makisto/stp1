#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

#define COMPL_PI 3.14159265358979323846

class TComplex 
{
	private:
		double re;
		double im;
		int is_equal(double x) const noexcept;
	public:
		class Zero : exception
		{
			public:
				explicit Zero(const char* message) : exception(message)
				{
				}
		};
		explicit TComplex(double real, double image);
		explicit TComplex(const string &f);
		TComplex copy() const noexcept;
		TComplex add(const TComplex &d) const noexcept;
		TComplex mul(const TComplex &d) const noexcept;
		TComplex square() const noexcept;
		TComplex inverse() const;
		TComplex sub(const TComplex &d) const noexcept;
		TComplex div(const TComplex &d) const;
		TComplex minus() const noexcept;
		double module() const noexcept;
		double angle_rad() const;
		double angle_deg() const noexcept;
		TComplex pow(int n) const noexcept;
		TComplex root(int n, int i) const;
		bool equals(const TComplex &d) const noexcept;
		bool non_equals(const TComplex &d) const noexcept;
		double get_re() const noexcept;
		string get_re_as_string() const noexcept;
		double get_im() const noexcept;
		string get_im_as_string() const noexcept;
		string get_complex_as_string() const noexcept;
};
