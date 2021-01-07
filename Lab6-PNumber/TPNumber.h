#pragma once
#include <string>
#include <iostream>

using namespace std;

class TPNumber
{
private:
	double n;
	int b;
	int c;
public:
	class constructor_exception : exception
	{
	public:
		explicit constructor_exception(const char* message) : exception(message)
		{
		}
	};
	class string_constructor_exception : exception
	{
	public:
		explicit string_constructor_exception(const char* message) : exception(message)
		{
		}
	};
	class add_exception : exception
	{
	public:
		explicit add_exception(const char* message) : exception(message)
		{
		}
	};
	class sub_exception : exception
	{
	public:
		explicit sub_exception(const char* message) : exception(message)
		{
		}
	};
	class mul_exception : exception
	{
	public:
		explicit mul_exception(const char* message) : exception(message)
		{
		}
	};
	class div_exception : exception
	{
	public:
		explicit div_exception(const char* message) : exception(message)
		{
		}
	};
	class reverse_exception : exception
	{
	public:
		explicit reverse_exception(const char* message) : exception(message)
		{
		}
	};
	class set_b_exception : exception
	{
	public:
		explicit set_b_exception(const char* message) : exception(message)
		{
		}
	};
	class set_string_b_exception : exception
	{
	public:
		explicit set_string_b_exception(const char* message) : exception(message)
		{
		}
	};
	class set_c_exception : exception
	{
	public:
		explicit set_c_exception(const char* message) : exception(message)
		{
		}
	};
	class set_string_c_exception : exception
	{
	public:
		explicit set_string_c_exception(const char* message) : exception(message)
		{
		}
	};
	explicit TPNumber(double n, int b, int c);
	explicit TPNumber(const string& n, const string& b, const string& c);
	TPNumber copy() const noexcept;
	TPNumber add(const TPNumber& d) const;
	TPNumber mul(const TPNumber& d) const;
	TPNumber sub(const TPNumber& d) const;
	TPNumber div(const TPNumber& d) const;
	TPNumber reverse() const;
	TPNumber square() const noexcept;
	double get_n() const noexcept;
	string get_n_as_string() const noexcept;
	int get_b() const noexcept;
	string get_b_as_string() const noexcept;
	int get_c() const noexcept;
	string get_c_as_string() const noexcept;
	void set_b(int newb);
	void set_b_by_string(const string& bs);
	void set_c(int newc);
	void set_c_by_string(const string& cs);
};

