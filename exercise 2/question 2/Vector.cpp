/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 2 Question 2
The program inputs 3 vectors, and by switch operation makes actions on them.*/

#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;
Vector::Vector() //empty ctor.
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

Vector::Vector(int size1) //one parameter ctor.
{
	data = nullptr;
	capacity = pow(2, ceil(log(size1) / log(2)));
	data = new int[capacity];
	size = 0;
}

Vector::Vector(const Vector& vec) //copy ctor.
{
	capacity = vec.capacity;
	size = vec.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = vec.data[i];
	}
}

Vector::~Vector() //dtor.
{
	if (data)
		//delete[] data;
	data = nullptr;
}

//gets.
int Vector::getCapacity()
{
	return capacity;
}

int Vector::getSize()
{
	return size;
}

void Vector::print() //printing the vector.
{
	cout << "capacity:" << " " << capacity << " size:" << " " << size << " " << "values:" << " ";
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void Vector::assign(Vector vec) //= operator.
{
	capacity = vec.capacity;
	size = vec.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = vec.data[i];
	}
}

bool Vector::isEqual(Vector vec) //cheking if two vectors are equal.
{
	int count = 0;
	if (size != vec.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; ++j)
		{
			if (data[i] == vec.data[j])
				count++;
		}
	}
	if (count == size)
		return true;
	return false;
}

int& Vector::at(int index) //returning the value in the requested index.
{
	if (index >= size || index < 0)
	{
		cout << "ERROR" << endl;
		index = 0;
	}
	return data[index];
}

int Vector::scalmul(Vector vec) //scalar multyply.
{
	int sum = 0;
	if (size != vec.size)
	{
		cout << "ERROR" << endl;
		return -1;
	}
	for (int i = 0; i < size; i++)
		sum += data[i] * vec.data[i];
	return sum;
}

Vector Vector::strnewcat(Vector vec) //making two vectors into 1.
{
	Vector vec1;
	vec1.capacity = capacity + vec.capacity;
	vec1.capacity = pow(2, ceil(log(vec1.capacity) / log(2)));
	vec1.data = new int[vec1.capacity];
	for (int i = 0; i < size; i++)
	{
		vec1.data[i] = data[i];
	}
	int j = 0;
	vec1.size = size + vec.size;
	for (int i = size; i < vec1.size; i++)
	{
		vec1.data[i] = vec.data[j];
		j++;
	}
	return vec1;
}

void Vector::clear() //clearing the values in the vector.
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
	size = 0;
}

void Vector::delLast() //deleting the last velue in the vector.
{
	if (size == 0)
	{
		cout << "ERROR" << endl;
		return;
	}
	data[size - 1] = 0;
	size--;
}

void Vector::insert(int val) //inserting new value in the vector.
{
	if (size == 0)
	{
		data[0] = val;
		size++;
		return;
	}
	if (size < capacity)
	{
		data[size] = val;
		size++;
	}
	else
	{
		capacity *= 2;
		int* data1 = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			data1[i] = data[i];
		}

		data1[size] = val;
		size++;
		//delete[] data;
		data = data1;
	}
}