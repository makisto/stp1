#include "TMember.h"

TMember::TMember()
{
	FCoeff = 0;
	FDegree = 0;
}

TMember::TMember(int c, int n)
{
	FCoeff = c;
	FDegree = n;
}

TMember::TMember(const TMember& p)
{
	FCoeff = p.FCoeff;
	FDegree = p.FDegree;
}

int TMember::get_coeff(void) const
{
	return FCoeff;
}

void TMember::set_coeff(const int& n)
{
	FCoeff = n;
}

int TMember::get_degree(void) const
{
	return FDegree;
}

void TMember::set_degree(const int& c)
{
	FDegree = c;
}

TMember TMember::diff(void)
{
	return TMember(FCoeff * FDegree, FDegree - 1);
}

double TMember::count_poly(double x)
{
	return FCoeff * pow(x, FDegree);
}

string TMember::get_tmember_as_string(void) const
{
	return string(FCoeff == 0 ? "0" : to_string(FCoeff) + (FDegree != 0 ? "*x^" + to_string(FDegree) : ""));
}

bool TMember::operator==(const TMember& q) const
{
	return (FCoeff == q.FCoeff && FDegree == q.FDegree);
}

TMember TMember::operator-() const
{
	return TMember(-FCoeff, FDegree);
}

TMember TMember::operator+(const TMember& q) const
{
	if (FDegree != q.FDegree)
	{
		throw - 1;
	}
	return TMember(FCoeff + q.FCoeff, FDegree);
}

TMember TMember::operator*(const TMember& q) const
{
	return TMember(FCoeff * q.FCoeff, FDegree + q.FDegree);
}
