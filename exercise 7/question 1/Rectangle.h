/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape
{
	//no need fields because of the inheritance
	//we only need to determines the number of pointes in the father ctor.

public:
	Rectangle(); //empty ctor

	virtual float area()const override;
	virtual bool isSpecial()const override;
	virtual void printSpecial()const override;
};