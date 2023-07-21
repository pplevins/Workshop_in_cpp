/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 1
The program inputs two polygons and checks if they equel.*/

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

float Point::distance(Point p) //returning the distance betweem this point and the next one in the polygon.
{
	return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}

Point::Point() //empty ctor.
{
	int x = 0;
	int y = 0;
}

Point::Point(int myX, int myY) //parameter ctor.
{
	x = myX;
	y = myY;
}

Point::Point(const Point& p) //copy ctor.
{
	x = p.x;
	y = p.y;
}