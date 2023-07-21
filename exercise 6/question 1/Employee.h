/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 1
The program calculates the salary of two kinds of Employees, using two classes inhariting from another class.*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
protected: //values
	string name;
	int id;
	int seniority;
	float pay;

public: //methods
	Employee(string n, int i, int sen); //parameters ctor.
	Employee(); //empty ctor.
	Employee(const Employee& emp); //copy ctor.
	float salaryAfterBonus(); //adding bonus to the salary.
	friend istream& operator>>(istream& is, Employee& emp); //cin operator.
	friend ostream& operator<<(ostream& os, const Employee& emp); //cout operator.
};