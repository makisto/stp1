#include "pch.h"
#include "TFrac.h"

int TFrac::gcd(int a, int b) const noexcept
{
	if (a == 0)
	{
		if (b < 0)
		{
			return -1 * b;
		}
		return b;
	}
	if (a < 0)
	{
		a *= -1;
	}
	if (b < 0)
	{
		b *= -1;
	}
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}
void TFrac::fix() noexcept
{
	if (this->znam < 0)
	{
		this->znam *= -1;
		this->chisl = -this->chisl;
	}
}
int TFrac::getchisl() const noexcept
{
	return this->chisl;
}
int TFrac::getznam() const noexcept
{
	return this->znam;
}
string TFrac::str_getchisl() const noexcept
{
	return to_string(this->chisl);
}
string TFrac::str_getznam() const noexcept
{
	return to_string(this->znam);
}
string TFrac::str_getprime() const noexcept
{
	return to_string(this->chisl) + "/" + to_string(this->znam);
}
TFrac::TFrac(int a, int b)
{
	if (b == 0)
	{
		throw Zero("ERROR 0 ZNAM");
	}

	this->chisl = (a / gcd(a, b));
	this->znam = (b / gcd(a, b));

	fix();
}
TFrac::TFrac(string tfrac)
{
	int a = 0;
	int b = 0;

	string delimiter = "/";

	string tokenA = tfrac.substr(0, tfrac.find(delimiter));
	a = stoi(tokenA);

	string tokenB = tfrac.substr(tfrac.find(delimiter) + delimiter.length(), std::string::npos);
	b = stoi(tokenB);

	if (b == 0)
	{
		throw Zero("ERROR 0 ZNAM");
	}

	this->chisl = (a / gcd(a, b));
	this->znam = (b / gcd(a, b));

	fix();
}
TFrac TFrac::copy() const noexcept
{
	return TFrac(this->chisl, this->znam);
}
TFrac TFrac::add(TFrac d) const noexcept
{
	return TFrac
	(
		((this->chisl * d.getznam() + this->znam * d.getchisl()) / gcd(this->chisl, this->znam)),
		((this->znam * d.getznam()) / gcd(this->chisl, this->znam))
	);
}
TFrac TFrac::sub(TFrac d) const noexcept
{
	return TFrac
	(
		((this->chisl * d.getznam() - this->znam * d.getchisl()) / gcd(this->chisl, this->znam)),
		((this->znam * d.getznam()) / gcd(this->chisl, this->znam))
	);
}
TFrac TFrac::mul(TFrac d) const noexcept
{
	return TFrac
	(
		((this->chisl * d.getchisl()) / gcd(this->chisl, this->znam)),
		((this->znam * d.getznam()) / gcd(this->chisl, this->znam))
	);
}
TFrac TFrac::div(TFrac d) const
{
	if (d.getchisl() == 0)
	{
		throw Zero("ERROR 0 CHISL IN DIV");
	}

	return TFrac
	(
		((this->chisl * d.getznam()) / gcd(this->chisl, this->znam)),
		((this->znam * d.getchisl()) / gcd(this->chisl, this->znam))
	);
}
TFrac TFrac::square() const noexcept
{
	return TFrac(this->chisl * this->chisl, this->znam * this->znam);
}
TFrac TFrac::reverse() const noexcept
{
	return TFrac(TFrac(1, 1).div(*this));
}
TFrac TFrac::minus() const noexcept
{
	return TFrac(TFrac(0, 1).sub(*this));
}
bool TFrac::equals(TFrac d) const noexcept
{
	if ((this->chisl * d.getznam()) == (d.getchisl() * this->znam))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TFrac::bigger(TFrac d) const noexcept
{
	if ((this->chisl * d.getznam()) > (d.getchisl() * this->znam))
	{
		return true;
	}
	else
	{
		return false;
	}
}
