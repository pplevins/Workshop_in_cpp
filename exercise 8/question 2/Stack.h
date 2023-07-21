/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 2
The program represent a third implementation of a queue using two stacks*/

//this is the standard abstarct class used for the stack implementation

#pragma once
//-------------------------------------------------------
// class stack
// abstract class - simply defines protocol for
// stack operations
//-------------------------------------------------------
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual int pop() = 0;
	virtual void push(int value) = 0;
	virtual int top() = 0;
};