/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

//sets & gets.
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

istream& operator>>(istream& is, Point& my_point)
{
	char tav;
	is >> tav >> my_point.x >> tav >> my_point.y >> tav;

	return is;
}

float Point::distance(Point p) //returning the distance betweem this point and the next one in the polygon.
{
	return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}