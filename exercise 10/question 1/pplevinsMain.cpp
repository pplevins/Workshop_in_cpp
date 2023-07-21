/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#include "PrivateSoldier.h"
#include"Commander.h"
#include"Officer.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

enum option {
	EXIT,	//	ending the program
	ADD_NEW_SOLDIER,	//	adding new soldier to the vector
	DESERVES_MEDAL,	//	print all the soldiers that are medal worthy
	HIGHEST_SOCIOMETRIC,	//print first and last name of the highest sociometric score
	PRIVATE_MEDAL_COUNT,	//	print the number of privates that are medal worthy
	NONCOMBAT_COMMANDER,	//	print forst and last name of all the non-fighters commanders
	SUPER_SOLDIER,   // print a massage if there are a soldier with more than 15 combats
	REMOVE_OFFICER,	//	erasing all the officers who wasn't in a combat
};

void add(vector<Soldier*>& myVec)
{
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";

	int num;
	cin >> num;

	cout << "enter id, first name, last name and number of operations\n";
	int myId; // id input
	string myFirst; // first name input
	string myLast; // last name input
	int myNum; // number of combats

	cin >> myId >> myFirst >> myLast >> myNum;

	if (num == 1) //private soldier
	{
		Soldier* ptr = new PrivateSoldier(myId, myFirst, myLast, myNum);
		myVec.push_back(ptr);
	}
	else if (num == 2) //commander
	{
		Soldier* ptr = new Commander(myId, myFirst, myLast, myNum);
		myVec.push_back(ptr);
	}
	else if (num == 3) //officer
	{
		Soldier* ptr = new Officer(myId, myFirst, myLast, myNum);
		myVec.push_back(ptr);
	}
}

void printMedalList(vector<Soldier*> myVec)
{
	vector<Soldier*>::iterator it = myVec.begin(); //iterator

	for (it = myVec.begin(); it != myVec.end(); it++)
	{
		if ((*it)->medal())
			(*it)->print();
	}
}

Soldier* highestSociometricScore(vector<Soldier*> myVec)
{
	int max = -1; // calculting the max value
	Soldier* ptrSol = NULL; // the ptr that will return with the value of the highest soldier
	vector<Soldier*>::iterator it = myVec.begin(); //iterator

	for (it = myVec.begin(); it != myVec.end(); it++)
	{
		if ((*it)->soldierType() == "officer")
		{
			//get the max
			if (((Officer*)*it)->getSociometricScore() > max)
			{
				max = ((Officer*)*it)->getSociometricScore();
				ptrSol = *it; // setting the ptr with the officer
			}
		}
	}
	return ptrSol;
}

int main()
{
	Soldier* s;
	vector<Soldier*> soldierVec;   // vector of soldier's decleration
	int op;
	int count = 0;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(soldierVec);  //adding new soldier					
			break;
		case DESERVES_MEDAL:printMedalList(soldierVec);  //print the medal worthy
			break;
		case HIGHEST_SOCIOMETRIC:   // print the name of the highest sociometric score
			s = highestSociometricScore(soldierVec);
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			//print the private medal worthy
			for_each(soldierVec.begin(), soldierVec.end(), [&count](Soldier* sol)
				{
				if (sol->soldierType() == "private" && sol->medal())
					count++;
				} // close for the lambda
			); // for_each close
			cout << count << endl; //printing the count
			count = 0;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //print list of all non-combat commanders
			for_each(soldierVec.begin(), soldierVec.end(), [](Soldier* sol)
				{
				if (sol->soldierType() == "commander" && !((Commander*)sol)->getFighter())
					cout << sol->getFirstName() << " " << sol->getLastName() << endl;
				}
			);
			cout << endl;
			break;
		case SUPER_SOLDIER:
			// check of exist a soldier with more than 15 battles
			if (any_of(soldierVec.begin(), soldierVec.end(), [](Soldier* sol)
				{
				if (sol->getOperationsNum() > 15)
					return true;
				return false;
				} // lambda close
			) //any_of close
				) // if close
				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://erase officers with no combats
			vector<Soldier*>::iterator it1;

			it1 = remove_if(soldierVec.begin(), soldierVec.end(), [](Soldier* sol)
				{
				if (sol->soldierType() == "officer" && sol->getOperationsNum() <= 0)
					return true;
				return false;
				}
			);
			vector<Soldier*>::iterator it2 = soldierVec.begin();
			for (it2 = soldierVec.begin(); it2 != it1; it2++)
				(*it2)->print();
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

/*Run sample:

enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
1
enter id, first name, last name and number of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
2
enter id, first name, last name and number of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
3
enter id, first name, last name and number of operations
333 ccc ccc 0
enter number of sociometric score
100
enter 0-7
3
Officer with the highest sociometric score: ccc ccc
enter 0-7
4
number of privates that received medals: 0
enter 0-7
5
list of noncombat commanders:
enter 0-7
6
no soldier did more than 15 operations
enter 0-7
7
PrivateSoldier
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
Commander
ID: 222
first name: bbb
last name: bbb
num operations: 0
combat: yes
enter 0-7
0*/