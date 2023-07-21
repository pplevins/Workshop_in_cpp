/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 3
The program input 3 circles and and checks points if they are in the circles.*/

#include "Circle.h"
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

//sets/gets.
void Circle::setCenter(int x, int y)
{
	center.setX(x);
	center.setY(y);
}

void Circle::setRadius(int myRadius)
{
	radius = myRadius;
}

Point Circle::getCenter()
{
	return center;
}

int Circle::getRadius()
{
	return radius;
}

float Circle::area()
{
	return PI * pow(radius, 2); //area calculation: PI * radius ^ 2.
}

float Circle::perimeter()
{
	return 2 * PI * radius; //perimeter calculation: 2PI * radius.
}

int Circle::onInOut(Point p)
{
	//according to the circle equation: (x - a)^2 + (y - b)^2 = radius ^ 2.
	if ((pow(p.getX() - center.getX(), 2)) + (pow(p.getY() - center.getY(), 2)) > pow(radius, 2))
		return 1; //the point is outside the circle
	if ((pow(p.getX() - center.getX(), 2)) + (pow(p.getY() - center.getY(), 2)) == pow(radius, 2))
		return 0; //the point is on the circle.
	if ((pow(p.getX() - center.getX(), 2)) + (pow(p.getY() - center.getY(), 2)) < pow(radius, 2))
		return -1; //the point is inside the circle.
}