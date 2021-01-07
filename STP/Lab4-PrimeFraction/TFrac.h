#pragma once
#include <string>
#include <iostream>

using namespace std;

class TFrac
{
private:
	int chisl;
	int znam;
	int gcd(int a, int b) const noexcept;
	void fix() noexcept;
public:
	class Zero : exception
	{
	public:
		Zero(const char* message) : exception(message)
		{

		}
	};
	explicit TFrac(int a, int b);
	explicit TFrac(string a);
	TFrac copy() const noexcept;
	TFrac add(TFrac d) const noexcept;
	TFrac sub(TFrac d) const noexcept;
	TFrac mul(TFrac d) const noexcept;
	TFrac div(TFrac d) const;
	TFrac square() const noexcept;
	TFrac reverse() const noexcept;
	TFrac minus() const noexcept;
	bool equals(TFrac d) const noexcept;
	bool bigger(TFrac d) const noexcept;
	int getchisl() const noexcept;
	int getznam() const noexcept;
	string str_getprime() const noexcept;
	string str_getchisl() const noexcept;
	string str_getznam() const noexcept;
};
