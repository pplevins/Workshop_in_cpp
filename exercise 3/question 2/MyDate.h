/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 2
The program creates object's class of date.*/

#pragma once

class MyDate
{
	int day;
	int month;
	int year;

public:
	MyDate(int d = 1, int m = 1, int y = 1920); //parameter ctor with defult values
	MyDate(const MyDate& MyD); //copy ctor
	void setDate(int d, int m, int y); //set
	void print();

	//operator= exist in defult.
	MyDate& operator++(); //pre++
	MyDate operator++ (int fake); //post++
	bool operator>(const MyDate& MyD) const;
	bool operator<(const MyDate& MyD) const;
	bool operator==(const MyDate& MyD) const;
};