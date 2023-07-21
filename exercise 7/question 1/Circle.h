/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape
{
protected:
	float radius;

public:
	Circle(float myRadius); //ctor
	float getRadius(); //get
	void setRadius(float myRadius); //set

	//virtual methods
	virtual float area()const override;
	virtual bool isSpecial()const override;
	virtual void printSpecial()const override;
};