/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 2
The program inputs a book (class) to a library (binary search tree) and doing actions on it.*/

//this is the same file as in question 1
//the standard searchTree class with the additional functions requeired for the quetion.
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}

	void remove(T val) { Tree<T>::root = remove(Tree<T>::root, val); }
	T successor(T val);
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); }

private:
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);

	typename Tree<T>::Node* remove(typename Tree<T>::Node* current, T val);
	T minValue(typename Tree<T>::Node* root); //helping find the successor

	void deleteDuplicates(typename Tree<T>::Node* root); // helping to the remove method
	typename Tree<T>::Node* helpSearch(typename Tree<T>::Node* current, T val);
};


template <class T>
void SearchTree<T>::add(T val)
{
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}

	add(Tree<T>::root, val);
}


template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val) {

	if (current->value < val)
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}


template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val) {

	if (!current)
		return false;	// we got to the end of the tree and the val isn't exist
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
inline T SearchTree<T>::successor(T val)
{
	typename Tree<T>::Node* current = helpSearch(Tree<T>::root, val);
	if (current->right != NULL)
		return minValue(current->right);
	else 
	{
		typename Tree<T>::Node* currentSuccessor = NULL;
		typename Tree<T>::Node* father = Tree<T>::root;
		while (father != current)
		{
			if (father->value > current->value)
			{
				currentSuccessor = father;
				father = father->left;
			}
			else
				father = father->right;
		}
		if (currentSuccessor == NULL)
			throw "no successor";
		else
			return currentSuccessor->value;
	}
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::remove(typename Tree<T>::Node* current, T val)
{
	if (current == NULL)
		return current;
	if (val < current->value)
		current->left = remove(current->left, val);
	else if (val > current->value)
		current->right = remove(current->right, val);
	else
	{
		if (current->left == NULL)
			return current->right;
		else if (current->right == NULL)
			return current->left;
		current->value = minValue(current->right);
		current->right = remove(current->right, current->value);
	}
	return current;
}


template <class T>
inline T SearchTree<T>::minValue(typename Tree<T>::Node* root)
{
	typename Tree<T>::Node* current = root;
	while (current->left != NULL)
		current = current->left;
	return current->value;
}

template <class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	static QueueVector<T>tempQueue(50);

	if (current)
	{ //if current is not null 
		deleteDuplicates(current->left);
		tempQueue.enqueue(current->value);
		deleteDuplicates(current->right);
	}

	if (current == Tree<T>::root)
	{
		T help1, help2;
		if (!tempQueue.isEmpty())
			help1 = tempQueue.dequeue();
		while (!tempQueue.isEmpty())
		{
			help2 = tempQueue.dequeue();
			if (help1 == help2)
				remove(help1);
			help1 = help2;
		}
	}
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::helpSearch(typename Tree<T>::Node* current, T val)
{
	if (!current)
		throw "no successor";
	if (current->value == val)
		return current;
	if (current->value < val)
		return helpSearch(current->right, val);
	else
		return helpSearch(current->left, val);
}