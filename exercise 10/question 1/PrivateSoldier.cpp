/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#include "PrivateSoldier.h"
#include <vector>
#include <numeric>
using namespace std;

PrivateSoldier::PrivateSoldier(int myId, string myFirst, string myLast, int myNum) : Soldier(myId, myFirst, myLast, myNum)
{
	if (myNum > 0)
	{
		cout << "enter " << myNum << " grades\n";
		int num;
		for (int i = 0; i < myNum; i++)
		{
			cin >> num;
			operationGrades.push_back(num);
		}
	}
}

PrivateSoldier::~PrivateSoldier()
{
	operationGrades.clear();
}

bool PrivateSoldier::medal() const
{
	float average = accumulate(operationGrades.begin(), operationGrades.end(), 0.0) / operationGrades.size();
	if (operationsNum >= 10 && average > 95)
		return true;
	return false;
}

string PrivateSoldier::soldierType() const
{
	return "private";
}

void PrivateSoldier::print() const
{
	cout << soldierType() << endl;
	Soldier::print(); // call to the soldier's print method.
	if (operationGrades.size() > 0)
	{
		cout << "grades: ";
		vector<int>::const_iterator it;
		for (it = operationGrades.begin(); it != operationGrades.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}