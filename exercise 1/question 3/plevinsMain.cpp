/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 3
The program input 3 circles and and checks points if they are in the circles.*/

#include "Circle.h"
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	//variables.
	Circle A, B, C;
	Point point;
	int x, y, r;
	char character;
	
	//inputting the circles, and after the perimeters and the areas.
	cout << "enter the center point and radius of 3 circles:\n";
	cin >> character >> x >> character >> y >> character >> r;
	A.setCenter(x, y);
	A.setRadius(r);
	cin >> character >> x >> character >> y >> character >> r;
	B.setCenter(x, y);
	B.setRadius(r);
	cin >> character >> x >> character >> y >> character >> r;
	C.setCenter(x, y);
	C.setRadius(r);
	cout << "perimeter:	A:" << A.perimeter() << " B:" << B.perimeter() << " C:" << C.perimeter() << endl;
	cout << "area: A:" << A.area() << " B:" << B.area() << " C:" << C.area() << endl;
	
	int counterA = 0, counterB = 0, counterC = 0;
	cout << "enter points until (0,0):\n";
	cin >> character >> x >> character >> y >> character;
	while (x != 0 || y != 0) //stops only when the user input the origin point (0,0)
	{
		point.setX(x);
		point.setY(y);
		if (A.onInOut(point) <= 0) //when the point is in or on the circle A.
			counterA++;
		if (B.onInOut(point) <= 0) //when the point is in or on the circle B.
			counterB++;
		if (C.onInOut(point) <= 0) //when the point is in or on the circle C.
			counterC++;
		cin >> character >> x >> character >> y >> character;
	}
	cout << "num of points in circle: A:" << counterA << " B:" << counterB << " C:" << counterC;
	return 0;
}

/*Run sample:
enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter: A:18.84 B:12.56 C:12.56
area: A:28.26 B:12.56 C:12.56
enter points until (0,0):
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle: A:2 B:2 C:0*/