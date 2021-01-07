#pragma once
#include <regex>
#include <string>
#include <iostream>

using namespace std;

class TPNumberEditor
{
	typedef enum
	{
		ADD_P_NUMBER,
		ADD_ZERO, 
		ADD_SIGN,
		DELETE_SYMBOL,
		ADD_DELIMITER,
		CLEAR,
		READ_NUMBER,
		WRITE_NUMBER
	}editor_commands;

	const char SIGN = '-';
	const string ZERO = "0";
	const string DELIMITER = ".";
	private:
		int base;
		int precision;
		string number;
	public:
		TPNumberEditor(const string& p_number, int p_base, int p_precision);
		bool is_zero();
		string add_sign();
		string add_p_number(int digit);
		string add_zero();
		string delete_symbol();
		string add_delimiter();
		string clear();
		string edit(int command);
		string read_number();
		string write_number(string a);
};

