/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 2
The program represent a third implementation of a queue using two stacks*/

//this is the queueStack class implementation

#include "QueueStack.h"
#include"StackList.h"
#include<iostream>
using namespace std;


QueueStack::QueueStack()
{
	data = new StackList;
}

void QueueStack::clear()
{
	data->clear();
}

int QueueStack::dequeue()
{

	if (data->isEmpty())
		throw "the Queue is empty\n";
	return  data->pop();
}

void QueueStack::enqueue(int value)
{
	StackList st; //the second stack

	while (!data->isEmpty()) //as long the main stack is not empty
		st.push(data->pop()); //moving all the values to the second stack

	data->push(value); //insert the new value to the main stack

	while (!st.isEmpty())
		this->data->push(st.pop()); //returning all the previous values to the main stack
}

int QueueStack::front()
{
	return data->top();
}

bool QueueStack::isEmpty() const
{
	if (data->isEmpty())
		return true;
	return false;
}