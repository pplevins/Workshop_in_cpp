/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#pragma once
#include "Employee.h"

class PartTime: public Employee
{
private: //additional values in addition to Employees values.
	int hoursOfWork;
	float payPerHour;

public:
	PartTime(string n, int i, int sen, int h, float p); //parameters ctor.
	PartTime(); //empty ctor.
	PartTime(const PartTime& part); //copy ctor.
	void salary(); //calculates the salaray according the "pay" value of the class.
	friend istream& operator>>(istream& is, PartTime& part); //cin operator.
	friend ostream& operator<<(ostream& os, const PartTime& part); //cout operator.
};