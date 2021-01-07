#include "pch.h"
#include "TProc.h"
#include <iostream>

template <class T>
TProc<T>::TProc()
{
	rop = T();
	lop_res = T();
	operation = None;
}

template<class T>
void TProc<T>::reset_proc()
{
	rop = T();
	lop_res = T();
	operation = None;
}

template<class T>
void TProc<T>::reset_operation()
{
	operation = None;
}

template<class T>
void TProc<T>::execute_operation()
{
	switch (operation)
	{
		case Add:
			lop_res = lop_res.add(rop);
			break;
		case Sub:
			lop_res = lop_res.sub(rop);
			break;
		case Mul:
			lop_res = lop_res.mul(rop);
			break;
		case Div:
			lop_res = lop_res.div(rop);
			break;
		case None:
		default:
			break;
	}
}

template<class T>
void TProc<T>::execute_function(enum TFunc func)
{
	switch (func)
	{
		case Rev:
			rop = rop.reverse();
			break;
		case Sqr:
			rop = rop.square();
			break;
		default:
			break;
	}
}

template<class T>
T TProc<T>::get_lop_res() const
{
	return lop_res;
}

template<class T>
void TProc<T>::set_lop_res(const T& set)
{
	lop_res = set;
}

template<class T>
T TProc<T>::get_rop() const
{
	return rop;
}

template<class T>
void TProc<T>::set_rop(const T& set)
{
	rop = set;
}

template<class T>
TOprtn TProc<T>::get_operation() const
{
	return operation;
}

template<class T>
void TProc<T>::set_operation(TOprtn set)
{
	operation = set;
}
