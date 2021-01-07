#include "TPoly.h"

TPoly::TPoly() 
{}

TPoly::TPoly(int c, int n)
{
	tpoly.emplace(n, TMember(c, n));
}

TPoly::TPoly(const TPoly& q)
{
	tpoly = q.tpoly;
}

int TPoly::get_max_degree()
{
	return tpoly.rbegin()->first;
}

int TPoly::get_coeff(int n)
{
	if (tpoly.count(n))
	{
		return tpoly[n].get_coeff();
	}
	return 0;
}

void TPoly::clear()
{
	tpoly.clear();
}

TPoly TPoly::operator+(const TPoly& q)
{
	TPoly result = *this;
	for (auto& elem : q.tpoly)
	{
		if (result.tpoly.count(elem.first))
		{
			result.tpoly[elem.first] = result.tpoly[elem.first] + elem.second;
		}
		else
		{
			result.tpoly.emplace(elem.first, elem.second);
		}
	}
	return result;
}

TPoly TPoly::operator*(const TPoly& q)
{
	TPoly result(0, 0);
	for (auto& it1 : tpoly)
	{
		for (auto& it2 : q.tpoly)
		{
			TMember m = it1.second * it2.second;
			if (result.tpoly.count(m.get_degree()))
			{
				result.tpoly[m.get_degree()] = result[m.get_degree()] + m;
			}
			else
			{
				result.tpoly[m.get_degree()] = m;
			}
		}
	}
	return result;
}

TPoly TPoly::operator-(const TPoly& q)
{
	return (*this) + (-q);
}

TPoly TPoly::operator-() const
{
	TPoly result;
	for (auto& elem : tpoly)
	{
		result.tpoly[elem.first] = -elem.second;
	}
	return result;
}

bool TPoly::operator==(const TPoly& q)
{
	return tpoly == q.tpoly;
}

TPoly TPoly::diff(void)
{
	TPoly result;
	for (auto& it : tpoly)
	{
		result.tpoly.emplace(it.first == 0 ? 0 : it.first - 1, it.second.diff());
	}
	return result;
}

double TPoly::count_poly(double x)
{
	double sum = 0.0;
	for (auto& it : tpoly)
	{
		sum += it.second.count_poly(x);
	}
	return sum;
}

string TPoly::get_poly_as_string()
{
	string result;
	for (auto elem = tpoly.rbegin(); elem != tpoly.rend(); elem++)
	{
		result += (elem->second.get_tmember_as_string() != "0" ? elem->second.get_tmember_as_string() + "+" : "");
	}
	if (result.size() != 0)
	{
		if (result[result.size() - 1] == '+')
		{
			result.erase(result.size() - 1, 1);
		}
	}
	int index = result.find("+-");
	while (index > 0)
	{
		result.replace(index, 2, "-");
		index = result.find("+-");
	}

	return result;
}

TMember TPoly::operator[](int i)
{
	if (i < 0 || i >(int)tpoly.size())
	{
		return TMember();
	}

	auto it = tpoly.begin();
	for (int in = 0; in < i; in++)
	{
		++it;
	}
	return (*it).second;
}