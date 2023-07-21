/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 2
The program represent a third implementation of a queue using two stacks*/

//this is the queueStack class implementation

#pragma once
#include "Queue.h"
#include "Stack.h"
#include "StackList.h"
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};