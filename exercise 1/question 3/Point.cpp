/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 3
The program input 3 circles and and checks points if they are in the circles.*/

#include "Point.h"
#include <iostream>
using namespace std;

//only sets/gets.
void Point::setX(int myX)
{
	x = myX;
}

void Point::setY(int myY)
{
	y = myY;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}