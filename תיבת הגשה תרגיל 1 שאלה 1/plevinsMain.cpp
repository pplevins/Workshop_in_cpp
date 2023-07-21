/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 1
The program creates object's class of rational numbers.*/

#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;

int main() //the standard main for the program.
{
	int num1, num2;
	char junk;

	cout << "part 1.  set/get" << endl;
	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat1;
	rat1.setNumerator(num1);
	rat1.setDenominator(num2);
	cout << "numerator: " << rat1.getNumerator() << endl;
	cout << "denominator: " << rat1.getDenominator() << endl;

	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat2;
	rat2.setNumerator(num1);
	rat2.setDenominator(num2);
	rat2.print();
	cout << endl << endl;

	cout << "part 2.  equals" << endl;
	if (rat1.equal(rat2))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;
	cout << endl << endl;

	cout << "part 3. add" << endl;
	Rational ans = rat1.add(rat2);
	rat1.print();
	cout << " + ";
	rat2.print();
	cout << "= ";
	ans.print();
	cout << endl;

	return 0;
}

/*Run sample:

sample A.
part 1.  set/get
enter a rational number:
2/12
numerator: 2
denominator: 12
enter a rational number:
4/12
4/12

part 2.  equals
The two numbers are different


part 3. add
2/12 + 4/12= 1/2

sample B.
part 1.  set/get
enter a rational number:
5/25
numerator: 5
denominator: 25
enter a rational number:
5/25
5/25

part 2.  equals
The two numbers are equal


part 3. add
5/25 + 5/25= 2/5*/