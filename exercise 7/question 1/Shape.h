/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Shape {

protected:
	int numOfPoints;
	Point* p; //pointer to the point array

public:
	Shape(); //empty ctor
	Shape(int points); //parameter ctor
	Shape(const Shape& myShape); //copy ctor
	Shape(Shape&& myShape); //move ctor
	virtual~Shape(); //virtual dtor
	friend ostream& operator<<(ostream& os, const Shape& my_shape);

	virtual float area()const = 0; //area calculation
	virtual bool isSpecial()const = 0;
	virtual void printSpecial()const = 0;
};
