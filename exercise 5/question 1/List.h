/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 5 Question 1
The program creates a sorted linked list, and do actions on it.*/

#pragma once

//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void remove(int  value);
	void insert(int);
	void addFirst(int key);
	List& operator=(const List& l);
	friend ostream& operator<<(ostream& os, const List& ms);
	friend istream& operator>>(istream& is, List& ms);
protected:
	// data field
	Link* head;

};
