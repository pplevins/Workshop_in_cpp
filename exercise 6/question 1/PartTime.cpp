/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#include "Employee.h"
#include "PartTime.h"
#include <string>
#include <iostream>
using namespace std;

PartTime::PartTime(string n, int i, int sen, int h, float p) : Employee(n, i, sen), hoursOfWork(h), payPerHour(p) //parameters ctor.
{
	salary(); //a function call to calculates the salary.
}

PartTime::PartTime() : Employee(), hoursOfWork(0), payPerHour(0)
{
	//empty ctor.
}

PartTime::PartTime(const PartTime& part) : Employee(part) //copy ctor.
{
	hoursOfWork = part.hoursOfWork;
	payPerHour = part.payPerHour;
}

void PartTime::salary() //calculates the salaray according the "pay" value of the class.
{
	pay = hoursOfWork * payPerHour; //for the part time employee.
}

istream& operator>>(istream& is, PartTime& part) //cin operator.
{
	cout << "Enter employee details:\n";
	is >> part.name >> part.id >> part.seniority >> part.hoursOfWork >> part.payPerHour;
	part.salary();
	if (part.id < 0 || part.seniority < 0 || part.hoursOfWork < 0 || part.payPerHour < 0)
		throw "ERROR\n";
	return is;
}


ostream& operator<<(ostream& os, const  PartTime& part) //cout operator.
{
	os << "Employee: " << part.name << endl;
	os << "Employee ID: " << part.id << endl;
	os << "Years Seniority: " << part.seniority << endl;
	os << "Hours: " << part.hoursOfWork << endl;
	os << "Salary per Month: " << part.pay << endl;
	return os;
}