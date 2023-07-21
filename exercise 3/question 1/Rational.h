/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 1
The program creates object's class of rational numbers.*/

#pragma once

#include <iostream>
using namespace std;

class Rational
{
private:
	int numerator; //fields of the rational number.
	int denominator;

public:
	Rational(); //empty ctor
	Rational(int numer, int denom); //parameter ctor.
	Rational(const Rational& rat); //copy ctor.
	void setNumerator(int); //setting the numerator.
	void setDenominator(int); //setting the denominator.
	int getNumerator(); //getting the numerator.
	int getDenominator(); //getting the denominator.
	void print();
	void  reduce(); //reducing the fraction.

	Rational operator+(const Rational& rat) const;
	Rational operator-(const Rational& rat) const;
	Rational operator*(const Rational& rat) const;
	Rational operator/(const Rational& rat) const;
	Rational& operator++();
	Rational operator++(int fake);
	Rational& operator--();
	Rational operator--(int fake);
	bool operator>=(const Rational& rat) const;
	bool operator<=(const Rational& rat) const;
	bool operator>(const Rational& rat) const;
	bool operator<(const Rational& rat) const;
	bool operator==(const Rational& rat) const;
	bool operator!=(const Rational& rat) const;
};