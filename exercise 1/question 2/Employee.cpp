/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 2
The program inputs employees and searching the one with the highest salary and the one that brought the lowest income.*/

#include "Employee.h"
#include <cstring>
#include <iostream>
using namespace std;

void Employee::setId(int num)
{
	id = num;
}

void Employee::setName(char* myString)
{
	strncpy(name, myString, 21);
}

void Employee::setSalaryPerHour(float num)
{
	salaryPerHour = num;
}

void Employee::setHours(int num)
{
	hours = num;
}

void Employee::setOrganizationIncome(float num)
{
	organizationIncome = num;
}

int Employee::getId()
{
	return id;
}

char* Employee::getName()
{
	return name;
}

float Employee::getSalaryPerHour()
{
	return salaryPerHour;
}

int Employee::getHours()
{
	return hours;
}

float Employee::getOrganizationIncome()
{
	return organizationIncome;
}

float Employee::salary()
{
	float salarySum = 0, bonus = getOrganizationIncome();
	float salaryByHour = (getSalaryPerHour() * getHours()); //summing the basic salary (per hour).
	//conditions to calculate the bonus according to the organization income the employee brought.
	if (bonus <= 1000)
		salarySum = salaryByHour + (bonus * 0.1); //10%
	if (bonus > 1000 && bonus <= 2000)
		salarySum = salaryByHour + (1000 * 0.1) + ((bonus - 1000) * 0.15); //10% + 15%
	if (bonus > 2000 && bonus <= 4000)
		salarySum = salaryByHour + (1000 * 0.1) + (1000 * 0.15) + ((bonus - 2000) * 0.2); //10% + 15% + 20%
	if (bonus > 4000 && bonus <= 5000)
		salarySum = salaryByHour + (1000 * 0.1) + (1000 * 0.15) + (2000 * 0.2) + ((bonus - 4000) * 0.3); //10% + 15% + 20% + 30%
	if (bonus > 5000)
		salarySum = salaryByHour + (1000 * 0.1) + (1000 * 0.15) + (2000 * 0.2) + (1000 * 0.3) + ((bonus - 5000) * 0.4); //10% + 15% + 20% + 30% + 40%
	return salarySum;
}