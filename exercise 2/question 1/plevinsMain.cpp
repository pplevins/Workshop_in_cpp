/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 1
The program inputs two polygons and checks if they equel.*/

#include "Point.h"
#include "Polygon.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int sides = 0, x, y;
	char character;
	Point point1;
	cout << "enter number of sides:\n";
	cin >> sides;
	Polygon poly1(sides);
	cout << "enter the point values:\n";
	for (int i = 0; i < sides; i++)
	{
		cin >> character >> x >> character >> y >> character;
		point1.setX(x);
		point1.setY(y);
		poly1.addPoint(point1, i);
	}
	cout << "enter number of sides:\n";
	cin >> sides;
	Polygon poly2(sides);
	cout << "enter the point values:\n";
	for (int i = 0; i < sides; i++)
	{
		cin >> character >> x >> character >> y >> character;
		point1.setX(x);
		point1.setY(y);
		poly2.addPoint(point1, i);
	}
	if (poly1.equal(poly2))
	{
		cout << "equal\n";
		cout << "perimeter: " << round(poly1.perimeter()) << endl;
	}
	else
	{
		cout << "not equal\n";
		cout << "perimeter: " << round(poly1.perimeter()) << endl;
		cout << "perimeter: " << round(poly2.perimeter()) << endl;
	}
	return 0;
}

/*Run sample:
A.
enter number of sides:
3
in one parameter constructor
enter the point values:
(10,10)(10,14)(13,10)
enter number of sides:
3
in one parameter constructor
enter the point values:
(13,10)(10,10)(10,14)
in copy constructor
in destructor
equal
perimeter: 12
in destructor
in destructor

B.
enter number of sides:
4
in one parameter constructor
enter the point values:
(0,0)(0,2)(2,2)(2,0)
enter number of sides:
3
in one parameter constructor
enter the point values:
(1,1)(2,0)(3,1)
in copy constructor
in destructor
not equal
perimeter: 8
perimeter: 5
in destructor
in destructor*/