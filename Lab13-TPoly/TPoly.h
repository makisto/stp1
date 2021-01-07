#pragma once
#include <iostream>
#include <string>
#include <map>
#include "TMember.h"
using namespace std;

class TPoly 
{
	private:
		map<int, TMember> tpoly;
	public:
		TPoly();
		TPoly(int c, int n);
		TPoly(const TPoly& q);

		int get_max_degree();
		int get_coeff(int n);
		void clear();

		TPoly operator+(const TPoly& q);
		TPoly operator-(const TPoly& q);
		TPoly operator-() const;
		TPoly operator*(const TPoly& q);
		bool operator==(const TPoly& q);

		TPoly diff(void);
		double count_poly(double x);
		string get_poly_as_string();
		TMember operator[] (int i);
};

