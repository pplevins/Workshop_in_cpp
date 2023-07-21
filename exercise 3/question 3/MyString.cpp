/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 3
The program using the learned class myString with implements,
and creating myString that is str is a combination of a two different myStrings.*/

#include "MyString.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

MyString::MyString(const char* s)
{
	setString(s);
}

MyString::MyString(const MyString& s)
{
	setString(s.getString());
}

MyString::MyString(MyString&& s) //move ctor
{
	str = s.str;
	s.str = nullptr;
	cout << "move ctor\n"; //printing
}

MyString::~MyString()
{
	if (str) delete[] str;
	str = nullptr;
}

char* MyString::getString() const
{
	return str;
}

void MyString::setString(const char* s)
{
	if (s) {
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	else str = nullptr;
}

MyString& MyString::operator=(const MyString& s) //move assign
{
	if (str)
		delete[] str;
	setString(s.getString());
	cout << "move assign\n"; //printing
	return *this;
}

MyString& MyString::operator=(MyString&& s) //move assign
{
	if (str)
		delete[] str;
	str = s.str;
	s.str = nullptr;
	cout << "move assign\n"; //printing
	return *this;
}

MyString MyString:: operator+(const MyString& s)
{
	int sizeI = strlen(str);
	int sizeII = strlen(s.getString());
	char* temp = new char[sizeI + sizeII + 1];
	strcpy(temp, str);
	strcpy(temp + sizeI, s.getString());
	MyString x(temp);
	return x;
}

MyString MyString::operator*(const int num)
{
	char* temp;
	int len = strlen(str);
	temp = new char[len * num + 1];
	for (int i = 0; i < num; i++)
		strcpy(temp + i * len, str);
	MyString s(temp);
	return s;
}

bool MyString::operator==(const MyString& s) const
{
	return !strcmp(str, s.getString());
}

bool MyString::operator>(const MyString& s) const //added operator
{
	int result = strcmp(str, s.getString());
	if (result > 0)
		return true;
	else
		return false;
}

bool MyString::operator<(const MyString& s) const //added operator
{
	int result = strcmp(str, s.getString());
	if (result < 0)
		return true;
	else
		return false;
}

bool MyString::operator>=(const MyString& s) const //added operator
{
	int result = strcmp(str, s.getString());
	if (result >= 0)
		return true;
	else
		return false;
}

bool MyString::operator<=(const MyString& s) const //added operator
{
	int result = strcmp(str, s.getString());
	if (result <= 0)
		return true;
	else
		return false;
}

bool MyString::operator!=(const MyString& s) const //added operator
{
	return strcmp(str, s.getString());
}

char& MyString::operator[](int index) //added operator
{
	if (index >= length())
	{
		cout << "ERROR\n";
		exit(0);
	}
	return str[index];
}

int MyString::length() const
{
	return strlen(str);
}

MyString MyString::insert(int index, const char* str1) //added method
{
	MyString new1;
	if (index > length()) //when trying to insert in wrong index
	{
		cout << "ERROR\n";
		return new1;
	}
	int len = length() + strlen(str1);
	new1.str = new char[len + 1];
	strncpy(new1.str, str1, index);
	new1.str[index] = '\0';
	strcat(new1.str, str);
	strcat(new1.str, str1 + index);
	MyString new2(new1);
	return new2;
}

void MyString::print() const
{
	if (str) cout << str << endl;
}