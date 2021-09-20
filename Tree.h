/*
David Ankory 206780066
Workshop in C ++
Exercise 9 Question 2
The h and cpp file includes the names and the algoritems of the functions and their definition
*/
#pragma once
#include <iostream>
#include "Queue.h"
#include "QueueVector.h"
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
	int height();
	void reflect();
	void breadthScan();

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	//help methods
	int hight(Node* current);
	void rflect(Node* current);
};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
/*
like the Tree.cpp file that Includes all the codes of the functions
*/

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
int Tree<T>::height()// deallocate tree
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		return(this->hight(this->root));
	}
}
template<class T>
inline int Tree<T>::hight(Node* current)
{
	if (current == NULL)
		return -1;
	else
	{
		return max(hight(current->left), hight(current->right)) + 1;
	}
}

template<class T>
inline void Tree<T>::rflect(Node* current)
{
	if (current == NULL)
		return;
	else
	{
		Node* temp;

		/* do the subtrees */
		rflect(current->left);
		rflect(current->right);

		/* swap the pointers in this node */
		temp = current->left;
		current->left = current->right;
		current->right = temp;
	}
}




template<class T>
void Tree<T>::reflect()
{
	if (isEmpty())
	{
		return;
	}
	rflect(Tree<T>::root);
}


template<class T>
void Tree<T>::breadthScan()
{
	if (root == NULL)// Base Case
	{
		return;
	}


	// Create an empty queue for level order traversal;
	QueueVector<Node*> print(50);//((pow(2, hight(current)+1 )-1));//queue int size of the num of valuse in the tree
	print.enqueue(root);

	while (!print.isEmpty())//have more value to print
	{
		Node* nod = print.front();
		cout << nod->value << " ";
		print.dequeue();

		//enqueue Left child

		if (nod->left != NULL)
		{
			print.enqueue(nod->left);
		}

		//enqueue Left child
		if (nod->right != NULL)
		{
			print.enqueue(nod->right);
		}
	}
}


