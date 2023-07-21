/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 2
The program creates a sorted linked round list, and do actions on it.*/

#pragma once
#include "List.h"

class RoundList :public List
{
public:
	RoundList();
	RoundList(const RoundList& rl);
	~RoundList();
	void removeFirst();
	void add(int value);
	void addToEnd(int value);
	int search(int value);
	void clear();
	friend ostream& operator<<(ostream& os, const RoundList& rl);
private:

};
