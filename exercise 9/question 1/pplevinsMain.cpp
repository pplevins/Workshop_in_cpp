/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 1
The program inputs a binary search tree and doing actions on it.*/

#include <iostream>
using namespace std;
#include "SearchTree.h"
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers:\n";
	int x, y, z;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "does not exist" << endl;
			break;
		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case BREADTHSCAN: cout << "breadth first scan: ";
			T1.breadthScan();
			cout << endl;
			break;
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;

			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case DELETEDUP: cout << "after deleting duplicates: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}

/*Run sample:

enter 10 numbers:
32 45 13 21 22 55 67 81 90 37
inorder: 13 21 22 32 37 45 55 67 81 90
enter 0-8:
1
enter a number: 4
after adding 4: 4 13 21 22 32 37 45 55 67 81 90
enter 0-8:
2
enter a number: 33
does not exist
enter 0-8:
3
enter a number: 13
after removing 13: 4 21 22 32 37 45 55 67 81 90
enter 0-8:
1
enter a number: 32
after adding 32: 4 21 22 32 32 37 45 55 67 81 90
enter 0-8:
4
breadth first scan: 32 21 45 4 22 37 55 32 67 81 90
enter 0-8:
5
height of tree: 5
enter 0-8:
6
enter a number: 21
successor of 21 is: 22
enter 0-8:
7
after deleting duplicates: 4 21 22 32 37 45 55 67 81 90
enter 0-8:
8
reflected tree: 90 81 67 55 45 37 32 22 21 4
enter 0-8:
0*/