#include "pch.h"
#include "TPNumberEditor.h"

TPNumberEditor::TPNumberEditor(const string &p_number, int p_base, int p_precision)
{
	base = p_base;
	number = p_number;
	precision = p_precision;
}
bool TPNumberEditor::is_zero()
{
	return number == ZERO || number == "-" + ZERO;
}
string TPNumberEditor::add_sign()
{
	if (number[0] == SIGN)
	{
		number.erase(number.begin());
	}
	else if (number != ZERO)
	{
		number = "-" + number;
	}

	return number;
}
string TPNumberEditor::add_p_number(int digit)
{
	int delimiter_index = number.find(DELIMITER);
	char add_symbol = (digit < 10 ? '0' + digit : 'A' + (digit - 10));
	if (digit < base)
	{
		if (number[0] == '0' && delimiter_index < 0)
		{
			number[0] = add_symbol;
		}
		else if (number[0] == '-' && number[1] == '0')
		{
			number[1] = add_symbol;
		}
		else if (delimiter_index > 0)
		{
			string delimiter_substr = number.substr(delimiter_index);
			if (delimiter_substr.length() == 2 && number[number.length() - 1] == '0')
			{
				if (add_symbol == '0')
				{
					number += add_symbol;
				}
				else
				{
					number[number.length() - 1] = add_symbol;
				}
			}
			else
			{
				number += add_symbol;
			}
		}
		else
		{
			number += add_symbol;
		}
	}

	return number;
}
string TPNumberEditor::add_zero()
{
	return add_p_number(0);
}
string TPNumberEditor::delete_symbol()
{
	int delimiter_index = number.find(DELIMITER);
	if (delimiter_index > 0)
	{
		string delimiter_substr = number.substr(delimiter_index);
		if (delimiter_substr.length() == 2)
		{
			number.pop_back();
			number.pop_back();
		}
		else
		{
			number.pop_back();
		}
	}
	else
	{
		number.pop_back();
	}
	if (number == "-" || number.empty()) 
	{
		number = ZERO;
	}

	return number;
}
string TPNumberEditor::clear()
{
	number = ZERO;
	return number;
}
string TPNumberEditor::add_delimiter()
{
	if (number.find(DELIMITER) == std::string::npos) 
	{
		number = number + DELIMITER + "0";
	}

	return number;
}
string TPNumberEditor::read_number()
{
	return number;
}
string TPNumberEditor::write_number(string a)
{
	int digit = 0;
	regex regex("-?([0-9A-F]+),?[0-9A-F]*");
	if (regex_match(a, regex))
	{
		for (int i = 0; i < a.length(); i++)
		{
			switch (a[i])
			{
				case '0':
					digit = 0;
					break;
				case '1':
					digit = 1;
					break;
				case '2':
					digit = 2;
					break;
				case '3':
					digit = 3;
					break;
				case '4':
					digit = 4;
					break;
				case '5':
					digit = 5;
					break;
				case '6':
					digit = 6;
					break;
				case '7':
					digit = 7;
					break;
				case '8':
					digit = 8;
					break;
				case '9':
					digit = 9;
					break;
				case 'A':
					digit = 10;
					break;
				case 'B':
					digit = 11;
					break;
				case 'C':
					digit = 12;
					break;
				case 'D':
					digit = 13;
					break;
				case 'E':
					digit = 14;
					break;
				case 'F':
					digit = 15;
					break;
				case '.':
					digit = 0;
					break;
			}
			if (digit < base)
			{
				continue;
			}
			else
			{
				return number;
			}
		}
	}
	number = a;

	return number;
}
string TPNumberEditor::edit(int command)
{
	string p;
	int digit;
	string res;

	switch (command)
	{
		case ADD_P_NUMBER:
			cin >> digit;
			res = add_p_number(digit);
			break;
		case ADD_ZERO:
			res = add_zero();
			break;
		case ADD_SIGN:
			res = add_sign();
			break;
		case DELETE_SYMBOL:
			res = delete_symbol();
			break;
		case ADD_DELIMITER:
			res = add_delimiter();
			break;
		case CLEAR:
			res = clear();
			break;
		case READ_NUMBER:
			res = read_number();
			break;
		case WRITE_NUMBER:
			cin >> p;
			res = write_number(p);
			break;
		default:
			res = number;
			break;
	}

	return res;
}