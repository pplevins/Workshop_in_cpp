/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 3
The program input 3 circles and and checks points if they are in the circles.*/

//the standard header file for the Question
#pragma once
#include "Point.h"

const float PI = 3.14;

class Circle
{
private:
	Point center;
	int radius;
public:
	void setCenter(int x, int y);
	void setRadius(int myRadius);
	Point getCenter();
	int getRadius();
	float area();
	float perimeter();
	int onInOut(Point p);
};
