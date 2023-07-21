/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 5 Question 2
The program creates a sorted linked list, and do actions on it.*/

#include <iostream>
using namespace std;
#include "List.h"

List merge(const List& l1, const List& l2)
{
	if (l1.isEmpty())
	{
		List merg(l2);
		return merg;
	}
	if (l2.isEmpty())
	{
		List merg(l1);
		return merg;
	}
	List merg = l1;
	List p = l2;
	while (!p.isEmpty())
	{
		merg.insert(p.firstElement());
		p.removeFirst();
	}
	return merg;
}

void makeSet(List& l)
{
	int temp = 0;//dropping duplicate values
	List new_list1, new_list2 = l;
	while (!new_list2.isEmpty())
	{
		temp = new_list2.firstElement();
		new_list2.removeFirst();
		if (!new_list2.isEmpty())
		{
			if (temp != new_list2.firstElement())
				new_list1.insert(temp);
		}
	}
	new_list1.insert(temp);
	l = new_list1;
}

void reverse(List& l)
{
	List reverse, temp = l;//making the existing list
	while (!temp.isEmpty())
	{
		reverse.add(temp.firstElement());
		temp.removeFirst();
	}
	l = reverse;
}

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;

	return 0;
}

/*enter sorted values for the first list :
6 5 4 3 2 1 9
enter sorted values for the second list :
7 5 4 3 9
the new merged list : 7 6 5 5 4 4 3 3 2 1
the new merged set : 7 6 5 4 3 2 1
the new merged reverse : 1 2 3 4 5 6 7
*/