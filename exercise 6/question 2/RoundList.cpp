/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 2
The program creates a sorted linked round list, and do actions on it.*/

#include "List.h"
#include "RoundList.h"
#include <iostream>
using namespace std;

RoundList::RoundList() : List()
{

}

RoundList::RoundList(const RoundList& rl)
{
	Link* src, *trg;
	if (rl.head == nullptr)//if the list is empty
		head = nullptr;
	else
	{
		head = new Link((rl.head)->value, rl.head->next);
		src = rl.head;
		trg = head;
		while (src->next->value != rl.head->value);
		{
			trg->next = new Link((src->next)->value, rl.head);
			src = src->next;
			trg = trg->next;
		}
	}
}

RoundList::~RoundList()
{
	clear();
}

void RoundList::removeFirst() //when there is only one organ on the list.
{
	if (isEmpty())
		return;
	if (head == head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	Link* w = head->next;
	head->next = w->next;
	w->next = nullptr;
	delete w;
}

void RoundList::add(int value)
{
	if (isEmpty())//when inserting the first organ, and because it's a round list
		addToEnd(value);
	else //The simple case.
	{
		Link* z = new Link(value, head->next);
		head->next = z;
	}
}

void RoundList::addToEnd(int value)
{
	if (isEmpty())//when inserting the first organ, and because it's a round list
	{
		Link* w = new Link(value, nullptr);
		head = w;
		head->next = head;
		return;
	}
	else//The simple case.
	{
		Link* w = new Link(value, head->next);
		head->next = w;
		head = w;
	}
}

int RoundList::search(int n) //Search by index and using counter because it's a round list.
{
	if (isEmpty())
		return -1;
	int counter = 0;
	for (Link* p = head->next; ; p = p->next, counter++)
	{
		if (n == counter)
			return p->value;
	}
}

void RoundList::clear()
{
	while (!isEmpty())
	{
		removeFirst();
	}
}

ostream& operator<<(ostream& os, const  RoundList& rl)
{

	if (rl.isEmpty())
		return os;
	RoundList::Link* p = rl.head->next;
	do
	{
		os << p->value << " ";
		p = p->next;
	}
	while (p != rl.head->next);
	return os;
}