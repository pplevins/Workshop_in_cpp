/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
The program inputs two polygons and checks if they equel.*/

#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();
	friend istream& operator>>(istream& is, Point& my_point);
	float distance(Point p);
};