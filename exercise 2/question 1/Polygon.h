/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 1
The program inputs two polygons and checks if they equel.*/

#pragma once
#include "Point.h"
class Polygon
{
private:
	Point* vertexes;
	int vertexesNum;
public:
	Polygon(); //empty ctor.
	Polygon(int num); //one parameter ctor.
	Polygon(const Polygon& poly); //copy ctor.
	~Polygon(); //dtor.
	//gets
	Point* getVertexes();
	int getVertexesNum();
	void addPoint(Point p, int index); //adding point to the polygon.
	float perimeter(); //returning the perimeter of the polygon.
	bool equal(Polygon poly1); //checking if this polygon is equal to the other.
};