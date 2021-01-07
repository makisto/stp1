#include "pch.h"
#include "TComplex.h"

TComplex::TComplex(double real, double image)
{
	this->re = round(real * 1000000) / 1000000;
	this->im = round(image * 1000000) / 1000000;
}
TComplex::TComplex(const string &f) 
{
	size_t pos = f.find("+i*");
	int k = 1;
	if (pos == string::npos) 
	{
		pos = f.find("-i*");
		k = -1;
	}
	if (pos == string::npos) 
	{
		this->re = round(stod(f) * 1000000) / 1000000;
		this->im = 0;
	}
	else 
	{
		this->re = round(stod(f.substr(0, pos)) * 1000000) / 1000000;
		this->im = round(stod(f.substr(pos + 3)) * k * 1000000) / 1000000;
	}
}
TComplex TComplex::copy() const noexcept
{
	return TComplex(this->re, this->im);
}
TComplex TComplex::add(const TComplex& d) const noexcept
{
	return TComplex(this->re + d.re, this->im + d.im);
}
TComplex TComplex::mul(const TComplex &d) const noexcept
{
	return TComplex(this->re * d.re - this->im * d.im, this->re * d.im + this->im * d.re);
} 
TComplex TComplex::square() const noexcept
{
	return this->mul(*this);
}
TComplex TComplex::inverse() const
{
	return TComplex(1, 0).div(*this);
}
TComplex TComplex::sub(const TComplex &d) const noexcept
{
	return TComplex(this->re - d.re, this->im - d.im);
}
TComplex TComplex::div(const TComplex &d) const
{
	if (d.re == 0 && d.im == 0) 
	{
		throw Zero("Division by zero");
	}

	return TComplex
	(
		((this->re * d.re + this->im * d.im) / (d.re * d.re + d.im * d.im)),
		((this->im * d.re - this->re * d.im) / (d.re * d.re + d.im * d.im))
	);
}
TComplex TComplex::minus() const noexcept
{
	return TComplex(-this->re, -this->im);
}
double TComplex::module() const noexcept
{
	return sqrt(this->re * this->re + this->im * this->im);
}
double TComplex::angle_rad() const
{
	switch (is_equal(this->re))
	{
		case 1:
			return atan(this->im / this->re);
		case 0:
			switch (is_equal(this->im))
			{
				case 1:
					return COMPL_PI / 2;
				case 0:
					throw Zero("Number is zero!");
				case -1:
					return -COMPL_PI / 2;
			}
		case -1:
			return atan(this->im / this->re) + COMPL_PI;
	}
}
double TComplex::angle_deg() const noexcept
{
	return this->angle_rad() * 180 / COMPL_PI;
}
TComplex TComplex::pow(int n) const noexcept
{
	double mod = std::pow(this->module(), n);
	double arg = this->angle_rad() * n;

	return TComplex(mod * cos(arg), mod * sin(arg));
}
TComplex TComplex::root(int n, int i) const
{
	if (n == 0)
	{
		throw Zero("Division by zero");
	}
	if (i >= n)
	{
		throw Zero("Index must be less than exponent");
	}

	double mod = std::pow(this->module(), 1.0 / n);
	double arg = (this->angle_rad() + 2 * COMPL_PI * i) / n;

	return TComplex(mod * cos(arg), mod * sin(arg));
}
bool TComplex::equals(const TComplex &d) const noexcept
{
	if (this->re == d.re && this->im == d.im)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TComplex::non_equals(const TComplex &d) const noexcept
{
	return !(this->equals(d));
}
double TComplex::get_re() const noexcept
{
	return this->re;
}
string TComplex::get_re_as_string() const noexcept
{
	return to_string(this->re);
}
double TComplex::get_im() const noexcept
{
	return this->im;
}
string TComplex::get_im_as_string() const noexcept
{
	return to_string(this->im);
}
string TComplex::get_complex_as_string() const noexcept
{
	string re = get_re_as_string();
	string im;
	string sign;

	switch (is_equal(this->im))
	{
		case -1:
			sign = "-i*";
			im = std::to_string(fabs(this->im));
			break;
		case 0:
			sign = im = "";
			break;
		case 1:
			sign = "+i*";
			im = get_im_as_string();
			break;
	}

	return re + sign + im;
}
int TComplex::is_equal(double x) const noexcept
{
	if (x > 0)
	{
		return 1;
	}
	else if (x == 0)
	{
		return 0;
	}
	return -1;
}
