/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 1
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
	void setNumerator(int); //setting the numerator.
	void setDenominator(int); //setting the denominator.
	int getNumerator(); //getting the numerator.
	int getDenominator(); //getting the denominator.
	void print();
	bool equal(Rational); // checking if 2 rational numbers are equal. 
	void reduction(); //reducing the fraction.
	Rational add(Rational); //adding two rational numbers to 1.
};