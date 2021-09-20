/*
David Ankory 206780066
Workshop in C ++
Exercise 9 Question 2
The h and cpp file includes the names and the algoritems of the functions and their definition
*/
#pragma once
#include "Tree.h"
#include <iostream>
#include "Queue.h"
#include "QueueVector.h"
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
	void remove(T val);
	T successor(T val);
	void deleteDuplicates();


private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	//help mettods
	typename Tree<T>::Node* Dell(typename Tree<T>::Node* current, T val);
	T minValue(typename Tree<T>::Node* root);
	typename Tree<T>::Node* Find(typename Tree<T>::Node* root, T data);//to find some data in the tree
	void deleteNode(typename Tree<T>::Node* root);
};

/*
like the QueueVector.cpp file that Includes all the codes of the functions
*/

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);

}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)//get the values in order of search binary tree
{
	if (current->value < val)//bigger right
	{
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else {
			add(current->right, val);
		}
	}
	else//smaller and equal to the left
	{
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else {
			add(current->left, val);
		}
	}
}



template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}



template<class T>
T SearchTree<T>::minValue(typename Tree<T>::Node* root)
{
	typename Tree<T>::Node* current = root;
	// loop down to find the leftmost leaf 
	while (current->left != NULL) {
		current = current->left;
	}
	return current->value;
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::Find(typename Tree<T>::Node* root, T data)//find values in the tree and return the Nod
{
	if (root == NULL) return NULL;
	else if (root->value == data) return root;
	else if (root->value < data) return Find(root->right, data);
	else return Find(root->left, data);
}

template<class T>
void SearchTree<T>::remove(T val)//dell valus
{
	Tree<T>::root = Dell(Tree<T>::root, val);
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::Dell(typename Tree<T>::Node* current, T val)
{

	if (current == NULL)
		return current;

	/* Otherwise, recur down the tree */
	if (val < current->value)
	{
		current->left = Dell(current->left, val);
	}
	else if (val > current->value)
	{
		current->right = Dell(current->right, val);
	}

	// if key is same as root's
	// key, then This is the
	// node to be deleted
	else {
		// node with only one child or no child
		if (current->left == NULL)
			return current->right;
		else if (current->right == NULL)
			return current->left;

		// node with two children: Get the inorder
		// successor (smallest in the right subtree)
		current->value = minValue(current->right);

		// Delete the inorder successor
		current->right = Dell(current->right, current->value);
	}

	return current;
}

template<class T>
T SearchTree<T>::successor(T val)
{
	typename Tree<T>::Node* current = Find(this->root, val);

	if (current->right != NULL) {  //Case 1: Node has right subtree
		return minValue(current->right);
	}

	else {   //Case 2: No right subtree  - O(h)
		typename Tree<T>::Node* successor = NULL;
		typename Tree<T>::Node* ancestor = this->root;
		while (ancestor != current) {
			if (current->value < ancestor->value) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		if (successor == NULL)
		{
			throw "no successor";
		}
		else
		{
			return successor->value;
		}
	}
}

template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	deleteNode(this->root);
}

template<class T>
void SearchTree<T>::deleteNode(typename Tree<T>::Node* root)//delete dop
{
	static QueueVector<T> help(50);//to chek the valuse
	if (root)//not empty
	{
		deleteNode(root->left);//chek the lfet
		help.enqueue(root->value);//get the value to the queue
		deleteNode(root->right);//chek the right
	}
	if (root == Tree<T>::root)
	{
		T temp1, temp2;//temps to help with the chek
		if (!help.isEmpty())//if is not empty
		{
			temp1 = help.dequeue();//get the first val in the queue
		}

		while (!help.isEmpty())
		{
			temp2 = help.dequeue();
			if (temp1 == temp2)//if the value preforme twice in the tree the methode delete him
			{
				remove(temp1);
			}
			temp1 = temp2;
		}
	}

}
