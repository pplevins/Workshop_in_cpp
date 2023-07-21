/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 2
The program inputs a book (class) to a library (binary search tree) and doing actions on it.*/

#include "Books.h"
#include <string>
#include <iostream>
using namespace std;

Books::Books()
{
	bookCode = 0;
	authorName = "";
	bookName = "";
}

bool Books::operator<(const Books& book) const
{
	//author name check
	if (authorName.compare(book.authorName) < 0)
		return true;
	else if (authorName.compare(book.authorName) > 0)
		return false;

	//book name check
	if (bookName.compare(book.bookName) < 0)
		return true;
	else if (bookName.compare(book.bookName) > 0)
		return false;
	
	//book code check
	if (bookCode < book.bookCode)
		return true;

	return false;
}

bool Books::operator>(const Books& book) const
{
	//author name check
	if (authorName.compare(book.authorName) > 0)
		return true;
	else if (authorName.compare(book.authorName) < 0)
		return false;

	//book name check
	if (bookName.compare(book.bookName) > 0)
		return true;
	else if (bookName.compare(book.bookName) < 0)
		return false;

	//book code check
	if (bookCode > book.bookCode)
		return true;

	return false;
}

bool Books::operator<=(const Books& book) const
{
	if (authorName.compare(book.authorName) <= 0)
		return true;
	return false;
}

bool Books::operator>=(const Books& book) const
{
	if (authorName.compare(book.authorName) >= 0)
		return true;
	return false;
}

bool Books::operator==(const Books& book) const
{
	return !authorName.compare(book.authorName) && !bookName.compare(book.bookName) && bookCode == book.bookCode;
}

bool Books::operator!=(const Books& book) const
{
	return !(*this == book);
}

ostream& operator<<(ostream& os, const Books& book)
{
	os << book.bookCode << " " << book.authorName << " " << book.bookName;
	return os;
}

istream& operator>>(istream& is, Books& book)
{
	is >> book.bookCode >> book.authorName >> book.bookName;
	return is;
}