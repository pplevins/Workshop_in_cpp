/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 1
The program inputs two polygons and checks if they equel.*/

#pragma once
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
	float distance(Point p);
	Point(); //empty ctor
	Point(int myX, int myY); //parameters ctor.
	Point(const Point& p); //copy ctor.
};