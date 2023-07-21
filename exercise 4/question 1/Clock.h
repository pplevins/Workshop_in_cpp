/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 4
The program manages bank accounts and deals with errors using exception (try & catch).*/

#pragma once

#include <iostream>
using namespace std;

class Clock
{
	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	Clock(int, int, int);
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	Clock operator+=(int second);
	friend ostream& operator<<(ostream& os, const Clock& ms);
	friend istream& operator>>(istream& is, Clock& ms);
};