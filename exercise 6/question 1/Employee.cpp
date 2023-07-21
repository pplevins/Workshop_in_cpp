/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(string n, int i, int sen): name(n), id(i), seniority(sen), pay(0)
{
	//parameters ctor.
}

Employee::Employee() //empty ctor.
{
	name = {};
	id = 0;
	seniority = 0;
	pay = 0;
}

Employee::Employee(const Employee& emp) //copy ctor.
{
	name = emp.name;
	id = emp.id;
	seniority = emp.seniority;
	pay = emp.pay;
}

float Employee::salaryAfterBonus() //adding bonus to the salary.
{
	if (seniority > 5)
		return pay + pay * 0.25;
	else
		return pay + 500;
}

istream& operator>>(istream& is, Employee& emp) //cin operator.
{
	cout << "Enter employee details:\n";
	is >> emp.name, emp.id, emp.seniority, emp.pay;
	if (emp.id < 0 || emp.seniority < 0 || emp.pay < 0)
		throw "ERROR\n";
	return is;
}

ostream& operator<<(ostream& os, const Employee& emp) //cout operator.
{
	os << "Employee: " << emp.name << endl;
	os << "Employee ID: " << emp.id << endl;
	os << "Years Seniority: " << emp.seniority << endl;
	return os;
}