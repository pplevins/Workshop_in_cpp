/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 1
The program inputs a binary search tree and doing actions on it.*/


//this is the standard queue class for the program with utilation to template class
#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
};