/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#pragma once
#include "PrivateSoldier.h"
using namespace std;

class Commander : public PrivateSoldier
{
protected:
	bool fighter;

public:
	Commander();
	Commander(int, string, string, int);
	~Commander();
	virtual bool medal()const override;
	virtual void print()const;
	virtual string soldierType() const;
	virtual bool getFighter();
};