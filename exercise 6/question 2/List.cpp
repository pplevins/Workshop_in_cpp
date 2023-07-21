/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 6 Question 2
The program creates a sorted linked round list, and do actions on it.*/

#include <iostream>
using namespace std;
#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{
	// no further initialization
}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}


List::~List()
{
	clear();
}

void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	/*if (head != nullptr) {

	}*/
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::addFirst(int key)
{
	head = new Link(key, head);
}

void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}
void List::remove(int  value) {
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	if (head->value == value) {
		Link* p = head;
		head = head->next;
		delete p;
		return;
	}
	Link* p = head;
	while (p->next && p->next->value != value)
		p = p->next;
	if (p->next) {
		Link* q = p->next;
		p->next = q->next;
		delete q;
		return;
	}
	throw "value not found\n ";
}
ostream& operator<<(ostream& os, const List& ms) {
	if (ms.isEmpty()) {
		os << "list empty\n";
		return os;
	}
	for (List::Link* p = ms.head; p != nullptr; p = p->next)
		os << p->value << " ";
	return os;
}
istream& operator>>(istream& is, List& ms) {
	bool binput = true;
	int input, input2;
	is >> input;
	input2 = input;
	ms.add(input);
	while (binput)
	{
		is >> input;
		if (input < input2)
			ms.insert(input);
		else
			binput = false;
		input2 = input;
	}
	return is;
}
void List::insert(int key) {
	if (isEmpty()) {
		addFirst(key);
		return;
	}
	Link* p = head;
	if (key >= p->value) {
		head = new Link(key, p);
		return;
	}

	for (; p->next != nullptr; p = p->next) {
		if (key >= p->next->value) {
			p->next = new Link(key, p->next);
			return;
		}
	}
	if (p->next == nullptr) {
		p->next = new Link(key, nullptr);
	}
}
List& List::operator=(const List& l) {
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		Link* p = l.head;
		head = new Link(p->value, head);
		Link* q = head;

		while (p->next != nullptr)
		{
			q->next = new Link(p->next->value, nullptr);
			q = q->next;
			p = p->next;
		}
	}

	return *this;
}