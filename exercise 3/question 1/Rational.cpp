/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 1
The program creates object's class of rational numbers.*/

#include "Rational.h"

Rational::Rational() //empty ctor
{
	numerator = 1;
	denominator = 1;
}

Rational::Rational(int numer, int denom) //parameter ctor.
{
	numerator = numer;
	if (denom < 0) //when the input is a negative number.
	{
		denominator = (denom) * -1; //setting the - in the numerator or changing to positive rational.
		numerator *= -1;
	}
	if (denom == 0)
		denominator = 1; //setting to 1.
	if (denom > 0)
		denominator = denom; //setting to positive number.
}

Rational::Rational(const Rational& rat) //copy ctor.
{
	numerator = rat.numerator;
	denominator = rat.denominator;
}

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
	cout << numerator;
	if (denominator != 1)
		cout << "/" << denominator;
}

void Rational::reduce() //reducing the fraction.
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

Rational Rational::operator+(const Rational& rat) const
{
	Rational rat1;
	rat1.setNumerator((numerator * rat.denominator) + (rat.numerator * denominator)); //setting the numerator to the 2 added rationals.
	rat1.setDenominator(denominator * rat.denominator); //setting the denominator to the 2 added rationals.
	rat1.reduce(); //reducing the new rational.
	return rat1; //returning the new rational.
}

Rational Rational::operator-(const Rational& rat) const
{
	Rational rat1;
	rat1.setNumerator((numerator * rat.denominator) - (rat.numerator * denominator)); //setting the numerator to the 2 added rationals.
	rat1.setDenominator(denominator * rat.denominator); //setting the denominator to the 2 added rationals.
	rat1.reduce(); //reducing the new rational.
	return rat1; //returning the new rational.
}

Rational Rational::operator*(const Rational& rat) const
{
	Rational rat1;
	rat1.setNumerator(numerator * rat.numerator);
	rat1.setDenominator(denominator * rat.denominator);
	rat1.reduce(); //reducing the new rational.
	return rat1; //returning the new rational.
}

Rational Rational::operator/(const Rational& rat) const
{
	Rational rat1;
	rat1.setNumerator(numerator * rat.denominator);
	rat1.setDenominator(denominator * rat.numerator);
	rat1.reduce();
	return rat1;
}

Rational& Rational::operator++()
{
	numerator += denominator;
	return *this;
}

Rational Rational::operator++(int fake)
{
	Rational temp = *this;
	numerator += denominator;
	return temp;
}

Rational& Rational::operator--()
{
	numerator -= denominator;
	return *this;
}

Rational Rational::operator--(int fake)
{
	Rational temp = *this;
	numerator -= denominator;
	return temp;
}

bool Rational::operator>=(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduce();
	temp2.reduce();
	if (((float)temp1.numerator / (float)temp1.denominator) >= ((float)temp2.numerator / (float)temp2.denominator))
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduce();
	temp2.reduce();
	if (((float)temp1.numerator / (float)temp1.denominator) <= ((float)temp2.numerator / (float)temp2.denominator))
		return true;
	else
		return false;
}

bool Rational::operator>(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduce();
	temp2.reduce();
	if (((float)temp1.numerator / (float)temp1.denominator) > ((float)temp2.numerator / (float)temp2.denominator))
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduce();
	temp2.reduce();
	if (((float)temp1.numerator / (float)temp1.denominator) < ((float)temp2.numerator / (float)temp2.denominator))
		return true;
	else
		return false;
}

bool Rational::operator==(const Rational& rat) const
{
	Rational temp1 = *this;
	Rational temp2 = rat;
	temp1.reduce();
	temp2.reduce();
	return temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator;
}

bool Rational::operator!=(const Rational& rat) const
{
	return !(*this == rat);
}