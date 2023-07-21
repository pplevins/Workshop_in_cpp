/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 1
The program creates object's class of rational numbers.*/

#include "Rational.h"

void Rational::setNumerator(int num) //setting the numerator.
{
	numerator = num;
}

void Rational::setDenominator(int num) //setting the denominator.
{
	if (num < 0) //when the input is a negative number.
	{
		denominator = (num) * -1; //setting the - in the numerator or changing to positive rational.
		numerator *= -1;
	}
	if (num == 0)
		denominator = 1; //setting to 1.
	if (num > 0)
		denominator = num; //setting to positive number.
}

int Rational::getNumerator() //getting the numerator.
{
	return numerator;
}

int Rational::getDenominator() //getting the denominator.
{
	return denominator;
}

void Rational::print() //printing the numerator and the denominator as a rational number.
{
	cout << numerator << "/" << denominator;
}

bool Rational::equal(Rational rat) // checking if 2 rational numbers are equal. 
{
	if (numerator == rat.numerator && denominator == rat.denominator) //when the 2 rationals are the same.
		return true;
	return false;
}

void Rational::reduction() //reducing the fraction.
{
	int num, gcd; //GCD = Greatest Common Divisor.
	if (numerator > 0)
	{
		if (numerator < denominator) //searching for the smallest number between the numerator and the denominator.
			num = numerator;
		else
			num = denominator;
	}
	else //if the numerator is a negative number.
		num = denominator;
	for (gcd = num; gcd > 1; gcd--) //searching the GCD.
	{
		if (numerator % gcd == 0 && denominator % gcd == 0) //true when gcd is dviding both the numerator and the denominator.
			break;
	}
	numerator /= gcd; //dividing the numerator.
	denominator /= gcd; //dividing the denominator.
}

Rational Rational::add(Rational rat)
{
	Rational rat1;
	rat1.setNumerator((numerator * rat.denominator) + (rat.numerator * denominator)); //setting the numerator to the 2 added rationals.
	rat1.setDenominator(denominator * rat.denominator); //setting the denominator to the 2 added rationals.
	rat1.reduction(); //reducing the new rational.
	return rat1; //returning the new rational.
}