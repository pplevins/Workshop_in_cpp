/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 3
The program using the learned class myString with implements,
and creating myString that is str is a combination of a two different myStrings.*/

#include "MyString.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char c1[10], c2[10];
	char cInput;
	int index;

	cin >> c1 >> c2;
	cin >> index;
	MyString myS1(c1);
	MyString myS2(c2);
	MyString myS3;


	if (myS1 > myS2)
		cout << "a>b" << endl;
	else if (myS1 < myS2)
		cout << "a<b" << endl;
	else
		cout << "a=b" << endl;

	myS3 = myS1.insert(index, c2);
	if (!myS3.getString())
	{
		cout << "ERROR\n";
		return 0;
	}
	myS3.print();
	cin >> cInput >> index;
	myS3[index] = cInput;
	myS3.print();
	return 0;
}

/*Run sample:

A.
World
Hello
5
a>b
move ctor
move assign
HelloWorld
!
5
Hello!orld

B.
Hello
Hello
2
a=b
move ctor
move assign
HeHellollo
h
2
Hehellollo

C.
Hello
World
2
a<b
move ctor
move assign
WoHellorld
?
10
ERROR

D.
Hello
World
0
a<b
move ctor
move assign
HelloWorld
-
6
HelloW-rld

E.
Hello
World
8
a<b
ERROR
move ctor
move assign
ERROR*/