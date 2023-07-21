/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 10 Question 1
The program inputs a STL vector of soldiers and doing actions according to their ranks.*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Soldier
{
protected:
	int id;
	string firstName;
	string lastName;
	int operationsNum;

public:
	Soldier() : id(0), firstName(""), lastName(""), operationsNum(0) {}
	Soldier(int myId, string myFirst, string myLast, int myNum) : id(myId), firstName(myFirst), lastName(myLast), operationsNum(myNum) {}
	virtual ~Soldier() {}
	virtual bool medal() const = 0;
	virtual void print() const
	{
		cout << "ID: " << id << endl;
		cout << "first name: " << firstName << endl;
		cout << "last name: " << lastName << endl;
		cout << "num operations: " << operationsNum << endl;
	}
	virtual string soldierType() const
	{
		throw "ERROR: this function is just for officer soldier\n";
	}
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	int getOperationsNum() { return operationsNum; }
};