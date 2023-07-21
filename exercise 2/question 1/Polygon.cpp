/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 1
The program inputs two polygons and checks if they equel.*/

#include "Point.h"
#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon() //empty ctor.
{
	vertexes = nullptr;
	vertexesNum = 0;
	cout << "in empty constructor\n";
}

Polygon::Polygon(int num) //one parameter ctor.
{
	vertexesNum = num;
	vertexes = new Point[vertexesNum];
	cout << "in one parameter constructor\n";
}

Polygon::Polygon(const Polygon& poly) //copy ctor.
{
	vertexesNum = poly.vertexesNum;
	vertexes = new Point[vertexesNum];
	for (int i = 0; i < vertexesNum; i++)
	{
		vertexes[i] = poly.vertexes[i];
	}
	cout << "in copy constructor\n";
}

Polygon::~Polygon() //dtor.
{
	if (vertexes)
		delete[] vertexes;
	vertexes = nullptr;
	cout << "in destructor\n";
}

//gets.
Point* Polygon::getVertexes()
{
	Point* vertexes1 = new Point[vertexesNum];
	for (int i = 0; i < vertexesNum; i++)
	{
		vertexes1[i] = vertexes[i];
	}
	vertexes = vertexes1;
	return vertexes;
}

int Polygon::getVertexesNum()
{
	return vertexesNum;
}

void Polygon::addPoint(Point p, int index) //adding point to the polygon.
{
	*(vertexes + index) = p;
}

float Polygon::perimeter() //returning the perimeter of the polygon.
{
	float distanceSum = 0;
	for (int i = 0; i < vertexesNum - 1; i++)
	{
		distanceSum += vertexes[i].distance(vertexes[i + 1]);
	}
	if (vertexesNum != 0)
		distanceSum += vertexes[0].distance(vertexes[vertexesNum - 1]);
	return distanceSum;
}

bool Polygon::equal(Polygon poly) //checking if this polygon is equal to the other.
{
	int counter = 0;
	if (vertexesNum != poly.getVertexesNum())
		return false;
	for (int i = 0; i < vertexesNum; i++)
	{
		for (int j = 0; j < vertexesNum; j++)
		{
			if (vertexes[i].getX() == poly.vertexes[j].getX() && vertexes[i].getY() == poly.vertexes[j].getY())
				counter++;
		}
	}
	if (counter != vertexesNum)
		return false;
	return true;
}