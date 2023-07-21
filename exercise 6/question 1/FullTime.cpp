/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#include "FullTime.h"
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

FullTime::FullTime(string n, int i, int sen, float sal) : Employee(n, i, sen), salaryPerYear(sal) //parameters ctor.
{
	salary(); //a function call to calculates the salary.
}

FullTime::FullTime() : Employee(), salaryPerYear(0)
{
	//empty ctor.
}

FullTime::FullTime(const FullTime& full) : Employee(full) //copy ctor.
{
	salaryPerYear = full.salaryPerYear;
}

void FullTime::salary() //calculates the salaray according the "pay" value of the class.
{
	pay = salaryPerYear / 12; //for the full time employee.
}

istream& operator>>(istream& is, FullTime& full) //cin operator.
{
	cout << "Enter employee details:\n";
	is >> full.name >> full.id >> full.seniority >> full.salaryPerYear;
	full.salary();
	if (full.id < 0 || full.seniority < 0 || full.salaryPerYear < 0)
		throw "ERROR\n";
	return is;
}

ostream& operator<<(ostream& os, const FullTime& full) //cout operator.
{
	os << "Employee: " << full.name << endl;
	os << "Employee ID: " << full.id << endl;
	os << "Years Seniority: " << full.seniority << endl;
	os << "Salary per Month: " << full.pay << endl;
	return os;
}