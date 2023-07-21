/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 2
The program represent a third implementation of a queue using two stacks*/

//this is the standard stackList class used for the stack implementation

#pragma once
#include "Stack.h"
#include "List.h"
//-------------------------------------------------------
// class StackList
// Stack implemented using List operations
//-------------------------------------------------------
class StackList : public Stack
{
public:
	StackList();
	StackList(const StackList&);
	// Stack operations
	void clear()override;
	bool isEmpty() const override;
	int pop()override;
	void push(int value) override;
	int top()override;
protected:
	// data fields
	List data;
};