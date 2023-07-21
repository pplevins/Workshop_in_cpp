/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 11 Question 1
The program creates a binary file with list of families, and their classes registerations.*/

#pragma once
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Family
{
private:
	int familyNum;
	char familyName[21];
	int familyMembers;
	int phoneNumber;
	short classes;

public:
	Family(); //ctor
	//sets
	void setFamilyNum(int);
	void setFamilyName(string);
	void setMembers(int);
	void setPhone(int);
	void setClasses(short);
	//gets
	int getFamilyNum();
	string getFamilyName();
	int getMembers();
	int getPhone();
	int getClasses();
};
