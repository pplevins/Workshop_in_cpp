/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 3
The program using the learned class myString with implements,
and creating myString that is str is a combination of a two different myStrings.*/

//this is the class myString that learned with number of added operators and methods.

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString
{
private:
	char* str;
	void setString(const char* s);
public:
	// constructor
	MyString(const char* s = nullptr);
	MyString(const MyString& s);
	MyString(MyString&& s);// move ctor
	~MyString();
	// view function.
	char* getString() const;
	// modify function
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);
	// operators
	bool operator==(const MyString&) const;
	bool operator>(const MyString&) const; //added operator
	bool operator<(const MyString&) const; //added operator
	bool operator>=(const MyString&) const; //added operator
	bool operator<=(const MyString&) const; //added operator
	bool operator!=(const MyString&) const; //added operator
	char& operator[](int index); //added operator
	MyString operator+(const MyString&);
	MyString operator* (int);
	MyString insert(int index, const char* str); //added method
	int length() const;
	// print
	void print() const;
};