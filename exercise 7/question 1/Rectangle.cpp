/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() :Shape(4)
{

	//no need for body. the father ctor gets the numOfPoints (4)
	//and then creates an array of 4 points
}

float Rectangle::area()const
{
	float s = (p[0].distance(p[1])) * (p[1].distance(p[2]));

	return s;
}

bool Rectangle::isSpecial()const
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[1].distance(p[2]);
	float side3 = p[2].distance(p[3]);
	float side4 = p[3].distance(p[0]);

	if (side1 == side2 && side1 == side3 && side1 == side4)
		return true;
	else
		return false;
}

void Rectangle::printSpecial()const
{
	if (isSpecial())
		cout << "Square with side length " << this->p[0].distance(this->p[1]) << endl;
}