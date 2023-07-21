/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 2
The program inputs 3 vectors, and by switch operation makes actions on them.*/

#pragma once
class Vector
{
private:
	int* data;
	int capacity;
	int size;
public:
	Vector();
	Vector(int size1);
	Vector(const Vector& vec);
	~Vector();
	int getCapacity();
	int getSize();
	void print();
	void assign(Vector vec);
	bool isEqual(Vector vec);
	int& at(int index);
	int scalmul(Vector vec);
	Vector strnewcat(Vector vec);
	void clear();
	void delLast();
	void insert(int val);
};