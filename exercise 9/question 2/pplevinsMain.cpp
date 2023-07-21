/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 2
The program inputs a book (class) to a library (binary search tree) and doing actions on it.*/

#include "Books.h"
#include "SearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	SearchTree<Books> booksTree;
	char choice = 'z';
	Books book;

	while (choice != 'e')
	{
		cout << "enter a-e:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 'a':
			cout << "enter a book" << endl;
			cin >> book;
			booksTree.add(book);
			break;

		case 'b':
			cout << "enter a book" << endl;
			cin >> book;
			try
			{
				booksTree.remove(book);
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;

		case 'c':
			cout << "enter a book" << endl;
			cin >> book;
			if (booksTree.search(book))
				cout << "exist" << endl;
			else
				cout << "not exist" << endl;
			break;

		case 'd':
			booksTree.inOrder();
			break;

		case 'e':
			break;

		default:
			cout << "error" << endl;
			break;
		}
	}
	return 0;
}

/*Run sample:

enter a-e:
a
enter a book
2 b b
enter a-e:
a
enter a book
5 e e
enter a-e:
a
enter a book
1 a a
enter a-e:
a
enter a book
4 d d
enter a-e:
a
enter a book
7 g g
enter a-e:
a
enter a book
3 c c
enter a-e:
b
enter a book
5 e e
enter a-e:
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e:
e*/