/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 9 Question 1
The program inputs a binary search tree and doing actions on it.*/

//this is the standard tree class with the addtional functions requeired in the quetion.
#pragma once
#include "QueueVector.h"
#include <iostream>
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int height() { return height(root); } //calculting the height of the tree
	void reflect() { reflect(root); } //creating the mirror view of the tree
	void breadthScan() { breadthScan(root); } //scan the width of the tree


private:
	//private function for not give access to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	int height(Node* current); //calculting the height of the tree
	void reflect(Node* current); //creating the mirror view of the tree
	void breadthScan(Node* current); //scan the width of the tree
};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template<class T>
int Tree<T>::height(Node* current)
{
	if (current == NULL) //empty
		return -1;

	return max(height(current->right), height(current->left)) + 1;
}

template<class T>
void Tree<T>::reflect(Node* current)
{
	if (current == NULL)
		return;
	else
	{
		Node* temp;
		reflect(current->left);
		reflect(current->right);

		//swap
		temp = current->left;
		current->left = current->right;
		current->right = temp;
	}
}

template<class T>
inline void Tree<T>::breadthScan(Node* current)
{

	if (current == NULL)
		return;

	QueueVector<Node*> qe(50);
	qe.enqueue(root);

	while (!qe.isEmpty())
	{
		Node* node = qe.front();
		cout << node->value << " ";
		qe.dequeue();

		if (node->left != NULL)
			qe.enqueue(node->left);

		if (node->right != NULL)
			qe.enqueue(node->right);
	}
}