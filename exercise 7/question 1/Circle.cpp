/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(float myRadius) : Shape(1) //ctor
{
	setRadius(myRadius);
}

float Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(float myRadius)
{
	if (myRadius < 0)
		throw "invalid input\n";
	radius = myRadius;
}

float Circle::area()const
{
	const float pi = 3.14;
	float circleArea = (radius * radius) * pi;
	return circleArea;
}

bool Circle::isSpecial()const
{
	if (p->getX() == 0 && p->getY() == 0)
		return true;
	else
		return false;
}

void Circle::printSpecial()const
{
	if (isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}