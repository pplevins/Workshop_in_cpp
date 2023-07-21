/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 2
The program represent a third implementation of a queue using two stacks*/

//this is the standard stackList class used for the stack implementation

#include "StackList.h"

//-------------------------------------------------------
// class StackList implementation
//-------------------------------------------------------
StackList::StackList() :data()
{
	// create and initialize a Stack based on Lists
}
StackList::StackList(const StackList& lst)
	: data(lst.data)
{ /* copy constructor*/
}
void StackList::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}
bool StackList::isEmpty() const
{ // return true if Stack is empty
	return data.isEmpty();
}
int StackList::pop()
{
	// return and remove the intopmost element in the Stack
	// get first element in List
	int result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}
void StackList::push(int val)
{
	// push new value onto Stack
	data.add(val);
}
int StackList::top()
{
	return data.firstElement();
}