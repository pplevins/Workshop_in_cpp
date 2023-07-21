/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#include "Officer.h"
using namespace std;

Officer::Officer() : Soldier() { sociometricScore = 0; }

Officer::Officer(int myId, string myFirst, string myLast, int myNum) : Soldier(myId, myFirst, myLast, myNum)
{
	cout << "enter the sociometric score" << endl;
	cin >> sociometricScore;
	if (sociometricScore < 0)
		sociometricScore = 0;
}

bool Officer::medal() const
{
	if (operationsNum > 2 && sociometricScore >= 92)
		return true;
	return false;
}

void Officer::print() const
{
	cout << soldierType() << endl;
	Soldier::print();

	cout << "sociometric score: " << sociometricScore << endl;
}

string Officer::soldierType() const
{
	return "officer";
}

int Officer::getSociometricScore()
{
	return sociometricScore;
}