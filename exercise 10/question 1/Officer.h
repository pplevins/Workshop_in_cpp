/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#pragma once
#include "Soldier.h"
using namespace std;

class Officer : public Soldier
{
private:
	int sociometricScore;

public:
	Officer();
	Officer(int, string, string, int);
	virtual int getSociometricScore();

	virtual void print()const;
	virtual string soldierType() const override;
	virtual bool medal() const override;
};