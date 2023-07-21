/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangel::Triangel() :Shape(3)
{
	//no need for body. the father ctor gets the numOfPoints (3)
	//and then creates an array of 3 points
}

float Triangel::area()const
{

	//determines the sodes of the triangel
	float a = p[0].distance(p[1]);
	float b = p[1].distance(p[2]);
	float c = p[2].distance(p[0]);

	//Law of cosines
	float cos_gama = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
	float gama_angel = acos(cos_gama); // gama = arc-cos(gama);

	//calculation of an erea of a triangel by the law of cosines
	float s = (a * b * sin(gama_angel)) / 2;

	return s;
}

bool Triangel::isSpecial()const
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[1].distance(p[2]);
	float side3 = p[2].distance(p[0]);

	if (side1 == side2 && side1 == side3 && side2 == side3)
		return true;
	else
		return false;
}

void Triangel::printSpecial()const
{
	if (isSpecial())
		cout << "An isosceles triangle with a side length " << this->p[0].distance(this->p[1]) << endl;
}