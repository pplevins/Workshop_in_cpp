/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 11 Question 1
The program creates a binary file with list of families, and their classes registerations.*/

#include "Family.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

Family::Family()
{
	setFamilyNum(0);
	setFamilyName("");
	setMembers(0);
	setPhone(0);
	setClasses(0);
}

void Family::setFamilyNum(int num) { familyNum = num; }
void Family::setFamilyName(string name) { strncpy(familyName, name.c_str(), 20); }
void Family::setMembers(int num) { familyMembers = num; }
void Family::setPhone(int num) { phoneNumber = num; }
void Family::setClasses(short num)
{ 
	if (num == 0)
		classes = num; //for intialization
	else
		classes |= num; //for update using a bitwise operation 'or'
}
int Family::getFamilyNum() { return familyNum; }
string Family::getFamilyName() { return familyName; }
int Family::getMembers() { return familyMembers; }
int Family::getPhone() { return phoneNumber; }
int Family::getClasses() { return classes; }