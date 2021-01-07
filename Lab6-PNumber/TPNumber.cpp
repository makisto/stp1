#include "pch.h"
#include "TPNumber.h"

TPNumber::TPNumber(double n, int b, int c)
{
	if (b <= 1 || b >= 17)
	{
		throw constructor_exception("Bad constructor argument: base");
	}
	if (c < 0) 
	{
		throw constructor_exception("Bad constructor argument: precision");
	}

	this->n = n;
	this->b = b;
	this->c = c;
}
TPNumber::TPNumber(const string& n, const string& b, const string& c)
{
	if (stoi(b) <= 1 || stoi(b) >= 17)
	{
		throw string_constructor_exception("Bad string constructor argument: base");
	}
	if (stoi(c) < 0)
	{
		throw string_constructor_exception("Bad string constructor argument: precision");
	}

	this->n = stod(n);
	this->b = stoi(b);
	this->c = stoi(c);
}
TPNumber TPNumber::copy() const noexcept
{
	return TPNumber(this->n, this->b, this->c);
}
TPNumber TPNumber::add(const TPNumber& d) const
{
	if (d.b != this->b)
	{
		throw add_exception("Incorrect add base");
	}
	if (d.c != this->c)
	{
		throw add_exception("Incorrect add precision");
	}

	return TPNumber(this->n + d.n, this->b, this->c);
}
TPNumber TPNumber::mul(const TPNumber& d) const
{
	if (d.b != this->b)
	{
		throw mul_exception("Incorrect mul base");
	}
	if (d.c != this->c)
	{
		throw mul_exception("Incorrect mul precision");
	}

	return TPNumber(this->n * d.n, this->b, this->c);
}
TPNumber TPNumber::sub(const TPNumber& d) const
{
	if (d.b != this->b)
	{
		throw sub_exception("Incorrect sub base");
	}
	if (d.c != this->c)
	{
		throw sub_exception("Incorrect sub precision");
	}

	return TPNumber(this->n - d.n, this->b, this->c);
}
TPNumber TPNumber::div(const TPNumber& d) const
{
	if (d.b != this->b)
	{
		throw div_exception("Incorrect div base");
	}
	if (d.c != this->c)
	{
		throw div_exception("Incorrect div precision");
	}
	if (d.n == 0)
	{
		throw div_exception("Div: Division by zero");
	}

	return TPNumber(this->n / d.n, this->b, this->c);
}
TPNumber TPNumber::reverse() const
{
	if (this->n == 0)
	{
		throw reverse_exception("Reverse: Division by zero");
	}

	return TPNumber(1 / this->n, this->b, this->c);
}
TPNumber TPNumber::square() const noexcept
{
	return TPNumber(this->n * this->n, this->b, this->c);
}
double TPNumber::get_n() const noexcept
{
	return this->n;
}
string TPNumber::get_n_as_string() const noexcept
{
	string result;

	int int_part = (int)this->n;
	double frac_part = this->n - int_part;

	while (int_part != 0)
	{
		auto digit = (int_part % this->b);

		if (digit >= 10)
		{
			result.insert(result.begin(), (char)(digit + 55));
		}
		else
		{
			result.insert(result.begin(), (char)(digit + 48));
		}

		int_part /= this->b;
	}

	if (frac_part != 0)
	{
		result += '.';

		for (int exp = 0; exp < this->c; exp++)
		{
			auto digit = (char)(frac_part *= this->b);

			if (digit >= 10)
			{
				result += (char)(digit + 55);
			}
			else
			{
				result += (char)(digit + 48);
			}

			frac_part -= digit;
		}
	}

	return result;
}
int TPNumber::get_b() const noexcept
{
	return this->b;
}
string TPNumber::get_b_as_string() const noexcept
{
	return to_string(this->b);
}
int TPNumber::get_c() const noexcept
{
	return this->c;
}
string TPNumber::get_c_as_string() const noexcept
{
	return to_string(this->c);
}
void TPNumber::set_b(int newb)
{
	if (newb <= 1 || newb >= 17)
	{
		throw set_b_exception("Incorrect newb");
	}

	this->b = newb;
}
void TPNumber::set_b_by_string(const string& bs)
{
	if (stoi(bs) <= 1 || stoi(bs) >= 17)
	{
		throw set_string_b_exception("Incorrect string newb");
	}

	this->b = stoi(bs);
}
void TPNumber::set_c(int newc)
{
	if (newc < 0)
	{
		throw set_c_exception("Incorrect newc");
	}

	this->c = newc;
}
void TPNumber::set_c_by_string(const string& cs)
{
	if (stoi(cs) < 0)
	{
		throw set_string_c_exception("Incorrect string newc");
	}

	this->c = stoi(cs);
}
