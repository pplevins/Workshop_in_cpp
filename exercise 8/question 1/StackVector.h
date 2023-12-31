/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 1
The program inputs an infix string and claculates it using a template stackVector */

//this is the standard stackVector class for the exercise with implementation to be template

#pragma once
#include "Vector.h"
#include "Stack.h"
//-------------------------------------------------------
// class StackVector
// Stack implemented using Vector
// Vector will grow as necessary to avoid overflow
//-------------------------------------------------------
template <class T>
class StackVector : public Stack<T>
{
public:
	// constructor requires a starting size
	StackVector(unsigned int capacity);
	StackVector(const StackVector<T>& s);

	// Stack operations
	void clear() override;
	bool isEmpty() const override;
	T pop() override;
	void push(T value) override;
	T top()override;
protected:
	// data fields
	Vector<T> data;
};

//-------------------------------------------------------
// class StackVector implementation
//-------------------------------------------------------
template < class T>
StackVector<T>::StackVector(unsigned int capacity) : data(capacity)
{
	// create and initialize a Stack based on Vectors
}

template < class T>
StackVector<T>::StackVector(const StackVector<T>& s) : data(s.data)
{}

template < class T>
void StackVector<T>::clear()
{
	// clear all elements from Stack, by setting
	// index to bottom of Stack
	data.clear();
}

template < class T>
bool StackVector<T>::isEmpty() const
{
	return data.getSize() == 0;
}

template < class T>
T StackVector<T>::pop()
{
	// return and remove the intopmost element in the Stack
	if (isEmpty())
		throw "Stack is empty";
	return data.delLast();
}

template < class T>
void StackVector<T>::push(T val)
{
	// push new value onto Stack
	data.insert(val);
}

template < class T>
T StackVector<T>::top()
{
	// return the intopmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data[data.getSize() - 1];
}