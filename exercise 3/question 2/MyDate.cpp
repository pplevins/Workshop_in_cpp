/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 2
The program creates object's class of date.*/

#include "MyDate.h"
#include <iostream>
using namespace std;

MyDate::MyDate(int d, int m, int y) //parameter ctor with defult values
{
	if (d < 1 || d > 30)
	{
		cout << "Error day\n";
		day = 1;
	}
	else
		day = d;
	if (m < 1 || m > 12)
	{
		cout << "Error month\n";
		month = 1;
	}
	else
		month = m;
	if (y < 1920)
	{
		cout << "Error year\n";
		year = 1920;
	}
	else
		year = y;
}

MyDate::MyDate(const MyDate& MyD) //copy ctor
{
	day = MyD.day;
	month = MyD.month;
	year = MyD.year;
}

void MyDate::setDate(int d, int m, int y) //set
{
	//integrity check. if not true, no changes made.
	if (d < 1 || d > 30)
		return;
	if (m < 1 || m > 12)
		return;
	if (y < 1920)
		return;
	day = d;
	month = m;
	year = y;
}

void MyDate::print()
{
	cout << day << "/" << month << "/" << year; //format 1/1/1920
}

MyDate& MyDate::operator++() //pre++
{
	if (day == 30) //if end of the month
	{
		day = 1;
		if (month == 12) //if end of the year
		{
			month = 1;
			++year;
		}
		else
			++month;
	}
	else
		++day;
	return *this;
}

MyDate MyDate::operator++ (int fake) //post++
{
	MyDate temp = *this;
	if (day == 30) //if end of the month
	{
		day = 1;
		if (month == 12) //if end of the year
		{
			month = 1;
			year++;
		}
		else
			month++;
	}
	else
		day++;
	return temp;
}

bool MyDate::operator>(const MyDate& MyD) const
{
	if (year > MyD.year)
		return true;
	if (year == MyD.year)
	{
		if (month > MyD.month)
			return true;
		if (month == MyD.month)
		{
			if (day > MyD.day)
				return true;
		}
	}
	return false;
}

bool MyDate::operator<(const MyDate& MyD) const
{
	if (year < MyD.year)
		return true;
	if (year == MyD.year)
	{
		if (month < MyD.month)
			return true;
		if (month == MyD.month)
		{
			if (day < MyD.day)
				return true;
		}
	}
	return false;
}

bool MyDate::operator==(const MyDate& MyD) const
{
	return ((day == MyD.day) && (month == MyD.month) && (year == MyD.year));
}