/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 4
The program manages bank accounts and deals with errors using exception (try & catch).*/

#include <iostream>
#include "Clock.h"
using namespace std;

Clock::Clock(int h, int m, int s)
{
	if (s < 0)
		throw "Invalid time - negative number of seconds\n";
	if (s > 59)
		throw "Invalid time - more than 60 seconds\n";
	if (m < 0)
		throw "Invalid time - negative number of minutes\n";
	if (m > 59)
		throw "Invalid time - more than 60 minutes\n";
	if (h < 0)
		throw "Invalid time - negative number of hours\n";
	if (h > 23)
		throw "Invalid time - more than 60 hours\n";
	hour = h;
	minute = m;
	second = s;
}

void Clock::setSecond(int s)
{
	if (s < 0)
		throw "Invalid time - negative number of seconds\n";
	if (s > 59)
		throw "Invalid time - more than 60 seconds\n";
	second = s;
}

void Clock::setMinute(int m)
{
	if (m < 0)
		throw "Invalid time - negative number of minutes\n";
	if (m > 59)
		throw "Invalid time - more than 60 minutes\n";
	minute = m;
}

void Clock::setHour(int h)
{
	if (h < 0)
		throw "Invalid time - negative number of hours\n";
	if (h > 23)
		throw "Invalid time - more than 60 hours\n";
	hour = h;
}

Clock Clock::operator+=(int seconds)
{
	int s = 0, m;
	second += seconds;
	if (second > 59)
	{
		s = second / 60;
		second %= 60;
	}
	else
		return *this;
	minute += s;
	if (minute > 59)
	{
		m = minute / 60;
		minute %= 60;
	}
	else
		return *this;
	hour += m;
	if (hour > 23)
		hour = 0;
	return *this;
}

ostream& operator<<(ostream& os, const Clock& ms)
{
	if (ms.hour < 10)
		os << '0';
	os << ms.hour;
	os << ":";
	if (ms.minute < 10)
		os << '0';
	os << ms.minute;
	os << ":";
	if (ms.second < 10)
		os << '0';
	os << ms.second;
	os << endl;
	return os;
}

istream& operator>>(istream& is, Clock& ms)
{
	Clock t(0, 0, 0);
	char ch;
	ms.second = ms.minute = ms.hour = 0;
	is >> t.second >> ch >> t.minute >> ch >> t.hour;
	if (t.second < 0)
		throw "Invalid time - negative number of seconds\n";
	if (t.second > 59)
		throw "Invalid time - more than 60 seconds\n";
	if (t.minute < 0)
		throw "Invalid time - negative number of minutes\n";
	if (t.minute > 59)
		throw "Invalid time - more than 60 minutes\n";
	if (t.hour < 0)
		throw "Invalid time - negative number of hours\n";
	if (t.hour > 23)
		throw "Invalid time - more than 60 hours\n";
	ms.second = t.second;
	ms.minute = t.minute;
	ms.hour = t.hour;
	return is;
}