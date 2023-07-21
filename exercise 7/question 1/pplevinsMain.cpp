/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 7
Polymorphism - the program creates an array of various shapes and checks their erea and speciality.*/

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE };
int main()
{


	int numShapes, choice;
	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;
	Shape** shapes = new Shape * [numShapes];
	for (int i = 0; i < numShapes; i++) {
		cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
		cin >> choice;
		switch (choice) {
		case CIRCLE:
			float radius;
			cout << "Enter radius :\n";
			cin >> radius;
			shapes[i] = new Circle(radius);
			break;
		case TRIANGLE:
			shapes[i] = new Triangel;
			break;
		case RECTANGLE:
			shapes[i] = new Rectangle;
			break;
		default:
			cout << "invalid input\n";
			i--;
		}

	}

	for (int i = 0; i < numShapes; i++){
		cout << *shapes[i];
		cout << " area is: " << shapes[i]->area() << endl;
		if (shapes[i]->isSpecial())
			shapes[i]->printSpecial();
	}

	return 0;
}