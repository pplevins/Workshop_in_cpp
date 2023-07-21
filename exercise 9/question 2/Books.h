/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 2
The program inputs a book (class) to a library (binary search tree) and doing actions on it.*/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Books
{
private:
	int bookCode;
	string authorName;
	string bookName;

public:
	Books();
	bool operator<(const Books&) const;
	bool operator>(const Books&) const;
	bool operator<=(const Books&) const;
	bool operator>=(const Books&) const;
	bool operator==(const Books&) const;
	bool operator!=(const Books&) const;

	friend ostream& operator<<(ostream& os, const Books& book);
	friend istream& operator>>(istream& is, Books& book);
};