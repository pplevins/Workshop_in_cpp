/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#include "Commander.h"
#include <numeric>
using namespace std;

Commander::Commander() : PrivateSoldier() { fighter = false; }

Commander::Commander(int myId, string myFirst, string myLast, int myNum) : PrivateSoldier(myId, myFirst, myLast, myNum)
{
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> fighter; //the user initializing the fighter flag
}

Commander::~Commander()
{
	operationGrades.clear();
}

bool Commander::medal() const
{
	float average = accumulate(operationGrades.begin(), operationGrades.end(), 0.0) / operationGrades.size();
	//check for fighter
	if (operationsNum >= 7 && average > 90 && fighter == true)
		return true;
	return false;
}

string Commander::soldierType() const
{
	return "commander";
}

void Commander::print() const
{
	PrivateSoldier::print(); //call to the PrivateSoldier's print method
	if (fighter)
		cout << "combat: yes" << endl;
	else
		cout << "combat: no " << endl;
}

bool Commander::getFighter()
{
	return fighter;
}