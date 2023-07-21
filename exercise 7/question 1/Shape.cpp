/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	numOfPoints = 0;
	p = NULL;
}

Shape::Shape(int points)
{
	numOfPoints = points;
	if (points < 0)
		return;
	p = new Point[numOfPoints];
	cout << "Enter values of " << numOfPoints << " " << "points: " << endl;

	Point myPoint;
	for (int i = 0; i < numOfPoints; i++)
	{
		cin >> myPoint;
		this->p[i] = myPoint;
	}
}

Shape::Shape(const Shape& myShape)
{
	numOfPoints = myShape.numOfPoints;
	p = new Point[myShape.numOfPoints];
	for (int i = 0; i < numOfPoints; i++)
		*(p + i) = *(myShape.p + i);
}

Shape::Shape(Shape&& myShape)
{
	numOfPoints = myShape.numOfPoints;
	p = myShape.p;
	myShape.p = nullptr;
}

Shape::~Shape()
{
	if (p)
		delete[]p;
	p = nullptr;
}

ostream& operator<<(ostream& os, const Shape& myShape)
{
	cout << endl;
	cout << "points: ";

	for (int i = 0; i < myShape.numOfPoints; i++)
		os << "(" << myShape.p[i].getX() << "," << myShape.p[i].getY() << ")" << " ";

	return os;
}