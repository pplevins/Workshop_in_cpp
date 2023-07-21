/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 1
The program inputs an infix string and claculates it using a template stackVector */

#pragma once
#include "Vector.h"
//-------------------------------------------------------
// class stack
// abstract class - simply defines protocol for
// stack operations
//-------------------------------------------------------
template <class T>
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual T pop() = 0;
	virtual void push(T value) = 0;
	virtual T top() = 0;
};