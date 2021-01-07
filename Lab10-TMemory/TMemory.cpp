#include "pch.h"
#include "TMemory.h"

template<class T>
TMemory<T>::TMemory()
{
	FNumber = T();
	FState = false;
}

template<class T>
void TMemory<T>::write_to_memory(const T & e)
{
	FNumber = e;
	FState = true;
}

template<class T>
T TMemory<T>::get_from_memory()
{
	return T(FNumber);
}

template<class T>
void TMemory<T>::add_in_memory(const T & e)
{
	FNumber = FNumber + e;
	FState = true;
}

template<class T>
void TMemory<T>::clear_memory()
{
	FNumber = T();
	FState = false;
}

template<class T>
string TMemory<T>::get_FState()
{
	return FState ? "ON" : "OFF";
}

template<class T>
T TMemory<T>::get_FNumber()
{
	return FNumber;
}