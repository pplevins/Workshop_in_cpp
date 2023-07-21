/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 2
The program inputs employees and searching the one with the highest salary and the one that brought the lowest income.*/

#pragma once

#include <iostream>
using namespace std;

class Employee
{
private:
	int id;
	char name[21];
	float salaryPerHour;
	int hours;
	float organizationIncome;

public:
	void setId(int); //set functions.
	void setName(char*);
	void setSalaryPerHour(float);
	void setHours(int);
	void setOrganizationIncome(float);

	int getId(); //get functions.
	char* getName();
	float getSalaryPerHour();
	int getHours();
	float getOrganizationIncome();

	float salary(); //summing the total salary + bonus.
};
