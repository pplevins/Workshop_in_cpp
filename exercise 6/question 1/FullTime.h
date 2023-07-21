/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#pragma once
#include "Employee.h"

class FullTime:public Employee
{
private: //additional value in addition to Employees values.
float salaryPerYear;

public: //methods.
	FullTime(string n, int i, int sen, float sal); //parameters ctor.
	FullTime(); //empty ctor.
	FullTime(const FullTime& full); //copy ctor.
	void salary(); //calculates the salaray according the "pay" value of the class.
	friend istream& operator>>(istream& is, FullTime& full); //cin operator.
	friend ostream& operator<<(ostream& os, const FullTime& full); //cout operator.
};
