#pragma once

enum TOprtn
{
	None,
	Add,
	Sub,
	Mul,
	Div
};

enum TFunc
{
	Rev,
	Sqr
};

template <class T>
class TProc
{
private:
	T lop_res;
	T rop;
	TOprtn operation;
public:
	TProc();
	void reset_proc();
	void reset_operation();
	void execute_operation();
	void execute_function(enum TFunc func);
	T get_lop_res() const;
	void set_lop_res(const T& set);
	T get_rop() const;
	void set_rop(const T& set);
	TOprtn get_operation() const;
	void set_operation(TOprtn set);
};


