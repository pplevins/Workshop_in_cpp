/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 5 Question 1
The program creates a sorted linked list, and do actions on it.*/

#include <iostream>
using namespace std;
#include "List.h"

enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };

int main() {
	List lst;
	List lst2;
	int choice, val;

	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-4\n";
	cin >> choice;
	while (choice != EXIT) {
		switch (choice) {
		case INSERT:
			cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case REMOVE:
			try
			{
				cout << "enter a value to remove\n";
				cin >> val;
				lst.remove(val);
			}
			catch (const char* prablem)
			{
				cout << prablem;
			}
			break;
		case ASSIGN:
			try
			{
				lst2 = lst;
				cout << "list 2: " << lst2;
				cout << "list 1: ";
			}
			catch (const char* prablem)
			{
				cout << prablem;
			}

		case PRINT:
			try
			{
				cout << lst << endl;
			}
			catch (const char* prablem)
			{
				cout << prablem;
			}

			break;
		default:cout << "ERROR\n";
		}
		cout << "choose 0-4\n";
		cin >> choice;
	}
	return 0;
}
/*enter the list values
25 20 15 8 6 10
choose 0-4
4
25 20 15 8 6
choose 0-4
1
enter a value to insert
15
choose 0-4
1
enter a value to insert
7
choose 0-4
4
25 20  15 15 8 7 6
choose 0-4
2
enter a value to remove
15
choose 0-4
2
enter a value to remove
8
choose 0-4
3
list2: 25 20 15 7 6
list1: 25 20 15 7 6
choose 0-4
0
*/