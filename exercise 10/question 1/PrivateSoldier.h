/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#pragma once
#include "Soldier.h"
#include <vector>
using namespace std;

class PrivateSoldier : public Soldier
{
protected:
	vector<int> operationGrades;
public:
	PrivateSoldier() : Soldier() {}
	PrivateSoldier(int, string, string, int);
	~PrivateSoldier();

	virtual bool medal()const override;
	virtual void print()const override;
	virtual string soldierType() const override;
};