#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class TMemory
{
	private:
		T FNumber;
		bool FState;
	public:
		TMemory();
		void write_to_memory(const T& e);
		T get_from_memory();
		void add_in_memory(const T& e);
		void clear_memory();
		string get_FState();
		T get_FNumber();
};

