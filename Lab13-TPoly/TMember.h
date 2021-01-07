#pragma once
#include <string>
#include <iostream>

using namespace std;

class TMember
{
	private:
		int FCoeff;
		int FDegree;
	public:
		TMember();
		TMember(int c, int n);
		TMember(const TMember& p);

		int get_coeff(void) const;
		void set_coeff(const int& n);
		int get_degree(void) const;
		void set_degree(const int& c);

		TMember diff(void);
		double count_poly(double x);
		string get_tmember_as_string(void) const;

		bool operator==(const TMember& q) const;

		TMember operator-() const;
		TMember operator+(const TMember& q) const;
		TMember operator*(const TMember& q) const;
};

