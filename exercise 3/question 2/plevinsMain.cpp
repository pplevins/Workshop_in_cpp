/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 3 Question 2
The program creates object's class of date.*/

#include "MyDate.h"
#include <iostream>
using namespace std;

enum OPERATOR
{
	EXIT, SET_DATE, ADD_PRE, ADD_POST, ASSIGNMENT,
	GREATER, SMALLER, EQUAL
};

int main()
{
	//setting the date.
	int inDay, inMonth, inYear, action;
	char junk;
	cout << "Enter a date\n";
	cin >> inDay >> junk >> inMonth >> junk >> inYear;
	MyDate date1(inDay, inMonth, inYear);
	date1.print();
	cout << endl;
	
	//starting actions.
	MyDate date2 = date1;
	cout << "Enter a code\n";
	cin >> action;
	while (action != EXIT)
	{
		switch (action)
		{
		case SET_DATE:
			cout << "Enter a date\n";
			cin >> inDay >> junk >> inMonth >> junk >> inYear;
			date1.setDate(inDay, inMonth, inYear);
			date1.print();
			cout << endl;
			break;
		
		case ADD_PRE:
			date2 = date1;
			date1 = ++date2;
			date1.print();
			cout << endl;
			date2.print();
			cout << endl;
			break;
		
		case ADD_POST:
			date2 = date1;
			date1 = date2++;
			date1.print();
			cout << endl;
			date2.print();
			cout << endl;
			break;

		case ASSIGNMENT:
			cout << "Enter a date\n";
			cin >> inDay >> junk >> inMonth >> junk >> inYear;
			date2.setDate(inDay, inMonth, inYear);
			date1 = date2;
			date1.print();
			cout << endl;
			break;

		case GREATER:
			cout << "Enter a date\n";
			cin >> inDay >> junk >> inMonth >> junk >> inYear;
			date2.setDate(inDay, inMonth, inYear);
			date1.print();
			cout << " > ";
			date2.print();
			cout << " : ";
			if (date1 > date2)
				cout << "true\n";
			else
				cout << "false\n";
			break;

		case SMALLER:
			cout << "Enter a date\n";
			cin >> inDay >> junk >> inMonth >> junk >> inYear;
			date2.setDate(inDay, inMonth, inYear);
			date1.print();
			cout << " < ";
			date2.print();
			cout << " : ";
			if (date1 < date2)
				cout << "true\n";
			else
				cout << "false\n";
			break;

		case EQUAL:
			cout << "Enter a date\n";
			cin >> inDay >> junk >> inMonth >> junk >> inYear;
			date2.setDate(inDay, inMonth, inYear);
			date1.print();
			cout << " == ";
			date2.print();
			cout << " : ";
			if (date1 == date2)
				cout << "true\n";
			else
				cout << "false\n";
			break;

		default:
			break;
		}
		cout << "Enter a code\n";
		cin >> action;
	}
}

/*Run sample:
Enter a date
-5/12/2012
Error day
1/12/2012
Enter a code
1
Enter a date
5/7/2010
5/7/2010
Enter a code
2
6/7/2010
6/7/2010
Enter a code
3
6/7/2010
7/7/2010
Enter a code
4
Enter a date
14/7/2010
14/7/2010
Enter a code
5
Enter a date
14/7/2010
14/7/2010 > 14/7/2010 : false
Enter a code
7
Enter a date
14/7/2010
14/7/2010 == 14/7/2010 : true
Enter a code
0*/